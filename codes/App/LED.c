#include "LED.h"

void LED_display(){
	u8 i,j; 
	for(i=0; i<8; i++){
		for(j=0; j<8; j++){
			if(map[i][j]){				
				P0=~(1<<i);
				hc595_write(1<<j);
				delay_ms(1);
				P0=~(0x0);
				hc595_write(0x0);
			}	
		}
	}
}