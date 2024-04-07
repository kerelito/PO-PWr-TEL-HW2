#ifndef GAMEMODEL_H
#define GAMEMODEL_H

class GameModel {
private:
    int points;
    int level;

public:
    GameModel();

    void addPoint();
    void setPoints(int newPoints);
    int getPoints() const;
    void setLevel(int newLevel);
    int getLevel() const;
    bool nextLevel() const;
};

#endif
