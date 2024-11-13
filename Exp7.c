//Name: Swaraj Yogesh Nangare
//Roll No.: 3402025
//Div: B

#include<p18f4520.h> 

void delay_timer() 
{ 
    T0CON=0x80;     // Timer 0, 16 bit, no prescalar 
    TMR0H=0xFB;    // Values calculated for 0.1 ms delay 
    TMR0L=0x50; 
    T0CONbits.TMR0ON=1;    // Timer 0 On 
    
    while(INTCONbits.TMR0IF==0);  // Wait until TMROIF gets flagged 
    T0CONbits.TMR0ON=0;           // Timer 0 Off 
    INTCONbits.TMR0IF=0;  // Clear Timer 0 interrupt flag 
} 

void main() 
{ 
    TRISCbits.TRISC0=0;  // Configure PORTC as output 
    while(1) 
    { 
       PORTCbits.RC0=1; 
       delay_timer(); 
       PORTCbits.RC0=0; 
       delay_timer(); 
    } 
} 