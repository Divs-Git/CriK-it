#include "game.h"

#include <Windows.h>
#include <unistd.h>

using namespace std;

inline void WaitEnter() {
	cout << "Press Enter to continue...";
	while (cin.get()!='\n');
}

Game :: Game() {
    playersPerTeam = 4;
    maxBalls = 6;
    totalPlayers = 11;

    players[0] = "Virat";
    players[1] = "Rohit";
    players[2] = "Dhawan";
    players[3] = "Rahul";
    players[4] = "Jadeja";
    players[5] = "Dhoni";
    players[6] = "Bumrah";
    players[7] = "Shami";
    players[8] = "Siraj";
    players[9] = "Bkumar";
    players[10] = "Chahal";

    isFirstInnings = false;
    teamA.name = "Team-A";
    teamB.name = "Team-B";
}

void Game :: welcomeMsg() {

    cout <<" \t " <<"-------------------------------------------" <<endl;
    cout <<" \t " <<"|=================CRIc-iT=================|" <<endl;
    cout <<" \t " <<"|                                         |" <<endl;
    cout <<" \t " <<"|   Welcome to the virtual Cricket Game   |" <<endl;
    cout <<" \t " <<"|                  (2022)                 |" <<endl;
    cout <<" \t " <<"-------------------------------------------" <<endl <<endl;
    sleep(2);
    cout <<" \t " <<"--------------------------------------------" <<endl;
    cout <<" \t " <<"|===============INSTRUCTIONS===============|" <<endl;
    cout <<" \t " <<"--------------------------------------------" <<endl;
    cout <<" \t " <<"|-----Read Carefully before proceeding-----|" <<endl;
    cout <<" \t " <<"|                                          |" <<endl;
    cout <<" \t " <<"|1. Create 2 teams (Team-A and Team-B with |" <<endl;
    cout <<" \t " <<"|   4 players each) from a given pool of   |" <<endl;
    cout <<" \t " <<"|   11 players.                            |" <<endl;
    cout <<" \t " <<"|2. Lead the toss and decide the choice of |" <<endl;
    cout <<" \t " <<"|   play.                                  |" <<endl;
    cout <<" \t " <<"|3. Each innings will be of 6 balls.       |" <<endl;
    cout <<" \t " <<"--------------------------------------------" <<endl;

}

bool Game :: validated(int index) {
	int n;
	vector<Player> players;
	players = teamA.player;
	n = players.size();
	for(int i = 0; i < n ; i++) {
		if(players[i].id == index) {
			return false;
		}
	}

	players = teamB.player;
		n = players.size();
		for(int i = 0; i < n ; i++) {
			if(players[i].id == index) {
				return false;
			}
		}
		return true;
}


void Game :: showAllPlayers() {
	cout <<endl <<endl;
	cout <<"---------------------------------------" <<endl;
	cout <<"=============Pool of Players===========" <<endl;
	cout <<"---------------------------------------" <<endl;
	sleep(2);
	for(int i = 0 ; i < totalPlayers ; i++) {
		cout <<"\t\t" <<"[" <<i+1 <<"]" <<" " <<players[i] <<endl;
	}
}

int Game:: takeIntInput() {
	int n;

	while(!(cin >>n)) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout <<"Oops! Invalid input \nPlease try again with a valid input : ";

	}
	return n;
}

void Game :: selectPlayers() {
	cout <<endl;
	cout <<"-----------------------------------------------" <<endl;
	cout <<"============Form Team-A and Team-B=============" <<endl;
	cout <<"-----------------------------------------------" <<endl;
	sleep(2);
	for(int i = 0 ; i < playersPerTeam ; i++) {

		teamASelection:
			cout <<endl;
			cout <<"Select player " <<i+1 <<" for Team-A - ";

		int playerIndexTeamA = takeIntInput();

		if(playerIndexTeamA < 1 || playerIndexTeamA > 11) {
			cout <<endl <<"Please select from the given players!" <<endl;
			goto teamASelection;
		}
		else if(!validated(playerIndexTeamA)) {
			cout <<"Player has been already selected\nPlease select another"
					"player" <<endl;
			goto teamASelection;
		}
		else{
			Player teamAPlayer;
			teamAPlayer.id = playerIndexTeamA;
			teamAPlayer.name = players[playerIndexTeamA-1];
			teamA.player.push_back(teamAPlayer);
		}

		teamBSelection:
			cout <<endl;
			cout <<"Select player " <<i+1 <<" for Team-B - ";

		int playerIndexTeamB = takeIntInput();

		if(playerIndexTeamB < 1 || playerIndexTeamB > 11) {
			cout <<endl <<"Please select from the given players!" <<endl;
			goto teamBSelection;
		}
		else if(!validated(playerIndexTeamB)) {
					cout <<endl <<"Player has been already selected!\nPlease select another player" <<endl;
					goto teamBSelection;
				}
		else {
			Player teamBPlayer;
			teamBPlayer.id = playerIndexTeamB;
			teamBPlayer.name = players[playerIndexTeamB-1];
			teamB.player.push_back(teamBPlayer);
			}
	}
}

