# packet sniffer
import scapy.all as scapy
import argparse
from scapy.layers import http
import colorama
from colorama import Fore
import csv

# Machine Learning
import math, time, random, datetime
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns
from sklearn import model_selection
from sklearn import metrics
plt.style.use('seaborn')
import warnings
warnings.filterwarnings('ignore')
import missingno
import pickle

# models
from sklearn.linear_model import LogisticRegression
from sklearn.tree import DecisionTreeClassifier
from sklearn.ensemble import RandomForestClassifier
from sklearn.neural_network import MLPClassifier
from sklearn.ensemble import GradientBoostingClassifier
from sklearn.naive_bayes import GaussianNB
from sklearn.svm import LinearSVC


# packet sniffer
default_values = {
    'id': 0, 'dur': 0, 'proto': 0, 'service': 0, 'state': 0, 'spkts': 0,
    'dpkts': 0, 'sbytes': 0, 'dbytes': 0, 'rate': 0, 'sttl': 0, 'dttl': 0,
    'sload': 0, 'dload': 0, 'sloss': 0, 'dloss': 0, 'sinpkt': 0, 'dinpkt': 0,
    'sjit': 0, 'djit': 0, 'swin': 0, 'stcpb': 0, 'dtcpb': 0, 'dwin': 0,
    'tcprtt': 0, 'synack': 0, 'ackdat': 0, 'smean': 0, 'dmean': 0,
    'trans_depth': 0, 'response_body_len': 0, 'ct_srv_src': 0,
    'ct_state_ttl': 0, 'ct_dst_ltm': 0, 'ct_src_dport_ltm': 0,
    'ct_dst_sport_ltm': 0, 'ct_dst_src_ltm': 0, 'is_ftp_login': 0,
    'ct_ftp_cmd': 0, 'ct_flw_http_mthd': 0, 'ct_src_ltm': 0, 'ct_srv_dst': 0,
    'is_sm_ips_ports': 0, 'attack_cat': "Normal", 'label': 0
}

data = []

def extract_data(packet):
    data = default_values.copy()
    def update_data(key, value):
        if key in data:
            data[key] = value

    # HTTP packets
    if packet.haslayer(http.HTTPRequest):
        update_data('proto', 'HTTP')

    # IP packets
    elif packet.haslayer(scapy.IP):
        ip_layer = packet[scapy.IP]
        update_data('sbytes', len(ip_layer))
        update_data('proto', ip_layer.proto)

    # TCP packets
    elif packet.haslayer(scapy.TCP):
        tcp_layer = packet[scapy.TCP]
        update_data('spkts', 1)  
        update_data('dpkts', 0)  

    # UDP packets
    elif packet.haslayer(scapy.UDP):
        udp_layer = packet[scapy.UDP]
        update_data('spkts', 1) 
        update_data('dpkts', 0) 

    # ICMP packets
    elif packet.haslayer(scapy.ICMP):
        icmp_layer = packet[scapy.ICMP]
        update_data('spkts', 1)
        update_data('dpkts', 0)

    return list(data.values())

def update_csv():
    global data
    csv_file_path = '/content/drive/My Drive/UNSW_NB15_training-set.csv'
    with open(csv_file_path, mode='r') as file:
        reader = list(csv.reader(file))

    max_id = max(int(row[0]) for row in reader[1:]) if len(reader) > 1 else 0
    for i, row in enumerate(data):
        row[0] = max_id + i + 1

    reader.extend(data)

    with open(csv_file_path, mode='w', newline='') as file:
        writer = csv.writer(file)
        writer.writerows(reader)

def get_interface():
    parser = argparse.ArgumentParser()
    parser.add_argument('-f')
    parser.add_argument("-i", "--interface", dest="interface", help="Specify the network interface")
    arguments = parser.parse_args()
    return arguments.interface

def sniff(iface):
    global data
    packet_count = 0

    def process_packet(packet):
        nonlocal packet_count
        print(f"[+] Packet {packet_count + 1} captured")
        packet.show()
        extracted_data = extract_data(packet)
        data.append(extracted_data)
        packet_count += 1

    scapy.sniff(iface=iface, store=False, prn=process_packet, stop_filter=lambda _: packet_count >= 10)

