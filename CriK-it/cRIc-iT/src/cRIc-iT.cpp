#include "game.h"
using namespace std;
inline void WaitEnter() {
	cout <<endl;
	cout << "Press Enter to continue...";
	while (cin.get()!='\n');
}

int main() {

    Game game;
    game.welcomeMsg(); cout  <<endl;
    sleep(1);
    WaitEnter();
    game.showAllPlayers(); cout  <<endl;
    WaitEnter();
    game.selectPlayers();
    game.showTeamPlayers();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    WaitEnter();
    game.toss();
    game.startFirstInnings();
    WaitEnter();
    game.startSecondInnings();
    game.showMatchSummary();
    return 0;
}
