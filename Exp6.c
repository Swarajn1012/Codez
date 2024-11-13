//Name: Swaraj Yogesh Nangare
//Roll No.: 3402025
//Div: B
#include <p18f4520.h> 

void lcdcmd(int cmd); 
void lcddata(unsigned char value); 
void msdelay(int time); 

#define ldata PORTD              // Data pins connected to PORTD 
#define rs PORTEbits.RE0         // RS connected to RE0 
#define rw PORTEbits.RE1         // RW connected to RE1 
#define en PORTEbits.RE2         // EN connected to RE2

void main() 
{ 
    ADCON1=0x0F;         //All ports used as Digital I/O
    TRISD = 0x00;        // Set PORTD as output 
    TRISE = 0x00;        // Set PORTE as output 
    msdelay(100); 

    lcdcmd(0x38);        // 16x2 LCD, 8-bit, 2 line, 5x7 dots 
    msdelay(50); 
    lcdcmd(0x0E);        // Display on, Cursor on 
    msdelay(15); 
    lcdcmd(0x01);        // Clear Display 
    msdelay(15); 
    lcdcmd(0x06);        // Entry mode set, Increment and shift right 
    msdelay(15); 
    lcdcmd(0x80);        // Move cursor to first row, first position 

    // Display "SPPU" on first row
    lcddata('S');  
    msdelay(50); 
    lcddata('P');  
    msdelay(50); 
    lcddata('P');  
    msdelay(50); 
    lcddata('U');  
    msdelay(50); 

    // Move cursor to second row and display "SITS"
    lcdcmd(0xC0);       // Move cursor to second row, first position 
    msdelay(15); 
    lcddata('S');  
    msdelay(50); 
    lcddata('I');  
    msdelay(50); 
    lcddata('T');  
    msdelay(50); 
    lcddata('S');  
    msdelay(50); 
} 

// Command function to send instructions to LCD
void lcdcmd(int cmd) 
{ 
    ldata = cmd;       // Send command to PORTD 
    rs = 0;              // Select command register 
    rw = 0;              // Write operation 
    en = 1;              // Generate a high-to-low pulse 
    msdelay(10); 
    en = 0; 
} 

// Data function to send data to LCD
void lcddata(unsigned char value) 
{ 
    ldata = value;       // Send data to PORTD 
    rs = 1;              // Select data register 
    rw = 0;              // Write operation 
    en = 1;              // Generate a high-to-low pulse 
    msdelay(10); 
    en = 0; 
} 

// Delay function (approximate timing based on oscillator frequency)
void msdelay(int time) 
{ 
    int i, j; 
    for (i = 0; i < time; i++) 
        for (j = 0; j < 135; j++); 
} 
