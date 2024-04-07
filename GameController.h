#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include "GameModel.h"
#include "GameView.h"
#include <string>
using namespace std;

class GameController {
private:
    GameModel& model;
    GameView& view;

public:
    GameController(GameModel& model, GameView& view);
    void launch();
    void saveGame(const string& filename, int points, int level);
    bool loadGame(const string& filename, GameModel& model);
};

#endif
