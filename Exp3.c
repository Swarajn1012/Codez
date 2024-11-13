//Name: Swaraj Yogesh Nangare
//Roll No.: 3402025
//Div: B 
#include <reg51.h> 
#define SEGMENT_PORT P2 
 
unsigned char segment_code[16] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F,0x77,0x7C,0x39,0x5E,0x79,0x71}; 
void delay(unsigned int ms)  
{ 
    unsigned int i, j; 
    for (i = 0; i < ms; i++)  
    { 
          for (j = 0; j < 1275; j++); 
    } 
} 
void main() { 
    unsigned char i; 
    while (1)  
    { 
          for (i = 0; i < 16; i++)  
          { 
             SEGMENT_PORT = segment_code[i]; // Send the segment code to the port 
             delay(100); // Delay for 1 second 
          } 
    } 
} 