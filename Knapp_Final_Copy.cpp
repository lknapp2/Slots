// Name: Leandra Knapp
// Date: 12/07/16
// Lab: Final
// Summary: This is a simulated slot machine. It is made using
//          a menu-driven case-switch method, and will ultimately
//          be using 4 concepts from the second half of the class

#include "stdafx.h"
#include "Tile.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>

using namespace std;

ofstream ofs("Knapp_Final.txt");

//***********************************
//*General and/or frequent variables*
//***********************************
string nameEtc = "Leandra Knapp, CIS2542-002, 12/07/16, Final";
string foot1 = "Printed are the statistics from today's adventures"
" with the slot machine. Stats";
string foot2 = "include games played, games won, games lost, money"
" won, money lost, and cash out";
string foot3 = "amount.";
string eofMsg = "EOF Message: ";
string pipeline = "|--------------------------------------------"
"--------------------------------------|";
string spacepipe = "|                                             "
"                                     |";
string col = ":", sp = " ", dol = "$", title;
string yes = "y", no = "n";
string errormsg = "Invalid entry. Please try again.";
int width = 84, numwid = 11, conswid = 132, boxwid = 25, plusmin;
const int nada = 0, one = 1, two = 2, three = 3, four = 4, five = 5, 
seven = 7, neg = -1;
const double ten = 10;
unsigned seed;
const int MAX = 10, MIN = 2;
int asdfghjkl = (rand() % (MAX - MIN + one)) + MIN;
bool l1, l2, l3, l4, l5, won, valid;

//**********************************
//*Start screen variables (strings)*
//**********************************
string start1 = "L)                             d)             "
" K) kk                           ";
string start2 = "L)                             d)             "
" K) k                            ";
string start3 = "L)    e)EEEE a)AAA  n)NNN   d)DDD r)RR a)AAA  "
" K)k    n)NNN  a)AAA  p)PP  p)PP ";
string start4 = "L)    e)EEE   a)AA  n)  NN d)  DD r) RR a)AA  "
" K)kk   n)  NN  a)AA  p) PP p) PP";
string start5 = "L)    e)     a)  A  n)  NN d)  DD r)   a)  A  "
" K) kk  n)  NN a)  A  p) PP p) PP";
string start6 = "L)llll e)EEE  a)AAA n)  NN  d)DDD r)    a)AAA "
" K)  kk n)  NN  a)AAA p)PP  p)PP ";
string start7 = "                                              "
"                      p)    p)   ";
string start8 = "  C)ccc I)iiii S)ssss   2)AAA  5)%%% 4)   SS  "
"2)AAA        0)))   0)))   2)AAA ";
string start9 = " C)       I)   S)   ss 2)   AA 5)    4)   SS 2"
")   AA      0)  )) 0)  )) 2)   AA";
string start10 = "C)        I)    S)ss        2) 5)%%% 4)SSSSS  "
"   2)       0)  )) 0)  ))     2) ";
string start11 = "C)        I)        S)    2)       5)     4)  "
"  2)  ##### 0)  )) 0)  ))    2)  ";
string start12 = " C)       I)   S)    ss  2)        5)     4)  "
" 2)         0)  )) 0)  ))   2)   ";
string start13 = "  C)ccc I)iiii  S)ssss  2)AAAA 5)%%%      4) 2"
")AAAAA       0)))   0)))  2)AAAAA";
string start14 = "  1)!    2)AAA      /)  1)!   4)   SS     /) 2"
")AAA   0))))    1)!    6)NNN  ";
string start15 = " 1)!!   2)   AA    /)  1)!!   4)   SS    /) 2)"
"   AA 0)   ))  1)!!   6)      ";
string start16 = "   1)       2)    /)     1)   4)SSSSS   /)    "
"  2)  0)   ))    1)   6)NNNN  ";
string start17 = "   1)      2)    /)      1)        4)  /)     "
" 2)   0)   ))    1)   6)   NN ";
string start18 = "   1)     2)    /)       1)        4) /)      "
"2)    0)   ))    1)   6)   NN ";
string start19 = "1)!!!!! 2)AAAAA/)     1)!!!!!      4)/)     2)"
"AAAAA  0))))  1)!!!!!  6)NNN  ";
string start20 = "\t\t\tF)ffffff ##                 l)L  ";
string start21 = "\t\t\tF)                           l)  ";
string start22 = "\t\t\tF)fffff  i) n)NNNN  a)AAAA   l)  ";
string start23 = "\t\t\tF)       i) n)   NN  a)AAA   l)  ";
string start24 = "\t\t\tF)       i) n)   NN a)   A   l)  ";
string start25 = "\t\t\tF)       i) n)   NN  a)AAAA l)LL ";

