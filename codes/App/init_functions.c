#include "init_functions.h"
#include "map.h"
#include "snake.h"

extern struct Food food;

//初始化定时器0
void timer0_init(){
	TMOD>>=4;
	TMOD<<=4;
	TMOD|=0x01;
	TH0=0x4c;
	TL0=0x00;                                                    
	ET0=1;
	EA=1;
	TR0=1;
}
//当有方向输入时开始游戏
void dir_init(){
	while(!key_scan());
	dir=key_scan();
	if(!dir){
		dir=1;
	}
}

void food_init(){
	food.x=rand()%7;
	food.y=rand()%7;
	while(map[food.x][food.y]==1){
		food.x=rand()%7;
		food.y=rand()%7;
	}
}


//游戏总初始化
void game_init(){
	map_init();
	dir_init();
	snake_init();
	food_init();
	map_update();
	timer0_init();	
}