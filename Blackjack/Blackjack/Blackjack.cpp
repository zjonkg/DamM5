#include <time.h>
#include <windows.h>
#include <iostream>
#include <locale>
#include <string>
#include <vector>

using namespace std;

void printTitle() {

	wcout << L"   ══════════════════════════════════════════════════════════════════════════════════════════════════════════════╗" << endl;
	wcout << L"   ╚█████╗░╚█████╗░ ╚█████╗░╚█████╗░╚█████╗░╚█████╗░╚█████╗░╚█████╗░╚█████╗░╚█████╗░╚█████╗░╚█████╗░╚█████╗░╚█████╗░ " << endl;
	wcout << L"   ██████╗░██████╗░ ██████╗░██████╗░██████╗░██████╗░██████╗░██████╗░██████╗░██████╗░██████╗░██████╗░██████╗░██████╗░" << endl;
	wcout << L"   ░╚═══██╗░╚═══██╗ ░╚═══██╗░╚═══██╗░╚═══██╗░╚═══██╗░╚═══██╗░╚═══██╗░╚═══██╗░╚═══██╗░╚═══██╗░╚═══██╗░╚═══██╗░╚═══██╗" << endl;
	wcout << L"   ╚█████╗░                                                                                                 ╚█████╗░  " << endl;
	wcout << L"   ░╚═══██╗                                                                                                 ░╚═══██╗ " << endl;
	wcout << L"   ██╔════╝    " << L"\033[1;94m       ██████╗░██╗░░░░░░█████╗░░█████╗░██╗░░██╗░░░░░██╗░█████╗░░█████╗░██╗░░██╗" << L" \033[0m            ██╔════╝" << endl;
	wcout << L"   ╚█████╗░    " << L"\033[1;94m       ██╔══██╗██║░░░░░██╔══██╗██╔══██╗██║░██╔╝░░░░░██║██╔══██╗██╔══██╗██║░██╔╝" << L"\033[0m            ╚█████╗░   " << endl;
	wcout << L"   ██████╗░    " << L"\033[1;94m       ██████╦╝██║░░░░░███████║██║░░╚═╝█████═╝░░░░░░██║███████║██║░░╚═╝█████═╝░" << L"\033[0m              ██████╗░   " << endl;
	wcout << L"   ░╚═══██╗    " << L"\033[1;94m       ██╔══██╗██║░░░░░██╔══██║██║░░██╗██╔═██╗░██╗░░██║██╔══██║██║░░██╗██╔═██╗░" << L"\033[0m             ░╚═══██╗   " << endl;
	wcout << L"   ╚══████╗░   " << L"\033[1;94m       ██████╦╝███████╗██║░░██║╚█████╔╝██║░╚██╗╚█████╔╝██║░░██║╚█████╔╝██║░╚██╗" << L"\033[0m            ╚══████╗░  " << endl;
	wcout << L"   █████══╝░   " << L"\033[1;94m       ╚═════╝░╚══════╝╚═╝░░╚═╝░╚════╝░╚═╝░░╚═╝░╚════╝░╚═╝░░╚═╝░╚════╝░╚═╝░░╚═╝ " << L"\033[0m           █████══╝░  " << endl;
	cout << "\033[0m";  // Reset de color
	wcout << L"   ╚█████╗░                                                                                                 ╚█████╗░" << endl;
	wcout << L"   ░╚═══██╗                                                                                                 ░╚═══██╗" << endl;
	wcout << L"   ╔═════╝██╔════╝ ██╔════╝██╔════╝██╔════╝██╔════╝██╔════╝██╔════╝██╔════╝██╔════╝██╔════╝██╔════╝██╔════╝██╔════╝" << endl;
	wcout << L"   ╚█████╗░╚█████╗░ ╚█████╗░╚█████╗░╚█████╗░╚█████╗░╚█████╗░╚█████╗░╚█████╗░╚█████╗░╚█████╗░╚█████╗░╚█████╗░╚█████╗░ " << endl;
	wcout << L"   ██████╗░██████╗░ ██████╗░██████╗░██████╗░██████╗░██████╗░██████╗░██████╗░██████╗░██████╗░██████╗░██████╗░██████╗░" << endl;
	wcout << L"   ░╚═══██╗░╚═══██╗ ░╚═══██╗░╚═══██╗░╚═══██╗░╚═══██╗░╚═══██╗░╚═══██╗░╚═══██╗░╚═══██╗░╚═══██╗░╚═══██╗░╚═══██╗░╚═══██╗" << endl;

	cout << endl;
	cout << endl;
}

