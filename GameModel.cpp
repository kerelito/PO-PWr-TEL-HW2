#include "GameModel.h"

GameModel::GameModel() : points(0), level(1) {}

void GameModel::addPoint() {
    points++;
}

void GameModel::setPoints(int newPoints) {
    points = newPoints;
}

int GameModel::getPoints() const {
    return points;
}

void GameModel::setLevel(int newLevel) {
    level = newLevel;
}

int GameModel::getLevel() const {
    return level;
}

bool GameModel::nextLevel() const {
    return (points % 5 == 0);
}
