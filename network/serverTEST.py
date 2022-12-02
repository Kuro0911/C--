import socket
import time

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

host = socket.gethostname()
port = 9999

s.bind((host, port))

s.listen(5)

conn, addr = s.accept()

conn.send(time.ctime(time.time()).encode())
print(conn.recv(1024).decode() + "client time")

while True:
    data = conn.recv(1024).decode()
    if(data == 'quit'):
        print("client closed the conn")
        conn.close()
        break
    print(data)
    msg = input()
    conn.send(msg.encode())
    if msg == 'quit':
        conn.close()
        break
s.close()