wstring getCardSymbol(int typeOfCard) {
	switch (typeOfCard) {
	case 0:
		return L"\033[1;31m♥";
	case 1:
		return L"\033[1;31m♦";
	case 2:
		return L"♣";
	case 3:
		return L"♠";
	default:
		return L"Invalid Type";
	}
}

void printCard(int typeOfCard, string givenCard) {
	wstring blankSpace = L"                                               ";
	wstring card(givenCard.begin(), givenCard.end());
	wstring symbolCard = getCardSymbol(typeOfCard);

	card.resize(2, L' ');

	wcout << blankSpace << L"┌──────────┐" << endl;
	wcout << blankSpace << L"│" << card << L"        │" << endl;
	wcout << blankSpace << L"│          │" << endl;
	wcout << blankSpace << L"│          │" << endl;
	wcout << blankSpace << L"│    " << symbolCard << L"\033[0m     │" << endl;
	wcout << blankSpace << L"│          │" << endl;
	wcout << blankSpace << L"│          │" << endl;
	wcout << blankSpace << L"│        " << card << L"│" << endl;
	wcout << blankSpace << L"└──────────┘" << endl;
	;
}

void initializeCards(vector<string>& cards) { 
	cards = { "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K" }; 
}

int randTypeOfCard(int max) {
	int num;
	num = rand() % max;
	return num;
}

int changeToRealValue(string cardGiven, int validate) {
	if (validate == 1) {
		if (cardGiven == "A") {
			char option;


			do {
				cout << "Which value do you want?" << endl;
				cout << "Y- 11" << endl;
				cout << "N- 1" << endl;

				cin >> option;

				option = toupper(option);

				switch (option) {
				case 'Y':
					return 11;
				case 'N':
					return 1;
				}
			} while (true);
		}
		else if (cardGiven == "J" || cardGiven == "Q" || cardGiven == "K") {
			return 10;
		}
		else {
			return stoi(cardGiven);
		}
	}
	else {
		if (cardGiven == "A")
			return 11;
		else if (cardGiven == "J" || cardGiven == "Q" || cardGiven == "K") {
			return 10;
		}
		else
			return stoi(cardGiven);
	}
}

int dispenseCard(vector<string>& card, int cardType, int validate) {
	int cardIndex = randTypeOfCard(card.size());
	string cardGiven = card[cardIndex];
	int num = changeToRealValue(cardGiven, validate);
	card.erase(card.begin() + cardIndex);  // Elimina la carta del vector original
	printCard(cardType, cardGiven);
	return num;
}

void giveFormatToText(int number, wstring& number1, wstring& number2) {
	


	switch (number)
	{
	case 1:
		number1 = L"█";
		number2 = L"█";
		break;
	case 2:
		number1 = L"█ █";
		number2 = L"█ █";
		break;
	case 3:
		number1 = L"█ █ █";
		number2 = L"█ █ █";
		break;
	case 4:
		number1 = L"█ █ █";
		number2 = L"█  █";
		break;
	case 5:
		number1 = L"█ █";
		number2 = L" █";
		break;
	case 6:
		number1 = L"█ █ █";
		number2 = L" █  █";
		break;
	case 7:
		number1 = L"█ █ █ █";
		number2 = L" █  █ █";
		break;
	case 8:
		number1 = L"█ █ █ █ █";
		number2 = L" █  █ █ █";
		break;
	case 9:
		number1 = L"▀▄▀";
		number2 = L"█░█";
		break;
	}
}

void playerTurn(int& playerScore, int& turno, vector<string>& hearth, vector<string>& diamonds, vector<string>& clovers, vector<string>& spades, int validate) {
	int num = 0;
	string blankSpace = "                                            ";
	wstring spaceBlank = L"                                          ";

	wstring number1;
	wstring number2;


	giveFormatToText(turno+1, number1, number2);

	cout << endl;
	wcout << spaceBlank << L"\033[1;32m▀█▀ █░█ █▀█ █▄░█   " << number1 <<endl;
	wcout << spaceBlank << L"░█░ █▄█ █▀▄ █░▀█   " << number2 << endl;
	cout << "\033[0m";  // Reset de color
	cout << endl;
	int typeOfCard = randTypeOfCard(4);

	if (validate == 1) {
		if (typeOfCard == 0)
			num = dispenseCard(hearth, 0, 1);
		else if (typeOfCard == 1)
			num = dispenseCard(diamonds, 1, 1);
		else if (typeOfCard == 2)
			num = dispenseCard(clovers, 2, 1);
		else
			num = dispenseCard(spades, 3, 1);
		playerScore += num;
		cout << blankSpace << "Player's score: " << playerScore << endl;
	}
	else {
		if (typeOfCard == 0)
			num = dispenseCard(hearth, 0, 2);
		else if (typeOfCard == 1)
			num = dispenseCard(diamonds, 1, 2);
		else if (typeOfCard == 2)
			num = dispenseCard(clovers, 2, 2);
		else
			num = dispenseCard(spades, 3, 2);

		playerScore += num;
		if (num == 11 && playerScore > 21) {
			playerScore -= num;
			playerScore++;
		}
		cout << blankSpace << "Croupier's score: " << playerScore << endl;
	}

	turno++;
}

