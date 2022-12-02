import socket

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

host = socket.gethostname()
port = 9999

s.bind((host, port))

s.listen()

conn, addr = s.accept()
print(f"server connected to {addr}")
conn.send("server connected".encode())
print(conn.recv(1024).decode())

while True:
    data = conn.recv(1024).decode()
    if data == 'quit':
        conn.close()
        break
    print(data)
    msg = input()
    conn.send(msg.encode())
    if msg == 'quit':
        break
s.close()
