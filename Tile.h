#pragma once
#include "stdafx.h"
#include "Windows.h"
#include <iostream>
#include <string>

using namespace std;

//**************************************************
//*These are color variables, and the pipe since it*
//*will be needed here.                            *
//**************************************************
int defwht = 7, yellow = 14, green = 10,
red = 12, blue = 11, brtwht = 15, purple = 13;
string pipe = "|";

//**************************************************
//*This just allows us to set the color of the text*
//**************************************************
void SetColor(int value)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), value);
}

//*****************************************************************
//*Tile class has a color, a name, and 8 strings to draw a picture*
//*Publicly, we have a default constructor and a constructor that *
//*basically takes in a value for each of the private members. We *
//*also have a getname function (which returns the string value of*
//*the name), a getline function for each line (which returns the *
//*string value of the line of the symbol to be printed), and a   *
//*printline function (which takes a string argument, sets the    *
//*proper color of the tile calling the function, prints the      *
//*string in that color, turns the color back to yellow, and then *
//*prints a pipe, and will be called numerous times by the play   *
//*screen in the program itself)                                  *
//*****************************************************************
class Tile
{
private:
	int color;
	string name;
	string line1;
	string line2;
	string line3;
	string line4;
	string line5;
	string line6;
	string line7;
	string line8;
public:
	Tile() {
		color = defwht;
		name = line1 = line2 = line3 = line4 = line5 = line6
			= line7 = line8 = " ";
	}
	Tile(int hue, string nm, string ln1, string ln2, string ln3,
		string ln4, string ln5, string ln6, string ln7, string ln8) {
		color = hue;
		name = nm;
		line1 = ln1;
		line2 = ln2;
		line3 = ln3;
		line4 = ln4;
		line5 = ln5;
		line6 = ln6;
		line7 = ln7;
		line8 = ln8;
	}
	string getname() {
		return name;
	}
	string gtln1() {
		return line1;
	}
	string gtln2() {
		return line2;
	}
	string gtln3() {
		return line3;
	}
	string gtln4() {
		return line4;
	}
	string gtln5() {
		return line5;
	}
	string gtln6() {
		return line6;
	}
	string gtln7() {
		return line7;
	}
	string gtln8() {
		return line8;
	}
	void prntln(string ln) {
		SetColor(color);
		cout << ln;
		SetColor(yellow);
		cout << pipe;
	}
};