import socket

sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server_address = ("pucp.jobenas.com", 5000)

print("Conectandose a {}, en el puerto {}".format(server_address[0], server_address[1]))

sock.connect(server_address)

try:
	msg = "Hola Mundo"
	print("enviando {}".format(msg))
	sock.sendall(msg)

	data = sock.recv(1024)
	print("recibi: {}".format(data))
finally:
	print("cerrando el puerto")
	sock.close()