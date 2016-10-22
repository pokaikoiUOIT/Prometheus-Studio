#pragma once

#include<iostream>
#include<cmath>
#include<Windows.h>
#include<thread>
#include<chrono>
using namespace std;

// ----COLOURS----
// char 219
void black();
void blue();
void green();
void cyan();
void red();
void magenta();
void brown();
void lightGrey();
void darkGrey();
void lightBlue();
void lightGreen();
void white();
// char 178
void black1();
void blue1();
void green1();
void cyan1();
void red1();
void magenta1();
void brown1();
void lightGrey1();
void darkGrey1();
void lightBlue1();
void lightGreen1();
void white1();
// char 177
void black2();
void blue2();
void green2();
void cyan2();
void red2();
void magenta2();
void brown2();
void lightGrey2();
void darkGrey2();
void lightBlue2();
void lightGreen2();
void white2();

// ----COLOUR FUNCTIONS----
// char 219
void black()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	char sq = 219;
	SetConsoleTextAttribute(h, 0);
	cout << sq;
}
void blue()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	char sq = 219;
	SetConsoleTextAttribute(h, 1);
	cout << sq;
}
void green()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	char sq = 219;
	SetConsoleTextAttribute(h, 2);
	cout << sq;
}
void cyan()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	char sq = 219;
	SetConsoleTextAttribute(h, 3);
	cout << sq;
}
void red()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	char sq = 219;
	SetConsoleTextAttribute(h, 4);
	cout << sq;
}
void magenta()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	char sq = 219;
	SetConsoleTextAttribute(h, 5);
	cout << sq;
}
void brown()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	char sq = 219;
	SetConsoleTextAttribute(h, 6);
	cout << sq;
}
void lightGrey()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	char sq = 219;
	SetConsoleTextAttribute(h, 7);
	cout << sq;
}
void darkGrey()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	char sq = 219;
	SetConsoleTextAttribute(h, 8);
	cout << sq;
}
void lightBlue()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	char sq = 219;
	SetConsoleTextAttribute(h, 9);
	cout << sq;
}
void lightGreen()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	char sq = 219;
	SetConsoleTextAttribute(h, 10);
	cout << sq;
}
void white()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	char sq = 219;
	SetConsoleTextAttribute(h, 15);
	cout << sq;
}

//char 178
void black1()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	char sq = 178;
	SetConsoleTextAttribute(h, 0);
	cout << sq;
}
void blue1()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	char sq = 178;
	SetConsoleTextAttribute(h, 1);
	cout << sq;
}
void green1()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	char sq = 178;
	SetConsoleTextAttribute(h, 2);
	cout << sq;
}
void cyan1()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	char sq = 178;
	SetConsoleTextAttribute(h, 3);
	cout << sq;
}
void red1()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	char sq = 178;
	SetConsoleTextAttribute(h, 4);
	cout << sq;
}
void magenta1()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	char sq = 178;
	SetConsoleTextAttribute(h, 5);
	cout << sq;
}
void brown1()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	char sq = 178;
	SetConsoleTextAttribute(h, 6);
	cout << sq;
}
void lightGrey1()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	char sq = 178;
	SetConsoleTextAttribute(h, 7);
	cout << sq;
}
void darkGrey1()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	char sq = 178;
	SetConsoleTextAttribute(h, 8);
	cout << sq;
}
void lightBlue1()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	char sq = 178;
	SetConsoleTextAttribute(h, 9);
	cout << sq;
}
void lightGreen1()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	char sq = 178;
	SetConsoleTextAttribute(h, 10);
	cout << sq;
}
void white1()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	char sq = 178;
	SetConsoleTextAttribute(h, 15);
	cout << sq;
}

//char 177
void black2()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	char sq = 177;
	SetConsoleTextAttribute(h, 0);
	cout << sq;
}
void blue2()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	char sq = 177;
	SetConsoleTextAttribute(h, 1);
	cout << sq;
}
void green2()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	char sq = 177;
	SetConsoleTextAttribute(h, 2);
	cout << sq;
}
void cyan2()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	char sq = 177;
	SetConsoleTextAttribute(h, 3);
	cout << sq;
}
void red2()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	char sq = 177;
	SetConsoleTextAttribute(h, 4);
	cout << sq;
}
void magenta2()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	char sq = 177;
	SetConsoleTextAttribute(h, 5);
	cout << sq;
}
void brown2()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	char sq = 177;
	SetConsoleTextAttribute(h, 6);
	cout << sq;
}
void lightGrey2()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	char sq = 177;
	SetConsoleTextAttribute(h, 7);
	cout << sq;
}
void darkGrey2()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	char sq = 177;
	SetConsoleTextAttribute(h, 8);
	cout << sq;
}
void lightBlue2()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	char sq = 177;
	SetConsoleTextAttribute(h, 9);
	cout << sq;
}
void lightGreen2()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	char sq = 177;
	SetConsoleTextAttribute(h, 10);
	cout << sq;
}
void white2()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	char sq = 177;
	SetConsoleTextAttribute(h, 15);
	cout << sq;
}