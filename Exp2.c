//Name: Swaraj Yogesh Nangare
//Roll No.: 3402025
//Div: B
#include<reg51.h>  
void Delay(void);  
void main (void) 
{ 
     while(1)                // infinite loop 
     { 
          P3 = 0x00;            // LED ON 
          Delay(); 
          P3 = 0xff;            // LED OFF 
          Delay(); 
               } 
} 
 
void Delay(void) 
{ 
      int i, j; 
 for(i=0;i<10;i++) 
       { 
          for(j=0;j<10000;j++) 
          { 
          } 
       } 
} 