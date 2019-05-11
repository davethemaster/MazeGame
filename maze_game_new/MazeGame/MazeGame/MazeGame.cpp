// MazeGame.cpp : Defines the entry point for the console application.
//224 = UP  

#include "stdafx.h"
#include <iostream>
#include <string>
#include <ctime>
#include <conio.h>
#include <windows.h>
#define UP 72
#define LEFT 75
#define RIGHT 77
#define DOWN 80
#define W 119
#define D 100
#define S 115
#define A 97
using namespace std;


class boardGame {
	//function printboard
	//function ramdomboard
	//variables for lines and characters
	//constructor
	//func to check possibility

	char lefttopcorner = 218;
	char dash = 196;
	char rightcorner = 191;
	char leftdowncorner = 192;
	char bottomrightcorner = 217;
	char space = 32;
	char block = 178;
	char verticalline = 179;
	char s = 83;
	char e = 69;
	char player = 223;
	int PlayerX = 0;
	int PlayerY = 0;
	int startX = 0;
	int startY = 0;
public:
	bool hasSolved = false;
	int printCount = 0;
	int boardArr[50][50] = {
    { 218, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196,196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196,196, 196, 196, 196, 196, 196, 196, 196, 191 },
	{ 179, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 179 },
	{ 179, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 179 },
	{ 179, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 179 },
	{ 179, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 179 },
	{ 179, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 179 },
	{ 179, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 179 },
	{ 179, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 179 },
	{ 179, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 179 },
	{ 179, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 179 },
	{ 179, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 179 },
	{ 179, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 179 },
	{ 179, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 179 },
	{ 179, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 179 },
	{ 179, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 179 },
	{ 179, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 179 },
	{ 179, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 179 },
	{ 179, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 179 },
	{ 179, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 179 },
	{ 179, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 179 },
	{ 179, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 179 },
	{ 179, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 179 },
	{ 179, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 179 },
	{ 179, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 179 },
	{ 179, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 179 },
	{ 179, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 179 },
	{ 179, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 179 },
	{ 179, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 179 },
	{ 179, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 179 },
	{ 179, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 179 },
	{ 179, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 179 },
	{ 179, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 179 },
	{ 179, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 179 },
	{ 179, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 179 },
	{ 179, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 179 },
	{ 179, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 179 },
	{ 179, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 179 },
	{ 179, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 179 },
	{ 179, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 179 },
	{ 179, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 179 },
	{ 179, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 179 },
	{ 179, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 179 },
	{ 179, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 179 },
	{ 179, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 179 },
	{ 179, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 179 },
	{ 179, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 179 },
	{ 179, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 179 },
	{ 179, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 179 },
	{ 179, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 179 },
	{ 192, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196,196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196,196, 196, 196, 196, 196, 196, 196, 196, 217 }
	};

	bool boolArr[50][50];
	void falser() {
		for (int i = 0; i < 50; i++) {
			for (int j = 0; j < 50; i++) {
				boolArr[i][j] = false;
			}
		}
	}

	boardGame() {
		

	}
	
	void printBoard() {
		system("CLS");
		for (int i = 0; i < 50; i++)
		{

			for (int j = 0; j < 50; j++) {
				if (boardArr[i][j] == 218) {
					cout << lefttopcorner;
				}
				else if (boardArr[i][j] == 196) {
					cout << dash;
				}
				else if (boardArr[i][j] == 191) {
					cout << rightcorner;
				}
				else if (boardArr[i][j] == 192) {
					cout << leftdowncorner;
				}
				else if (boardArr[i][j] == 217) {
					cout << bottomrightcorner;
				}
				else if (boardArr[i][j] == 83) {
					cout << s;
				}
				else if (boardArr[i][j] == 69) {
					cout << e;
				}
				else if (boardArr[i][j] == 179) {
					cout << verticalline;
				}
				else if (boardArr[i][j] == 0) {
					cout << space;
				}
				else if (boardArr[i][j] == 178) {
					cout << block;
				}
				else if (boardArr[i][j] == 223) {
					cout << player;
				}


			}
			cout << '\n';
		}

	}
	

