#ifndef _PUBLIC_H_
#define _PUBLIC_H_

#include <reg52.h>
#include <stdio.h>
#include <stdlib.h>

typedef unsigned char u8;
typedef unsigned int u16;
typedef unsigned long u32;

//蛇实体
struct Snake{
	u8 x[100],y[100];
	u8 length;
};

struct Food{
	u8 x,y;
};

extern u8 dir;
extern u8 map[8][8];
extern struct Snake snake;

#endif