import socket

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

host = socket.gethostname()
port = 9999

s.connect((host, port))

print(s.recv(1024).decode())
s.send("client connected".encode())

while True:
    msg = input()
    s.send(msg.encode())
    if msg == 'quit':
        break
    data = s.recv(1024).decode()
    if data == 'quit':
        s.close()
        break
    print(data)
