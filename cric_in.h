
#ifndef CRIC_IN_H
#define CRIC_IN_H

#include <iostream>
#include <vector>
#include <string>

extern std::string weather;

std::string getCommentary();
void setWeather();

class Player {
public:
    std::string name;
    int runs;
    int balls;
    bool isOut;
    Player(std::string n);
};

class Team {
public:
    std::string name;
    std::vector<Player> players;
    int totalRuns;
    int wickets;
    Team(std::string n, std::vector<std::string> playerNames);
    void playInnings();
};

void superOver(Team &team);

#endif
