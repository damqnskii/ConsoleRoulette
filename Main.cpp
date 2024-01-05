using namespace std;
#include <iostream>
#include <cmath>
#include <string>
#include <array>
#include <iomanip>
#include <locale.h>
#include <locale>
#include <stdio.h>
#include <fstream>
#include <cstdlib>
#include <cstring>
struct casinoEarnings {
	double profit = 0;
	double startingMoney = 100000.00;
};
struct client {
	int registrationNum;
	string firstname;
	string lastname;
	double balance = 0;
	double rolledMoney = 0;
	bool smallBonus = false;
	bool mediumBonus = false;
	bool largeBonus = false;
	string accountRank;
};

const char line = '-';
const int capacity = 50;
const int rouletteCap = 36;
void lineoutput() {
	for (int i = 0; i < 104; i++) {
		cout << line;
	}
	cout << endl;
}
void formating() {
	for (int i = 0; i < 40; i++) cout << ' ';
}
void casinoMenu() {
	
	cout << endl << setw(60) << "Welcome to the casino" << endl;
	lineoutput();
	formating();;
	cout << "A. Insert money" << endl;
	lineoutput();
	formating();
	cout << "B. Information about accounts" << endl;
	lineoutput();
	formating();
	cout << "C. Start the game" << endl;
	lineoutput();
	formating();
	cout << "D. Create an account" << endl;
	lineoutput();
	formating();
	cout << "E. Casino Details" << endl;
	cout << endl;
}
int randomNumber() {
	return rand() % 900000 + 100000;
}
const int redNumbers[18]{ 1, 3, 5, 7, 9, 12, 14, 16, 18, 19, 21, 23, 25, 27, 30, 32, 34, 36 };
const int blackNumbers[18]{ 2, 4, 6, 8, 10, 11, 13, 15, 17, 20, 22, 24, 26, 28, 29, 31, 33, 35 };
const int green = 0;
void addingAccount(client oneperson[], int& total, int amount) {
	if (total <= 50) {
		
		int randomReg = randomNumber();
		formating();
		cout << "Account creation menu" << endl;
		for (int i = total; i < amount + total; i++) {	
			cin.ignore();
			formating();
			cout << "Enter your first name" << endl;
			getline(cin, oneperson[i].firstname);
			formating();
			cout << "Enter your last name" << endl;
			getline(cin, oneperson[i].lastname);
			
			oneperson[i].registrationNum = randomReg += 103;
			
			cout << "Your registration number is // " << randomReg << " // please remember it!" << endl;
		}
		total += amount;
	}
	else {
		formating();
		cout << "The list of clients is full" << endl;
		return;
	}
}
void casinoDetails(casinoEarnings casino, int total) {
	formating();
	cout << "Casino Profit and Details" << endl;
	formating();
	cout << "Casino money + starting = " << casino.startingMoney << " $" << endl;
	if (casino.profit > 0) {
		formating();
		cout << "The casino has " << casino.profit << " $ profit" << endl;
	}
	else if (casino.profit < 0) {
		formating();
		cout << "The casino has " << abs(casino.profit) << " $ debt" << endl;
	}
	else {
		formating();
		cout << "The casino is neither in profit nor in loss" << endl;
	}
	lineoutput();
	formating();
	cout << "Casino active players" << endl;
	formating();
	cout << "The casino has " << total << " active players" << endl;
}
void allAccountOutput(client onePerson[], int total, casinoEarnings casino) {
	formating();
	cout << "Secret pass" << endl;
	char confirmation[100] = "ABC100";
	char pass[100];
	formating();
	cin >> pass;
	while (strcmp(confirmation, pass) != 0){
		formating();
		cout << "Wrong password" << endl;
		formating();
		cin >> pass;
	}
	for (int i = 0; i < total; i++) {
		formating();
		cout << "Information about the accounts" << endl;
		formating();
		cout << "First and last name" << endl;
		cout << onePerson[i].firstname << " / " << onePerson[i].lastname << endl;
		formating();
		cout << "Registration number" << endl;
		cout << onePerson[i].registrationNum << endl;
		formating();
		cout << "Balance in the account" << endl;
		cout << onePerson[i].balance << endl;\
		formating();
		cout << "Played money in the account" << endl;
		cout << onePerson[i].rolledMoney << endl;
	}
	casinoDetails(casino, total);
}
double balanceInput(client person[], int& total, casinoEarnings& casino) {
	if (total <= 0) {
		formating();
		cout << "There are not any accounts registered " << endl;
		return 0;
	}
	else {
		bool isFound = false;
		lineoutput();
		formating();
		cout << "The minimum balance add is: 10.00$" << endl;
		lineoutput();
		formating();
		cout << "Write the amount of wanted money to insert" << endl;
		double moneyAdded;
		formating();
		cin >> moneyAdded;
		

		while (moneyAdded < 10.00) {
			formating();
			cout << "The amount is too small!" << endl;
			formating();
			cin >> moneyAdded;
		}
		while (moneyAdded > 75000.00) {
			formating();
			cout << "The amount is too high!" << endl;
			formating();
			cin >> moneyAdded;
		}
		formating();
		cout << "Write your registration number for validation" << endl;
		int registrationValidation;
		formating();
		cin >> registrationValidation;
		for (int i = 0; i < total; i++) {
			if (person[i].registrationNum == registrationValidation) {
				return person[i].balance += moneyAdded;
				casino.profit += moneyAdded;
				isFound = true;
				formating();
			}
		}
		if (!isFound) {
			formating();
			cout << "The registration number is wrong or do not exist please contact support" << endl;
			return 0.0;
		}
	}
}

