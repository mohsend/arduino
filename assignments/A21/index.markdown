---
title: تمرین ۲۱ - ارتباط سنکرون
layout: page
---

# {{ page.title }}

## متن تمرین

### اصلی 

دو میکروکنترلر ATMEGA32 را از طریق واحد SPI شبکه‌بندی کنید به نحوی‌که میکروی فرمانده نام کوچک شما را به میکروی فرمانبر ارسال نموده و میکروی فرمانبر آن را روی LCD نمایش دهد. (با و بدون مکانیزم وقفه داخلی)

### بازنویسی شده برای آردوینو UNO

دو برد آردوینو را از طریق واحد I<sup>2</sup>C شبکه‌بندی کنید به نحوی‌که آردوینوی فرمانده نام کوچک شما را به آردوینوی فرمانبر ارسال نموده و آردوینوی فرمانبر آن را روی LCD نمایش دهد. 

## مدار

<video autoplay="autoplay" loop="loop" width="480" height="344">
<source src="video.mp4" type="video/mp4" />
<img src="picture.jpg" width="480" height="344" />
</video>

## کد برنامه

### [فرمانده](A21-master.ino)
```c
{% include_relative A21-master.ino %}
```

### [فرمانبر](A21-slave.ino)
```c
{% include_relative A21-slave.ino %}
```
