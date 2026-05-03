# server.py
import socket
import threading

# 服务器地址和端口
HOST = '127.0.0.1'
PORT = 65432

# 客户端列表
clients = []

def handle_client(client_socket, client_address):
    print(f"客户端 {client_address} 已连接")
    clients.append(client_socket)
    
    try:
        while True:
            message = client_socket.recv(1024).decode('utf-8')
            if not message:
                break
            print(f"来自 {client_address} 的消息: {message}")
            broadcast_message(message, client_socket)
    except Exception as e:
        print(f"客户端 {client_address} 断开连接: {e}")
    finally:
        clients.remove(client_socket)
        client_socket.close()

def broadcast_message(message, sender_socket):
    for client in clients:
        if client != sender_socket:
            try:
                client.sendall(message.encode('utf-8'))
            except Exception as e:
                print(f"广播消息失败: {e}")
                clients.remove(client)
                client.close()

def start_server():
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server_socket.bind((HOST, PORT))
    server_socket.listen()
    print(f"服务器启动，监听 {HOST}:{PORT}")

    try:
        while True:
            client_socket, client_address = server_socket.accept()
            client_thread = threading.Thread(target=handle_client, args=(client_socket, client_address))
            client_thread.start()
    except KeyboardInterrupt:
        print("服务器关闭")
    finally:
        server_socket.close()

if __name__ == "__main__":
    start_server()




import socket
import threading
from cryptography.hazmat.primitives.asymmetric import rsa
from cryptography.hazmat.primitives.asymmetric import padding
from cryptography.hazmat.primitives import serialization
from cryptography.hazmat.primitives import hashes
from cryptography.hazmat.primitives.ciphers import Cipher, algorithms, modes
from cryptography.hazmat.primitives.kdf.pbkdf2 import PBKDF2HMAC
from cryptography.hazmat.primitives import padding as sym_padding
import os
import base64

# 服务器地址和端口
HOST = '127.0.0.1'
PORT = 65432

# 客户端列表
clients = []

# 生成 RSA 密钥对
server_private_key = rsa.generate_private_key(
    public_exponent=65537,
    key_size=2048,
)
server_public_key = server_private_key.public_key()

def handle_client(client_socket, client_address):
    print(f"客户端 {client_address} 已连接")
    clients.append(client_socket)
    
    # 接收客户端公钥
    client_public_key_bytes = client_socket.recv(2048)
    client_public_key = serialization.load_pem_public_key(client_public_key_bytes)

    # 生成对称密钥
    symmetric_key = os.urandom(32)  # AES-256 需要 32 字节密钥

    # 使用客户端公钥加密对称密钥
    encrypted_symmetric_key = client_public_key.encrypt(
        symmetric_key,
        padding.OAEP(
            mgf=padding.MGF1(algorithm=hashes.SHA256()),
            algorithm=hashes.SHA256(),
            label=None
        )
    )

    # 发送加密后的对称密钥
    client_socket.sendall(encrypted_symmetric_key)

    try:
        while True:
            # 接收加密消息
            encrypted_message = client_socket.recv(4096)
            if not encrypted_message:
                break

            # 解密消息
            iv = encrypted_message[:16]
            ciphertext = encrypted_message[16:]
            cipher = Cipher(algorithms.AES(symmetric_key), modes.CFB(iv))
            decryptor = cipher.decryptor()
            padded_message = decryptor.update(ciphertext) + decryptor.finalize()
            unpadder = sym_padding.PKCS7(128).unpadder()
            message = unpadder.update(padded_message) + unpadder.finalize()

            print(f"来自 {client_address} 的消息: {message.decode('utf-8')}")
            broadcast_message(encrypted_message, client_socket)
    except Exception as e:
        print(f"客户端 {client_address} 断开连接: {e}")
    finally:
        clients.remove(client_socket)
        client_socket.close()

def broadcast_message(encrypted_message, sender_socket):
    for client in clients:
        if client != sender_socket:
            try:
                client.sendall(encrypted_message)
            except Exception as e:
                print(f"广播消息失败: {e}")
                clients.remove(client)
                client.close()

def start_server():
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server_socket.bind((HOST, PORT))
    server_socket.listen()
    print(f"服务器启动，监听 {HOST}:{PORT}")

    try:
        while True:
            client_socket, client_address = server_socket.accept()
            client_thread = threading.Thread(target=handle_client, args=(client_socket, client_address))
            client_thread.start()
    except KeyboardInterrupt:
        print("服务器关闭")
    finally:
        server_socket.close()

if __name__ == "__main__":
    start_server()