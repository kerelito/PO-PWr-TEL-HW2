#include "GameController.h"
#include <iostream>
#include <fstream>
using namespace std;

GameController::GameController(GameModel& model, GameView& view) : model(model), view(view) {}

void GameController::launch() {
    GameView::printStartHeader();
    while (true) {
        view.printData(model.getPoints(), model.getLevel());
        char input = GameView::getUserInput();
        const char addPointCondition = 'b';
        const char exitCondition = 'e';
        const char saveCondition = 's';
        const char loadCondition = 'l';
        if (input == addPointCondition) {
            model.addPoint();
            if (model.nextLevel()) {
                model.setLevel(model.getLevel() + 1);
            }
        } else if (input == exitCondition) {
            cout << "Program zakonczony.\n";
            break;
        } else if (input == saveCondition) {
            cout << "Podaj nazwe pliku do zapisu: ";
            string filename;
            cin >> filename;
            saveGame(filename, model.getPoints(), model.getLevel());
            cout << "Stan gry zapisany.\n";
        } else if (input == loadCondition) {
            cout << "Podaj nazwe pliku do wczytania: ";
            string filename;
            cin >> filename;
            if (loadGame(filename, model)) {
                cout << "Stan gry wczytany.\n";
            } else {
                cout << "Nie udalo sie wczytac stanu gry z pliku.\n";
            }
        } else {
            cout << "Wprowadzono nieobslugiwane wejscie. Akceptowane pola wyboru to 'b', 'e', 's' oraz 'l'.\n";
        }
    }
}

void GameController::saveGame(const string& filename, int points, int level) {
    ofstream file(filename);
    if (file.is_open()) {
        file << points << endl;
        file << level << endl;
        file.close();
    } else {
        cout << "Nie udalo sie zapisac stanu gry do pliku.\n";
    }
}

bool GameController::loadGame(const string& filename, GameModel& model) {
    ifstream file(filename);
    if (file.is_open()) {
        int points, level;
        file >> points >> level;
        model.setPoints(points);
        model.setLevel(level);
        file.close();
        return true;
    } else {
        return false;
    }
}
