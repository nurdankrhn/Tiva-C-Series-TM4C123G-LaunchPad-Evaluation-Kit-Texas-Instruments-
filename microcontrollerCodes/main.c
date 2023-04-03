#include <stdint.h>
#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_types.h"
#include "inc/hw_timer.h"
#include "driverlib/pin_map.h"
#include "driverlib/sysctl.c"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "driverlib/gpio.c"
#include "driverlib/timer.h"
#include "driverlib/interrupt.h"
#include "driverlib/uart.h"
#include "driverlib/pin_map.h"
#include "driverlib/adc.h"
#include "lcd.h"
#include "driverlib/uart.h"
#include "driverlib/pin_map.h"
#include "driverlib/timer.h"
#include <stdio.h>
#include <string.h>



int sn,dk,sa;
int timerkesmesi;
int gelenveri;//seri porttan gelen saat bilgisi
bool saatmi=false;
int saatdizi[8];
int gelensaatno=0;



void initcpu();
void initsaatvariable(int sngirilen, int dkgirilen, int sagirilen);
void saatdegiskenlerinihesapla();
void saatdegiskenleriniyaz(int sa1, int dk1, int sn1);
void adcdegiskenleriniyaz(int a);
void adcseridengonder(int deger);

void tkesmesi()
{
    TimerIntClear(TIMER0_BASE, TIMER_TIMA_TIMEOUT);
    GPIOPinWrite(GPIO_PORTF_BASE, 2, ~GPIOPinRead(GPIO_PORTF_BASE, 2));
    saatdegiskenlerinihesapla();
    saatdegiskenleriniyaz(sa,dk,sn);

    uint32_t a[1]; // dizi yaptik
    ADCProcessorTrigger(ADC0_BASE, 3);  //çevrim basladi adc calismaya basladi yazilimla tetikliyorum
    while (!ADCIntStatus(ADC0_BASE, 3, false)); //raw interrupt status, cevrim bitti mi?

    ADCSequenceDataGet(ADC0_BASE, 3, a); //dizinin adresi olur

    ADCIntClear(ADC0_BASE, 3);
    ADCProcessorTrigger(ADC0_BASE, 3);
    adcseridengonder(*a);
    adcdegiskenleriniyaz(*a);



}

void main(void)
{
    initcpu();
    initsaatvariable(58, 55, 23);


    while(1){
        if(!GPIOPinRead(GPIO_PORTF_BASE, GPIO_PIN_4))
        {
            UARTCharPut(UART0_BASE, '{'); //keyfi veri gitmeye basladi
            UARTCharPut(UART0_BASE, 'M');
            UARTCharPut(UART0_BASE, 'E');
            UARTCharPut(UART0_BASE, 'R');
            UARTCharPut(UART0_BASE, 'H');
            UARTCharPut(UART0_BASE, 'A');
            UARTCharPut(UART0_BASE, 'B');
            UARTCharPut(UART0_BASE, 'A');
            UARTCharPut(UART0_BASE, '}');
            UARTCharPut(UART0_BASE, '\n');
        }

        if(UARTCharsAvail(UART0_BASE))
        {
            gelenveri=UARTCharGet(UART0_BASE);
            if(gelenveri=='&')
            {
                //saat gelecek 8 tane karakter
                saatmi=true;
                TimerDisable(TIMER0_BASE, TIMER_A);

            }
            else if(saatmi==true)
            {
                saatdizi[gelensaatno]=gelenveri-48;
                gelensaatno++;
                if(gelensaatno==8)
                {
                    saatmi=false;
                    gelensaatno=0;
                    TimerEnable(TIMER0_BASE, TIMER_A);
                }
                initsaatvariable((saatdizi[6]*10+saatdizi[7]) , (saatdizi[3]*10+saatdizi[4]), (saatdizi[0]*10+saatdizi[1]));
            }

            else if(gelenveri=='#')
                        {

                        int j=1;
                        while(UARTCharsAvail(UART0_BASE))
                        {
                            gelenveri=UARTCharGet(UART0_BASE);
                            UARTCharPut(UART0_BASE, gelenveri);
                            Lcd_Satir_Sutuna_Git(2, j);
                            Lcd_Tek_Karakter_Yaz(gelenveri);
                            j++;
                        }

            }
            else if(gelenveri=='*')
            {

                unsigned char dizi[]={' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '};
                Lcd_Satir_Sutuna_Git(2, 1);
                Lcd_Cok_Karakter_Yaz(dizi, 15);
                SysCtlDelay(100);
            }
        }





    }
}


