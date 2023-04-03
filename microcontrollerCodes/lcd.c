/*
 * lcd.c
 *
 *  Created on: 31 Eki 2021
 *      Author: Nurdan
 */
#include "stdbool.h"
#include "stdint.h"
#include "inc/hw_ints.h"
#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "lcd.h"

void Lcd_ilk_ayarlar() {

    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);
    GPIOPinTypeGPIOOutput(LCDPORT, 0xFF);

    SysCtlDelay(50000);

    GPIOPinWrite(LCDPORT, RS, 0x00);

    GPIOPinWrite(LCDPORT, D4| D5| D6| D7, 0x30);
    GPIOPinWrite(LCDPORT, E, 0x02);
    SysCtlDelay(10);
    GPIOPinWrite(LCDPORT, E, 0x00);

    SysCtlDelay(50000);

    GPIOPinWrite(LCDPORT, D4| D5| D6| D7, 0x30);
    GPIOPinWrite(LCDPORT, E, 0x02);
    SysCtlDelay(10);
    GPIOPinWrite(LCDPORT, E, 0x00);

    SysCtlDelay(50000);

    GPIOPinWrite(LCDPORT, D4| D5| D6| D7, 0x30);
    GPIOPinWrite(LCDPORT, E, 0x02);
    SysCtlDelay(10);
    GPIOPinWrite(LCDPORT, E, 0x00);

    SysCtlDelay(50000);


    GPIOPinWrite(LCDPORT, D4| D5| D6| D7, 0x20);
    GPIOPinWrite(LCDPORT, E, 0x02);
    SysCtlDelay(10);
    GPIOPinWrite(LCDPORT, E, 0x00);

    SysCtlDelay(50000);

    Lcd_Temizle();
    Lcd_Komut_Gonder(0x28);  //fonksiyon secimi f=0 n=1
    Lcd_Komut_Gonder(0xC0);
    Lcd_Komut_Gonder(0x06);  //ekran acik, kursor acik
    Lcd_Komut_Gonder(0x80);  //kursor konumu
    Lcd_Komut_Gonder(0x28);
    Lcd_Komut_Gonder(0x0f);  //kursoru ac
    Lcd_Temizle();






}
void Lcd_Komut_Gonder(unsigned char c) {

    GPIOPinWrite(LCDPORT,D4| D5| D6| D7 , (c & 0xf0) );
    GPIOPinWrite(LCDPORT, RS, 0x00);
    GPIOPinWrite(LCDPORT, E, 0x02);
    SysCtlDelay(10);
    GPIOPinWrite(LCDPORT, E, 0x00);

    SysCtlDelay(50000);

    GPIOPinWrite(LCDPORT,D4| D5| D6| D7 , (c & 0x0f)<<4 );
    GPIOPinWrite(LCDPORT, RS, 0x00);
    GPIOPinWrite(LCDPORT, E, 0x02);
    SysCtlDelay(50000);
    GPIOPinWrite(LCDPORT, E, 0x00);

    SysCtlDelay(50000);



}
void Lcd_Tek_Karakter_Yaz(unsigned char d) {
    GPIOPinWrite(LCDPORT,D4| D5| D6| D7 , (d & 0xf0) );
    GPIOPinWrite(LCDPORT, RS, 0x01);
    GPIOPinWrite(LCDPORT, E, 0x02);
    SysCtlDelay(10);
    GPIOPinWrite(LCDPORT, E, 0x00);

    SysCtlDelay(50000);

    GPIOPinWrite(LCDPORT,D4| D5| D6| D7 , (d & 0x0f)<<4 );
    GPIOPinWrite(LCDPORT, RS, 0x01);
    GPIOPinWrite(LCDPORT, E, 0x02);
    SysCtlDelay(10);
    GPIOPinWrite(LCDPORT, E, 0x00);

    SysCtlDelay(50000);



}
void Lcd_Satir_Sutuna_Git(char x, char y){

    if(x==1)
        Lcd_Komut_Gonder(0x80+((y-1)%16));
    else
        Lcd_Komut_Gonder(0xC0+((y-1)%16));

}
void Lcd_Temizle(void){
    Lcd_Komut_Gonder(0x01);
    SysCtlDelay(10);
}
void Lcd_Cok_Karakter_Yaz(unsigned char dizi[], int dizisayisi){
    // Burayidoldur
    // dizi: karakter dizisi
    // dizisayisi: karakter dizisi boyutu
    // for ile karakter dizisini Lcd_Tek_Karakter_Yaz fonksiyonu ile tek tek yaz
    int a;
    for(a=0; a<dizisayisi; a++)
    {

        Lcd_Tek_Karakter_Yaz(dizi[a]);
    }

}





