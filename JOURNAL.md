---
title: "d-Compressed"
github: "https://github.com/KingsStarDV/d-Compressed"
description: "a compressed air projectile shooter"
created_at: "2026-11-01"
total_time: "7h 30m"
---

# November 1, 2026: Started Design
<!-- fabricate:entry 1775 -->

so the idea to make a DIY COMPRESSED AIR PROJECTILE SHOOTER,was on my mind since a long time and now i deciding to make it in real life.

But before that i need to tell everyone going through the journals that, throughout the JOURNALS and in my README [in github], i will refer this as PROJECTILE SHOOTER and not a "GUN" due to obviously legal reasons.

i got a lot of help, from two videos on youtube:
[https://youtu.be/n_JUTz0vEwk?si=cMsoiEQ9pckPP10f](https://)

[https://youtu.be/C8H3tE_26Qk?si=hPblf5GDHsLatxnZ](https://)



then i started to make my own.
For some parts i m not sure yet, about what to use such as the barrel and th3 air tank.

But beside those i have a rough idea.

![](https://fabricate.hackclub-assets.com/6f5b7a498b394b0d842bf0fc262aa694e2399b62749af06ce40952c721f3073c/image-png/Airflow.drawio.png)

I also sourced some parts that are shown in this diagram

**Total time spent: 1h 30m**

# November 3, 2026: Cad Modelling
<!-- fabricate:entry 2071 -->

i started with making a CAD model for the project.

i went up on grabcad and tried to get models for TEE JOINTS, REDUCER, ALBOW BENTS, etc. 
But none of the parts were actaully fitting each other.
every Part was either bigger or smaller than each other.|

Then i tried to rescale the bodies to right sizes, but that made the proportions even more bad.

Eventually after a lot of tries, i asked GEMINI about that and then i got to know that NPT sizes, do not match to their actual outer diameter.
For ex. 1/4" dont mean the outer diameter will be actually 0.25inch..
It will be 0.504inchs instead.

So i tried to again resclae evrything according to these new diamters and i think , the proportions look good now.!!!
Then i modelled a basic structure for the solenoid valve as this part i couldnt find any model online-
![](https://fabricate.hackclub-assets.com/4a4c4fbf1a31dcab70407bc69699048a212470befdef17aa449a3215ba24eefe/image-png/Screenshot%202026-11-02%20115523.png)

Then according to the diagram made previously, i assembled all the parts-
![](https://fabricate.hackclub-assets.com/8f0cfba54af0795a3f504abd355afe9d880d549e8f3281f2aa2fb1f3bdd6e449/image-png/Screenshot%202026-11-02%20220739.png)


as for the Air tank, i decided to use a MOSQUITO REPLLENT CAN.
i took its measurements and made a simple cyclinder model.
then i added that model to the assembly.


I also addded a servo motor to allow this part to slide-
![](https://fabricate.hackclub-assets.com/2656a2c238ced8b24064d7d1d0b8aee83efd30d2195abf145115167dc8545531/image-png/Screenshot%202026-11-03%20102155.png)

now, i was faced with a major block ahead..
I didnt knew how to add the barrel and supports for rest parts!
so i went online and did many researching
and eventually i think i found a way!

So, i designed a locking mechanism which will hold the can and keep the barrel from moving-
![](https://fabricate.hackclub-assets.com/30628e756b4edffbe291669946621e8af5de304a53582a8b0d9472d90e38cd76/image-png/Screenshot%202026-11-02%20234341.png)
The part is supoosed to be open from bottom, and tightend using screw. this will work like a clamp.

next made a same part, but with slight chnages to hold a hollow rod which will act as a magazine.
![](https://fabricate.hackclub-assets.com/a688cc9c5bb0a0ed0cad54cc984889ecad5aecb07c9af0bc1fc7dc33c578d9da/image-png/Screenshot%202026-11-03%20102830.png)
The projectiles are gravity feed into the barrel.


he slider part pushes the projectiles further into the barrel.
![](https://fabricate.hackclub-assets.com/0de6f43e1938e5ed564dba9f41d1e42f986c37ca7e498fa53af876484a48fcf6/image-png/Screenshot%202026-11-03%20091830.png)
Next i added some wooden sticks in under part of the can for electronics and assembled some part.
![](https://fabricate.hackclub-assets.com/01229547294f66a952d65f6eb700c01d0a7c50af2bfae4e9be321bc057823cec/image-png/Screenshot%202026-11-03%20095743.png)
![](https://fabricate.hackclub-assets.com/08f7b0c47a25d2791b538ba3ec29b54911c2418fb1d9f59a8a9eb5cded6f0eec/image-png/Screenshot%202026-11-03%20095749.png)

Also, extended the barrel holders to give the project a GUN look-

**Total time spent: 5h 30m**

# November 3, 2026 (entry 2): firmware and wiring
<!-- fabricate:entry 2073 -->

it took me few minutes to create a wiring diagram for the project.
It is pretty easy to understand by just looking at it-

![](https://fabricate.hackclub-assets.com/39c263dd35f3cd6d73e89127bda125378a3b953b32293e7f2c312f06fbadf0d3/image-png/WD.png)

..

And then made a firmware for the project.
everything is now available tin the github repo.

[AND I USED CLAUDE FOR THE FIRMWARE]

i wanted by esp32 to perform these things ( Which i then gave to claude and he handed me a firmware)
-

-1. Continously check if the signal on gpio21 is high or low.
-2. When he signal on gpio21 becomes low, it means that button is pressed.
-3. For 50ms pull the GPIO0 pin high. [This is conncted to the mosfet which turns on the solenoid valve for about 50ms]

**Total time spent: 30m**
