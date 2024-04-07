#include <iostream>
#include "GameController.h"
#include "GameModel.h"
#include "GameView.h"

int main() {
    GameModel model;
    GameView view;
    GameController controller(model, view);


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
