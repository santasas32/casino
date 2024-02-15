#include <iostream>
#include <cstdlib>
#include <string>
#include "windows.h"
#include <Windows.h>
#define _CRT_SECURE_NO_WARNINGS

using namespace std;
string username;
string cards[52];
int money;//счёт пользователя


void roulette() {
	srand(time(0));//тру рандом
	string numbers[]{ "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "even", "odd" };
	int bet;
	string choise;
	system("cls");
	cout << "$$                    $$  $$$$$$$$$$$$  $$          $$               $$$$$       $$$$       $$          $$  $$$$$$$$$$$$\n"
			" $$                  $$   $$            $$          $$            $$$$        $$$    $$$    $$$$      $$$$  $$          \n"
			"  $$                $$    $$            $$          $$           $$         $$$        $$$  $$  $$  $$  $$  $$          \n"
			"   $$      $$      $$     $$$$$$$$$$$$  $$          $$          $$          $$          $$  $$    $$    $$  $$$$$$$$$$$$\n"
			"    $$    $$$$    $$      $$$$$$$$$$$$  $$          $$          $$          $$          $$  $$          $$  $$$$$$$$$$$$\n"
			"     $$  $$  $$  $$       $$            $$          $$           $$         $$$        $$$  $$          $$  $$          \n"
			"      $$$$    $$$$        $$            $$          $$            $$$$        $$$    $$$    $$          $$  $$          \n"
			"       $$      $$         $$$$$$$$$$$$  $$$$$$$$$$  $$$$$$$$$$       $$$$$       $$$$       $$          $$  $$$$$$$$$$$$\n\n\n";
	
	cout << "\t\t\t\t$$$$$   $$$$  $   $ $    $$$$$  $$$$$ $$$$$ $$$$$\n"
			"\t\t\t\t$    $ $    $ $   $ $    $        $     $   $    \n"
			"\t\t\t\t$$$$$  $    $ $   $ $    $$$$$    $     $   $$$$$\n"
			"\t\t\t\t$   $  $    $ $   $ $    $        $     $   $    \n"
			"\t\t\t\t$    $  $$$$   $$$  $$$$ $$$$$    $     $   $$$$$\n\n\n";

	cout << "Rules: \n"
		"\tTo win, you need to guess the number(0-9) that will fall out\n"
		"\tYou can put on a specific number and win double of your bet.\n"
		"\tYou can choose even or odd number and win your bet.\n"
		"\n\nWrite your bet and number or even/odd.\n";
	while (true)
	{
		string strbet, strchoise;
		cout << "bet = ";
		cin >> strbet;
		cout << "\nchoise = ";
		cin	>> choise;
		bet = stoi(strbet);
		

		if (bet <= money) {
			for (int i = 0; i < 12; i++) {
				if (numbers[i] == choise) {
					break;
				}
			}
			break;
		}
		else {
			cout << "\nNot enough money\n";
		}
	}
	int k = 0;//счётчик для цикла
	int randnum;
	string randnumstr;
	system("cls");
	while (k < 10)
	{
		randnum = rand() % 10;
		randnumstr = to_string(randnum);
		string randcurs[] = { " ", " ", " ", " "," "," "," "," "," "," ", "|" };
		cout << "|";
		for (int i = 0; i < 11; i++) {
			if (i == randnum) {
				cout << "|";
			}
			else {
				cout << randcurs[i];
			}
		}
		cout <<
			"\n ----------\n"
			" 0123456789\n";
		k++;
		Sleep(200);
		if (k < 10) { system("cls"); }
	}

	if (choise == "even" || choise == "odd") {
		if (choise == "even" && randnum % 2 == 0) {
			cout << "\nWin\n";
			money += bet;
		}
		else if (choise == "even" && randnum % 2 != 0) {
			cout << "\nLose\n";
			money -= bet;
			cout << "Win number is " << randnum << "\n";
		}
		else if (choise == "odd" && randnum % 2 != 0) {
			cout << "\nWin\n";
			money += bet;
		}
		else if (choise == "odd" && randnum % 2 == 0) {
			cout << "\nLose\n";
			money -= bet;
			cout << "Win number is " << randnum << "\n";
		}
	}
	else {
		if (randnumstr == choise) {
			cout << "\nWOW! You win\n";
			money += 2*bet;
		}
		else {
			cout << "\nYou lose\n";
			money -= 2*bet;
			cout << "Win number is " << randnum << "\n";
		}
	}
	system("PAUSE");
	system("cls");
	cout << "\nYour balanse: " << money << "$\n";
}

void cardsinit() {
	int rank[] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13 };
	int suit[] = { 0,1,2,3 };//0 - pika 1 - cherva 2 - kresti 3 - buba
	int i = 0;
	for (int rank = 1; rank <= 13; rank++) {
		for (int suit = 0; suit <= 3; suit++) {
			i++;
			string strrank = to_string(rank);
			string strsuit = to_string(suit);
			cards[i] = strrank + strsuit;
		}
	}
}

