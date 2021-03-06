#-*- coding: utf-8 -*-
from socket import socket, AF_INET, SOCK_STREAM

#HOST        = 'localhost'
#HOST        = '172.21.2.167'
HOST        = '127.0.0.1'
PORT        = 51000
MAX_MESSAGE = 1024

def py_recv():

    #mess[MAX_MESSAGE]

    # 通信の確立
    sock = socket(AF_INET, SOCK_STREAM)
    sock.bind    ((HOST, PORT))
    sock.listen  (1)
    print ('receiver ready ')

    conn, addr = sock.accept()

    # メッセージ受信
    while True:
        try:
            # decode()  バイト型 -> 文字列型に変換
            mess = conn.recv(MAX_MESSAGE).decode()
            print ('receive message: ' + mess)

            # mess サイズがゼロになったら終了
            #print (len(mess))
            if len(mess) == 0:
                break
            else:
                mode_str = mess

        except:
            print ('Error:' + mess)

    conn.close()
    # 通信の終了
    sock.close()

    print ('end of receiver')
    mode_int = int(mode_str[0])
    return mode_int
