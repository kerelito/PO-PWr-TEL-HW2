#include "GameView.h"
#include <iostream>
using namespace std;

void GameView::printStartHeader() {
    cout << "Program typu kliker!" << endl;
    cout << "Uzytkowniku, aby naliczac kolejne punkty nalezy podac do wejscia litere 'b'." << endl;
    cout << "Punkty oraz poziomy beda naliczane automatycznie." << endl;
    cout << "Aby zakonczyc dzialanie programu nalezy wcisnac 'e'." << endl;
    cout << "W kazdym momencie trwania programu można zapis progres - 's', bądź go wczytać - 'l'" << endl;
    cout << "Milego klikania!.\n" << endl;
}

void GameView::printData(int points, int level) {
    cout << "Level: " << (level > 0 ? romanNumeral(level) : "I") << endl;
    cout << "Points: " << points << endl;
}

char GameView::getUserInput() {
    char input;
    cin >> input;
    return input;
}

string GameView::romanNumeral(int num) {
    string roman;
    while (num >= 1000) {
        roman += "M";
        num -= 1000;
    }
    while (num >= 900) {
        roman += "CM";
        num -= 900;
    }
    while (num >= 500) {
        roman += "D";
        num -= 500;
    }
    while (num >= 400) {
        roman += "CD";
        num -= 400;
    }
    while (num >= 100) {
        roman += "C";
        num -= 100;
    }
    while (num >= 90) {
        roman += "XC";
        num -= 90;
    }
    while (num >= 50) {
        roman += "L";
        num -= 50;
    }
    while (num >= 40) {
        roman += "XL";
        num -= 40;
    }
    while (num >= 10) {
        roman += "X";
        num -= 10;
    }
    while (num >= 9) {
        roman += "IX";
        num -= 9;
    }
    while (num >= 5) {
        roman += "V";
        num -= 5;
    }
    while (num >= 4) {
        roman += "IV";
        num -= 4;
    }
    while (num >= 1) {
        roman += "I";
        num -= 1;
    }
    return roman;
}
