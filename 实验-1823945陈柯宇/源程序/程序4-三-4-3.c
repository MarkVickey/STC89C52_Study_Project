#include<reg52.h>
#define uint unsigned int 
#define uchar unsigned char 
unsigned char flag,a,i;
void init(){
//SCON=0x50;//01010000
	TR1=1;
	SM0=0;
	SM1=1; 
	TMOD=0X20;	
	REN=1; 
	TH1=0XF4;
	TL1=0XF4; 
	EA=1;
	ES=1;
}
void main()
{
	init();
	while(1)
	{
 	if(flag==1) 
		{
		ES=0; 
		flag=0;
		SBUF=a; 
		while(!TI); 
		TI=0;   
		ES=1;
		}
	}
}
void ser() interrupt 4
{
	RI=0;
	P1=SBUF;  
	a=SBUF;     
	flag=1;
}
