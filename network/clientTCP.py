import socket

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

port = 9999
host = socket.gethostname()


s.connect((host, port))
while True:
    msg = input()
    s.sendto(msg.encode(), (host, port))
    if msg == "quit":
        s.close()
        break
    data = s.recv(1024).decode()
    print(data)
    if(data == 'quit'):
        s.close()
        break
