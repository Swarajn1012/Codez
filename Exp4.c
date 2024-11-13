//Name: Saloni Santosh Dhaktode
//Roll No.: 3401024
//Div: A
#include<reg51.h> 
void msdelay(unsigned int time) 
    { 
    unsigned i,j ;
    for(i=0;i<time;i++)
    for(j=0;j<1275;j++);
    }
void main()
{ 
    while(1)
    { 
        P2 = 0x08;         //0011     P2_0=1,P2_1=1,P2_2=0,P2_3=0 
        msdelay(1);
			  P2 = 0x0C;         //0011     P2_0=1,P2_1=1,P2_2=0,P2_3=0 
        msdelay(1);
			  P2 = 0x04;         //0011     P2_0=1,P2_1=1,P2_2=0,P2_3=0 
        msdelay(1);
        P2 = 0x06;         //0110 
        msdelay(1);
			  P2 = 0x02;         //0011     P2_0=1,P2_1=1,P2_2=0,P2_3=0 
        msdelay(1);
        P2 = 0x03;         //1100 
        msdelay(1);
			  P2 = 0x01;         //0011     P2_0=1,P2_1=1,P2_2=0,P2_3=0 
        msdelay(1);
        P2 = 0x09;         //1001 
        msdelay(1);
    } 
} 