import socket

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

port = 9999
host = socket.gethostname()

s.connect((host, port))

msg = "hellp"

s.sendto(msg.encode(), (host, port))
