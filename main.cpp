#include <iostream>
#include <string>
#include <fstream>
#include <map>
using namespace std;

class GameModel {
private:
    int points;
    int level;

public:
    GameModel() : points(0), level(1) {}

    void addPoint() {
        points++;
    }

    void setPoints(int newPoints) {
        points = newPoints;
    }

    int getPoints() const {
        return points;
    }

    void setLevel(int newLevel) {
        level = newLevel;
    }

    int getLevel() const {
        return level;
    }

    bool nextLevel() const {
        return (points % 5 == 0);
    }
};

class GameView {
public:
    static void printStartHeader() {
        cout << "Program typu kliker!" << endl;
        cout << "Uzytkowniku, aby naliczac kolejne punkty nalezy podac do wejscia litere 'b'." << endl;
        cout << "Punkty oraz poziomy beda naliczane automatycznie." << endl;
        cout << "Aby zakonczyc dzialanie programu nalezy wcisnac 'e'." << endl;
        cout << "W kazdym momencie trwania programu można zapis progres - 's', bądź go wczytać - 'l'" << endl;
        cout << "Milego klikania!.\n" << endl;
    }

    static void printData(int points, int level) {
        cout << "Level: " << (level > 0 ? romanNumeral(level) : "I") << endl;
        cout << "Points: " << points << endl;
    }

    static char getUserInput() {
        char input;
        cin >> input;
        return input;
    }

private:
    static string romanNumeral(int num) {
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
};

class GameController {
private:
    GameModel& model;
    GameView& view;

public:
    GameController(GameModel& model, GameView& view) : model(model), view(view) {}

    void launch() {
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

    void saveGame(const string& filename, int points, int level) {
        ofstream file(filename);
        if (file.is_open()) {
            file << points << endl;
            file << level << endl;
            file.close();
        } else {
            cout << "Nie udalo sie zapisac stanu gry do pliku.\n";
        }
    }

    bool loadGame(const string& filename, GameModel& model) {
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
};

int main() {
    GameModel model;
    GameView view;
    GameController controller(model, view);

    // Wczytaj stan gry z pliku, jeśli możliwe
    char input;
    cout << "Czy chcesz wczytac stan gry z pliku? (T/N): ";
    cin >> input;
    if (toupper(input) == 'T') {
        cout << "Podaj nazwe pliku do wczytania: ";
        string filename;
        cin >> filename;
        if (!controller.loadGame(filename, model)) {
            cout << "Nie udalo sie wczytac stanu gry z pliku.\n";
        }
    } else {
        cout << "Nowa gra rozpoczeta.\n";
    }

    controller.launch();

    return 0;
}
