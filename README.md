# PIC16F6xx-PWM

PWM program az Educore-hu által forgalmazott áramkörhöz.

## Leírás
Ez a projekt egy egyszerű példaprogram, amely PWM jelet állít elő a mikrokontroller kimenetein. Ideális az áramkör és a fejlesztőkörnyezet első teszteléséhez,
és a függvények kiszervezének bemutatására.

### Tesztelt környezet
* **Mikrokontroller:** PIC16F690
* **Hardver:** Educore-hu saját fejlesztésű áramköre
* **Fejlesztőkörnyezet:** MPLAB X v5.00 / XC8 fordító

## Használat
1. Nyisd meg a projektet a fejlesztőkörnyezetedben.
2. Ellenőrizd a konfigurációs biteket a forráskódban.
3. Fordítsd le és égesd a programot a PIC16F690-es mikrokontrollerre.
4. Az áramkör bekapcsolása után az RC4 és RC5 lábakon az 1000Hz-es 50% kitöltésű PWM jelnek kell megjelennie.

---
*Készítette: educore-hu*
