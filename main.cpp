
// main.cpp - CRIC-IN Execution File
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
#include "cric_in.h"
using namespace std;

int main() {
    srand(time(0));

    vector<string> playerPool = {"Rohit", "Virat", "Rahul", "Hardik", "Jadeja", "Dhoni", "Gill", "Bumrah"};

    Team teamA("Strikers", {playerPool[0], playerPool[1], playerPool[2], playerPool[3]});
    Team teamB("Blasters", {playerPool[4], playerPool[5], playerPool[6], playerPool[7]});

    cout << "Welcome to CRIC-IN!\n";
    setWeather();

    int toss = rand() % 2;
    bool teamABatsFirst = toss;
    cout << "\nToss won by: " << (teamABatsFirst ? teamA.name : teamB.name) << "\n";

    if (teamABatsFirst) {
        teamA.playInnings();
        teamB.playInnings();
    } else {
        teamB.playInnings();
        teamA.playInnings();
    }

    cout << "\n--- MATCH RESULT ---\n";
    if (teamA.totalRuns > teamB.totalRuns) cout << teamA.name << " wins!\n";
    else if (teamB.totalRuns > teamA.totalRuns) cout << teamB.name << " wins!\n";
    else {
        cout << "Match tied! Proceeding to SUPER OVER!\n";
        superOver(teamA);
        superOver(teamB);
        if (teamA.totalRuns > teamB.totalRuns) cout << teamA.name << " wins Super Over!\n";
        else if (teamB.totalRuns > teamA.totalRuns) cout << teamB.name << " wins Super Over!\n";
        else cout << "Even the Super Over is tied! Match drawn!\n";
    }

    return 0;
}
