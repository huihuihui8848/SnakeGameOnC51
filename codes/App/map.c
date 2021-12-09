#include "map.h"

extern struct Food food;

void map_update(){
	u8 i,j;
	for(i=0;i<8;i++){
		for(j=0;j<8;j++){
			map[i][j]=0;
		}
	}
	//更新蛇
	snake_update();
	map[food.x][food.y]=2;
}

void map_init(){
	u8 i,j; 
	for(i=0; i<8; i++){
		for(j=0; j<8; j++){
			map[i][j]=0;
		}
	}
}