//**********************************************
//*Menu screen variables (strings & const ints)*
//**********************************************
string menusc1 = "\t\t $$       $$ $$$$$$$$ $$    $$ $$   $$";
string menusc2 = "\t\t $$$     $$$ $$       $$$   $$ $$   $$";
string menusc3 = "\t\t $$$$   $$$$ $$       $$$$  $$ $$   $$";
string menusc4 = "\t\t $$ $$ $$ $$ $$$$$    $$ $$ $$ $$   $$";
string menusc5 = "\t\t $$  $$$  $$ $$       $$  $$$$ $$   $$";
string menusc6 = "\t\t $$   $   $$ $$       $$   $$$ $$   $$";
string menusc7 = "\t\t $$       $$ $$$$$$$$ $$    $$  $$$$$$";
string menusc8 = "\t\t  .      .-. .                   .--.      .         ";
string menusc9 = "\t\t.'|     (   )|                   |   )     |         ";
string menusc10 = "\t\t  |      `-. |--. .-..  .    ._  |--' .  . | .-. .--.";
string menusc11 = "\t\t  |     (   )|  |(   )\\  \\  /    |  \\ |  | |(.-' `--.";
string menusc12 = "\t\t'---'o   `-' '  `-`-'  `' `'     '   ``--`-`-`--'`--'";
string menusc13 = "\t\t .-.    .  .   .  .   . .     .                      ";
string menusc14 = "\t\t(   )    \\  \\ /  /    | |    _|_                     ";
string menusc15 = "\t\t  .'      \\  \\  /.-.  | | .-. |                      ";
string menusc16 = "\t\t /         \\/ \\/(   ) | |(.-' |                      ";
string menusc17 = "\t\t'---'o      ' '  `-'`-`-`-`--'`-'                    ";
string menusc18 = "\t\t.--.   .--. .             .--.                       ";
string menusc19 = "\t\t    )  |   )|            :                           ";
string menusc20 = "\t\t --:   |--' | .-.  .  .  | --. .-.  .--.--. .-.      ";
string menusc21 = "\t\t    )  |    |(   ) |  |  :   |(   ) |  |  |(.-'      ";
string menusc22 = "\t\t`--'o  '    `-`-'`-`--|   `--' `-'`-'  '  `-`--'     ";
string menusc23 = "\t\t                      ;                              ";
string menusc24 = "\t\t.  .    .--.       `-' .                             ";
string menusc25 = "\t\t|  |   :    :       o _|_                            ";
string menusc26 = "\t\t'--|-  |    |.  .   .  |                             ";
string menusc27 = "\t\t   |   :  ( ;|  |   |  |                             ";
string menusc28 = "\t\t   'o   `--`-`--`--' `-`-'                           ";
string pleasepick = "Please pick a menu option: ";
const int RULES = 1, WALLET = 2, PLAY = 3, EXIT = 4;
string selection;
int choice;

//**********************************
//*Rules screen variables (strings)*
//**********************************
string rules1 = "\t______ _             _              ______      _"
"             ";
string rules2 = "\t| ___ \\ |           (_)             | ___ \\    "
"| |          _ ";
string rules3 = "\t| |_/ / | __ _ _   _ _ _ __   __ _  | |_/ /   _| "
"| ___  ___(_)";
string rules4 = "\t|  __/| |/ _` | | | | | '_ \\ / _` | |    / | | |"
" |/ _ \\/ __|  ";
string rules5 = "\t| |   | | (_| | |_| | | | | | (_| | | |\\ \\ |_| "
"| |  __/\\__ \\_ ";
string rules6 = "\t\\_|   |_|\\__,_|\\__, |_|_| |_|\\__, | \\_| \\_\\"
"__,_|_|\\___||___(_)";
string rules7 = "\t                __/ |         __/ |               "
"            ";
string rules8 = "\t               |___/         |___/                "
"            ";
string rules9 = "\t ,    .                        ,      ,          ";
string rules10 = "\t/|    |*._  _   ._  _.  . __  /|   * /|          ";
string rules11 = "\t.|.   ||[ )(/,  [_)(_]\\_|_)   .|.  * .|.         ";
string rules12 = "\t                |     ._|                        ";
string rules13 = "\t _,   .                            .      .  .   ";
string rules14 = "\t'_)   |*._  _  __  ._  _.  . __   _| _ . .|_ | _ ";
string rules15 = "\t._)   ||[ )(/,_)   [_)(_]\\_|_)   (_](_)(_|[_)|(/,";
string rules16 = "\t                   |     ._|                     ";
string rules17 = "\t._,   .                           ,        .     ";
string rules18 = "\t|_    |*._  _  __  ._  _.  . __  -+-._.*._ | _   ";
string rules19 = "\t._)   ||[ )(/,_)   [_)(_]\\_|_)    | [  |[_)|(/,  ";
string rules20 = "\t                   |     ._|            |        ";
int num;

//******************
//*Wallet variables*
//******************
string wallet1 = "\t:::       :::     :::     :::        :::        "
":::::::::: ::::::::::: ";
string wallet2 = "\t:+:       :+:   :+: :+:   :+:        :+:        "
":+:            :+:     ";
string wallet3 = "\t+:+       +:+  +:+   +:+  +:+        +:+        "
"+:+            +:+     ";
string wallet4 = "\t+#+  +:+  +#+ +#++:++#++: +#+        +#+        "
"+#++:++#       +#+     ";
string wallet5 = "\t+#+ +#+#+ +#+ +#+     +#+ +#+        +#+        "
"+#+            +#+     ";
string wallet6 = "\t #+#+# #+#+#  #+#     #+# #+#        #+#        "
"#+#            #+#     ";
string wallet7 = "\t  ###   ###   ###     ### ########## ########## "
"##########     ###     ";
string wallet_a = "You have $";
string wallet_b = " in your wallet.";
string wallet_c = " Would you like to add more? (y/n) ";
string wallfull = " There's no room to add more money.";
string howmuch_a = "How much money would you like to add (whole dollars, "
"max $";
string howmuch_b = ")? $";
string haveadd_a = "You have added $";
string haveadd_b = " to your wallet.";
string nomore = "You did not add any money to your wallet.";
int buyin = 0, wallet = 0, moremoney, maxwal = 1000000;
string addmoney, strmoremoney;

