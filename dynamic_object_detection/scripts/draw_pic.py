#!/usr/bin/env python3
# license removed for brevity
from tkinter import E
import matplotlib.pyplot as plt
from matplotlib.font_manager import FontProperties
import statistics

from numpy import average

stock_tsmcc = [6,8,5,5,6,5,5,6,5,5,6,6,6,7,6,6,6,6,6,6,6,5,6,5,6,5,6,6,6,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,6,6,6,6,6,5,6,5,6,6,6,6,6,6,6,6,6,6,6,6,7,6,6,7,6,6,6,7,7,6,6,6,7,6,6,7,6,5,6,6,6,6,6,6,6,7,7,7,7,7,7,7,7,6,6,6,7,6,6,6,7,6,6,7,6,7,6,7,7,6,6,7,7,6,7,5,6,7,7,7,6,7,6,6,6,6,6,6,6,6,6,6,6,7,6,6,6,7,7,7,6,7,7,7,7,7,7,6,6,6,6,6,6,6,6,6,8,7,7,7,7,8,7,7,8,7,7,7,7,7,7,7,7,7,6,6,6,6,6,6,6,6,7,7,6,7,7,7,7,7,7,7,6,6,6,6,6,6,6,6,7,5,5,5,5,5,5,5,5,6,6,6,6,6,6,6,6,6,7,7,7,7,6,6,6,6,6,7,7,7,7,6,7,7,7,7,7,7,7,7,7,7,7,7,7,6,6,6,6,6,6,6,6,6,6,6,6,6,6,5,6,5,6,6,7,6,6,7,6,6,6,7,6,6,6,6,6,6,7,6,6,6,6,6,6,6,6,6,6,6,6,6,6,8,6,8,6,6,7,7,6,6,7,7,7,7,6,7,8,7,8,8,6,8,8,8,6,6,6,6,6,5,6,6,5,7,7,6,7,7,7,7,7,7,6,6,6,6,6,6,6,6,6,6,7,7,7,7,6,7,7,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,5,5,6,6,5,5,6,5,6,6,6,6,6,6,6,6,6,6,6,5,5,5,5,5,5,6,5,6,6,6,6,6,6,6,6,6,7,6,7,7,7,7,7,7,7,5,6,6,6,6,6,5,6,6,6,7,7,6,7,6,7,6,7,7,7,6,7,6,7,6,7,6,6,6,6,6,6,5,6,5,7,8,7,6,7,8,6,7,7,6,5,6,5,6,5,5,6,5,6,7,6,6,8,7,6,6,6,6,6,6,6,6,6,6,6,7,6,6,6,6,6,6,6,6,6,6,6,6,6,6,7,6,6,6,6,6,6,6,6,6,6,6,6,6,7,6,7,7,7,7,7,5,6,6,7,5,6,5,6,6,8,6,6,7,6,6,8,8,7,7,7,7,7,7,7,7,7,7,7,6,6,7,6,7,7,6,7,7,7,7,7,7,7,7,6,6,6,6,6,5,6,6,5,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,5,5,5,5,6,5,5,5,5,5,5,7,5,5,5,5,5,7,6,6,6,6,6,6,8,6,6,7,6,7,6,6,7,6,6,6,6,6,6,6,6,6,6,6,6,6,8,6,6,6,6,7,6,6,6,6,6,6,6,6,6,6,6,7,7,7,7,7,7,7,6,7,5,5,5,5,5,5,5,5,5,6,6,6,5,5,6,6,6,6,6,6,6,6,6,6,7,6,7,7,7,6,6,6,6,6,6,7,7,6,6,7,6,7,7,7,6,6,6,6,6,6,6,6,7,6,6,6,6,7,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,7,6,7,6,6,6,6,7,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,5,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,7,6,6,6,6,6,6,6,6,6,7,7,7,7,6,6,6,7,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,7,6,7,6,6,6,7,6,7,7,6,6,6,7,6,6,6,6,6,6,6,6,5,6,6,6,6,6,6,6,6,6,7,7,6,7,6,7,6,7,7,5,5,5,5,5,5,6,5,5,6,6,6,6,6,6,5,6,6,6,5,6,5,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,5,5,6,6,6,6,6,6,6,6,6,6,6,6,6,6,7,7,7,7,6,7,7,7,7,6,6,6,6,6,5,6,6,6,6,6,6,6,6,6,6,6,6,7,7,7,7,7,7,7,7,7,6,6,6,6,6,6,6,6,6,6,6,6,6,6]

# 使用月份當做X軸資料
month = []
nnnn = []
aaaa = []
qqqq = []
rrrr = []
# xxxx = []
# yyyy = []
# rrrr = []
# for i in range(len(stock_tsmcc)):
#     if i%3==0:
#         xxxx.append(stock_tsmcc[i])
#     elif i%3==1:
#         yyyy.append(stock_tsmcc[i])
#     else:
#         rrrr.append(stock_tsmcc[i])

for i in range(len(stock_tsmcc)):
    nnnn.append(stock_tsmcc[i])


temp = nnnn

for i in range(len(temp)):
    month.append(i)

# print(statistics.mean(nnnn))

for i in range(len(temp)):
    aaaa.append(5)

print(statistics.mean(nnnn))
print(len(temp))

for i in range(len(temp)):
    qqqq.append(0)

for i in range(len(temp)):
    rrrr.append(605)

# 設定圖片大小為長15、寬10
plt.figure(figsize=(len(temp),100),dpi=100,linewidth = 2)

# 把資料放進來並指定對應的X軸、Y軸的資料，用方形做標記(s-)，並指定線條顏色為紅色，使用label標記線條含意
plt.plot(month,qqqq,color = 'k')
# plt.plot(month,rrrr,color = 'k', label="Raw Data")
plt.plot(month,temp,color = 'r', label="Original")
plt.plot(month,aaaa,color = 'b', label="Improved")

# 設定圖片標題，以及指定字型設定，x代表與圖案最左側的距離，y代表與圖片的距離
# plt.title("The speed in y-axis direction",  x=0.5, y=1.03)

# 设置刻度字体大小
plt.xticks(fontsize=20)
plt.yticks(fontsize=20)

# 標示x軸(labelpad代表與圖片的距離)
# plt.xlabel("k", fontsize=30, labelpad = 15)

# 標示y軸(labelpad代表與圖片的距離)
plt.ylabel("k", fontsize=30, labelpad = 15)

# 顯示出線條標記位置
plt.legend(loc = "best", fontsize=20)

# 畫出圖片
plt.show()

# plt.savefig('src/strategy/img/123.png')