int dealercards() {
	srand(time(0));
	int cardrank, cardsuit, dealerCardSum = 0, bet;
	system("cls");
	cardsinit();
	cout << "Dealer cards: ";
	restart:
	while (true) {
		int randcard = rand() % 53 + 1;
		cardrank = stoi(cards[randcard]) / 10;
		cardsuit = stoi(cards[randcard]) % 10;
		cout << "[";
		switch (cardrank)
		{
		case 0: goto restart;
		case 1: cout << "Ace"; break;
		case 2: cout << "2"; break;
		case 3: cout << "3"; break;
		case 4: cout << "4"; break;
		case 5: cout << "5"; break;
		case 6: cout << "6"; break;
		case 7: cout << "7"; break;
		case 8: cout << "8"; break;
		case 9: cout << "9"; break;
		case 10: cout << "10"; break;
		case 11: cout << "Jack"; break;
		case 12: cout << "Qween"; break;
		case 13: cout << "King"; break;
		default: break;
		}
		switch (cardsuit)
		{
		case 0: cout << " Spades"; break;
		case 1: cout << " Hearts"; break;
		case 2: cout << " Clubs"; break;
		case 3: cout << " Diamonds"; break;
		default: break;
		}
		cout << "], ";
		dealerCardSum += cardrank;
		if (dealerCardSum > 21) {
			cout << "Sum: " << dealerCardSum;
			dealerCardSum = 0;
			break;
		}
		if (dealerCardSum >= 17) {
			cout << "Sum: " << dealerCardSum;
			break;
		}
	}
	return dealerCardSum;
}

int playercards() {
	string choise;
	//srand(time(0));
	int cardrank, cardsuit, playerCardSum = 0, bet;
	cout << "\nPlayer cards: ";
	restart:
	while (true) {
		int randcard = rand() % 53 + 1;
		cardrank = stoi(cards[randcard]) / 10;
		cardsuit = stoi(cards[randcard]) % 10;
		cout << "[";
		switch (cardrank)
		{
		case 0: goto restart;
		case 1: cout << "Ace"; break;
		case 2: cout << "2"; break;
		case 3: cout << "3"; break;
		case 4: cout << "4"; break;
		case 5: cout << "5"; break;
		case 6: cout << "6"; break;
		case 7: cout << "7"; break;
		case 8: cout << "8"; break;
		case 9: cout << "9"; break;
		case 10: cout << "10"; break;
		case 11: cout << "Jack"; break;
		case 12: cout << "Qween"; break;
		case 13: cout << "King"; break;
		default: break;
		}
		switch (cardsuit)
		{
		case 0: cout << " Spades"; break;
		case 1: cout << " Hearts"; break;
		case 2: cout << " Clubs"; break;
		case 3: cout << " Diamonds"; break;
		default: break;
		}
		playerCardSum += cardrank;
		if (playerCardSum > 21) {
			cout << "], Sum: " << playerCardSum;
			playerCardSum = 0;
			break;
		}
		cout << "], Sum = " << playerCardSum;
		cout << "\nDo you want more card? (y/n)\n";
		cin >> choise;
		if (choise == "n") {
			cout << "Sum: " << playerCardSum;
			break;
		}
	}
	return playerCardSum;
}