//*************************************
//*Slot machine and gameplay variables*
//*************************************
string howmany = "How many lines would you like to play? (1, 3, 5) ";
string howbet_a = "How much would you like to bet/line? "
"(whole dollars; $0-$";
string howbet_b = ") $";
string spinormenu = "Enter s to spin, or m to cancel and return to menu. ";
string bt_rows = "----------------------------------------------------"
"------------------------";
string spinagain = " Spin again? (y/n) ";
string conditions;
string buyintitle = "Buy in: $", monwon = "Won/Lost: $",
waltitle = "Wallet: $", wintitle = "Wins: ", lostitle = "Losses: ",
betitle = "Bet/line: $", lintitle = "Lines: ",
resultitle = "Spin Result: You lose :(";
string s_or_m, again, spin = "s", menuuu = "m";
string strlines, strbetamt;
int numlines, betamt, amtwon = 0, numloss = 0, paymult, lineswon,
totwon = 0, totlost = 0;
int sq1, sq2, sq3, sq4, sq5, sq6, sq7, sq8, sq9;
double winperc = 20, games = 0, numwin = 0, hundo = 100;

//***************************************************
//*strings to make cherry icon, which will be in red*
//***************************************************
string chernm = "Cherry";
string cherry1 = "   __.--~~.,-.__        ";
string cherry2 = "     `~-._.-(`-.__`-.   ";
string cherry3 = "             \\    `~~`  ";
string cherry4 = "        .--./ \\         ";
string cherry5 = "       /#   \\  \\.--.    ";
string cherry6 = "       \\    /  /#   \\   ";
string cherry7 = "        '--'   \\    /   ";
string cherry8 = "                '--'    ";
//*******************************************************
//*strings to make shamrock icon, which will be in green*
//*******************************************************
string clonm = "Shamrock";
string clover1 = "         .-. .-.        ";
string clover2 = "        (   |   )       ";
string clover3 = "      .-.:  |  ;,-.     ";
string clover4 = "     (_ __`.|.'__ _)    ";
string clover5 = "     (    .'|`.    )    ";
string clover6 = "      `-'/  |  \\`-'     ";
string clover7 = "        (   !   )       ";
string clover8 = "         `-' `-'        ";
//*********************************************************
//*strings to make lightning icon, which will be in yellow*
//*********************************************************
string lightnm = "Lightning";
string lightn1 = "              ,/        ";
string lightn2 = "            ,'/         ";
string lightn3 = "          ,' /          ";
string lightn4 = "        ,'  /_____,     ";
string lightn5 = "      .'____    ,'      ";
string lightn6 = "           /  ,'        ";
string lightn7 = "          / ,'          ";
string lightn8 = "         /,'            ";
//***************************************************
//*strings to make seven icon, which will be in blue*
//***************************************************
string sevnm = "Seven";
string seven1 = "       8888888888       ";
string seven2 = "             d88P       ";
string seven3 = "            d88P        ";
string seven4 = "           d88P         ";
string seven5 = "        88888888        ";
string seven6 = "         d88P           ";
string seven7 = "        d88P            ";
string seven8 = "       d88P             ";
//***************************************************************
//*strings to make money bag icon, which will be in bright white*
//***************************************************************
string moname = "Money";
string money1 = "       \\`\\/\\/\\/`/       ";
string money2 = "        )======(        ";
string money3 = "      .'        '.      ";
string money4 = "     /    _||__   \\     ";
string money5 = "    /    (_||_     \\    ";
string money6 = "   |     __||_)     |   ";
string money7 = "   |       ||       |   ";
string money8 = "   '.--------------.'   ";

//************************************************************
//*strings to make diamond icon, which will be in bright blue*
//************************************************************
string diname = "Diamond";
string diam1 = "      ____________      ";
string diam2 = "   :'/\\/\\/\\''/\\/\\/\\':   ";
string diam3 = " .'. \\/\\/\\/::\\/\\/\\/ .'. ";
string diam4 = " :====:====::====:====: ";
string diam5 = "  '.'  \\  '  '  /  '.'  ";
string diam6 = "    ':  \\:    :/  :'    ";
string diam7 = "      '. \\:  :/ .'      ";
string diam8 = "        '.\\::/.'        ";

//********************************************************************
//*These are basic vectors that will be shuffled to come up with the
//*tiles that show on the slot machine                              
//********************************************************************
vector<string> row1{ chernm,chernm,chernm,
clonm,lightnm,lightnm,lightnm,sevnm,sevnm,sevnm,
moname,moname,moname,diname,diname,diname };
vector<string> row2{ chernm,chernm,chernm,
clonm,lightnm,lightnm,lightnm,sevnm,sevnm,sevnm,
moname,moname,moname,diname,diname,diname };
vector<string> row3{ chernm,chernm,chernm,
clonm,lightnm,lightnm,lightnm,sevnm,sevnm,sevnm,
moname,moname,moname,diname,diname,diname };

//*************************************************************
//*These are arrays that will be used to determine if/how many*
//*lines are won                                              *
//*************************************************************
string top[3];
string mid[3];
string bot[3];
string diag4[3];
string diag5[3];

//**************************************
//*makes tile objects for use on screen*
//**************************************
Tile Cherry(red, chernm, cherry1, cherry2, cherry3, cherry4,
	cherry5, cherry6, cherry7, cherry8);
Tile Shamrock(green, clonm, clover1, clover2, clover3, clover4,
	clover5, clover6, clover7, clover8);
Tile Lightning(yellow, lightnm, lightn1, lightn2, lightn3, lightn4,
	lightn5, lightn6, lightn7, lightn8);
Tile Seven(purple, sevnm, seven1, seven2, seven3, seven4, seven5,
	seven6, seven7, seven8);
Tile Moneybag(brtwht, moname, money1, money2, money3, money4, money5,
	money6, money7, money8);
Tile Diamond(blue, diname, diam1, diam2, diam3, diam4, diam5, diam6,
	diam7, diam8);