int returnIndexOfTheaccount(client onePerson[], int total, string& firstNameConfirmation, string& lastNameConfirmation, int regNumConfirmation) {
	for (int i = 0; i < total; i++) {
		if (firstNameConfirmation == onePerson[i].firstname && lastNameConfirmation == onePerson[i].lastname && regNumConfirmation == onePerson[i].registrationNum) {
			formating();
			cout << "Login successful" << endl;
			return i;
		}
	}
	formating();
	cout << "Login unsuccessful, please try again" << endl;
	return -1;
}
void rouletteRules() {
	char option;

	lineoutput();
	formating();
	cout << "Welcome to the Roulette" << endl;
	formating();
	cout << "The rules" << endl;
	cout << "You must choose between 36 numbers 0-36" << endl;
	cout << "The roulette spins and the ball lands on a random number" << endl;
	cout << "The numbers are split by some stats" << endl;
	lineoutput();
	cout << "Firstly they are red, black and 0 which is green" << endl;
	cout << "The multiply bet on red and black is x2" << endl;
	cout << "Green 0 multiplies the bet x36 times" << endl;
	cout << "Secondly you can bet on each number" << endl;
	cout << "A single number multiply x36 the bet" << endl;
	cout << "You can bet on dosens which are 3" << endl;
	cout << "First of them are the numbers 1-12" << endl;
	cout << "Second of them are the numbers 13-24" << endl;
	cout << "Third of them are the numbers 24-36" << endl;
	cout << "Each dosen multiply the bet by x3" << endl;
	cout << "The third way to bet at rows" << endl;
	cout << "The first row is 1 + 3 = n" << endl;
	cout << "The second row is 2 + 3 = n" << endl;
	cout << "The third row is 3 + 3 = n" << endl;
	cout << "This kind of bet multiplies the bet by x3" << endl;
	cout << "You can bet if the number is even or odd" << endl;
	cout << "Other way is to guess if the number is 1 to 18" << endl;
	cout << "or 19 to 36 which multiplies the bet by x2\n\n" << endl;
	
	cout << "Enter X when you are ready to bet" << endl;
	cin >> option;
}
void rouletteVisualized() {
	cout << setw(65) << "|0(green)|" << endl;
	cout << setw(10) << "|3(r)|" << setw(10) << "|6(b)|" << setw(10) << "|9(r)|" << setw(10) << "|12(r)|" << setw(10) << "|15(b)|";
	cout << setw(10) << "|18(r)|" << setw(10) << "|21(r)|" << setw(10) << "|24(b)|" << setw(10) << "|27(r)|" << setw(10) << "|30(r)|" << setw(10)
		<< "|33(b)|" << setw(10) << "|36(r)|" << setw(10) << " | Third row";




	cout << endl << setw(10) << "|2(b)|" << setw(10) << "|5(r)|" << setw(10) << "|8(b)|" << setw(10) << "|11(b)|" << setw(10) << "|14(r)|" << setw(10) << "|17(b)|";
	cout << setw(10) << "|20(b)|" << setw(10) << "|23(r)|" << setw(10) << "|26(b)|" << setw(10) << "|29(b)|" << setw(10) << "|32(r)|" << setw(10) <<
		"|35(b)|" << " | Second row";

	cout << endl << setw(10) << "|1(r)|" << setw(10) << "|4(b)|" << setw(10) << "|7(r)|" << setw(10) << "|10(b)|" << setw(10) << "|13(b)|" << setw(10) << "|16(r)|" << setw(10) << "|19(r)|" << setw(10) << "|22(b)|"
		<< setw(10) << "|25(r)|" << setw(10) << "|28(b)|" << setw(10) << "|31(b)|" << setw(10) << "|34(r)|" << " | First row";
	cout << endl << setw(3) << " " << setw(39) << setfill('=') << " " << " " << setw(39) << setfill('=') << " " << " " << setw(39) << setfill('=') << " ";
	cout << endl << setw(3) << setfill(' ') << " " << setfill(' ') << setw(25) << setfill(' ') << "First dosen" << setw(40) << setfill(' ') << "Second dosen" << setw(40)
		<< setfill(' ') << "Third dosen" << endl << endl;

	cout << setw(20) << setfill(' ') << "1-18" << setw(20) << setfill(' ') << "EVEN" << setw(20) << setfill(' ') << "RED";
	cout << setw(20) << setfill(' ') << "BLACK" << setw(20) << setfill(' ') << "ODD" << setw(20) << setfill(' ') << "19-36" << endl << endl;
}
void balanceOutput(client personBalance[], int takenIndex, int total) {

	for (int i = 0; i < total; i++) {
		if (i == takenIndex) {
			cout << "\n\n\n";
			formating();
			cout << fixed << setprecision(2) << "Your balance is: " << personBalance[i].balance << "$" << endl;
		}
	}
}

