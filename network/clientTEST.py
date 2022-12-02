import socket
import time

c = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

host = socket.gethostname()
port = 9999

c.connect((host, port))

msg = time.ctime(time.time())
c.sendto(msg.encode(), (host, port))
c.close()