Tile tiles[6] = { Cherry, Diamond, Lightning, Moneybag, Seven, Shamrock };
Tile s1, s2, s3, s4, s5, s6, s7, s8, s9;
//**********************************
//*Final screen variables (strings)*
//**********************************
string bye1 = "\t\t\t   ___                    _       ";
string bye2 = "\t\t\t  / _ \\ _ __   __ _  ____(_)  ___ ";
string bye3 = "\t\t\t / /_\\/| '__| / _` ||_  /| | / _ \\";
string bye4 = "\t\t\t/ /_\\\\ | |   | (_| | / / | ||  __/";
string bye5 = "\t\t\t\\____/ |_|    \\__,_|/___||_| \\___|\n";
string bye6 = "\t\t\t                ___               ";
string bye7 = "\t\t\t               / _ \\              ";
string bye8 = "\t\t\t              |  __/              ";
string bye9 = "\t\t\t               \\___|              \n";
string bye10 = "\t\t\t          _                  _    ";
string bye11 = "\t\t\t     ___ (_)  __ _   ___    / \\   ";
string bye12 = "\t\t\t    / __|| | / _` | / _ \\  /  /   ";
string bye13 = "\t\t\t   | (__ | || (_| || (_) |/\\_/    ";
string bye14 = "\t\t\t    \\___||_| \\__,_| \\___/ \\/      \n";
string statitle = "Slot Machine Statistics:";
string gamesplayedtitle = "Games Played:";
string numwontitle = "Games Won:";
string numlostitle = "Games Lost:";
string monwontitle = "Money Won:";
string monlostitle = "Money Lost:";
string cashoutitle = "Cash Out:";

//***********************************
//*Prints header (name, class, date)*
//***********************************
void hdr()
{
	ofs << pipeline << endl << pipe << nameEtc << right
		<< setw(width - pipe.length() - nameEtc.length()) << pipe
		<< endl << pipeline << endl << spacepipe << endl
		<< pipeline << endl;
}

//**************************************************************
//*This simply gets the seed ready for random number generation*
//**************************************************************
unsigned setseed()
{
	seed = time(0);
	return seed;
}

//***********************************************************
//*This function tells us whether or not the input is valid.*
//*It takes a string entered by the user, and 2 ints (first *
//*int is min length the string can be, the second int is   *
//*the max length the string can be). It returns true if    *
//*the input is valid, or false if the input is not valid.  *
//*This function is called pretty much after every instance *
//*of user input.                                           *
//***********************************************************
bool validate(string astring, int least, int most)
{
	if (astring.length() > most)
	{
		return false;
	}
	else if (astring.length() < least)
	{
		return false;
	}
	else
	{
		for (int index = nada; index < astring.length(); index++)
		{
			if (!isdigit(astring.c_str()[index]))
			{
				return false;
			}
		}
	}
	return true;
}

//*******************************************************************
//*This is the start screen. It displays my name, the course number,*
//*the date, and the name of the lab ("Final"). Called from main(). *
//*******************************************************************
void screen1()
{
	SetColor(yellow);
	cout << start1 << endl << start2 << endl << start3 << endl << start4
		<< endl << start5 << endl << start6 << endl << start7 << endl
		<< start7 << endl << sp << endl << start8 << endl << start9
		<< endl << start10 << endl << start11 << endl << start12 << endl
		<< start13 << endl << sp << endl << start14 << endl << start15
		<< endl << start16 << endl << start17 << endl << start18 << endl
		<< start19 << endl << sp << endl << start20 << endl << start21
		<< endl << start22 << endl << start23 << endl << start24 << endl
		<< start25 << endl;
	system("pause");
}

//*********************************************************************
//*This is the menu screen. It very simply displays the menu options: *
//*(1) show rules, (2) wallet, (3) play game, and (4) quit. Called    *
//*from menu().                                                       *
//*********************************************************************
void screen2()
{
	SetColor(yellow);
	cout << menusc1 << endl << menusc2 << endl << menusc3 << endl
		<< menusc4 << endl << menusc5 << endl << menusc6 << endl
		<< menusc7 << endl << menusc8 << endl << menusc9 << endl
		<< menusc10 << endl << menusc11 << endl << menusc12 << endl
		<< menusc13 << endl << menusc14 << endl << menusc15 << endl
		<< menusc16 << endl << menusc17 << endl << menusc18 << endl
		<< menusc19 << endl << menusc20 << endl << menusc21 << endl
		<< menusc22 << endl << menusc23 << endl << menusc24 << endl
		<< menusc25 << endl << menusc26 << endl << menusc27 << endl
		<< menusc28 << endl;
}

//*******************************************************************
//*This screen displays the rules of payout based on number of lines*
//*******************************************************************
void screen3()
{
	SetColor(yellow);
	system("CLS");
	cout << rules1 << endl << rules2 << endl << rules3 << endl
		<< rules4 << endl << rules5 << endl << rules6 << endl
		<< rules7 << endl << rules8 << endl << rules9 << endl
		<< rules10 << endl << rules11 << endl << rules12 << endl
		<< rules13 << endl << rules14 << endl << rules15 << endl
		<< rules16 << endl << rules17 << endl << rules18 << endl
		<< rules19 << endl << rules20 << endl;
	system("pause");
}

