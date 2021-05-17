import socket
import sched
import time
import os
import datetime
import signal
import sys
import random
import math
# Define a constant for our buffer size

BUFFER_SIZE = 1024
deltaList = []


# Create a list in directory, save port and addr
# Balancer Creates a request every five minutes
# Save time send request to server , save time inseperate variable upon arival
# find the delta and assign it to that server time
# compare the delta of all servers
# append addr and port of lowest delta to return variable
# Return Addr and Port of best address

def signal_handler(sig, frame):
    print('Interrupt received, shutting down ...')
    sys.exit(0)

def prepare_response_message(value):
    date = datetime.datetime.now()
    date_string = 'Date: ' + date.strftime('%a, %d %b %Y %H:%M:%S EDT')
    message = 'HTTP/1.1 '
    if value == '200':
        message = message + value + ' OK\r\n' + date_string + '\r\n'
    elif value == '301':
        message = message + value + ' Moved Permanently\r\n' + date_string
        '\r\n'
    elif value == '404':
        message = message + value + ' Not Found\r\n' + date_string + '\r\n'
    elif value == '501':
        message = message + value + ' Method Not Implemented\r\n' + date_string + '\r\n'
    elif value == '505':
        message = message + value + ' Version Not Supported\r\n' + date_string + '\r\n'
    return message

def send_response_to_client(sock, code, file_name):

    # Determine content type of file

    if ((file_name.endswith('.jpg')) or (file_name.endswith('.jpeg'))):
        type = 'image/jpeg'
    elif (file_name.endswith('.gif')):
        type = 'image/gif'
    elif (file_name.endswith('.png')):
        type = 'image/jpegpng'
    elif ((file_name.endswith('.html')) or (file_name.endswith('.htm'))):
        type = 'text/html'
    else:
        type = 'application/octet-stream'

    # Get size of file

    file_size = os.path.getsize(file_name)

    # Construct header and send it

    header = prepare_response_message(code) + 'Content-Type: ' + type + '\r\nContent-Length: ' + str(file_size) + '\r\n\r\n'
    sock.send(header.encode())

    # Open the file, read it, and send it

    with open(file_name, 'rb') as file_to_send:
        while True:
            chunk = file_to_send.read(BUFFER_SIZE)
            if chunk:
                sock.send(chunk)
            else:
                break


def get_line_from_socket(sock):
    done = False
    line = ''
    while (not done):
        char = sock.recv(1).decode()
        if (char == '\r'):
            pass
        elif (char == '\n'):
            done = True
        else:
            line = line + char
    return line


def save_file_from_socket(sock, bytes_to_read, file_name):
    with open(file_name, 'wb') as file_to_write:
        bytes_read = 0
        while (bytes_read < bytes_to_read):
            chunk = sock.recv(BUFFER_SIZE)
            bytes_read += len(chunk)
            file_to_write.write(chunk)


def prepare_get_message(host, port, file_name):
    request = f'GET {file_name} HTTP/1.1\r\nHost: {host}:{port}\r\n\r\n'
    return request

def getKey(item):
    return item[2]

def sortListPlusPriority(deltaList):
    for x in range(len(deltaList)):
        deltaList[x] = deltaList[x].split(',')
    tempList = sorted(deltaList, key=getKey)
    for x in range(len(tempList)):
                tempList[x] = str(tempList[x]) + "," + str(x)
                print(tempList[x])
    deltaList = tempList
    return deltaList

def clearServer(ip, port):
    delete = str(ip) + ',' + str(port)
    path = os.getcwd()
    path = os.path.abspath(os.path.join(path, os.pardir))
    print(path)
    path = path + '\server\ServerList.txt'
    with open(path, "r") as f:
        lines = f.readlines()
    with open(path, "w") as f:
        for line in lines:
            if line.strip("\n") != delete:
                f.write(line)
    print("deleted")
    f.close()


