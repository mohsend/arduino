---
title: تمرین ۱۹ - ارتباط سریال
layout: page
---

# {{ page.title }}

## متن تمرین

### اصلی 

دو میکروکنترلر ATMEGA32 را از طریق واحد USART  شبکه بندی کنید به نحویکه میکروی فرستنده نام و نام خانوادگی شما را با تاخیر ۵۰۰ میلی‌ثانیه به میکروی گیرنده ارسال کند و گیرنده آن را روی LCD نمایش دهد. (با و بدون استفاده از مکانیزم وقفه داخلی)

### بازنویسی شده برای آردوینو UNO

دو برد Arduino UNO را از طریق واحد UART  شبکه بندی کنید به نحویکه میکروی فرستنده نام و نام خانوادگی شما را با تاخیر ۵۰۰ میلی‌ثانیه به میکروی گیرنده ارسال کند و گیرنده آن را روی LCD نمایش دهد.

## مدار

<video autoplay="autoplay" loop="loop" width="320" height="480">
<source src="video.mp4" type="video/mp4" />
<img src="picture.jpg" width="320" height="480" />
</video>

## کد برنامه

### [فرستنده](A19-sender.ino)

```c
{% include_relative A19-sender.ino %}
```

### [گیرنده](A19-reciver.ino)

```c
{% include_relative A19-reciver.ino %}
```