int randomRouletteNumber() {
	srand(static_cast<unsigned int>(time(nullptr)));
	return rand() % 37;
}

double playedMoney(client onePerson[],int takenIndex, double betsize) {
	return onePerson[takenIndex].rolledMoney += betsize;
}

string redOrBlackNumber() {
	int TRN = randomRouletteNumber();
	for (int i = 0; i < 36; i++) {
		if (TRN == redNumbers[i]) {
			return " Red";
			break;
		}
		else if (TRN == blackNumbers[i]) {
			return " Black";
			break;
		}
		else if (TRN == green) {
			return " Green";
			break;
		}
	}
}

void specificNumberBetting(client onePerson[], int takenIndex, casinoEarnings& casino) {
	double lostBet = 0;
	int n;
	int theRandomNumber = randomRouletteNumber();
	double bet;
	bool isWinable = false;
	formating();
	cout << "Write amount of specific numbers you want to bet on" << endl;
	formating();
	cin >> n;
	int specificNumberBet[rouletteCap];
	if (n < 0 && n > rouletteCap) {
		formating();
		cout << "numbers to bet on are between 0-36" << endl;
	}
	for (int i = 0; i < n; i++) {
		formating();
		cout << "Write the number you want to bet on" << endl;
		formating();
		cin >> specificNumberBet[i];
		while (specificNumberBet[i] < 0 || specificNumberBet[i] > 36) {
			formating();
			cout << "The number do not contains in the roulette" << endl;
			formating();
			cin >> specificNumberBet[i];
		}
		formating();
		cout << "Set the bet on the number" << endl;
		formating();
		cin >> bet;
		lostBet += bet;
		if (onePerson[takenIndex].balance < bet) {
			formating();
			cout << "You do not have enough money to set this bet" << endl;
			return;
		}
		onePerson[takenIndex].balance -= bet;
		playedMoney(onePerson, takenIndex, bet);
	}
	for (int i = 0; i < n; i++) {
		if (specificNumberBet[i] == theRandomNumber) {
			isWinable = true;
			onePerson[takenIndex].balance += (bet * 36);
			casino.startingMoney -= bet * 36;
		}
	}
	
	if (!isWinable) {
		formating();
		cout << "You have lost " << lostBet << " $" << endl;
		casino.startingMoney += lostBet;
		formating();
		cout << "The number was: " << theRandomNumber << redOrBlackNumber() << endl;
	}
	else {
		formating();
		cout << "You have won " << bet * 36 << " $" << endl;
		formating();
		cout << "The number was: " << theRandomNumber << redOrBlackNumber() << endl;
	}

}
void rowBetting(client onePerson[], int takenIndex, casinoEarnings& casino) {
	int firstRowNumbers[13]{0, 1, 4, 7, 10, 13, 16, 19, 22, 25, 28, 31, 34 };
	int secondRowNumbers[13]{0, 2, 5, 8, 11, 14, 17, 20, 23, 26, 29, 32, 35 };
	int thirdRowNumbers[13]{0, 3, 6, 9, 12, 15, 18, 21, 24, 27, 30, 33, 36 };
	int theRandomNumber = randomRouletteNumber();
	int rowSelection;
	do {
		formating();
		cout << "The rows are between 1 - 3" << endl;
		formating();
		cout << "Write the row you want to bet on" << endl;
		formating();
		cin >> rowSelection;
	} while (rowSelection < 1 || rowSelection > 3);
	formating();
	cout << "Enter the amount of money you are betting on this row" << endl;
	double betSize;
	formating();
	cin >> betSize;
	if (betSize > onePerson[takenIndex].balance) {
		formating();
		cout << "You do not have enough money to bet on" << endl;
		return;
	}
	onePerson[takenIndex].balance -= betSize;
	playedMoney(onePerson, takenIndex, betSize);
	bool isWon = false;
	if (rowSelection == 1) {
		for (int i = 0; i < 13; i++) {
			if (theRandomNumber == firstRowNumbers[i]) {
				onePerson[takenIndex].balance += (betSize * 3);
				casino.startingMoney -= (betSize * 3);
				formating();
				cout << "You won " << betSize * 3 << " $" << endl;
				casino.startingMoney -= betSize * 3;
				formating();
				cout << "The number was " << theRandomNumber << redOrBlackNumber() << endl;
				isWon = true;
			}
		}
		if (!isWon) {
			formating();
			cout << "You lost " << betSize << " $" << endl;
			casino.startingMoney += betSize;
			formating();
			cout << "The number was " << theRandomNumber << redOrBlackNumber() << endl;
		}
	}
	else if (rowSelection == 2) {
		for (int i = 0; i < 13; i++) {
			if (theRandomNumber == secondRowNumbers[i]) {
				onePerson[takenIndex].balance += (betSize * 3);
				casino.startingMoney = casino.profit - (betSize * 2);
				formating();
				cout << "You won " << betSize * 3 << "$" << endl;
				casino.startingMoney -= betSize * 3;
				formating();
				cout << "The number was " << theRandomNumber << redOrBlackNumber() << endl;
				isWon = true;
			}
		}
		if (!isWon) {
			formating();
			cout << "You lost " << betSize << " $" << endl;
			casino.startingMoney += betSize;
			formating();
			cout << "The number was " << theRandomNumber << redOrBlackNumber() << endl;
		}
	}
	else if (rowSelection == 3) {
		for (int i = 0; i < 13; i++) {
			if (theRandomNumber == thirdRowNumbers[i]) {
				onePerson[takenIndex].balance += (betSize * 3);
				casino.startingMoney = casino.profit - (betSize * 2);
				formating();
				cout << "You won " << betSize * 3 << "$" << endl;
				casino.startingMoney -= betSize * 3;
				formating();
				cout << "The number was " << theRandomNumber << redOrBlackNumber() << endl;
				isWon = true;
			}
		}
		if (!isWon) {
			formating();
			cout << "You lost " << betSize << " $" << endl;
			casino.startingMoney += betSize;
			formating();
			cout << "The number was " << theRandomNumber << redOrBlackNumber() << endl;
		}
	}
}