void initcpu()
{
    SysCtlClockSet(SYSCTL_SYSDIV_5| SYSCTL_USE_PLL| SYSCTL_XTAL_16MHZ| SYSCTL_OSC_MAIN);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF); //SYSCTL_RCGCGPIO_R |=0x20;
    GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_1| GPIO_PIN_2| GPIO_PIN_3); //pin 123 out

    //asagidaki 3 kod portf'in 0 nolu pininin lock ozelligini kapatiyor
    //bu kod olmazsa portf, pin0 okuma fonksiyonu  asagiya calismaz
    HWREG(GPIO_PORTF_BASE+ GPIO_O_LOCK)=GPIO_LOCK_KEY;
    HWREG(GPIO_PORTF_BASE+ GPIO_O_CR)=0x01;
    GPIOPinTypeGPIOInput(GPIO_PORTF_BASE,GPIO_PIN_0| GPIO_PIN_4);
    GPIOPadConfigSet(GPIO_PORTF_BASE, GPIO_PIN_0| GPIO_PIN_4, GPIO_STRENGTH_4MA, GPIO_PIN_TYPE_STD_WPU);  //pu-pd larý aktif hale getirmeye yarayan fonksiyondur
    GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1| GPIO_PIN_2| GPIO_PIN_3,0);

    SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER0); //timer 0 2 tane birimden oluþuyor a ve b
    TimerConfigure(TIMER0_BASE, TIMER_CFG_A_PERIODIC); // down sayar
    TimerLoadSet(TIMER0_BASE, TIMER_A, SysCtlClockGet()-1); //timerýmýza 40 milyon yükledik bu sayede 1 sn geçmiþ olur

    IntMasterEnable();
    IntEnable(INT_TIMER0A); //timer0A yý kesme olarak açtýk

    TimerIntEnable(TIMER0_BASE, TIMER_TIMA_TIMEOUT); //0 olunca kesme üretecek
    TimerIntClear(TIMER0_BASE, TIMER_TIMA_TIMEOUT);
    Lcd_ilk_ayarlar();
    TimerIntRegister(TIMER0_BASE, TIMER_A, tkesmesi); //timer kesme fonksiyon

    //uart0 pa0 rx ve pa1 tx  usb üzerinden seri port haberleþmesi yapiyor
    SysCtlPeripheralEnable(SYSCTL_PERIPH_UART0);   //(çevre birimine hayat ver demek, saat)
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);

    GPIOPinConfigure(GPIO_PA0_U0RX);
    GPIOPinConfigure(GPIO_PA1_U0TX);
    GPIOPinTypeUART(GPIO_PORTA_BASE, GPIO_PIN_0| GPIO_PIN_1);

    UARTConfigSetExpClk(UART0_BASE, SysCtlClockGet(), 115200, UART_CONFIG_WLEN_8|UART_CONFIG_PAR_NONE|UART_CONFIG_STOP_ONE);
    UARTEnable(UART0_BASE); //haberlesme basladi

    SysCtlPeripheralEnable(SYSCTL_PERIPH_ADC0); //adc enerjilendi
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOE); //ch0 kullan, pe3, gpioe enerji verdik

    ADCSequenceConfigure(ADC0_BASE, 3, ADC_TRIGGER_PROCESSOR, 0); // adc0 seq 3 kullanacagim dedim
    ADCSequenceStepConfigure(ADC0_BASE, 3, 0, ADC_CTL_CH0| ADC_CTL_IE| ADC_CTL_END); //pe3 adc 0 seq 3 0. step

    ADCSequenceEnable(ADC0_BASE, 3);  //aktif seq 3


    TimerEnable(TIMER0_BASE, TIMER_A);







}

void initsaatvariable(int sngirilen, int dkgirilen, int sagirilen)
{
    sn=sngirilen;
    dk=dkgirilen;
    sa=sagirilen;
}
void saatdegiskenlerinihesapla()
{
   //sn ++
        //sn=60 olmussa
            //dk ++, sn=0
                //dk=60 olmussa
                    //sa++ ,dk=0
                        //sa=24 olmusaa
                            //sa=0
    sn++;
        if(sn==60)
        {
            sn=0;
            dk++;
            if(dk==60)
            {
                dk=0;
                sa++;
                if(sa==24)
                {
                    sa=0;
                }
            }
        }
}