//********************************************************************
//*This is the wallet. It shows you how much money you currently have*
//*and asks if you want to add more (if you have room). If you decide*
//*you would like to add more money, it tells you the maximum amount *
//*you can add. To prevent overflow, you cannot choose to add more to*
//*the wallet if there is already >= 1 million dollars in there. If  *
//*more money is added, that amount is added both to the wallet and  *
//*to the buyin amount.                                              *
//********************************************************************
void screen4()
{
	SetColor(yellow);
	system("CLS");
	cout << wallet1 << endl << wallet2 << endl << wallet3 << endl
		<< wallet4 << endl << wallet5 << endl << wallet6 << endl
		<< wallet7 << endl;
	cout << wallet_a << wallet << wallet_b;
	if (wallet >= maxwal)
		cout << wallfull << endl;
	else
	{
		do
		{
			cout << wallet_c;
			cin >> addmoney;
			if (addmoney != yes && addmoney != no)
				cout << errormsg << endl;
		} while (addmoney != yes && addmoney != no);
		if (addmoney == yes)
		{
			do
			{
				cout << howmuch_a << maxwal - wallet << howmuch_b;
				cin >> strmoremoney;
				valid = validate(strmoremoney, one, seven);
				if (valid)
					moremoney = atoi(strmoremoney.c_str());
				if (!valid || (moremoney > (maxwal - wallet)))
					cout << errormsg << endl;
			} while (!valid || (moremoney > (maxwal - wallet)));
			buyin += moremoney;
			wallet += moremoney;
			cout << haveadd_a << moremoney << haveadd_b << endl;
		}
		else
		{
			cout << nomore << endl;
		}
	}
	system("pause");
}

//*****************************************************
//*CONCEPT 4: BUBBLE SORT                             *
//*This sorts whichever string array is the parameter *
//*to make it easier to determine if there was a win  *
//*or not. Basically, it sorts each of these arrays so*
//*into "ascending order" (alphabetical order). It is *
//*called by the "linewin" function. ~~~This function *
//*has 2 variables declared within it, whch are       *
//*specifically related to the sort: a bool for       *
//*swapping purposes, and a string "tempName" to make *
//*sure nothing gets "lost" in the swapping process~~~*
//*****************************************************
void sortArr(string arrname[])						
{
	bool swap;									
	string tempName;							
	do
	{
		swap = false;							
		for (int count = nada; count < two; count++)	
		{
			if (arrname[count] > arrname[count + 1]) 
			{										
				tempName = arrname[count];			
				arrname[count] = arrname[count + 1];
				arrname[count + 1] = tempName;
				swap = true;						
			}
		}
	} while (swap);								
}												

//**********************************************************
//*This sets up the horizontal line arrs according to their* 
//*corresponding vector elements, and also sets up the     *
//*diagonal lines with their corresponding elements from   *
//*the top, middle, and bottom arrays                      *
//**********************************************************
void setuplines()
{
	for (int i = nada; i < three; i++)
	{
		top[i] = row1[i];
		mid[i] = row2[i];
		bot[i] = row3[i];
	}

	diag4[0] = top[0];
	diag4[1] = mid[1];
	diag4[2] = bot[2];
	
	diag5[0] = bot[0];
	diag5[1] = mid[1];
	diag5[2] = top[2];
}

//*********************************************************
//*This bool function takes an array name, calls the sort *
//*function, and then returns true if that particular line*
//*is a winning line - or false if it is not a winner.    *
//*Because clonm ("Shamrock") is the "highest" value, that*
//*is why this algorithm works with a sorted-ascending arr*
//*********************************************************
bool linewin(string arrnm[])
{
	sortArr(arrnm);
	if ((arrnm[0] == arrnm[1] && arrnm[1] == arrnm[2])
		|| (arrnm[0] == arrnm[1] && arrnm[2] == clonm)
		|| (arrnm[1] == arrnm[2] && arrnm[2] == clonm))
	{
		return true;
	}
	else return false;
}


//**************************************************************
//*CONCEPT 2: BINARY SEARCH                                    *
//*This searches for the name of the tile in the array of tiles*
//*by comparing the tilename to the name returned by getname() *
//*member function for the various tiles in the tiles array.   *
//*As is typical in a binary search, the search starts in the  *
//*middle of the array. If the value being searched for has a  *
//*higher value than in the middle element of the array, then  *
//*the next search point splits the difference between its     *
//*current position and the beginning of the array (or the end *
//*of the array if the search value is lower than the value at *
//*the current position). When the search has "zeroed in on"   *
//*the position of the specific tile in the tile array, that   *
//*position is returned as an int value to the proper square in*
//*the "assign" function (below). ~~~Please note that this     *
//*function has 5 variables declared in it, that are specific  *
//*to the binary search. They are ints: first, last, middle,   *
//*and position - which will all be locations in the array -   *
//*and the bool found, which will help keep moving through the *
//*array until such time as the string in question is actually *
//*found in the tile array.~~~                                 *
//**************************************************************
int binarysearch(string tilename, Tile arr[])
{
	int first = nada, last = five, middle, position = neg;
	bool found = false;

	while (!found && first <= last)
	{
		middle = (first + last) / 2;
		if (arr[middle].getname() == tilename)
		{
			found = true;
			position = middle;
		}
		else if (arr[middle].getname() > tilename)
			last = middle - one;
		else
			first = middle + one;
	}
	return position;
}

//****************************************************************
//*This assigns the position of the proper tile in the tiles     *
//*array to the "sq" value which will be printed out on the      *
//*screen, by calling binary search. For example, whatever tile  *
//*name is listed in the 2nd element of column 1 will be searched*
//*for in the tiles array, and the position in which the tile    *
//*name is found will be assigned to sq1 (which will be the top  *
//*left corner of the playing grid). After each sq gets its      *
//*position, a square is assigned to the tile itself at that     *
//*position of the tiles array.                                  *
//****************************************************************
void assignsquares()
{
	sq1 = binarysearch(row1[0], tiles);
	s1 = tiles[sq1];
	sq2 = binarysearch(row1[1], tiles);
	s2 = tiles[sq2];
	sq3 = binarysearch(row1[2], tiles);
	s3 = tiles[sq3];
	sq4 = binarysearch(row2[0], tiles);
	s4 = tiles[sq4];
	sq5 = binarysearch(row2[1], tiles);
	s5 = tiles[sq5];
	sq6 = binarysearch(row2[2], tiles);
	s6 = tiles[sq6];
	sq7 = binarysearch(row3[0], tiles);
	s7 = tiles[sq7];
	sq8 = binarysearch(row3[1], tiles);
	s8 = tiles[sq8];
	sq9 = binarysearch(row3[2], tiles);
	s9 = tiles[sq9];
}