iface = get_interface()
sniff(iface)
update_csv()

train_data = pd.read_csv('/content/drive/My Drive/UNSW_NB15_training-set.csv')
test_data = pd.read_csv('/content/drive/My Drive/UNSW_NB15_testing-set.csv')

# Combine the data to avoid preprocessing twice
combined_data = pd.concat([train_data, test_data]).reset_index(drop=True)

categorical_cols = combined_data.select_dtypes('object').columns
numeric_cols = combined_data._get_numeric_data().columns
print(numeric_cols)

# Handle type of service that is '-'
combined_data['service'].unique()
combined_data['service'] = np.where(combined_data['service'] == '-', 'None', combined_data['service'])
print(combined_data['service'].unique())

# Automate the process of removing dump values
def remove_dump_values(data, columns):
    for column in columns:
        data[column] = np.where(data[column] == '-', 'None', data[column])
    return data

columns = combined_data.columns
processed_data = remove_dump_values(combined_data, columns)


# Remove features that are not needed
processed_data = processed_data.drop(['id'], axis=1)
# Replace the attack_cat with true
processed_data.drop(['attack_cat'], axis=1, inplace=True)
categorical_cols = categorical_cols.drop(['attack_cat'])

# Perform one-hot encoding
processed_data_encoded = pd.get_dummies(processed_data, columns=categorical_cols)

# Normalization
numeric_cols = list(numeric_cols)
numeric_cols.remove('label')
numeric_cols.remove('id')

processed_data_encoded[numeric_cols] = processed_data_encoded[numeric_cols].astype('float')

processed_data_encoded[numeric_cols] = (processed_data_encoded[numeric_cols] - np.min(processed_data_encoded[numeric_cols])) / np.std(processed_data_encoded[numeric_cols])

processed_data_encoded.head()

X = processed_data_encoded.drop('label', axis=1)
Y = processed_data_encoded['label']

def perform_model_fit(algorithm, features, labels, cv_splits):
    # Fit the model
    trained_model = algorithm.fit(features, labels)
    
    # Evaluate its accuracy
    accuracy = round(trained_model.score(features, labels) * 100, 2)
    predicted_labels = model_selection.cross_val_predict(algorithm, features, labels, cv=cv_splits, n_jobs=-1)
    
    accuracy_cv = round(metrics.accuracy_score(labels, predicted_labels) * 100, 2)
    
    return predicted_labels, accuracy, accuracy_cv, trained_model

classifiers = [
    ("Logistic Regression", LogisticRegression(C=0.1)),
    ("Decision Tree", DecisionTreeClassifier(random_state=42)),
    ("Random Forest", RandomForestClassifier(n_estimators=100)),
    ("Random Forest (Entropy)", RandomForestClassifier(n_estimators=100, criterion='entropy')),
    ("MLP Classifier", MLPClassifier(hidden_layer_sizes=(20,), activation='relu', solver='adam')),
    ("Gaussian Naive Bayes", GaussianNB()),
    ("Gradient Boosting", GradientBoostingClassifier()),
    ("Linear SVC", LinearSVC())
]

def evaluate_classifiers(classifiers, X, Y, cv):
    results = []
    for clf_name, clf in classifiers:
        start_time = time.time()
        pred_now, acc, acc_cv, model = perform_model_fit(clf, X, Y, cv)
        exec_time = (time.time() - start_time)
        results.append((clf_name, acc, acc_cv, exec_time))
        print(f"{clf_name} - Accuracy: {acc}, Accuracy of CV: {acc_cv}, Execution time: {exec_time}")
    return results
results = evaluate_classifiers(classifiers, X, Y, 10)


algo_name = ['Log. Reg.', 'Decision Tree', 'RandomForest Gini', 'RandomForest IG', 'Neural Network', 'Gaussian NB', 'GBC', 'SVM']
accuracy_scores = [result[2] for result in results] 
acc_df = pd.DataFrame({'Algorithm': algo_name, 'Accuracy %': accuracy_scores})
acc_df = acc_df.sort_values(by='Accuracy %', ascending=False)
acc_df = acc_df.reset_index(drop=True)
print(acc_df)