	void randBoard() {


		srand(time(NULL));

		printCount += 1;
		for (int i = 0; i < 50; i++) {
			for (int j = 0; j < 50; j++)
			{
				boolArr[i][j] = false;
				if (boardArr[i][j] == 0 || boardArr[i][j] == 178 || boardArr[i][j] == 223) {

					int a = rand() % 10 + 1;

					if (a <= 4)
					{
						boardArr[i][j] = 178;
					}
					else if (a > 4)
					{
						boardArr[i][j] = 0;
					}

				}
				else if (boardArr[i][j] == 83 || boardArr[i][j] == 69) {
					boardArr[i][j] = 196;
				}
			}
		}

		int indStr = rand() % 48 + 1;
		int indEd = rand() % 48 + 1;
		boardArr[0][indStr] = s;
		
		
		startX = 1;
		startY = indStr;
	    PlayerX = 1;
		PlayerY = indStr;
		
		boardArr[PlayerX][PlayerY] = 223;
		boardArr[49][indEd] = e;
		boardArr[48][indEd] = 0;


	}
		
	bool checkPos() {
		return recursiveSolve(PlayerX, PlayerY);
	}

	bool recursiveSolve(int X, int Y) {
		if (boardArr[X][Y] == e)
		{

			return true;
		}
		//boardArr[X][Y] = 223;
		boolArr[X][Y] = true;
		//check left
		if ((boardArr[X][Y - 1] == 0 || boardArr[X][Y - 1] == e) && boolArr[X][Y - 1] == false) {
			if (recursiveSolve(X, Y - 1))
			{
				return true;
			}
		}
		//check down
		if ((boardArr[X + 1][Y] == 0 || boardArr[X + 1][Y] == e) && boolArr[X + 1][Y] == false) {
			if (recursiveSolve(X + 1, Y))
			{
				return true;
			}
		}

		// check right
		if ((boardArr[X][Y + 1] == 0 || boardArr[X][Y + 1] == e) && boolArr[X][Y + 1] == false) {
			if (recursiveSolve(X, Y + 1))
			{
				return true;
			}
		}
		//check up
		if ((boardArr[X - 1][Y] == 0 || boardArr[X - 1][Y] == e) && boolArr[X - 1][Y] == false) {
			if (recursiveSolve(X - 1, Y)) {
				return true;
			}
		}

		return false;
	}

	void checkMove(int direction) {
		if (direction == 72 || direction == W)
		{
			
			if (boardArr[PlayerX - 1][PlayerY] == 0) {
				//remove the old player symbol
				boardArr[PlayerX][PlayerY] = 0;
				PlayerX = PlayerX - 1;
				//add the new player symbol
				boardArr[PlayerX][PlayerY] = 223;
				printBoard();
				

			}
		}
		else if (direction == 75 || direction == A)
		{
			if (boardArr[PlayerX][PlayerY - 1] == 0) {
				boardArr[PlayerX][PlayerY] = 0;
				PlayerY = PlayerY - 1;
				boardArr[PlayerX][PlayerY] = 223;
				printBoard();
				
			}
			

		}
		else if (direction == 77 ||direction == D)
		{
			if (boardArr[PlayerX][PlayerY + 1] == 0) {
				boardArr[PlayerX][PlayerY] = 0;
				PlayerY = PlayerY + 1;
				boardArr[PlayerX][PlayerY] = 223;
				printBoard();
				
			}
			
		}
		else if (direction == 80 || direction == S)
		{
			if (boardArr[PlayerX + 1][PlayerY] == 0) {
				boardArr[PlayerX][PlayerY] = 0;
				PlayerX = PlayerX + 1;
				boardArr[PlayerX][PlayerY] = 223;
				printBoard();
			
			}
			else if (boardArr[PlayerX + 1][PlayerY] == e)
			{
				
				cout << "YOU PASSED THE HARDEST MAZE IN THE WORLD!!!!!!!";
				hasSolved = true;
				
			}
			
		}
		
	}
	void resetPos() {
		boardArr[PlayerX][PlayerY] = 0;
		boardArr[startX][startY] = 223;
		PlayerX = startX;
		PlayerY = startY;
	}
	
};




