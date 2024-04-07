#ifndef GAMEVIEW_H
#define GAMEVIEW_H

#include <string>
using namespace std;

class GameView {
public:
    static void printStartHeader();
    static void printData(int points, int level);
    static char getUserInput();

private:
    static string romanNumeral(int num);
};

#endif
