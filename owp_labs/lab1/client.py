import socket

def input_serv_port():
    print("Please enter server port:")
    data = input()
    if data == "exit":
        return
    return data

sock = socket.socket()
PORT = int(input_serv_port())
sock.connect(('localhost', PORT))
while (1):
    outdata = input('>>>')
    if len(outdata) == 0:
        continue
    if outdata == "exit":
        #sock.send('exit'.encode('utf_8'))
        sock.close()
        break
    sock.send(outdata.encode('utf-8'))
    indata = sock.recv(1024)
    print ('<<<' + indata.decode('utf-8'))

sock.close()