class Player {

	
	//int x = 0, y = 0;
	int ID;
public:
	Player(int PlayerID) {
		ID = PlayerID;
	}
	Player() {
		ID = 1;
	}
	void move(boardGame * checkBoard) {
		int input = 0;
		input = _getch();
		if (ID == 1) {
			switch (input)
			{
			case 224:
				break;
			case UP:
				checkBoard->checkMove(UP);

				break;

			case DOWN:
				checkBoard->checkMove(DOWN);

				break;

			case RIGHT:
				checkBoard->checkMove(RIGHT);

				break;

			case LEFT:
				checkBoard->checkMove(LEFT);

				break;

			default: {
			}
			}
		}
			
			




		
	}
		/*void move(int moveX, int moveY) {
			if (GetAsyncKeyState(VK_UP)) {
				move(x - 1, y);
				cout << "Up";
				
			}
			if (GetAsyncKeyState(VK_DOWN)) {
				
				move(x + 1, y);
				cout << "Down";
				
			}
			if (GetAsyncKeyState(VK_LEFT)) {
				move(x, y - 1);
				cout << "Left";
				
			}
			if (GetAsyncKeyState(VK_RIGHT)) {
				move(x, y + 1);
				cout << "Right";
				
			}
			

		}
	
	*/
};






int main()
{
	int c;

	int i;
	int j;
	string multiplayerQ = "Do you want to play multiplayer?";
	string a = "Do you want to play again?";
	bool solved = false;
	bool multiplayer;
	cout << multiplayerQ;
	cin >> multiplayerQ;
	if (multiplayerQ == "yes" || multiplayerQ == "Yes")
	{
		multiplayer = true;
		cout << "Generating Maze...";
	}
	else {
		multiplayer = false;
		cout << "Generating Maze...";
	}
	Player player;
	boardGame board;
	board.randBoard();
	while (board.checkPos() == false) {

		board.randBoard();
		
		//board.printBoard();

	}

	board.printBoard();
	cout << '\n' << "Use Only Arrow Keys" << '\n';
	int sec = 0;
	
	
	while (board.hasSolved == false) {
		
		player.move(&board);
		if (sec == 0) {
			
			sec = time(0);
		}
	}
	int newsec = time(0);
	
	if (board.hasSolved == true)
	{
		if (multiplayer == true) {

			cout << '\n' << "It took you " << newsec - sec << " SECONDS " <<'\n' <<"Now it is Player 2's turn" << '\n';
			board.hasSolved = false;
			
			system("pause");
			board.resetPos();
			board.printBoard();
	
			int sec2 = 0;

			

			while (board.hasSolved == false) {
				player.move(&board);
				if (sec2 == 0) { 
					
					sec2 = time(0);
				}
			}
			int newsec2 = time(0);

			cout << '\n' << "It took you " << newsec2 - sec2 << " SECONDS";
			if (newsec - sec < newsec2 - sec2) {
				cout << '\n' << "Player 1 took " << newsec - sec << " Seconds" << " & Player 2 took " << newsec2 - sec2 << " Seconds";
				cout << '\n' << "Player 1 Wins!!";
			}
			else if (newsec - sec == newsec2 - sec2)
			{
				cout << "!!DRAW!!";
			}
			else {
				cout << '\n' << "Player 1 took " << newsec - sec << " Seconds" << " & Player 2 took " << newsec2 - sec2 << " Seconds" << '\n';
				cout << "Player 2 Wins!!";
			}
		}
		
		else if (multiplayer == false) {

			cout << '\n' << "It took you " << newsec - sec << " SECONDS" << '\n';
			if (newsec - sec <= 20) {
				cout << "YOU ARE GOD LEVEL FAST!!!";

			}
			else if (newsec - sec <= 30)
			{
				cout << "YOU ARE FAST!!";
			}
			else if (newsec - sec <= 45) {
				cout << "NICE JOB";

			}
			else if (newsec - sec >= 60 || newsec - sec <= 60) {
				cout << "YOU ARE PRETTY SLOW";
			}
			cout << '\n' << a;
			cin >> a;
			if (a == "yes")
			{
				main();
			}
			else {
				return 0;


			}
		}
	}
		
		

		
	/*	int sec = 0;
		int min = 0;
		int hours = 0;
		while (sec != 30)
		{
			Sleep(1000);
			sec = sec + 1;
			if (sec == 60)
			{
				min = min + 1;
				sec = 0;
			}
			if (min == 60)
			{
				hours = hours + 1;
				min = 0;
			}
			system("CLS");
			cout << hours << " hours " << min << " minutes " << "and " << sec << " seconds." << endl;
		}

		*/
		//player.move(0, 0);
		/*char topleft = 218;
		char topright = 191;
		char bottomleft = 192;
		char bottomright = 217;
		char horizontalline = 196;
		char block = 178;
		cout << topleft <<horizontalline << horizontalline << horizontalline << horizontalline << horizontalline << horizontalline << horizontalline << horizontalline << horizontalline << horizontalline << horizontalline << horizontalline << horizontalline << horizontalline << horizontalline << horizontalline << horizontalline << horizontalline << horizontalline << horizontalline << horizontalline << horizontalline << horizontalline << horizontalline << horizontalline << horizontalline <<  horizontalline << horizontalline << horizontalline << horizontalline << horizontalline << horizontalline << horizontalline << horizontalline << horizontalline << horizontalline << horizontalline << topright << '\n';
		cout << "|" << "               " << block << " " << block << "                   |" << '\n';

		cout << "|" << "               " << block << " " << block << "                   |" << '\n';
		cout << "|" << "               " << block << " " << block << "                   |" << '\n';
		cout << "|" << "               " << block << " " << block << "                   |" << '\n';
		cout << "|" << "               " << block << " " << block << "                   |" << '\n';
		cout << "|" << "               " << block << " " << block << "                   |" << '\n';
		cout << "|" << "               " << block << " " << block << "                   |" << '\n';
		cout << "|" << "               " << block << " " << block << "                   |" << '\n';
		cout << "|" << "               " << block << " " << block << "                   |" << '\n';
		cout << "|" << "               " << block << " " << block << "                   |" << '\n';
		cout << "|" << "               " << block << " " << block << "                   |" << '\n';
		cout << "|" << "               " << block << " " << block << "                   |" << '\n';
		cout << "|" << "               " << block << " " << block << "                   |" << '\n';
		cout << "|" << "               " << block << " " << block << "                   |" << '\n';
		cout << "|" << "               " << block << " " << block << "                   |" << '\n';
		cout << "|" << "               " << block << " " << block << "                   |" << '\n';
		cout << "|" << "               " << block << " " << block << "                   |" << '\n';
		cout << "|" << "               " << block << " " << block << "                   |" << '\n';


		cout << bottomleft<< horizontalline << horizontalline << horizontalline << horizontalline << horizontalline << horizontalline << horizontalline << horizontalline << horizontalline << horizontalline << horizontalline << horizontalline << horizontalline << horizontalline << horizontalline << horizontalline << horizontalline << horizontalline << horizontalline << horizontalline << horizontalline << horizontalline << horizontalline << horizontalline << horizontalline << horizontalline << horizontalline << horizontalline << horizontalline << horizontalline << horizontalline << horizontalline << horizontalline << horizontalline << horizontalline << horizontalline << horizontalline << bottomright;

		*/

		cin >> c;
		return 0;
	}



