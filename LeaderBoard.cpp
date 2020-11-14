//to be implemented
#include <iostream>
#include <vector>
#include <iomanip>
#include "library.h"
#include "LeaderBoard.h"

using namespace std;


LeaderBoard::LeaderBoard(){
  this->head_ = nullptr;
  this->tail_ = nullptr;
  nPlayers_ = 0;
}

LeaderBoard::LeaderBoard(const vector<string>& names, const vector<unsigned>& times){
  this->head_ = nullptr;
  this->tail_ = nullptr;
  nPlayers_ = 0;

  for(int loop = 0; loop < names.size(); loop++){
    Player* ptr = new Player;
    ptr->username = names[loop];
    ptr->seconds = times[loop];
    ptr->next = nullptr;

    if(head_== nullptr){
      this->head_ = ptr;
      this->tail_ = head_;
    }
    else{
      this->tail_->next = ptr;
      this->tail_ = ptr;
    }
  }
}

void LeaderBoard::display() const{
  cout << "RANK    PLAYER    TIME" << endl;
  cout << "======================" << endl;
  int loop = 0;
  Player* q = this->head_;
   while(q != NULL) {  
    cout << left << setw(4) << loop+1 << setw(14) << q->username << q->seconds << endl;
    q = q->next;
    loop++;
   }
   cout << "Tail is now " << tail_-> username << endl;
   delete q;
}

string LeaderBoard::getPlayer(unsigned rank) const{
  string user;
  int loop = 0;
  Player* q = this->head_;
   while(q != NULL) {  
    if(rank == loop+1){
      user = q->username;
    }
    q = q->next;
    loop++;
   }
   delete q;

  return user;

}

unsigned LeaderBoard::getPlayerTime(const string& name) const{
  int time;
  Player* q = this->head_;
   while(q != NULL) {  
    if(name == q->username){
      time = q->seconds;
    }
    q = q->next;
   }
   delete q;

  return time;

}

void LeaderBoard::addPlayer (const string& user, unsigned time){
  int rank;
  Player* finder = this->head_;
  while(finder != NULL){
    if(time > finder->seconds){
      rank++;
    }
    finder = finder->next;
  }
  delete finder;

cout << "the rank is " << rank << endl;
  
  Player* q = new Player();
  q->username = user;
  q->seconds = time;
  q->next = NULL;
  if(rank == 0){
    q->next = head_;
    head_ = q;
  }
  Player* temp = head_;
  for(int loop = 0; loop < rank; loop++){
    temp = temp->next;
  }
  q->next = temp->next;
  temp->next = q;


}
