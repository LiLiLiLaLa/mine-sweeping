#ifndef __GAME_H__//��ֹͷ�ļ��ظ�����
#define __GAME_H__

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#define ROW 11
#define COL 11
#define COUNT 10


void menu();//�˵�����
void display (char show[ROW][COL]);//�����չʾ����չʾ
int game(char mine[ROW][COL], char show[ROW][COL]);//��Ϸ
void set_mine(char mine[ROW][COL]);//������
int sweep(char mine[ROW][COL], char show[ROW][COL]);//����
int get_num(char mine[ROW][COL], int x, int y);//�����׵ĸ���


#endif