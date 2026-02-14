
import socket

import threading

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

def handler(conn, address):
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
                vow = 'aeiouAEIOU'
                con = 0

                for i in msg:
                    if i in vow:
                        con +=1

                if con == 0:
                    conn.send('Not enough vowels'.encode(format))
                elif con<=2:
                    conn.send('Enough vowels I guess'.encode(format))
                elif con>2:
                    conn.send('"Too many vowels" to the client'.encode(format))


    conn.close()

while True:
    conn, address = server.accept()
    thread = threading.Thread(target=handler,args=(conn,address))
    thread.start()