import cv2
 
# カメラ準備 
cap = cv2.VideoCapture(0)
 
# 無限ループ 
while True:
    # キー押下で終了 
    key = cv2.waitKey(1)
    if key != -1:
        break
 
    # カメラ画像読み込み 
    ret ,frame = cap.read()
 
    # 画像表示 
    cv2.imshow('image', frame)
 
# 終了処理 
cap.release()
cv2.destroyAllWindows()

