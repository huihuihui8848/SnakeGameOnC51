#include "HC595.h"

sbit _SER = P3^4; //data
sbit _RCLK = P3^5; //byte
sbit _SRCLK = P3^6; //bit

void hc595_write(u8 dat){
	u8 i;
	_SRCLK=0;
	_RCLK=0;
	for(i=0; i<8; i++){
		_SER=dat>>7;
		dat<<=1;
		_SRCLK=1;
		_SRCLK=0;
	}
	_RCLK=1;
	_RCLK=0;
}