void dosenBetting(client onePerson[], int takenIndex, casinoEarnings& casino) {
	int firstDosen[13] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };
	int secondDosen[13] = {0, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24 };
	int thirdDosen[13] = {0, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36 };

	int theRandomNumber = randomRouletteNumber();
	int dosenSelection;
	do {
		formating();
		cout << "The dosens are between 1 - 3" << endl;
		formating();
		cout << "Write which dosen you want to bet on" << endl;
		formating();
		cin >> dosenSelection;
	} while (dosenSelection < 1 || dosenSelection > 3);
	formating();
	cout << "Write the size of bet you want to put" << endl;
	double betSize;
	formating();
	cin >> betSize;
	playedMoney(onePerson, takenIndex, betSize);
	if (betSize > onePerson[takenIndex].balance) {
		formating();
		cout << "You do not have enough balance!" << endl;
	}
	onePerson[takenIndex].balance -= betSize;
	playedMoney(onePerson, takenIndex, betSize);
	bool isWon = false;
	if (dosenSelection == 1) {
		for (int i = 0; i < 13; i++) {
			if (firstDosen[i] == theRandomNumber) {
				onePerson[takenIndex].balance += (betSize * 3);
				casino.startingMoney -= betSize * 3;
				formating();
				cout << "You won " << betSize * 3 << "$" << endl;
				formating();
				cout << "The number was " << theRandomNumber << redOrBlackNumber() << endl;
				isWon = true;
			}
		}
		if (!isWon) {
			formating();
			cout << "You lost " << betSize << " $" << endl;
			casino.startingMoney += betSize;
			formating();
			cout << "The number was " << theRandomNumber << redOrBlackNumber() << endl;
		}
	}
	if (dosenSelection == 2) {
		for (int i = 0; i < 13; i++) {
			if (secondDosen[i] == theRandomNumber) {
				onePerson[takenIndex].balance += (betSize * 3);
				casino.startingMoney -= betSize * 3;
				formating();
				cout << "You won " << betSize * 3 << "$" << endl;
				formating();
				cout << "The number was " << theRandomNumber << redOrBlackNumber() << endl;
				isWon = true;
			}
		}
		if (!isWon) {
			formating();
			cout << "You lost " << betSize << " $" << endl;
			casino.startingMoney += betSize;
			formating();
			cout << "The number was " << theRandomNumber << redOrBlackNumber() << endl;
		}
	}
	if (dosenSelection == 3) {
		for (int i = 0; i < 13; i++) {
			if (thirdDosen[i] == theRandomNumber) {
				onePerson[takenIndex].balance += (betSize * 3);
				casino.startingMoney -= betSize * 3;
				formating();
				cout << "You won " << betSize * 3 << "$" << endl;
				formating();
				cout << "The number was " << theRandomNumber << redOrBlackNumber() << endl;
				isWon = true;
			}
		}
		if (!isWon) {
			formating();
			cout << "You lost " << betSize << " $" << endl;
			casino.startingMoney += betSize;
			formating();
			cout << "The number was " << theRandomNumber << redOrBlackNumber() << endl;
		}
	}
	
}