void Game :: showTeamPlayers() {
	cout <<endl;
	vector<Player> teamAPlayers = teamA.player;
	vector<Player> teamBPlayers = teamB.player;
	cout <<endl <<endl;
	sleep(2);
	cout <<"----------------------------\t\t---------------------------------" <<endl;
	cout <<"===========Team-A==========|\t\t|============Team-B==============" <<endl;
	cout <<"----------------------------\t\t---------------------------------" <<endl;

	for(int i = 0; i < playersPerTeam; i++) {
		cout <<"|\t" <<"[" <<i+1 <<"]" <<teamAPlayers[i].name <<"\t   |" <<"\t\t" <<"|\t" <<"[" <<i+1 <<"]" <<teamBPlayers[i].name <<"\t\t|" <<endl;
	}
	cout <<"----------------------------\t\t---------------------------------" <<endl <<endl;
}

void Game :: toss() {
	cout <<endl;
	cout <<"----------------------------------------------" <<endl;
	cout <<"=================Time to Toss=================" <<endl;
	cout <<"----------------------------------------------" <<endl;
	cout <<endl;
	sleep(2);
	cout <<"Tossing the coin..." <<endl <<endl;
	sleep(4);
	srand(time(NULL));
	int randomValue = rand() % 2; // 0 or 1;

	switch(randomValue) {
		case 0:
			cout <<"Team-A won the toss" <<endl;
			tossChoice(teamA);
			break;
		case 1:
			cout <<"Team-B won the toss" <<endl;
			tossChoice(teamB);
			break;
	}
	cout <<endl;
}

void Game :: tossChoice(Team tossWinnerTeam) {
	cout <<endl;
	sleep(2);
	cout <<"Press 1 to bat or 2 to bowl first!" <<endl
			<<"1. Bat" <<endl <<"2. Bowl\n\n" <<endl;
	int tossInput = takeIntInput();
	cin.ignore(numeric_limits<streamsize>::max(),'\n');

	switch(tossInput) {
		case 1:
			cout <<endl <<tossWinnerTeam.name <<" won the toss and elected to bat "
					"first." <<endl <<endl;

			if(tossWinnerTeam.name.compare("Team-A") == 0) {
				battingTeam = &teamA;
				bowlingTeam = &teamB;
			}
			else {
				battingTeam = &teamB;
				bowlingTeam = &teamA;
			}
			break;
		case 2:
				cout <<endl <<tossWinnerTeam.name <<" won the toss and elected to bowl "
						"first." <<endl <<endl;
				if(tossWinnerTeam.name.compare("Team-A") == 0) {
								battingTeam = &teamB;
								bowlingTeam = &teamA;
							}
							else {
								battingTeam = &teamA;
								bowlingTeam = &teamB;
							}
				break;
		default:
				cout <<endl <<"Please enter a valid input!" <<endl <<endl;
				tossChoice(tossWinnerTeam);
				break;
		}
}

void Game :: startFirstInnings() {
	sleep(3);
	cout <<"\t\t" <<"||| FIRST INNINGS STARTS |||" <<endl <<endl;
	sleep(2);
	isFirstInnings = true;

	initializePlayers();
	playInnings();
}

void Game :: initializePlayers() {
	batsman = &battingTeam->player[0];
	bowler = &bowlingTeam->player[0];

	cout <<battingTeam->name <<"-" <<batsman->name <<" is batting" <<endl;
	cout <<bowlingTeam->name <<"-" <<bowler->name <<" is bowling" <<endl;
}

void Game :: playInnings() {

	for(int i = 0; i < maxBalls; i++) {
		cout <<endl;
		sleep(0.5);
		cout <<"Press Enter to bowl" <<endl;
		getchar();
		sleep(0.3);
		cout <<"Bowling..." <<endl <<endl;
		sleep(2);
		bat();

		if(!validateInnings()) {
			break;
		}
	}
}

void Game :: bat() {

	srand(time(NULL));
	int randomValue = rand() % 7; // 0 -------> 6

	//Update batting team and batsman score
	batsman->runsScored = batsman->runsScored + randomValue;
	battingTeam->totalRunsScored = battingTeam->totalRunsScored + randomValue;
	batsman->ballsPlayed = batsman->ballsPlayed + 1;

	//Update bowling team and bowler score
	bowler->ballsBowled = bowler->ballsBowled + 1;
	bowlingTeam->totalBallsBowled = bowlingTeam->totalBallsBowled + 1;
	bowler->runsGiven = bowler->runsGiven + randomValue;

	if(randomValue != 0) {
		cout <<bowler->name <<" to " <<batsman->name <<" " <<randomValue <<" runs!" <<endl;
		showInningsScore();
	}
	else {
		cout <<bowler->name <<" to " <<batsman->name <<" " <<" OUT!" <<endl;

		battingTeam->wicketsLost = battingTeam->wicketsLost + 1;
		bowler->wicketsTaken = bowler->wicketsTaken + 1;
		showInningsScore();
		int nextPlayer = battingTeam->wicketsLost;
		batsman = &battingTeam->player[nextPlayer];

	}
}

