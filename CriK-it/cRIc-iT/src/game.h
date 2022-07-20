#include <iostream>
#include <cstdlib>
#include <cstring>
#include <limits>
#include <unistd.h>
#include <ctime>
#include "team.h"


class Game {
    public:
        Game();
        int playersPerTeam;
        int maxBalls;
        int totalPlayers;
        std::string players[11];

        bool isFirstInnings;
        Team teamA, teamB;
        Team *battingTeam, *bowlingTeam;
        Player *batsman, *bowler;

        void welcomeMsg();
        void showAllPlayers();
        int takeIntInput();
        void selectPlayers();
        bool validated(int);
        void showTeamPlayers();
        void toss();
        void tossChoice(Team);
        void startFirstInnings();
        void initializePlayers();
        void playInnings();
        void bat();
        bool validateInnings();
        void showInningsScore();
        void startSecondInnings();
        void swap(Team*, Team*);
        void showMatchSummary();
};