void colorBetting(client onePerson[], int takenIndex, casinoEarnings& casino) {
	

	int theRandomNumber = randomRouletteNumber();
	formating();
	cout << "Choose Red[r], Black[b], Green[g]" << endl;
	char choice;
	formating();
	cin >> choice;
	while (choice != 'r' && choice != 'R' && choice != 'B' && choice != 'b' && choice != 'g' && choice != 'G') {
		cout << "Wrong option! R / B / G only! " << endl;
		formating();
		cin >> choice;
	}
	double betsize;
	formating();
	cout << "Write the bet size" << endl;
	formating();
	cin >> betsize;
	if (betsize > onePerson[takenIndex].balance) {
		formating();
		cout << "You do not have enough balance" << endl;
		return;
	}
	onePerson[takenIndex].balance -= betsize;
	playedMoney(onePerson, takenIndex, betsize);
	bool isWon = false;
	if (choice == 'r' || choice == 'R') {
		for (int i = 0; i < 18; i++) {
			if (redNumbers[i] == theRandomNumber) {
				onePerson[takenIndex].balance += (betsize * 2);
				casino.startingMoney -= betsize * 2;
				formating();
				cout << "You won " << betsize * 2 << "$" << endl;
				formating();
				cout << "The number was " << theRandomNumber << redOrBlackNumber() << endl;
				isWon = true;

			}
		}
	}

	if (choice == 'b' || choice == 'B') {
		for (int i = 0; i < 18; i++) {
			if (blackNumbers[i] == theRandomNumber) {
				onePerson[takenIndex].balance += (betsize * 2);
				casino.startingMoney -= betsize * 2;
				formating();
				cout << "You won " << betsize * 2 << "$" << endl;
				formating();
				cout << "The number was " << theRandomNumber << redOrBlackNumber() << endl;
				isWon = true;
				
			}
		}
	}
	if (choice == 'g' || choice == 'G') {
		if (theRandomNumber == green) {
			onePerson[takenIndex].balance += (betsize * 36);
			casino.startingMoney -= betsize * 36;
			formating();
			cout << "You won " << betsize * 36 << "$" << endl;
			formating();
			cout << "The number was " << theRandomNumber << redOrBlackNumber() << endl;
			isWon = true;
		}
	}
	if (!isWon) {
		formating();
		cout << "You lost " << betsize << " $" << endl;
		casino.startingMoney += betsize;
		formating();
		cout << "The number was " << theRandomNumber << redOrBlackNumber() << endl;
	}
}


