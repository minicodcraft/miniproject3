//add header guard and appropriate includes
#ifndef LEADER_BOARD_H
#define LEADER_BOARD_H
#include <iostream>
using namespace std;

struct Player {
  std::string username;  //unique username for a playe
  unsigned seconds; //time in seconds for the player
  Player* next; //point to the next player in rank
};

class LeaderBoard {
	private:
		Player* head_;		//point to the player at the highest rank
    Player* tail_;    //point to the player at the lowest rank
    unsigned nPlayers_; //number of players
    void destroyAll();  //release all players and their respective memory units
	public:
		LeaderBoard();	//defaulty constructor to set up an empty sequence 
    LeaderBoard(const vector<string>&, const vector<unsigned>&);
		LeaderBoard(const LeaderBoard& c);	//copy constructor
		//~LeaderBoard();	//destructor
    LeaderBoard& operator=(const LeaderBoard& c);

    void display() const; //show the leader board.
    string getPlayer(unsigned rank) const; //return the name of the player by rank
    int getPlayerByUser(const string& name) const;
    unsigned getPlayerTime(const string& username) const;  //get seconds for given player
    void addPlayer(const string& username, unsigned seconds); //add a new player to an appropriate place on the leaderboard
    void removePlayer(const string& username); //remove a player by username
    void updatePlayer(const string& username, unsigned seconds); //update a player's time and their position on the leaderboard if appropriate
};

#endif