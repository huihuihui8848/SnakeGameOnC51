#include "beep.h"

sbit BEEP=P2^5;

void beep(){
	u8 i;
	for(i=0; i<10; i++){
		BEEP=!BEEP;
		delay_ms(10);
	}
}