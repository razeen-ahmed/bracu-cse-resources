import socket

format = 'utf-8'

data = 16

disconnected_msg = "end"

port = 5060

hostname = socket.gethostname()

host_address = socket.gethostbyname(hostname)

server_sock_address = (host_address,port)

client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

client.connect(server_sock_address)

def msg_send(msg):
    msg_var = msg.encode(format)
    msg_length = len(msg_var)
    msg_length = str(msg_length).encode(format)
    msg_length += b' '*(data-len(msg_length))

    client.send(msg_length)
    client.send(msg_var)

    print(client.recv(2048).decode(format))

while True:
    input_message = input('Please Enter a Message: ')


    if input_message == 'end':
        msg_send(disconnected_msg)
        break
    else:
        msg_send(input_message)