void OddOrEvenBetting(client onePerson[], int takenIndex, casinoEarnings& casino) {
	int theRandomNumber = randomRouletteNumber();
	formating();
	cout << "Choose odd[o] or even[e]" << endl;
	char choice;
	formating();
	cin >> choice;
	while (choice != 'o' && choice != 'O' && choice != 'E' && choice != 'e') {
		formating();
		cout << "Wrong option! O or E only!" << endl;
		formating();
		cin >> choice;
	}
	formating();
	cout << "Set the bet size" << endl;
	double betsize;
	formating();
	cin >> betsize;
	if (betsize > onePerson[takenIndex].balance) {
		formating();
		cout << "You do not have enough balance to put the bet" << endl;
		return;
	}
	onePerson[takenIndex].balance -= betsize;
	playedMoney(onePerson, takenIndex, betsize);
	bool isWon = false;
	if (choice == 'o' || choice == 'O') {
		for (int i = 0; i < rouletteCap; i++) {
			if (theRandomNumber % 2 != 0) {
				onePerson[takenIndex].balance += (betsize * 2);
				casino.startingMoney -= betsize * 2;
				formating();
				cout << "You won " << betsize * 2 << "$" << endl;
				formating();
				cout << "The number was " << theRandomNumber << redOrBlackNumber() << endl;

				isWon = true;
				if (isWon) {
					break;
				}
			}
			if (!isWon) {
				formating();
				cout << "You lost " << betsize << " $" << endl;
				casino.startingMoney += betsize;
				formating();
				cout << "The number was " << theRandomNumber << redOrBlackNumber() << endl;
				break;
			}
		}
	}
	if (choice == 'e' || choice == 'E') {
		for (int i = 0; i < rouletteCap; i++) {
			if (theRandomNumber % 2 == 0) {
				onePerson[takenIndex].balance += (betsize * 2);
				formating();
				cout << "You won " << betsize * 2 << "$" << endl;
				casino.startingMoney -= betsize * 2;
				formating();
				cout << "The number was " << theRandomNumber << redOrBlackNumber() << endl;
				isWon = true;
				if (isWon) {
					break;
				}
			}
			if (!isWon) {
				formating();
				cout << "You lost " << betsize << " $" << endl;
				casino.startingMoney += betsize;
				formating();
				cout << "The number was " << theRandomNumber << redOrBlackNumber() << endl;
				break;
			}
		}
	}
}
void lowOrHighNumberBet(client onePerson[], int takenIndex, casinoEarnings& casino) {
	formating();
	cout << "Bet on low or high numbers" << endl;
	formating();
	cout << "Press L for low and H for high numbers" << endl;
	int theRandomNumber = randomRouletteNumber();
	char choice;
	formating();
	cin >> choice; 
	while (choice != 'h' && choice != 'H' && choice != 'l' && choice != 'L') {
		formating();
		cout << "Wrong option! H / L !" << endl;
		formating();
		cin >> choice;
	}
	formating();
	cout << "Set the bet" << endl;
	double betsize;
	formating();
	cin >> betsize;
	if (betsize > onePerson[takenIndex].balance) {
		formating();
		cout << "You do not have enough balance to put the bet" << endl;
		return;
	}
	onePerson[takenIndex].balance -= betsize;
	playedMoney(onePerson, takenIndex, betsize);
	bool isWon = false;
	if (choice == 'L' || choice == 'l') {
		for (int i = 1; i <= 18; i++) {
			if (theRandomNumber == i) {
				onePerson[takenIndex].balance += (betsize * 2);
				casino.startingMoney -= betsize * 2;
				formating();
				cout << "You won " << betsize * 2 << "$" << endl;
				formating();
				cout << "The number was " << theRandomNumber << redOrBlackNumber() << endl;
				isWon = true;
			}
		}
		if (!isWon) {
			formating();
			cout << "You lost " << betsize << " $" << endl;
			casino.startingMoney += betsize;
			formating();
			cout << "The number was " << theRandomNumber << redOrBlackNumber() << endl;
		}
	}
	if (choice == 'H' || choice == 'h') {
		for (int i = 19; i <= 36; i++) {
			if (theRandomNumber == i) {
				onePerson[takenIndex].balance += (betsize * 2);
				formating();
				cout << "You won " << betsize * 2 << "$" << endl;
				casino.startingMoney -= betsize * 2;
				formating();
				cout << "The number was " << theRandomNumber << redOrBlackNumber() << endl;
				isWon = true;
			}
		}
		if (!isWon) {
			formating();
			cout << "You lost " << betsize << " $" << endl;
			casino.startingMoney += betsize;
			formating();
			cout << "The number was " << theRandomNumber <<  redOrBlackNumber() <<endl;
		}
	}
}

