import socket
import thread

def handle(client_socket, address):
 while True:
  data = client_socket.recv(1024)
  if not data: # if data start with "exit"
   client_socket.close() # close the connection with the client
   break

  print("Recibi: {}. Reenviando".format(data))
  client_socket.send(data) # echo the received string
   

# opening the port 1075
server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server.bind(("172.31.45.236",5000))
# server.bind(("10.100.104.199", 5000))
server.listen(5)

while True: # listen for incoming connections
 client_socket, address = server.accept()
 print("solicitud de la ip: ",address[0])
 # spawn a new thread that run the function handle()
 thread.start_new_thread(handle, (client_socket, address)) 	