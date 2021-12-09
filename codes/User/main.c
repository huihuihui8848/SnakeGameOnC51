#include "public.h"
#include "delay.h"
#include "LED.h"
#include "init_functions.h"
#include "KEY.h"
#include "snake.h"
#include "map.h"
#include "beep.h"
//#include <intrins.h>

//地图矩阵
u8 map[8][8];
//方向
u8 dir = 0;
//方向锁
bit dir_flag = 1;
//蛇实体
struct Snake snake;
//食物
struct Food food;

//检测输入设置方向 若方向相反则不变
void dir_set()
{
	u8 dir_temp;
	dir_temp = key_scan();
	if (dir_temp)
	{
		if (!((dir_temp == 1 && dir == 3) || (dir_temp == 3 && dir == 1) || (dir_temp == 2 && dir == 4) || (dir_temp == 4 && dir == 2) || (dir_temp == dir)))
		{
			dir = dir_temp;
			dir_flag = 0;
		}
	}
}

void main()
{
	game_init();
	while (1)
	{
		if (dir_flag)
		{
			dir_set();
		}
		LED_display();
	}
}

void timer0() interrupt 1
{
	static u8 timer_count = 0;
	if (timer_count == 10)
	{
		//beep();
		dir_flag = 1;
		timer_count = 0;
		TH0 = 0x4c;
		TL0 = 0x00;
		snake_move();
		map_update();
	}
	else
	{
		timer_count++;
	}
}
