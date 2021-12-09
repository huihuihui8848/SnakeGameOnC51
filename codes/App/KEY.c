#include "KEY.h"

/*
    1
   4 2
    3
*/


u8 key_scan(){
	u8 key=0;

	P1=0xfe;
	if(P1!=0xfe){
		delay_ms(10);
		switch(P1){
			case 0x7e:
				key=0;
				break;
			case 0xbe:
				key=2; //right
				break; 
			case 0xde:
				key=0;
				break;  
		}
	}

	P1=0xfd;
	if(P1!=0xfd){
		delay_ms(10);
		switch(P1){
			case 0x7d:
				key=1; //up
				break;
			case 0xbd:
				key=0; 
				break; 
			case 0xdd:
				key=3; //down
				break;  
		}
	}

	P1=0xfb;
	if(P1!=0xfb){
		delay_ms(10);
		switch(P1){
			case 0x7b:
				key=0;
				break;
			case 0xbb:
				key=4; //left
				break; 
			case 0xdb:
				key=0;
				break;  
		}
	}
	return key;	
}