#include<reg52.h>
#include<intrins.h>
#define uint unsigned int
void delay(uint a);
void main()
	{
		
		unsigned char temp,i;
		while(1)
		{
			
			for(i=0;i<8;i++)
			{temp=0x01;
				temp=_crol_(temp,i);
				P1=temp;
				delay(300);
			}
			for(i=0;i<8;i++)
			{temp=0x01;
				temp=_cror_(temp,i);
				P1=temp;
				delay(300);
			}
		}
	}

void delay(uint a)
{
		uint i,j;
		for(i=a;i>0;i--)
			for(j=114;j>0;j--);
}