void bjgame() {
	int dealerCardSum, playerCardSum, bet;
	{
		cout << "$$                    $$  $$$$$$$$$$$$  $$          $$               $$$$$       $$$$       $$          $$  $$$$$$$$$$$$\n"
			" $$                  $$   $$            $$          $$            $$$$        $$$    $$$    $$$$      $$$$  $$          \n"
			"  $$                $$    $$            $$          $$           $$         $$$        $$$  $$  $$  $$  $$  $$          \n"
			"   $$      $$      $$     $$$$$$$$$$$$  $$          $$          $$          $$          $$  $$    $$    $$  $$$$$$$$$$$$\n"
			"    $$    $$$$    $$      $$$$$$$$$$$$  $$          $$          $$          $$          $$  $$          $$  $$$$$$$$$$$$\n"
			"     $$  $$  $$  $$       $$            $$          $$           $$         $$$        $$$  $$          $$  $$          \n"
			"      $$$$    $$$$        $$            $$          $$            $$$$        $$$    $$$    $$          $$  $$          \n"
			"       $$      $$         $$$$$$$$$$$$  $$$$$$$$$$  $$$$$$$$$$       $$$$$       $$$$       $$          $$  $$$$$$$$$$$$\n\n\n";

		cout << "\t\t\t\t$$$$  $       $     $$$$ $  $     $$$$    $     $$$$ $  $\n"
			"\t\t\t\t$   $ $      $ $   $     $ $         $   $ $   $     $ $ \n"
			"\t\t\t\t$$$$  $     $   $  $     $$          $  $   $  $     $$  \n"
			"\t\t\t\t$   $ $    $$$$$$$ $     $ $    $$  $$ $$$$$$$ $     $ $ \n"
			"\t\t\t\t$$$$  $$$$ $     $  $$$$ $  $    $$$$  $     $  $$$$ $  $\n\n\n";

		cout << "Rules: \n";
		cout << "\t1. You have to draw the cards one by one. \n\t   The winner is the one who scored the most points, but did not exceed 21\n"
			"\t2. Card values: \n\t Ace - 1\n\t 2 - 2 \n\t 3 - 3 \n\t 4 - 4 \n\t 5 - 5 \n\t 6 - 6\n\t 7 - 7\n\t 8 - 8\n\t 9 - 9\n\t 10 - 10\n\t Jack - 10 \n\t Qween - 10 \n\t King - 10\n";

	}
	cout << "Your bet: ";
	cin >> bet;
	cardsinit();
	dealerCardSum = dealercards();
	playerCardSum = playercards();
	if (playerCardSum > dealerCardSum) { cout << "\nWin!\n"; money += bet; }
	else if (playerCardSum < dealerCardSum) { cout << "\nLose(\n"; money -= bet; }
	else { cout << "\nDraw\n"; money = money; }
	cout << "You balance: " << money << "$\n";
}


int menu() {
	int choise;
	cout << username << ", what game do you want to play?\n";
	while (1) {
		if (money <= 0) {
			cout << "\n Unluck( \n";
			return (0);
		}
		cout << "\t\t\t-------------------------------------\n"
			"\t\t\t| 1. Roulette                       |\n"
			"\t\t\t| 2. Black Jack(in development)     |\n"   // choise form
			"\t\t\t| 3. Exit                           |\n"
			"\t\t\t-------------------------------------\n";

		string strchoise;
		cin >> strchoise;
		choise = stoi(strchoise);
		switch (choise)
		{
		case 1: roulette(); break;
		case 2: bjgame(); break;
		case 3: cout << "\nSee you soon"; return(0); break;
		default:cout << "Unknown command \n"; system("PAUSE"); system("cls");
		}
	}

}

int main() {
	cout << "\t\t\t            $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n"
			"\t\t\t           $  wellcome to the c++ casino   $\n"
			"\t\t\t            $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n\n"
			"\t\t\t		   $$$$$$$$$$$$$$$$$\n"
			"\t\t\t		   $ ---           $\n"
			"\t\t\t		   $  |            $\n"
			"\t\t\t		   $	 $$  $$    $\n"
			"\t\t\t		   $	$  $$  $   $\n"
			"\t\t\t		   $	 $    $    $\n"
			"\t\t\t		   $      $  $     $\n"
			"\t\t\t		   $       $$      $\n"
			"\t\t\t		   $           --- $\n"
			"\t\t\t		   $            |  $\n"
			"\t\t\t		   $$$$$$$$$$$$$$$$$\n\n\n";

	cout << "Whats you name? \n";
	cin >> username;
	cout << "\nOK. How much are you ready to lose today?\n$ ";
	while (true) {
		string strmoney;
		cin >> strmoney;
		money = stoi(strmoney);
		if (money > 0) {
			break;
		}
		else { 
			cout << "Nice joke, but our casino is very serios. I'm patient. let's try again.\n";
			cout << "Enter the money for the game: \n$ ";
		}
	}
	cout << "\nOK, " << username << "\n";
	cout << "You have " << money << "$ on your play wallet\n";
	system("PAUSE");
	system("CLS");
	cout << "OK. lets play!\n";
	menu();
}