def calcDelta():
    print("Calculating Priority")
    path = os.getcwd()
    path = os.path.abspath(os.path.join(path, os.pardir))
    serverFile = path + '\server\ServerList.txt'

    with open(serverFile) as fd:
        line = fd.readline()
        while line:
            tempLine = line
            tempLine = tempLine.split(",")
            addr = str(tempLine[0])
            port = int(tempLine[1])
            # read in a line while its not empty , [0] Ip, [1] port calc and restore delta
            try:
                client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
                client_socket.connect((addr, port))
            except ConnectionRefusedError:
                print('Error:  That host or port is not accepting connections.')
                # remove server from list
                clearServer(addr, port)

            print('Connection to server established. Sending message...\n')
            tempFile = 'Test_' + str(port)
            msg = prepare_get_message(addr, port, path + '\server\pogTest.jpg')
            deltaX = time.perf_counter()
            client_socket.send(msg.encode())
            done = False
            bytes_to_read = 0
            while not done:
                line = get_line_from_socket(client_socket)
                tempList = line.split(" ")
                if line == "":
                    done = True
                elif tempList[0] == "Length":
                    bytes_to_read = int(tempList[1])
            save_file_from_socket(client_socket, bytes_to_read, tempFile)
            deltaY = time.perf_counter()
            delta = deltaY - deltaX
            os.remove(tempFile)
            print("Time to get file:" + str(delta))
            tempstr = str(addr) + ',' + str(port) + ',' + str(delta)
            deltaList.append(tempstr)
            client_socket.close()
            line = fd.readline()
            print("Sending File")

def numOfServer(deltaList):
    amountofServers = len(deltaList)
    print(amountofServers)
    return amountofServers

def balancer(request, deltaList):
    # A ,B ,C  : 1 ,2, 3
    #
    # count * factorial for max slots
    amountofServers = numOfServer(deltaList)
    selection = random.randint(1, 6)
    print(selection)
    if selection in range(4, 7):
        print(deltaList[0])
        tempList = deltaList[0]
        host = tempList[0]
        port = tempList[1]
        request_list = request.split("/")
        request_line = request_list[1].split(" ")
        file_name = request_line[0]
        message = prepare_get_message(host, port, file_name)
        print(message)
        return message
    elif selection in range(2, 4):
        tempList = deltaList[1]
        host = tempList[0]
        port = tempList[1]
        request_list = request.split("/")
        request_line = request_list[1].split(" ")
        file_name = request_line[0]
        message = prepare_get_message(host, port, file_name)
        print(message)
        return message
    elif selection in range(2) :
        tempList = deltaList[2]
        host = tempList[0]
        port = tempList[1]
        request_list = request.split("/")
        request_line = request_list[1].split(" ")
        file_name = request_line[0]
        message = prepare_get_message(host, port, file_name)
        print(message)
        return message
    else:
        print("all connections allocated please try again")

def main():

    # Register our signal handler for shutting down.
    signal.signal(signal.SIGINT, signal_handler)
    # Create the socket.  We will ask this to work on any interface and to pick
    # a free port at random.  We'll print this out for clients to use.
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server_socket.bind(('localhost', 0))
    server_socket.listen(1)
    target = datetime.datetime.now() + datetime.timedelta(minutes=5)
    calcDelta()
    sortListPlusPriority(deltaList)
    # Keep the server running forever.
    while(1):
        if datetime.datetime.now().strftime("%M") >= target.strftime("%M"):
            calcDelta()
            sortListPlusPriority(deltaList)
            target = datetime.datetime.now() + datetime.timedelta(minutes=5)

        print('Will wait for client connections at port ' + str(server_socket.getsockname()[1]))
        print('Waiting for incoming client connection ...')
        conn, addr = server_socket.accept()
        print('Accepted connection from client address:', addr)
        print('Connection to client established, waiting to receive message...')
        # We obtain our request from the socket.  We look at the request and
        # figure out what to do based on the contents of things.
        request = get_line_from_socket(conn)
        print('Received request:  ' + request)
        # retrieve the quickest server, count is the deepest server on the list which is highest prio
        print('Connection to Client established. Sending message...\n')
        message = balancer(request, deltaList)
        print(message)
        conn.send(message.encode())
        send_response_to_client(conn, '301', '301.html')



if __name__ == '__main__':
    main()
