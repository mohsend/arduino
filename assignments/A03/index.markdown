---
title: تمرین سه - روشن شدن به ترتیب
layout: page
---

# {{ page.title }}

## متن تمرین

### اصلی 

روشن کردن ۸ تا LED توسط PORTA از ATMEGA32 به فاصله ۱۰ ثانیه از یکدیگر.

### بازنویسی شده برای آردواینو UNO

روشن کردن ۸ تا LED توسط PORTD به فاصله ۱ ثانیه از یکدیگر. (تغییر به ۱ ثانیه صرفا برای سریع تر دیده شدن نتیجه است)

## مدار

<video autoplay loop muted playsinline width="754" height="532">
<source src="video.mp4" type="video/mp4" />
<img src="picture.jpg" width="754" height="532" />
</video>

## [کد برنامه](A03.ino)

```c
{% include_relative A03.ino %}
```
