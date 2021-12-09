#include "snake.h"
#include "LED.h"
#include "delay.h"

void game_over(){
	
}

void eat_food(){

}


//根据起始方向初始化蛇实体
void snake_init(){
	u8 dir_code[5][2][2]={{{{0},{0}},{{0},{0}}}, 
						{{{4},{4}},{{4},{3}}}, 
						{{{3},{3}},{{4},{3}}}, 
						{{{4},{3}},{{4},{4}}}, 
						{{{4},{3}},{{3},{3}}}};

	//struct Snake_body body1, body2;
	struct Snake_body *body1, *body2;
	body1=(struct Snake_body*)malloc(sizeof(struct Snake_body));
	body2=(struct Snake_body*)malloc(sizeof(struct Snake_body));

	//蛇头
	body1->i=dir_code[dir][0][0];
	body1->j=dir_code[dir][0][1];
	body1->next=NULL;

	//蛇尾
	body2->i=dir_code[dir][1][0];
	body2->j=dir_code[dir][1][1];
	body2->next=body1;

	//蛇头指向队尾 蛇尾指向队头
	snake.head=body1;
	snake.tail=body2;
}


//对map更新蛇的位置
void snake_update(){
	struct Snake_body *current=snake.tail;
		while(current){
			map[current->i][current->j]=1;
			current=current->next;
		}
}

//移动蛇
void snake_move(){
	//struct Snake_body new_body;
	struct Snake_body *new_body, *temp;
	new_body=(struct Snake_body *)malloc(sizeof(struct Snake_body));

	//根据反向设置新蛇身
	switch(dir){
		case 1:
			new_body->i=snake.head->i;
			new_body->j=snake.head->j+1;
			break;
		case 2:
			new_body->i=snake.head->i-1;
			new_body->j=snake.head->j;
			break;
		case 3:
			new_body->i=snake.head->i;
			new_body->j=snake.head->j-1;
			break;
		case 4:
			new_body->i=snake.head->i+1;
			new_body->j=snake.head->j;
			break;
	}

	//判断越位
	if(new_body->i>7){
		new_body->i-=8;
	} else if(new_body->i<0){
		new_body->i+=8;
	} else if(new_body->j>7){
		new_body->i-=8;
	} else if(new_body->j<0){
		new_body->j+=8;
	}

	//判断碰撞或吃到食物
	if(map[new_body->i][new_body->j]==1){
		game_over();
	} else if(map[new_body->i][new_body->j]==2){
		eat_food();
	} else {
		//插入蛇头
		snake.head->next=new_body;
		snake.head=new_body;
		new_body->next=NULL;

		//删除蛇尾
		map[snake.tail->i][snake.tail->j]=0;
		temp=snake.tail;
		snake.tail=snake.tail->next;
		free(temp);
	}
}