void accountStatus(client onePerson[], int takenIndex) {
	if (onePerson[takenIndex].rolledMoney >= 0 && onePerson[takenIndex].rolledMoney < 2000) {
		onePerson[takenIndex].accountRank = "Bronze";
		cout << "The rank of the account is " << onePerson[takenIndex].accountRank << endl;
		
	}
	if (onePerson[takenIndex].rolledMoney >= 2000 && onePerson[takenIndex].rolledMoney < 15000) {
		onePerson[takenIndex].accountRank = "Silver";
		cout << "The rank of the account is " << onePerson[takenIndex].accountRank << endl;
		return;
	}
	if (onePerson[takenIndex].rolledMoney >= 15000 && onePerson[takenIndex].rolledMoney < 50000) {
		onePerson[takenIndex].accountRank = "Gold";
		cout << "The rank of the account is " << onePerson[takenIndex].accountRank << endl;
		return;
	}
	if (onePerson[takenIndex].rolledMoney >= 50000 && onePerson[takenIndex].rolledMoney < 100000) {
		onePerson[takenIndex].accountRank = "Platinum";
		cout << "The rank of the account is " << onePerson[takenIndex].accountRank << endl;
		return;
	}
	if (onePerson[takenIndex].rolledMoney > 100000) {
		onePerson[takenIndex].accountRank = "Diamond";
		cout << "The rank of the account is " << onePerson[takenIndex].accountRank << endl;
		return;
	}
}

void bonus(client onePerson[], int takenIndex, casinoEarnings& casino) {
	if(onePerson[takenIndex].smallBonus == false) {
		if (onePerson[takenIndex].rolledMoney >= 500 && onePerson[takenIndex].rolledMoney <= 1000) {
			formating();
			cout << "You have received 50 $ bonus !" << endl;
			onePerson[takenIndex].balance += 50;
			casino.profit -= 50;
			onePerson[takenIndex].smallBonus = true;
		}
	}
	if(onePerson[takenIndex].mediumBonus == false) {
		if (onePerson[takenIndex].rolledMoney >= 1001 && onePerson[takenIndex].rolledMoney <= 5000) {
		formating();
		cout << "You have received 200 $ bonus !" << endl;
		onePerson[takenIndex].balance += 200;
		casino.profit -= 200;
		onePerson[takenIndex].mediumBonus = true;
		}
	}
	if(onePerson[takenIndex].largeBonus == false) {
		if (onePerson[takenIndex].rolledMoney > 5001) {
			formating();
			onePerson[takenIndex].balance += 500;
			casino.profit -= 500;
			cout << "You have received 500 $ bonus !" << endl;
			onePerson[takenIndex].largeBonus = true;
		}
	}
}

void allInformationAboutTheAcc(client onePerson[], int takenIndex) {
	lineoutput();
	formating();
	cout << "All the information about the account" << endl;
	formating();
	cout << "The registration number: " << onePerson[takenIndex].registrationNum << endl;
	formating();
	cout << "Name of the account: " << onePerson[takenIndex].firstname << " " << onePerson[takenIndex].lastname << endl;
	formating();
	cout << "Balance in the account " << fixed << setprecision(2) << onePerson[takenIndex].balance << " $" << endl;
	formating();
	cout << "Amount of money that you have rolled: " << onePerson[takenIndex].rolledMoney << " $" << endl;
	formating();
	accountStatus(onePerson, takenIndex);

}

