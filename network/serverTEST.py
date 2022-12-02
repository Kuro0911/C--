import socket
import time

s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

host = socket.gethostname()
port = 9999

s.bind((host, port))

while True:
    print(s.recvfrom(1024)[0].decode())
    break
s.close()
