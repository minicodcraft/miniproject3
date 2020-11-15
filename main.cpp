#include <iostream>
#include <vector>
#include "library.h"
#include "LeaderBoard.h"
using namespace std;

/*
  Do not delete or modify any of the statement provided to your in this project.

  During your development, it would be good to comment out blocks of code so that you can focus on selected methods. You are welcome to add test cases and/or output statements but need to remove them once the related methods have been successfully implemented.
  
  Be sure to commit your project after successfully implemented EACH method. Frequent commit is an important professional practice for software developers.
*/

int main() {
  //Collect initial leaderboard data into two parallel vectors
  vector<string> playerNames;
  vector<unsigned> playerTimes;
  collect_data(playerNames, playerTimes);

  //Create a LeaderBoard object based on the data in the parallel vectors
  LeaderBoard players(playerNames, playerTimes);
  cout << "Initial leaderboard from https://www.speedrun.com/ac#All_Debts\n";
  players.display();
  cout << endl;


  
  //Reviewing players by rank
  srand(time(NULL));
  for (int i = 0; i < 5; i++) {
    unsigned rank = rand() % playerNames.size() + 1;
    string name = players.getPlayer(rank);
    cout << name << " is ranked #" << rank;
    cout << ", with a record of ";
    cout << players.getPlayerTime(name) << endl;
  }
  cout << endl;
  /*
  //Make a deep copy of the leaderboard
  LeaderBoard backup(players);
  cout << "The backup leaderboard:\n";
  backup.display();
  cout << endl;	
  */

  
  //Add playing records from new players
  players.addPlayer("second", 2079);
  players.addPlayer("fastest", 2077);  //insert at the beginning
  players.addPlayer("notbad", 2230);   // insert in the middle
  players.addPlayer("slower", 2365);
  players.addPlayer("slowest", 2400);  // insert at end
  cout << "After adding new players\n";
  players.display();
  cout << endl;
  
  //Remove players
  players.removePlayer("fastest");
  players.removePlayer("second");
  players.removePlayer("notbad");
  players.removePlayer("slowest");
  players.removePlayer("slower");
  cout << "After removing the new players\n";
  players.display();
  cout << endl;
/*
  //Submit new time for existing players
  players.updatePlayer("coldeggman", 2035);
  players.updatePlayer("G_heinz", 2022);
  players.updatePlayer("Jonas", 2256);
  players.updatePlayer("Dalton", 2120);
  players.updatePlayer("Totalled", 2270);
  players.updatePlayer("tutelarfiber7", 2456);
  cout << "After submitting new time for existing players\n";
  players.display();
  cout << endl;
  
  
  //Recover from the backup
  players = backup;
  cout << "After recovering from the backup\n";
  players.display();
  cout << endl;
  */

	return 0;
}