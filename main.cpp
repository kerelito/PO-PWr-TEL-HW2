#include <iostream>
#include <string>
using namespace std;

class GameModel {
private:
    int points;

public:
    GameModel() : points(0) {}

    void addPoint() {
        points++;
    }

    [[nodiscard]] int getPoints() const {
        return points;
    }

    [[nodiscard]] bool NextLevel() const {
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
        cout << "Milego klikania!.\n" << endl;
    }

    static void printData(int points, int level) {
        cout << "Level: " << romanNumeral(level) << endl;
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
    int level;

public:
    GameController(GameModel& model, GameView& view) : model(model), view(view), level(1) {}

    void launch() {
        GameView::printStartHeader();
        while (true) {
            view.printData(model.getPoints(), level);
            char input = GameView::getUserInput();
            if (input == 'b') {
                model.addPoint();
                if (model.NextLevel()) {
                    level++;
                }
            } else if (input == 'e') {
                cout << "Program zakonczony.\n";
                break;
            } else {
                cout << "Wprowadzono nieobslugiwane wejscie. Akceptowane pola wyboru to 'b' oraz 'e'.\n";
            }
        }
    }
};

int main() {
    GameModel model;
    GameView view;
    GameController controller(model, view);

    controller.launch();

    return 0;
}
