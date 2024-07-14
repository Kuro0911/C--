
import pandas as pd
import numpy as np
import seaborn as sns
import matplotlib.pyplot as plt
from sklearn.preprocessing import RobustScaler
from sklearn.model_selection import train_test_split
from sklearn.metrics import classification_report, confusion_matrix
from sklearn.ensemble import RandomForestClassifier
from sklearn.tree import DecisionTreeClassifier
from sklearn.svm import SVC
from sklearn.neighbors import KNeighborsClassifier
from sklearn.linear_model import LogisticRegression


# Load the dataset
data = pd.read_csv('/content/drive/MyDrive/nsl-kdd/KDDTrain+.txt')
data.head()


columns = (['duration','protocol_type','service','flag','src_bytes','dst_bytes','land','wrong_fragment','urgent','hot'
,'num_failed_logins','logged_in','num_compromised','root_shell','su_attempted','num_root','num_file_creations'
,'num_shells','num_access_files','num_outbound_cmds','is_host_login','is_guest_login','count','srv_count','serror_rate'
,'srv_serror_rate','rerror_rate','srv_rerror_rate','same_srv_rate','diff_srv_rate','srv_diff_host_rate','dst_host_count','dst_host_srv_count'
,'dst_host_same_srv_rate','dst_host_diff_srv_rate','dst_host_same_src_port_rate','dst_host_srv_diff_host_rate','dst_host_serror_rate'
,'dst_host_srv_serror_rate','dst_host_rerror_rate','dst_host_srv_rerror_rate','outcome','level'])
data.columns = columns
data.info()
data.describe().style.background_gradient(cmap='Blues').set_properties(**{'font-family':'Segoe UI'})

data.loc[data['outcome'] == "normal", "outcome"] = 'normal'
data.loc[data['outcome'] != 'normal', "outcome"] = 'attack'

def pie_plot(df, cols_list, rows, cols):
    fig, axes = plt.subplots(rows, cols)
    for ax, col in zip(axes.ravel(), cols_list):
        df[col].value_counts().plot(ax=ax, kind='pie', figsize=(15, 15), fontsize=10, autopct='%1.0f%%')
        ax.set_title(str(col), fontsize = 12)
    plt.show()
pie_plot(data, ['protocol_type', 'outcome'], 1, 2)




# Define categorical and numerical columns
CATEGORICAL_COLS = ['is_host_login', 'protocol_type', 'service', 'flag', 'land', 'logged_in', 'is_guest_login', 'level', 'outcome']

# Function to scale numerical features
def scale_numerical_features(df, numerical_columns):
    scaler = RobustScaler()
    scaled_features = scaler.fit_transform(df[numerical_columns])
    return pd.DataFrame(scaled_features, columns=numerical_columns)

# Function to preprocess the dataset
def preprocess_dataset(dataset):
    # Separate numerical and categorical data
    numerical_data = dataset.drop(CATEGORICAL_COLS, axis=1)
    numerical_cols = numerical_data.columns

    # Scale numerical data
    scaled_numerical_data = scale_numerical_features(numerical_data, numerical_cols)

    # Update the dataset with scaled numerical data
    dataset = dataset.drop(numerical_cols, axis=1)
    dataset = pd.concat([dataset, scaled_numerical_data], axis=1)

    # Convert 'outcome' to binary
    dataset['outcome'] = dataset['outcome'].apply(lambda x: 0 if x == 'normal' else 1)

    # Apply one-hot encoding to categorical data
    dataset = pd.get_dummies(dataset, columns=['protocol_type', 'service', 'flag'])

    return dataset

# Apply preprocessing
preprocessed_data = preprocess_dataset(data)

# Prepare features and labels
X = preprocessed_data.drop(['outcome', 'level'], axis=1).values
y = preprocessed_data['outcome'].values.astype('int')

# Split the data into training and test sets
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)


# Initialize models
models = {
    'Random Forest': RandomForestClassifier(n_estimators=100),
    'Decision Tree': DecisionTreeClassifier(),
    'SVM': SVC(),
    'KNN': KNeighborsClassifier(),
    'Logistic Regression': LogisticRegression(max_iter=1000)
}


# Function to train and evaluate a model
def train_eval_model(model, X_train, y_train, X_test, y_test):
    model.fit(X_train, y_train)
    y_pred = model.predict(X_test)
    print(model.__class__.__name__)
    print(classification_report(y_test, y_pred))
    conf_matrix = confusion_matrix(y_test, y_pred)
    plt.figure(figsize=(10, 7))
    sns.heatmap(conf_matrix, annot=True, fmt='g')
    plt.title('Confusion Matrix for ' + model.__class__.__name__)
    plt.ylabel('Actual Label')
    plt.xlabel('Predicted Label')
    plt.show()

# Train and evaluate each model
for name, model in models.items():
    train_eval_model(model, X_train, y_train, X_test, y_test)