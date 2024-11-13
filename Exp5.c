//Name: Swaraj Yogesh Nangare
//Roll No.: 3402025
//Div: B
#include <p18f4520.h>
#include <delays.h>

#define buzzer PORTAbits.RA3    
#define switch1 PORTBbits.RB0   
#define switch2 PORTBbits.RB1   

void main(void)
{
    ADCON1=0x0F;
    TRISA = 0x00;  
    TRISB = 0xFF;  
    TRISD = 0x00;  
    PORTD = 0xFF;  

    while (1)
    {
        if (switch1==1 && switch2==0)
        {  
            while (1)
            {
                buzzer = 1;         
                PORTD = 0x37;       
                Delay10KTCYx(100);  
                PORTD = 0x3B;
                Delay10KTCYx(100);
                PORTD = 0x3D;
                Delay10KTCYx(100);
                PORTD = 0x3E;
                Delay10KTCYx(100);

                if (switch1==0 || (switch1==1 && switch2==1))
                {  
                    buzzer = 0;
                    break;
                }
            }
        }
        else if (switch1==0 && switch2==1)
        {  
            while (1)
            {
                buzzer = 0;         
                PORTD = 0x0E;       
                Delay10KTCYx(100);  
                PORTD = 0x0D;
                Delay10KTCYx(100);
                PORTD = 0x0B;
                Delay10KTCYx(100);
                PORTD = 0x07;
                Delay10KTCYx(100);

                if (switch2==0 || (switch1==1 && switch2==1))
                {
                    break;
                }
            }
        }
        else
        {
            PORTD=0xFF;
        }
    }
}
