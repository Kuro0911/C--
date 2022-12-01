import socket

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

port = 9999
host = socket.gethostname()

s.bind((host, port))
s.listen(5)

conn, adrr = s.accept()
print(f"got conn from {adrr}")

while True:
    data = conn.recv(1024).decode()
    if(data == 'quit'):
        conn.close()
        break
    print(data)
    msg = input()
    conn.send(msg.encode())
    if msg == "quit":
        break

s.close()
