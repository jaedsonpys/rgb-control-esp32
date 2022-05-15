import socket


class Controller:
    def __init__(self, host: str, port: int):
        self.socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.socket.connect((host, port))

    def on_red(self):
        self.socket.send(b'RED')

    def on_green(self):
        self.socket.send(b'GREEN')

    def on_blue(self):
        self.socket.send(b'BLUE')

    def rgb(self, red: int, green: int, blue: int):
        self.socket.send(f'RGB {red},{green},{blue}'.encode())
