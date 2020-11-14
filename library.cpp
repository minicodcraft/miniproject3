#include <fstream>
#include <vector>
#include "library.h"
using namespace std;

/*
  This function populates the names and times vectors using the data from
  the "players.dat" file without changing the order of the players. 
  These two vector objects are parallel. That is, 
  names[0] and times[0] store the name and time for the best player
  names[1] and times[1] store the name and time for the second best player
  and so on
*/
void collect_data(vector<string>& names, vector<unsigned>& times) {
  ifstream input("players.dat");
  string credit, name;
  char ch;
  int minute, second; 
  getline(input, credit);
  while (!input.eof()) {
    input >> name >> minute >> ch >> second >> ch;
    input.ignore();
    names.push_back(name);
    times.push_back(minute * 60 + second);
  }
  input.close();
}