bool Game :: validateInnings() {

	if(isFirstInnings) {

		if(battingTeam->wicketsLost == playersPerTeam || bowlingTeam->totalBallsBowled == maxBalls) {
			cout <<"\t\t" <<"||| FIRST INNINGS ENDS |||" <<endl <<endl;
			cout <<battingTeam->name <<" " <<battingTeam->totalRunsScored <<" - "
					<<battingTeam->wicketsLost <<" (" <<bowlingTeam->totalBallsBowled <<")" <<endl;
			cout <<bowlingTeam->name <<" needs " <<battingTeam->totalRunsScored + 1 <<" runs to win the match." <<endl;

			return false;
		}
	}
	else {
		if(battingTeam->totalRunsScored > bowlingTeam->totalRunsScored) {
			cout <<endl <<battingTeam->name <<" WON THE MATCH!!!" <<endl <<endl;
			return false;
		}
		else if(battingTeam->wicketsLost == playersPerTeam || bowlingTeam->totalBallsBowled == maxBalls) {
			if(battingTeam->totalRunsScored < bowlingTeam->totalRunsScored) {
				cout <<endl <<bowlingTeam->name <<" WON THE MATCH!!!" <<endl <<endl;
			}
			else {
				cout <<endl <<"MATCH DRAW" <<endl <<endl;
			}
			return false;
		}
	}
	return true;
}

void Game :: showInningsScore() {
			cout <<endl;
			cout <<"---------------------------------------------------------------" <<endl;
			cout <<"\t\t" <<battingTeam->name <<" " <<battingTeam->totalRunsScored <<" - " <<battingTeam->wicketsLost <<" "
					<<"(" <<bowlingTeam->totalBallsBowled <<")" <<endl <<endl;
			cout<<"  "<<batsman->name <<" " <<batsman->runsScored <<" (" <<batsman->ballsPlayed <<") " <<"\t"
					<<bowler->name <<" " <<bowler->wicketsTaken <<" - " <<bowler->runsGiven <<" - " <<bowler->ballsBowled <<endl;
			cout <<"----------------------------------------------------------------" <<endl <<endl;
}

void Game :: startSecondInnings() {

		cout <<endl;
		sleep(2);
		cout <<"\t\t" <<"||| SECOND INNINGS STARTS |||" <<endl <<endl;
		swap(battingTeam, bowlingTeam);
		isFirstInnings = false;
		initializePlayers();
		playInnings();
}

void Game :: swap(Team *battingTeam, Team *bowlingTeam) {
	   Team temp = *battingTeam;
	   *battingTeam = *bowlingTeam;
	   *bowlingTeam = temp;
	   return;
}

void Game :: showMatchSummary() {
		cout <<endl <<endl;
		sleep(2);
		cout <<"\t\t" <<"||| MATCH ENDS |||" <<endl;
		sleep(2);
		cout <<endl;
		cout <<bowlingTeam->name <<" " <<bowlingTeam->totalRunsScored <<"-" <<bowlingTeam->wicketsLost <<"(" <<battingTeam->totalBallsBowled <<")" <<endl;
		cout <<"=========================================================="<<endl;
		cout <<"| PLAYER \t\t BATTING \t\t BOWLING |" <<endl;
		for(int i = 0 ; i < playersPerTeam ; i++) {
			Player thePlayer = bowlingTeam->player[i];

			cout <<"|--------------------------------------------------------|" <<endl;
			cout <<"| " <<"[" <<i+1 <<"]" <<" "	<<thePlayer.name <<" \t\t " <<thePlayer.runsScored <<"(" <<thePlayer.ballsPlayed <<")" <<" \t\t "
					<<thePlayer.ballsBowled <<"-" <<thePlayer.runsGiven <<"-" <<thePlayer.wicketsTaken <<" \t\t |" <<endl;
		}
		cout <<"=========================================================="<<endl;

		cout <<endl;
		cout <<battingTeam->name <<" " <<battingTeam->totalRunsScored <<"-" <<battingTeam->wicketsLost <<"(" <<bowlingTeam->totalBallsBowled <<")" <<endl;
		cout <<"=========================================================="<<endl;
		cout <<"| PLAYER \t\t BATTING \t\t BOWLING |" <<endl;
			for(int i = 0 ; i < playersPerTeam ; i++) {
				Player thePlayer = battingTeam->player[i];

				cout <<"|--------------------------------------------------------|" <<endl;
				cout <<"| " <<"[" <<i+1 <<"]" <<" "	<<thePlayer.name <<" \t\t " <<thePlayer.runsScored <<"(" <<thePlayer.ballsPlayed <<")" <<" \t\t "
							<<thePlayer.ballsBowled <<"-" <<thePlayer.runsGiven <<"-" <<thePlayer.wicketsTaken <<" \t\t |" <<endl;
				}
				cout <<"=========================================================="<<endl;
}