//***************************************************************
//*This function starts by calling the setuplines function, then*
//*checks each line for a win (each line calls the bool linewin *
//*function with the respective array of interest). The function*
//*then enters a case switch that uses the number of lines      *
//*that the player has chosen to play, in order to determine    *
//*whether the player won the spin (returned as a bool to the   *
//*screen5().)                                                  *
//*For case 1, the pay multiplier is 1, and only line 1 is      *
//*looked at: either it has one line won or 0 lines won.        *
//*For case 3, the pay multiplier is 2, and lines 1, 2, & 3 are *
//*looked at - lines won = 3, 2, 1, or 0.                       *
//*For case 5, the pay multiplier is 3, and lines 1, 2, 3, 4, & *
//*5 are looked at - lines won = 5, 4, 3, 2, 1, or 0.           *
//*In any case, 0 lines won will return false - but any other   *
//*will return true.
//***************************************************************
bool didwin()
{
	setuplines();
	l1 = linewin(mid);
	l2 = linewin(top);
	l3 = linewin(bot);
	l4 = linewin(diag4);
	l5 = linewin(diag5);
	switch (numlines)
	{
	case one:
		paymult = 1;
		if (l1)
		{
			lineswon = 1;
			return true;
		}
		else if (!l1)
		{
			lineswon = 0;
			return false;
		}
		break;
	case three:
		paymult = 2;
		if (l1 && l2 && l3)
		{
			lineswon = 3;
			return true;
		}
		else if ((l1 && l2) || (l1 && l3) || (l2 && l3))
		{
			lineswon = 2;
			return true;
		}
		else if (l1 || l2 || l3)
		{
			lineswon = 1;
			return true;
		}
		else if (!l1 && !l2 && !l3)
		{
			lineswon = 0;
			return false;
		}
		break;
	case five:
		paymult = 3;
		if (l1 && l2 && l3 && l4 && l5)
		{
			lineswon = 5;
			return true;
		}
		else if ((l1 && l2 && l3 && l4) || (l1 && l2 && l3 && l5)
			|| (l1 && l2 && l4 && l5) || (l1 && l3 && l4 && l5)
			|| (l2 && l3 && l4 && l5))
		{
			lineswon = 4;
			return true;
		}
		else if ((l1 && l2 && l3) || (l1 && l2 && l4) || (l1 && l2 && l5)
			|| (l1 && l3 && l4) || (l1 && l3 && l5) || (l1 && l4 && l5)
			|| (l2 && l3 && l4) || (l2 && l3 && l5) || (l2 && l4 && l5)
			|| (l3 && l4 && l5))
		{
			lineswon = 3;
			return true;
		}
		else if ((l1 && l2) || (l1 && l3) || (l1 && l4)
			|| (l1 && l5) || (l2 && l3) || (l2 && l4) ||
			(l2 && l5) || (l3 && l4) || (l3 && l5) || (l4 && l5))
		{
			lineswon = 2;
			return true;
		}
		else if (l1 || l2 || l3 || l4 || l5)
		{
			lineswon = 1;
			return true;
		}
		else if (!l1 && !l2 && !l3 && !l4 && !l5)
		{
			lineswon = 0;
			return false;
		}
		break;
	default:
		cout << errormsg << endl;
		break;
	}
}

