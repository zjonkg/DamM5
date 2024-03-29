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

/**
 * The function "getCardSymbol" returns the symbol of a card based on its type.
 *
 * @param typeOfCard The parameter `typeOfCard` is an integer that represents the type of card. The
 * possible values are:
 *
 * @return The function `getCardSymbol` returns a string representing the symbol of a playing card
 * based on the given `typeOfCard` parameter. The possible return values are:
 * - If `typeOfCard` is 0, the function returns the heart symbol (♥) in red color.
 * - If `typeOfCard` is 1, the function returns the diamond symbol (♦) in
 */
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


/**
 * The function "changeToRealValue" takes a card value and a validation flag as input and returns the
 * corresponding numerical value of the card.
 *
 * @param cardGiven The parameter `cardGiven` is a string that represents the value of a playing card.
 * @param validate The `validate` parameter is used to determine whether the user wants to validate the
 * card value or not. If `validate` is 1, it means the user wants to validate the card value and if it
 * is 0, it means the user does not want to validate the card value.
 *
 * @return an integer value.
 */

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

/**
 * The function dispenseCard randomly selects a card from a vector, converts it to a real value based
 * on a validation parameter, removes the card from the vector, and prints the card type and value.
 *
 * @param card A vector of strings representing a deck of cards.
 * @param cardType The cardType parameter represents the type of card being dispensed. It is an integer
 * value that can be used to determine the specific type of card being dispensed, such as a credit
 * card, debit card, or gift card.
 * @param validate The "validate" parameter is used to determine whether the card value should be
 * validated or not. If "validate" is set to 1, the card value will be validated using the
 * "changeToRealValue" function. If "validate" is set to 0, the card value will not
 *
 * @return an integer value.
 */
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

/**
 * The function "playerTurn" handles a player's turn in a card game, updating their score and
 * displaying it on the console.
 *
 * @param playerScore The player's current score.
 * @param turno The parameter "turno" represents the current turn number in the game. It is passed by
 * reference, meaning that any changes made to it inside the function will affect the original variable
 * in the calling code.
 * @param hearth A vector of strings representing the cards in the hearth suit.
 * @param diamonds The "diamonds" parameter is a vector of strings that represents the cards in the
 * diamonds suit. Each string in the vector represents a card, and the vector as a whole represents all
 * the cards in the diamonds suit.
 * @param clovers The parameter `clovers` is a vector of strings that represents the cards of the
 * clover suit.
 * @param spades The `spades` parameter is a vector of strings that represents the cards of the spades
 * suit.
 * @param validate The `validate` parameter is used to determine whether the player's turn is a regular
 * turn or the croupier's turn. If `validate` is 1, it means it's the player's turn and if `validate`
 * is 2, it means it's the croupier's
 */
void playerTurn(int& playerScore, int& turno, vector<string>& hearth, vector<string>& diamonds, vector<string>& clovers, vector<string>& spades, int validate) {
	int num = 0;
	string blankSpace = "                                            ";
	wstring spaceBlank = L"                                          ";

	wstring number1;
	wstring number2;


	giveFormatToText(turno+1, number1, number2);

	cout << endl;
	wcout << spaceBlank << L"\033[1;32m▀█▀ █░█ █▀█ █▄░█ █▀█  " << number1 <<endl;
	wcout << spaceBlank << L"░█░ █▄█ █▀▄ █░▀█ █▄█  " << number2 << endl;
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
/**
 * The function "gameLoop" is a game loop that allows the player to play a card game against a computer
 * opponent.
 *
 * @param playerScore The parameter `playerScore` is a reference to an integer variable that represents
 * the score of the player in the game. It is used to keep track of the player's score throughout the
 * game.
 * @param machineScore The parameter "machineScore" is an integer reference that represents the score
 * of the machine in the game. It is passed by reference so that any changes made to it inside the
 * function will be reflected outside the function.
 */
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
				cout << blankSpace <<"                   Your score is: " << playerScore << endl;
			}

			if (!isStop) {
				cout << blankSpace << "                Do you want another card?" << endl;
				cout << blankSpace << "                    Y- Yes     N- No" << endl;

				cin >> option;
				option = toupper(option);
				system("cls");
			}

			switch (option) {
			case 'Y':
				playerTurn(playerScore, turno, hearth, diamonds, clovers, spades, 1);
				if (playerScore > 21) {
					cout << "                                             You've lost";
					isDispensed = true;
					Sleep(3000);
					system("cls");
				}
				break;
			case 'N':
				isStop = true;

				if (machineScore < 17) {
					playerTurn(machineScore, turno, hearth, diamonds, clovers, spades, 2);
					cout << "                                            Your score is: " << playerScore << endl;

					if (machineScore > 21) {
						cout << "                                            You have won ";
						Sleep(5000);
						isDispensed = true;

					}
					else if (machineScore == 21 && playerScore == 21) {
						cout << "                                             You have won";
						Sleep(5000);
						isDispensed = true;
					}
					else if (machineScore == 21) {
						cout << "                                             You have lost";
						Sleep(5000);
						isDispensed = true;
					}
					else {
						if (machineScore > playerScore) {
							cout << "                                          You have lost";
							Sleep(5000);
							isDispensed = true;
						} 
						else if (machineScore == playerScore) { 
							cout << "                                            ITS A TIE";
							Sleep(5000);
							isDispensed = true;
						}
					}
					Sleep(2000);

					system("cls");

				}
				else
				{
					cout << "                                            Your score is: " << playerScore << endl;
					if (machineScore > playerScore) {
						cout << "                                           You have lost";
						Sleep(5000);
						isDispensed = true;
					}
					else if (playerScore > machineScore)
					{
						cout << "                                           You have won";
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
 