void moneyInsertWithoutRegNum(client onePerson[], int takenIndex, casinoEarnings casino) {
	lineoutput();
	formating();
	cout << "The minimum balance add is: 10.00$" << endl;
	lineoutput();
	formating();
	cout << "Write the amount of wanted money to insert" << endl;
	double moneyAdded;
	formating();
	cin >> moneyAdded;
	casino.profit += moneyAdded;

	while (moneyAdded < 10.00) {
		formating();
		cout << "The amount is too small!" << endl;
		formating();
		cin >> moneyAdded;
	}
	while (moneyAdded > 75000.00) {
		formating();
		cout << "The amount is too high!" << endl;
		formating();
		cin >> moneyAdded;
	}

	onePerson[takenIndex].balance += moneyAdded;
	lineoutput(); 
	cout << endl;
	formating();
	cout << "Successfully added money!" << endl;
	
}
void placeBetter() {
	lineoutput();
	formating();
	cout << "Place your bet" << endl;
	formating();
	cout << "1. Specific number" << endl;
	formating();
	cout << "2. On Row" << endl;
	formating();
	cout << "3. On Dosen" << endl;
	formating();
	cout << "4. On color" << endl;
	formating();
	cout << "5. Odd or Even" << endl;
	formating();
	cout << "6. Range of number" << endl;
	formating();
	cout << "7. Check Balance" << endl;
	formating();
	cout << "8. To show all the information about the account" << endl;
	formating();
	cout << "9. Add money" << endl;
	formating();
	cout << "Press S to return to main menu" << endl;


}



void loginToacc(client onePerson[], int total, casinoEarnings& casino) {
	formating();
	cout << "You must log in to your account" << endl;
	formating();
	cout << "Press Y to login / Press N to create account" << endl;
	char choice;
	cin >> choice;

	if (choice == 'Y' || choice == 'y') {	
		formating();
		cout << "Write your first name" << endl;
		string firstNameConfirmation;
		cin >> firstNameConfirmation;
		formating();
		cout << "Write your last name" << endl;
		string lastNameConfirmation;
		cin >> lastNameConfirmation;
		formating();
		cout << "Write your registration number" << endl;
		int regNumConfirmation;
		cin >> regNumConfirmation;
		
		int loggedID = returnIndexOfTheaccount(onePerson, total, firstNameConfirmation, lastNameConfirmation, regNumConfirmation);
		
		if (loggedID < 0) {
			return;
		}
		
		else {
			rouletteRules();
			rouletteVisualized();
			balanceOutput(onePerson, loggedID, total);
			bonus(onePerson, loggedID, casino);
			char betChoice;
			do {
				placeBetter();
				cin >> betChoice;
				if (betChoice == '1') {
					rouletteVisualized();
					specificNumberBetting(onePerson, loggedID, casino);
				}
				else if (betChoice == '2') {
					rouletteVisualized();
					rowBetting(onePerson, loggedID, casino);
				}
				else if (betChoice == '3') {
					rouletteVisualized();
					dosenBetting(onePerson, loggedID, casino);
					
				}
				else if (betChoice == '4') {
					rouletteVisualized();
					colorBetting(onePerson, loggedID, casino);
				}
				else if (betChoice == '5') {
					rouletteVisualized();
					OddOrEvenBetting(onePerson, loggedID, casino);
				}
				else if (betChoice == '6') {
					rouletteVisualized();
					lowOrHighNumberBet(onePerson, loggedID, casino);
				}
				else if (betChoice == '7') {
					balanceOutput(onePerson, loggedID, total);
				}
				else if (betChoice == '8') {
					allInformationAboutTheAcc(onePerson, loggedID);
				}
				else if (betChoice == '9') {
					moneyInsertWithoutRegNum(onePerson, loggedID, casino);
				}
			} while (betChoice != 'S' && betChoice != 's');
		}	
	}
	else if (choice == 'N' || choice == 'n') {
		formating();
		cout << "Press d [D] to make an account" << endl;
		formating();
		return;
	}
}



int main() {
	char option;
	int totalAccounts = 0;
	int amountOfaccToadd = 1;
	client onePerson[50];
	casinoEarnings casino;
	do {
		casinoMenu();
		cin >> option;
		if (option == 'a' || option == 'A') {
			balanceInput(onePerson, totalAccounts, casino);
		}
		else if (option == 'b' || option == 'B') {
			allAccountOutput(onePerson, totalAccounts, casino);
		}
		else if (option == 'c' || option == 'C') {
			loginToacc(onePerson, totalAccounts, casino);			
		}
		else if (option == 'd' || option == 'D') {
			addingAccount(onePerson, totalAccounts, amountOfaccToadd);
		}
		else if (option == 'e') {
			casinoDetails(casino, totalAccounts);
		}
	} 	while (option != 'N' && option != 'n');

	return 0;

}