//*****************************************************************************
//*This is the picture of the slot machine. Basically, based on the assgnments*
//*for each s assigned earlier, the printline() and getline() tile member     *
//*fuctions are called so we can get a visual representation of the various   *
//*icons in their respective positions. The player stats are also listed on   *
//*the screen.                                                                *
//*****************************************************************************
void slot()
{
	cout << buyintitle << buyin << setw(boxwid - buyintitle.length() - to_string(buyin).length() +7) << sp << monwon
		<< amtwon << setw(2*boxwid - monwon.length() - to_string(amtwon).length()-7 - waltitle.length() - to_string(wallet).length()) << sp << waltitle << wallet
		<< endl << setw(boxwid) << wintitle << numwin << setw(boxwid-1) << sp << lostitle
		<< numloss << endl;
	
	cout << bt_rows << endl << pipe;
	s1.prntln(s1.gtln1()); s2.prntln(s2.gtln1()); s3.prntln(s3.gtln1());
	cout << endl << pipe;
	s1.prntln(s1.gtln2()); s2.prntln(s2.gtln2()); s3.prntln(s3.gtln2());
	cout << endl << pipe;
	s1.prntln(s1.gtln3()); s2.prntln(s2.gtln3()); s3.prntln(s3.gtln3());
	cout << endl << pipe;
	s1.prntln(s1.gtln4()); s2.prntln(s2.gtln4()); s3.prntln(s3.gtln4());
	cout << endl << pipe;
	s1.prntln(s1.gtln5()); s2.prntln(s2.gtln5()); s3.prntln(s3.gtln5());
	cout << endl << pipe;
	s1.prntln(s1.gtln6()); s2.prntln(s2.gtln6()); s3.prntln(s3.gtln6());
	cout << endl << pipe;
	s1.prntln(s1.gtln7()); s2.prntln(s2.gtln7()); s3.prntln(s3.gtln7());
	cout << endl << pipe;
	s1.prntln(s1.gtln8()); s2.prntln(s2.gtln8()); s3.prntln(s3.gtln8());
	
	cout << endl << bt_rows << endl << pipe;
	s4.prntln(s4.gtln1()); s5.prntln(s5.gtln1()); s6.prntln(s6.gtln1());
	cout << endl << pipe;
	s4.prntln(s4.gtln2()); s5.prntln(s5.gtln2()); s6.prntln(s6.gtln2());
	cout << endl << pipe;
	s4.prntln(s4.gtln3()); s5.prntln(s5.gtln3()); s6.prntln(s6.gtln3());
	cout << endl << pipe;
	s4.prntln(s4.gtln4()); s5.prntln(s5.gtln4()); s6.prntln(s6.gtln4());
	cout << endl << pipe;
	s4.prntln(s4.gtln5()); s5.prntln(s5.gtln5()); s6.prntln(s6.gtln5());
	cout << endl << pipe;
	s4.prntln(s4.gtln6()); s5.prntln(s5.gtln6()); s6.prntln(s6.gtln6());
	cout << endl << pipe;
	s4.prntln(s4.gtln7()); s5.prntln(s5.gtln7()); s6.prntln(s6.gtln7());
	cout << endl << pipe;
	s4.prntln(s4.gtln8()); s5.prntln(s5.gtln8()); s6.prntln(s6.gtln8());
	
	cout << endl << bt_rows << endl << pipe;
	s7.prntln(s7.gtln1()); s8.prntln(s8.gtln1()); s9.prntln(s9.gtln1());
	cout << endl << pipe;
	s7.prntln(s7.gtln2()); s8.prntln(s8.gtln2()); s9.prntln(s9.gtln2());
	cout << endl << pipe;
	s7.prntln(s7.gtln3()); s8.prntln(s8.gtln3()); s9.prntln(s9.gtln3());
	cout << endl << pipe;
	s7.prntln(s7.gtln4()); s8.prntln(s8.gtln4()); s9.prntln(s9.gtln4());
	cout << endl << pipe;
	s7.prntln(s7.gtln5()); s8.prntln(s8.gtln5()); s9.prntln(s9.gtln5());
	cout << endl << pipe;
	s7.prntln(s7.gtln6()); s8.prntln(s8.gtln6()); s9.prntln(s9.gtln6());
	cout << endl << pipe;
	s7.prntln(s7.gtln7()); s8.prntln(s8.gtln7()); s9.prntln(s9.gtln7());
	cout << endl << pipe;
	s7.prntln(s7.gtln8()); s8.prntln(s8.gtln8()); s9.prntln(s9.gtln8());
	cout << endl << bt_rows << endl;

	cout << setw(boxwid+3) << betitle << betamt
		<< setw(boxwid - lintitle.length()-to_string(betamt).length()-1) 
		<< sp << lintitle << numlines << endl;
}


//*******************************************************************
//*CONCEPT #3: RANDOM SHUFFLE                                       *
//*The stl command random_shuffle will be used on the row1, row2,   *
//*and row3 vectors (which contain tile names), in order to randomly*
//*"decide" which icons will go in which positions on the play      *
//*screen - by literally just shuffling the contents of each of the *
//*aforementioned vectors.                                          *
//*This is the function for screen 5, which is the play screen. It  *
//*starts by randomly shuffling each of the row vectors, calling the*
//*assign() and slot() functions to get the proper picture, and then*
//*entering a do/while loop which asks how many lines the player    *
//*would like to play, then asks how much they would like to bet,   *
//*then if they want to play vs. return to the menu. If they would  *
//*1 is added to games, and then another do/while loop is entered to*
//*shuffle the columns again, assign, determine if it is a win - and*
//*as long as the running win percentage is lower than the          *
//*designated win percentage at the top of the program,
//*will keep doing that until there's a win. After exiting the loop,*
//*the slot machine picture is displayed again and, a win vs loss is*
//*displayed, the gained/lost is calculated, along with the number  *
//*of wins or losses incremented, and the user is asked if they'd   *
//*like to play again.                                              *
//*(If yes, then it goes back to the beginning of the outer do/while*
//*loop). However, if the user had entered m for menu, they'd simply*
//*break out and return to the menu.                                *
//*******************************************************************
void screen5()
{
	SetColor(yellow);
	system("CLS");
	random_shuffle(row1.begin(), row1.end());
	random_shuffle(row2.begin(), row2.end());
	random_shuffle(row3.begin(), row3.end());
	assignsquares();
	slot();
	do
	{
		
		do
		{
			cout << howmany;
			cin >> strlines;
			valid = validate(strlines, one, one);
			if (valid)
				numlines = atoi(strlines.c_str());
			if (!valid || numlines < one ||numlines > five || numlines == two || numlines ==four)
				cout << errormsg << endl;
		} while (!valid || numlines < one || numlines > five || numlines == two || numlines == four);
		do
		{
			cout << howbet_a << wallet/numlines << howbet_b;
			cin >> strbetamt;
			valid = validate(strbetamt, one, seven);
			if (valid)
				betamt = atoi(strbetamt.c_str());
			if (!valid || betamt < nada || betamt * numlines > wallet)
				cout << errormsg << endl;
		} while (!valid || betamt < nada || betamt * numlines > wallet);
		do
		{
			cout << spinormenu;
			cin >> s_or_m;
			if (s_or_m != spin && s_or_m != menuuu)
				cout << errormsg << endl;
		} while (s_or_m != spin && s_or_m != menuuu);
		if (s_or_m == spin)
		{
			games++;
			do
			{
				random_shuffle(row1.begin(), row1.end());
				random_shuffle(row2.begin(), row2.end());
				random_shuffle(row3.begin(), row3.end());
				assignsquares();
				won = didwin();
			} while (!won && (numwin < (winperc/hundo * games)));
			if (won)
			{
				numwin++;
				amtwon = betamt*lineswon*(paymult+1);
				wallet += amtwon - betamt*numlines;
				totwon += amtwon;
			}
			else
			{
				numloss++;
				amtwon = neg*betamt*numlines;
				wallet += amtwon;
				totlost += neg*amtwon;
			}
			system("CLS");
			slot();
			if (won) conditions = "You win!!!";
			else conditions = "You lose :(";
			cout << conditions;
			do
			{
				cout << spinagain;
				cin >> again;
				if (again != yes && again != no)
					cout << errormsg << endl;
			} while (again != yes && again != no);
		}
		else if (s_or_m == menuuu)
			break;
	} while (again == yes);
	system("pause");
}

