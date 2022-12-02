import socket
import time

c = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

host = socket.gethostname()
port = 9999

c.connect((host, port))

print(c.recv(1024).decode() + "server time")
c.send(time.ctime(time.time()).encode())

while True:
    msg = input()
    c.send(msg.encode())
    if msg == 'quit':
        break
    data = c.recv(1024).decode()
    if(data == 'quit'):
        print("server closed the conn")
        break
    print(data)
c.close()
