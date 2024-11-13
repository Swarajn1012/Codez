// Name: Swaraj Yogesh Nangare
// Roll No.: 3402025
// Div: B

#include <p18f4520.h>

void main()
{
    TRISC = 0xFB;      // Set RC2 as output and the rest of PORTC as input(0 = output, 1 = input)
    TRISD = 0x80;      // Set RD7 as input and the rest of PORTD as output
    CCP1CON = 0x3C;    // Configure CCP1 module in PWM mode
    PR2 = 100;         // Load period value for Timer2
    T2CON = 0x01;      // Timer2 setup: prescaler = 1, Timer2 off initially
    
    while(1)
    {
        if(PORTDbits.RD7 == 1)   // Corrected from POTRDbits to PORTDbits
        {
            CCPR1L = 25;  // Set duty cycle to 25
        }
        else
        {
            CCPR1L = 50;  // Set duty cycle to 50
        }
        TMR2 = 0x00;          // Clear Timer2 counter
        PIR1bits.TMR2IF = 0;  // Clear Timer2 interrupt flag
        T2CONbits.TMR2ON = 1; // Turn on Timer2
        while(PIR1bits.TMR2IF == 0);  // Wait until Timer2 overflows
    }
}
