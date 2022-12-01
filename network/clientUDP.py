import socket
import time

s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

host = socket.gethostname()
port = 9999

currTime = time.ctime(time.time())
s.sendto(currTime.encode(), (host, port))