void saatdegiskenleriniyaz(int sa1, int dk1, int sn1)
{
    //tek tek bütün karakterleri oluþtur
    //dk1= 56 int sayi
    //5 i elde etmen lazým
    //6 yý elde etmen lazým
    //int 5 i char 5 yapman lazým
    //int 6 yýda char 6 yapman lazým
    int saonlar,sabirler,dkonlar,dkbirler,snonlar,snbirler;
    sabirler=sa1%10; //6
    saonlar=(sa1-sabirler)/10; //5
    dkbirler=dk1%10; //6
    dkonlar=(dk1-dkbirler)/10; //5
    snbirler=sn1%10; //6
    snonlar=(sn1-snbirler)/10; //5

    char sachonlar,sachbirler, dkchonlar, dkchbirler, snchonlar, snchbirler;
    sachonlar=saonlar+48;
    sachbirler=sabirler+48;
    dkchonlar=dkonlar+48;
    dkchbirler=dkbirler+48;
    snchonlar=snonlar+48;
    snchbirler=snbirler+48;



    Lcd_Satir_Sutuna_Git(1, 7);
    //SysCtlDelay(80000000/3);
    Lcd_Tek_Karakter_Yaz(sachonlar);
    //SysCtlDelay(80000000/3);
    Lcd_Satir_Sutuna_Git(1, 8);
    //SysCtlDelay(80000000/3);
    Lcd_Tek_Karakter_Yaz(sachbirler);
    //SysCtlDelay(80000000/3);
    Lcd_Satir_Sutuna_Git(1, 9);
    //SysCtlDelay(80000000/3);
    Lcd_Tek_Karakter_Yaz(':');
    //SysCtlDelay(80000000/3);
    Lcd_Satir_Sutuna_Git(1, 10);
    //SysCtlDelay(80000000/3);
    Lcd_Tek_Karakter_Yaz(dkchonlar);
    //SysCtlDelay(80000000/3);
    Lcd_Satir_Sutuna_Git(1, 11);
    //SysCtlDelay(80000000/3);
    Lcd_Tek_Karakter_Yaz(dkchbirler);
    //SysCtlDelay(80000000/3);
    Lcd_Satir_Sutuna_Git(1, 12);
    //SysCtlDelay(80000000/3);
    Lcd_Tek_Karakter_Yaz(':');
    //SysCtlDelay(80000000/3);
    Lcd_Satir_Sutuna_Git(1, 13);
    //SysCtlDelay(80000000/3);
    Lcd_Tek_Karakter_Yaz(snchonlar);
    //SysCtlDelay(80000000/3);
    Lcd_Satir_Sutuna_Git(1, 14);
    //SysCtlDelay(80000000/3);
    Lcd_Tek_Karakter_Yaz(snchbirler);



}

void adcdegiskenleriniyaz(int a)
{
    int binler,yuzler, onlar,birler;
    birler=a%10; //4192
    onlar=((a%100)-birler)/10;
    yuzler=((a%1000)-(a%100))/100;
    binler=(a-(a%1000))/1000;


    char chbinler, chyuzler, chonlar, chbirler;
    chbinler=binler+48;
    chyuzler=yuzler+48;
    chonlar=onlar+48;
    chbirler=birler+48;


    Lcd_Satir_Sutuna_Git(1, 1);
    Lcd_Tek_Karakter_Yaz(chbinler);
    Lcd_Satir_Sutuna_Git(1, 2);
    Lcd_Tek_Karakter_Yaz(chyuzler);
    Lcd_Satir_Sutuna_Git(1, 3);
    Lcd_Tek_Karakter_Yaz(chonlar);
    Lcd_Satir_Sutuna_Git(1, 4);
    Lcd_Tek_Karakter_Yaz(chbirler);
}

void adcseridengonder(int deger)
{
    int binler,yuzler, onlar,birler;
    birler=deger%10; //4192
    onlar=((deger%100)-birler)/10;
    yuzler=((deger%1000)-(deger%100))/100;
    binler=(deger-(deger%1000))/1000;


    char chbinler, chyuzler, chonlar, chbirler;
    chbinler=binler+48;
    chyuzler=yuzler+48;
    chonlar=onlar+48;
    chbirler=birler+48;

    UARTCharPut(UART0_BASE, '(');
    UARTCharPut(UART0_BASE, chbinler);
    UARTCharPut(UART0_BASE, chyuzler);
    UARTCharPut(UART0_BASE, chonlar);
    UARTCharPut(UART0_BASE, chbirler);
    UARTCharPut(UART0_BASE, ')');
    UARTCharPut(UART0_BASE, '\n');
}


//void adcseridengonder(uint16_t deger)
//{
//    uint8_t veriler[5] = {'(', (uint8_t)((deger & 0x00FF), (uint8_t)(deger & 0x00FF),')','\n',};
//
//    for (uint8_t i = 0; i < strlen(veriler); i++) {
//        UARTCharPut(UART0_BASE, veriler[i]);
//
//    }






