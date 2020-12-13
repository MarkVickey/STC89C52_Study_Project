#include<reg52.h>
#include<intrins.h>
#define uint unsigned int
#define uchar unsigned char
uchar temp;
sbit bell=P2^3;
void beep(uchar);
void delay(uint a);
void main()
	{
		uchar m;
		temp=0xfe;
		while(1)
		{
		for(m=0;m<7;m++)
		{
			P1=temp;
			beep(0);
			delay(200);
			beep(1);
			P1=0xff;
			delay(200);
			temp=_crol_(temp,1);//rolling to left
		}
		temp=0x7f;
		for(m=0;m<7;m++)
		{
			P1=temp;
			beep(0);
			delay(200);
			beep(1);
			P1=0xff;
			delay(200);
			temp=_cror_(temp,1);//rolling to right
		}
		beep(0);
		delay(500);
		beep(1);
	}
}
void delay(uint a)
{
		uint i,j;
		for(i=a;i>0;i--)
			for(j=114;j>0;j--);
}

void beep(uchar a)
{
	uchar k;
	if(a==0)
	{
		for(k=0;k<200;k++)
		{
			bell = ~bell;
			delay(1);
		}
	}
	else if(a==1)bell = 0;
}