Hands-on 2: UART Communicating
===
UART 是在電子產品中經常用到的通訊界面，在這個練習中，我們將會學習到如何設定 STM32 MCU 的 UART 裝置來傳送、接收資料。

Preparation
---
在開始動手之前，請先確認你手邊有以下的工具或是軟體。

### USB-Serial converter

比較有年代的電腦可以透過 RS-232 cable 連接電腦上的 COM port 來跟 MCU 的 UART 介面通訊，但現今一般的 PC 或是 NB 大多已沒有支援 COM port 的介面。所以需要一個 USB 轉 serial 的轉接卡，讓我們可以透過電腦的 USB port 來跟 MCU 的 UART 介面通訊。
![image](https://github.com/sujean323/intern/assets/90737530/cad7075d-0d0d-433f-b1b7-23c56b5d8edd)

接上轉接板之後，在裝置管理員中應該會出現如下的裝置，
![image](https://github.com/sujean323/intern/assets/90737530/da542280-8b34-4608-9f9d-5207a618ed9d)

### PC Terminal app
Terminal 軟體是在 PC 端執行，可以透過 COM port 來收發資料的工具程式，你可以安裝任何你熟悉的 Terminal app，或是安裝推薦使用的 CoolTerm。 

Assignment
---
我們的任務是要實作一個簡單的通訊協議，讓 Host （在此會是一台 PC 或是 Notebook）可以經由 UART 來跟 EVB 上的 MCU 進行溝通，用以控制或是取得 EVB 上的 LED 燈狀態。

![image](https://github.com/sujean323/intern/assets/90737530/021a0c1c-000f-4190-a1a8-375c73ff943d)

### Communication Protocol
我們定義的協議非常簡單，只包含了兩個指令分別用來設定及取得 EVB 上 LED 燈的狀態。

我們將版上的燈號由左到右分別編號為 1、2、3、4 四排燈，指令以1排燈為單位來控制及取得狀態。

指令的詳細格式說明如下：

#### Ending Symbol
協議是採用類似 CLI (Command Line) 下指令的方式，所以每個指令的結尾需要有個結束符號表示這是一個完整的指令，我們使用兩個字元 **"\r\n"** 做為結束符號。



#### Set command
_set line [col] [state]_

設定某一排的 LED 燈是開啟或是關閉。

* col: 要設定的燈號的 column index
* state: 0-> 熄燈，1->亮燈


#### Get command
_get line [col]_

取得某一排 LED 燈目前的狀態，回傳 0 表示燈是關閉的，1 表示開啟。

* col: 要取得燈號狀態的 column index

Validation
---
試著執行下面的指令(請用 copy & paste 的方式)來確認你的程式有如預期般的結果，如果一切 OK，可以請你的指導者來驗收啦!

```c
set line 2 1
```
```c
set line  3 0
```
```c
get LINE 1
```

