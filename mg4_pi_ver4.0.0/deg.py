 # -*- coding: utf-8 -*-
import cv2 as cv
import numpy as np
import math

fn = 'my_pic.jpg'

# カメラ初期化
cap = cv.VideoCapture(0)

# 撮影した写真を読み込む
ret , img = cap.read()
#img = cv.imread('ballimg.jpg')
ball_n = [0,0,0,0]
height, width, channels = img.shape[:3]


# 顔検出のための学習元データを読み込む
ball_cascade = cv.CascadeClassifier('cascade.xml')
# 顔検出を行う
ballrect = ball_cascade.detectMultiScale(img, scaleFactor=1.2, minNeighbors=2, minSize=(1, 1))

print(ballrect)

# 顔を検出した場合
if len(ballrect) > 0:
	# 検出した場所すべてに赤色で枠を描画する
	for rect in ballrect:
		cv.rectangle(img, tuple(rect[0:2]), tuple(rect[0:2]+rect[2:4]), (0, 0, 255), thickness=3)
		if rect[2]*rect[3] > ball_n[2]*ball_n[3]:
			ball_n=rect

# 結果の画像を表示する
print(ball_n,height,width/2)
a = height - (ball_n[1]+(ball_n[3]/2))
b = (ball_n[0]+(ball_n[2]/2)) - (width/2)
deg = math.atan(b/a)
deg = deg/math.pi*90
if ball_n[0]==0:
	deg = 200
print(ball_n,height,width/2,deg)
f = open("deg.txt","w")
f.write(str(int(deg)))
f.close()
#cv.imshow('camera', img)
# 結果を書き出す
cv.imwrite(fn, img)
# 何かキーが押されるまで待機する
#cv.waitKey(0)
# 表示したウィンドウを閉じる
cap.release()
cv.destroyAllWindows()
