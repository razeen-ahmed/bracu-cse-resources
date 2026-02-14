import socket

data = 16

port = 5060

format = 'utf-8'

disconnected_msg = 'end'

hostname = socket.gethostname()

host_address = socket.gethostbyname(hostname)

server_sock_address = (host_address,port)

server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

server.bind(server_sock_address)

server.listen()

print("Server is listening")

while True:
    conn, address = server.accept()
    print("Connected to",address)
    connected = True

    while connected:
        initial = conn.recv(data).decode(format)
        print('Length of the msg to be sent',initial)

        if initial:
            msg_length = int(initial)
            msg = conn.recv(msg_length).decode(format)

            if msg == disconnected_msg:
                print('Terminating connection with',address)
                conn.send('Nice to meet you'.encode(format))
                connected = False

            else:
                print(msg)
                conn.send('Received your msg'.encode(format))

    conn.close()