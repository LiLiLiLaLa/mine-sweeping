#ifndef __GAME_H__//防止头文件重复包含
#define __GAME_H__

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#define ROW 11
#define COL 11
#define COUNT 10


void menu();//菜单函数
void display (char show[ROW][COL]);//给玩家展示版面展示
int game(char mine[ROW][COL], char show[ROW][COL]);//游戏
void set_mine(char mine[ROW][COL]);//设置雷
int sweep(char mine[ROW][COL], char show[ROW][COL]);//排雷
int get_num(char mine[ROW][COL], int x, int y);//计算雷的个数


#endif