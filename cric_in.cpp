
#include "cric_in.h"
#include <cstdlib>
#include <ctime>
#include <unistd.h>

std::vector<std::string> commentary = {
    "What a shot! Straight down the ground!",
    "Clean bowled! What a delivery!",
    "The crowd goes wild!",
    "That’s a cheeky single.",
    "Smashed it through the covers!",
    "He’s gone! What a breakthrough!",
    "It’s in the air… and taken!",
    "Powerful strike! That’s six!"
};

std::string weather;

std::string getCommentary() {
    return commentary[rand() % commentary.size()];
}

void setWeather() {
    std::vector<std::string> types = {"Sunny", "Cloudy", "Windy"};
    weather = types[rand() % types.size()];
    std::cout << "\nWeather today: " << weather << std::endl;
}

Player::Player(std::string n) : name(n), runs(0), balls(0), isOut(false) {}

Team::Team(std::string n, std::vector<std::string> playerNames) : name(n), totalRuns(0), wickets(0) {
    for (std::string pn : playerNames)
        players.emplace_back(pn);
}

void Team::playInnings() {
    std::cout << "\n" << name << " starts batting...\n";
    for (int i = 0; i < 6 && wickets < players.size(); ++i) {
        Player &p = players[wickets];
        int run = rand() % 7;

        if (weather == "Cloudy") run = rand() % 6;
        if (weather == "Windy") run = (rand() % 7 > 4 ? 0 : rand() % 7);

        sleep(1);
        std::cout << "\nBall " << i+1 << ": ";

        if (run == 0) {
            std::cout << getCommentary() << " " << p.name << " is OUT!\n";
            p.isOut = true;
            wickets++;
        } else {
            p.runs += run;
            p.balls++;
            totalRuns += run;
            std::cout << getCommentary() << " " << p.name << " scores " << run << " run(s)!\n";
        }
    }
    std::cout << "\nInnings Over. Total: " << totalRuns << "/" << wickets << "\n";
}

void superOver(Team &team) {
    team.totalRuns = 0;
    team.wickets = 0;
    std::cout << "\nSUPER OVER: " << team.name << "\n";
    for (int i = 0; i < 1 && team.wickets < team.players.size(); ++i) {
        for (int b = 0; b < 6 && team.wickets < team.players.size(); ++b) {
            Player &p = team.players[team.wickets];
            int run = rand() % 7;
            sleep(1);
            std::cout << "\nSuper Over Ball " << b+1 << ": ";

            if (run == 0) {
                std::cout << getCommentary() << " " << p.name << " is OUT!\n";
                team.wickets++;
            } else {
                p.runs += run;
                p.balls++;
                team.totalRuns += run;
                std::cout << getCommentary() << " " << p.name << " scores " << run << " run(s)!\n";
            }
        }
    }
    std::cout << "\nSuper Over Total: " << team.totalRuns << "/" << team.wickets << "\n";
}
