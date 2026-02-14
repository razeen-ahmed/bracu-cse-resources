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

msg = f"IP address of the client is {host_address} and device name is {hostname}"
msg_send(msg)
msg_send(disconnected_msg)
