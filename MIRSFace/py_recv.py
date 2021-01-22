#-*- coding: utf-8 -*-
import time
from socket import socket, AF_INET, SOCK_STREAM

#HOST        = 'localhost'
#HOST        = '172.21.2.167'
HOST        = '127.0.0.1'
PORT        = 51000
MAX_MESSAGE = 1024

def py_recv(mode):

    #mess[MAX_MESSAGE]

    # 通信の確立
    sock = socket(AF_INET, SOCK_STREAM)
    sock.bind    ((HOST, PORT))
    sock.listen  (1)
    #print ('receiver ready ')

    #conn, addr = sock.accept()

    # メッセージ受信
    while True:
        try:
            print ('receiver ready ')
            conn, addr = sock.accept()
            # decode()  バイト型 -> 文字列型に変換
            mess = conn.recv(MAX_MESSAGE).decode()

            # mess サイズがゼロになったら終了
            #print (len(mess))
            if len(mess) == 0:
                time.sleep(1)
            else:
                print ('receive message: ' + mess)
                mode_str = mess
                mode = int(mode_str[0])

        except:
            print ('Error:' + mess)
        

    conn.close()
    # 通信の終了
    sock.close()

    print ('end of receiver')
    return
