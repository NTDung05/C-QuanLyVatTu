#pragma once
#include<iostream>
#include <conio.h>

#include <stdio.h>
#include <stdlib.h>
#include <dos.h>
#include <string.h>
#include <windows.h>

#define Enter 13
#define PASSWORD "abcdef"
const int WHITE=15;
using namespace std;

char* Pwd () {
     char S[40]; int i=0;
     while ((S[i]= getch()) != Enter ) 
     { printf ("%c", '*') ; i++ ; 
     }
     S[i]='\0';
     return S;
}

int CheckPwd () {
    int dem =0; 
    for ( dem =1 ; dem <=3 ; dem++)
    { printf( "Password :"); 
      if (strcmp(Pwd(),PASSWORD) ==0)   return 1;
      else printf ( "\nPassword sai. Hay nhap lai\n")  ; 
    }
    return 0;  
}

void gotoxy(short x,short y)
{
        HANDLE hConsoleOutput;
        COORD Cursor_an_Pos = { x,y};
        hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleCursorPosition(hConsoleOutput , Cursor_an_Pos);
}  

int wherex( void )
{
    HANDLE hConsoleOutput;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
    GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);
    return screen_buffer_info.dwCursorPosition.X;
}

int wherey( void )
{
    HANDLE hConsoleOutput;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
    GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);
    return screen_buffer_info.dwCursorPosition.Y;
}
void clreol( ) {
COORD coord;
DWORD written;
CONSOLE_SCREEN_BUFFER_INFO info;
GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
coord.X = info.dwCursorPosition.X;
coord.Y = info.dwCursorPosition.Y;
FillConsoleOutputCharacter (GetStdHandle(STD_OUTPUT_HANDLE), ' ',
  info.dwSize.X - info.dwCursorPosition.X * info.dwCursorPosition.Y, coord, &written);
gotoxy (info.dwCursorPosition.X , info.dwCursorPosition.Y );
}

void SetColor(WORD color)
{
    HANDLE hConsoleOutput;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
    GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

    WORD wAttributes = screen_buffer_info.wAttributes;
    color &= 0x000f;
    wAttributes &= 0xfff0;
    wAttributes |= color;

    SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}
void SetBGColor(WORD color)
{
    HANDLE hConsoleOutput;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
    GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

    WORD wAttributes = screen_buffer_info.wAttributes;
    color &= 0x000f;
    color <<= 4;
    wAttributes &= 0xff0f;
    wAttributes |= color;

    SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}

void clrscr() {
	system("cls");
}

void resizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}

//ve duong thang ngang tu toa do (x0, y) den (x1, y)
void linex(int x0, int x1, int y)
{
	gotoxy(x0, y);
	for (int i = x0; i < x1; i++)
	{
		cout << char(196);
	}
}

//ve duong thang doc tu toa do (x, y0) den (x, y1)
void liney(int y0, int y1, int x)
{
	for (int i = y0; i <= y1; i++)
	{
		gotoxy(x, i);
		cout << char(179);
	}
	gotoxy(wherex(), y0);
}

//an di con tro chi vi nhap nhay tren man hinh, 0 la an con tro, 1 la hien lai con tro
void Xu_Li_Con_Tro_Chi_Vi(bool CursorVisibility)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor = { 1, CursorVisibility };
	SetConsoleCursorInfo(handle, &cursor);
}

void Normal () {
	SetColor(WHITE);
	SetBGColor(0);
}
void HighLight () {
	SetColor(10);
	SetBGColor(WHITE);
}

void HighLight_Errorr () {
	SetColor(WHITE);
	SetBGColor(4);
}

void HighLight_KEY() {
	SetColor(WHITE);
	SetBGColor(10);
}
void DapAn () {
	SetColor(15);
	SetBGColor(1);
}

void DapAn_ABCD () {
	SetColor(1);
	SetBGColor(13);
}

void HighLight2 () {
    SetColor(0);
    SetBGColor(WHITE);
	 
}
void background () {
	SetColor(10);
	SetBGColor(WHITE);
}
void backgroud_DapAn() {
	SetColor(15);
	SetBGColor(0);
}

void MenuGV_Color () {
	SetColor(1);
}
void Mau_Diem(){
	SetColor(12);
}
void Mau_Close()
{
	SetBGColor(0);
	SetColor(12);
}

void TextResize(int size)
{
	HANDLE cons = GetStdHandle(STD_OUTPUT_HANDLE);
    PCONSOLE_FONT_INFOEX font = new CONSOLE_FONT_INFOEX() ;
    font->cbSize = sizeof(CONSOLE_FONT_INFOEX);
    GetCurrentConsoleFontEx(cons,0,font);
    font->dwFontSize.X = 18;
    font->dwFontSize.Y = size;
    font->FontWeight = FW_ULTRALIGHT;
    //font->FontFamily = FF_DECORATIVE;
    SetCurrentConsoleFontEx(cons,0,font);
 } 

void VeKhung(int x, int y, int width, int height)
{
	char a = 218, b = 196, c = 191, d = 179, e = 192, f = 217;//Ki tu dac biet 
	gotoxy(x, y);
	cout << a;                // goc tren trai
	for (int i = 1; i < width; i++) {
		gotoxy(x + i, y);
		cout << b;
	}
	gotoxy(x + width, y);     // goc tren phai
	cout << c;
	for (int i = 1; i < height; i++) {
		gotoxy(x, y + i);
		cout << d;
	}
	gotoxy(x, y + height);    // goc duoi trai
	cout << e;
	for (int i = 1; i < width; i++) {
		gotoxy(x + i, y + height);
		cout << b;
	}
	gotoxy(x + width, y + height);   // goc duoi phai
	cout << f;
	for (int i = 1; i < height; i++) {
		gotoxy(x + width, y + i);
		cout << d;
	}
}
	
void BaoLoi (char *s){
  int x=wherex() , y=wherey();
  gotoxy (35,30); SetColor(4);
  cout <<s;
  gotoxy(35,30); SetColor(10); 
  Sleep(2000);
  clreol();
  //gotoxy(x,y);
}
