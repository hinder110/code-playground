import socket
import threading

import socket
import threading
# 服务器地址和端口
HOST = '127.0.0.1'
HOST = '127.0.0.1'

PORT = 65432
PORT = 65432

def receive_messages(client_socket):
    try:
        while True:
            message = client_socket.recv(1024).decode('utf-8')
            print(message)
    except Exception as e:
        print(f"接收消息失败:{e}")
    finally:
        client_socket.close()
def receive_messages(client_socket):
    try:
        while True:
            message = client_socket.recv(1024).decode('utf-8')
            print(message)
    except Exception as e:
        print(f"接收消息失败: {e}")
    finally:
        client_socket.close()

def send_messages(client_socket):
    try:
        while True:
            message = input()
            client_socket.sendall(message.encode('utf-8'))
    except Exception as e:
        print(f"发送消息失败: {e}")
    finally:
        client_socket.close()

def start_client():
    client_socket = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
    client_socket.connect((HOST, PORT))
    print(f"已经连接到服务器 {HOST}:{PORT}")

    receive_thread = threading.Thread(target=receive_messages,args=(client_socket,))
    send_tread = threading.Thread(target=send_messages, args=(client_socket,))

    receive_thread.start()
    send_tread.start()

    receive_thread.join()
    send_tread.join()

def start_client():
    client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    client_socket.connect((HOST, PORT))
    print(f"已连接到服务器 {HOST}:{PORT}")

    receive_thread = threading.Thread(target=receive_messages, args=(client_socket,))
    send_thread = threading.Thread(target=send_messages, args=(client_socket,))

    receive_thread.start()
    send_thread.start()

    receive_thread.join()
    send_thread.join()

if __name__ == "__main__":
    start_client()

if __name__ == "__main__":
    start_client()

#这是一个模块化编程的必要的步骤，在Java中是很常见的。