//******************************************************************
//*This is the farewell screen. It says "Thanks & bye!" in Italian.*
//*It is called from case EXIT on screen2.                         *
//******************************************************************
void screen6()
{
	SetColor(yellow);
	system("CLS");
	cout << bye1 << endl << bye2 << endl << bye3 << endl << bye4
		<< endl << bye5 << endl << bye6 << endl << bye7 << endl
		<< bye8 << endl << bye9 << endl << bye10 << endl << bye11
		<< endl << bye12 << endl << bye13 << endl << bye14 << endl;
}

//****************************************
//*This prints out the stats to the file.*
//****************************************
void stats()
{
	ofs << left << pipe << setw(width - 2) << statitle << pipe << endl;
	ofs << pipe << setw(statitle.length() + 2) << gamesplayedtitle << right << setw(numwid) << games 
		<< setw(width -statitle.length()-numwid -3) <<  pipe << endl;
	ofs << pipe << left << setw(statitle.length() +2) << numwontitle << right << setw(numwid) << numwin 
		<< setw(width - statitle.length() - numwid - 3) << pipe << endl;
	ofs << pipe << left << setw(statitle.length() +2) << numlostitle << right << setw(numwid) << numloss 
		<< setw(width - statitle.length() - numwid - 3) << pipe << endl;
	ofs << spacepipe << endl << pipe << left << setw(statitle.length()+1)<< monwontitle << dol
		<< right << setw(numwid) << totwon << setw(width - statitle.length() - numwid - 3)
		<< pipe << endl;
	ofs << pipe << left << setw(statitle.length() +1) << monlostitle << dol << right << setw(numwid) << totlost
		<< setw(width - statitle.length() - numwid - 3) << pipe << endl;
	ofs << pipe << left << setw(statitle.length() +1) << cashoutitle << dol << right << setw(numwid) << wallet 
		<< setw (width - statitle.length() - numwid - 3) << pipe << endl;
}

//******************************************************************
//*CONCEPT #1: RECURSION                                           *
//*Recursion will be used within the menu instead of "traditional" *
//*looping. When the menu screen is reached, the menu will be shown*
//*and the user will be prompted to enter a menu option, after     *
//*which point the program will enter a case-switch. Within this,  *
//*the end of each case will instead recursively call the menu     *
//*function, so the user can enter their next menu choice - with   *
//*the exception of the "EXIT" option (menu option #4). (Note, this*
//*means that the break statements will usually not be reached with*
//*exception to the one in the EXIT case, but I needed to leave    *
//*them because if I took them out, the wrong screens were called  *
//*when "EXIT" was entered.)                                       *
//*The menu options in the case-switch are (1) to display the      *
//*rules, (2) to call the wallet, (3) to play the game, (4) to exit*
//*the program, and default to display an error message asking for *
//*a new (valid) menu option to be entered.                        *
//******************************************************************
void menu()
{
	system("CLS");
	screen2();
	do
	{
		cout << pleasepick;
		cin >> selection;
		valid = validate(selection, one, one);
		if (!valid)
			cout << errormsg << endl;
	} while (!valid);
	choice = atoi(selection.c_str());
	switch (choice)
	{
	case RULES:
		screen3();
		menu();
		break;
	case WALLET:
		screen4();
		menu();
		break;
	case PLAY:
		screen5();
		menu();
		break;
	case EXIT:
		screen6();
		stats();
		break;
	default:
		cout << errormsg << endl;
		system("pause");
		menu();
		break;
	}
}


//***************************************************
//*Prints footer: A summary of what was printed out.*
//***************************************************
void ftr()
{
	ofs << spacepipe << endl << pipeline << endl << pipe
		<< foot1 << right << setw(width - pipe.length() - foot1.length())
		<< pipe << endl << pipe << foot2
		<< setw(width - pipe.length() - foot2.length()) << pipe << endl
		<< pipe << foot3 << setw(width - pipe.length() - foot3.length())
		<< pipe << endl << pipeline << endl << spacepipe << endl;
}

//******************************************************************
//*Prints EOF message: "EOF Message" plus restating info in header.*
//******************************************************************
void eof()
{
	ofs << pipeline << endl << pipe << eofMsg << nameEtc << right
		<< setw(width - pipe.length() - eofMsg.length() - nameEtc.length())
		<< pipe << endl << pipeline << endl;
}

//*********************************************************************
//*Calls a variety of other functions (header, screen1/welcome,       *
//*setseed(), srand(seed),
//*screen2/menu, screen5/farewell, footer, & EOF message), and closes *
//*output file. Screens 2-6 aren't called from main, but from menu(). *
//*********************************************************************
int main()
{
	hdr();
	setseed();
	srand(seed);
	screen1();
	menu();
	ftr();
	eof();
	ofs.close();
	return 0;
}