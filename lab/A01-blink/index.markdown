---
title: تمرین ۱ - چشمک‌زن با دکمه
layout: page
---

# {{ page.title }}

## ATMEGA8 - CodeVision AVR & Proteous

### متن تمرین

یک چراغ LED هر ثانیه یک بار چشمک بزند. در صورتی که دکمه ای فشرده شد چراغ حالت فعلی خود را تا قطع شدن دکمه نگه دارد.


### [مدار](blink.pdsprj)

<video autoplay loop muted playsinline width="416" height="224">
<source src="video.mp4" type="video/mp4" />
<img src="picture.jpg" width="416" height="224" />
</video>

### [کد برنامه](blink.c)
```c
{% include_relative blink.c %}
```

## Arduino Uno

### [کد برنامه](blink.ino)
```c
{% include_relative blink.ino %}
