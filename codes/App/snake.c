#include "snake.h"

extern struct Food food;

void game_over(){
	while(1){
		TR0=0;
		beep();
	}
}

void eat_food(){
	snake.length++;
	snake.x[snake.length-1]=snake.x[snake.length-2];
	snake.y[snake.length-1]=snake.y[snake.length-2];
	food.x=rand()%7;
	food.y=rand()%7;
	while(map[food.x][food.y]==1){
		food.x=rand()%7;
		food.y=rand()%7;
	}
}

extern u8 map[8][8];
extern struct Snake snake;
extern u8 dir;


//根据起始方向初始化蛇实体
void snake_init(){
	u8 dir_code[5][2][2]={{{{0},{0}},{{0},{0}}}, 
						{{{4},{4}},{{4},{3}}}, 
						{{{3},{3}},{{4},{3}}}, 
						{{{4},{3}},{{4},{4}}}, 
						{{{4},{3}},{{3},{3}}}};
	snake.length=2;
	snake.x[0]=dir_code[dir][0][0];
	snake.y[0]=dir_code[dir][0][1];
	snake.x[1]=dir_code[dir][1][0];
	snake.y[1]=dir_code[dir][1][1];
}


//对map更新蛇的位置
void snake_update(){
	u8 i;
	for(i=0; i<snake.length;i++){
		map[snake.x[i]][snake.y[i]]=1;
	}
}

//移动蛇
void snake_move(){
	u8 i;
	for(i=snake.length-1; i>0; i--){
		snake.x[i]=snake.x[i-1];
		snake.y[i]=snake.y[i-1];
	}
	switch(dir) {
		case 1:
			snake.y[0]++;
			if(snake.y[0]>7 || map[snake.x[0]][snake.y[0]]==1){
				game_over();
			} else if(map[snake.x[0]][snake.y[0]]==2){
				eat_food();
			}
			break;
		case 2:
			snake.x[0]--;
			if(snake.x[0]<0 || map[snake.x[0]][snake.y[0]]==1){
				game_over();
			} else if(map[snake.x[0]][snake.y[0]]==2){
				eat_food();
			}
			break;
		case 3:
			snake.y[0]--;
			if(snake.y[0]<0 || map[snake.x[0]][snake.y[0]]==1){
				game_over();
			} else if(map[snake.x[0]][snake.y[0]]==2){
				eat_food();
			}
			break;
		case 4:
			snake.x[0]++;
			if(snake.x[0]>7 || map[snake.x[0]][snake.y[0]]==1){
				game_over();
			} else if(map[snake.x[0]][snake.y[0]]==2){
				eat_food();
			}
			break;
	}
}