//Name: Swaraj Yogesh Nangare
//Roll No.: 3402025
//Div: B

//Program to transfer message "YES" serially at 9600 baud rate 
#include <p18f4520.h> 

void SerTx(unsigned char c); 

void main(void) 
{ 
    TXSTA=0x20;  // choose low baud rate, 8-bit 
    SPBRG=15;   // 9600 baud rate/ XTAL - 10 MHz 
    TXSTAbits.TXEN=1;  // Enable transmission 
    RCSTAbits.SPEN=1;  // Enable serial port (configures TX/CK pins) 
    
    while (1) 
    { 
        SerTx('Y'); 
        SerTx('E'); 
        SerTx('S'); 
    } 
} 
 
void SerTx (unsigned char c) 
{ 
    while (PIR1bits. TXIF==0); //wait until transmitted 
    TXREG=c;   //place character in buffer 
} 