#include "delay.h"

//void delay_10us(u32 i){
//	while(i--);
//}

void delay_ms(u32 i){
	u8 j;
	while(i--){
		j=125;
		while(j--);
	}
}