void gameLoop(int& playerScore, int& machineScore) {
	int turno = 0;
	string blankSpace = "                          ";

	vector<string> hearth, diamonds, clovers, spades;

	initializeCards(hearth);
	initializeCards(diamonds);
	initializeCards(clovers);
	initializeCards(spades);

	int num = 0;
	char option;
	bool isDispensed = false;


	do {
		playerTurn(playerScore, turno, hearth, diamonds, clovers, spades, 1);

		cout << "                            The croupier have already given to you two cards?" << endl;
		cout << "                                             Y- Yes     N- No" << endl;

		cin >> option;

		system("cls");

		option = toupper(option);

		switch (option) {
		case 'Y':
			if (turno == 2) {
				isDispensed = true;
			}
			else {
				cout << "You're such a liar" << endl;
				cout << "Here you have your card" << endl;
			}

			break;
		case 'N':
			if (turno == 2) {
				isDispensed = true;
				cout << "Why do you lie? You know you can get banned from the Casino!" << endl;
			}
			break;
		}

	} while (!isDispensed);

	bool isStop = false;

	isDispensed = false;

	if (turno >= 2) {
		do
		{
			
			if (turno == 2) {
				playerTurn(machineScore, turno, hearth, diamonds, clovers, spades, 2);
				cout << blankSpace <<"                Your score is: " << playerScore << endl;
			}

			if (!isStop) {
				cout << blankSpace << "             Do you want another card?" << endl;
				cout << blankSpace << "                  Y- Yes     N- No" << endl;

				cin >> option;
				option = toupper(option);
				system("cls");
			}

			switch (option) {
			case 'Y':
				playerTurn(playerScore, turno, hearth, diamonds, clovers, spades, 1);
				if (playerScore > 21) {
					cout << "You've lost";
					Sleep(5000);
					isDispensed = true;
				}
				break;
			case 'N':
				isStop = true;

				if (machineScore < 17) {
					playerTurn(machineScore, turno, hearth, diamonds, clovers, spades, 2);
					cout << "Your score is: " << playerScore << endl;

					if (machineScore > 21) {
						cout << "You have won hahah";
						Sleep(5000);
						isDispensed = true;

					}
					else if (machineScore == 21 && playerScore == 21) {
						cout << "You have won jujuju";
						Sleep(5000);
						isDispensed = true;
					}
					else if (machineScore == 21) {
						cout << "You have lost jujuju";
						Sleep(5000);
						isDispensed = true;
					}
					else {
						if (machineScore > playerScore) {
							cout << "You have lost";
							Sleep(5000);
							isDispensed = true;
						} 
						else if (machineScore == playerScore) {
							cout << "ITS A TIE";
							Sleep(5000);
							isDispensed = true;
						}
					}
					Sleep(2000);

					system("cls");

				}
				else
				{
					cout << "Your score is: " << playerScore << endl;
					if (machineScore > playerScore) {
						cout << "You have lost haha";
						Sleep(5000);
						isDispensed = true;
					}
					else if (playerScore > machineScore)
					{
						cout << "You have won haha";
						Sleep(5000);
						isDispensed = true;
					}
					Sleep(2000);

					
				}
			}
		} while (!isDispensed);
		cout << endl;
	}
} 

int main() {
	using namespace std;

	locale utf8_locale("es_US.UTF-8");
	locale::global(utf8_locale);


	srand(time(NULL));
	int playerScore = 0;
	int machineScore = 0;

	int option;
	bool validate = false;

	do
	{
		system("cls");
		printTitle();
		cout << endl;
		cout << "                                           What do you want to do?" << endl;
		cout << endl;
		cout << "                                   1- Play                      ";
		cout << "2- Close" << endl;


		cin >> option;
		switch (option)
		{
		case 1:
			system("cls");
			playerScore = 0;
			machineScore = 0;
			gameLoop(playerScore, machineScore);
			break;
		case 2:
			return 0;
			break;
		default:
			break;
		}
	} while (!validate);
	return 0;
}
 