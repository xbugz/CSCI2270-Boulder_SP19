#include <iostream>
#include "hash.hpp"
#include <string>
using namespace std;

HashTable::HashTable(int bsize){
  this->tableSize = bsize;
    hashTable = new player*[tableSize];
    for (int i = 0; i < tableSize; i++) {
      hashTable[i] = NULL;
}
}


HashTable::~HashTable(){

}

string getname(string name) {
  string name2;
  size_t pos;
  pos = name.find('\\');
  name2 = name.substr(0,pos);
  return name2;
}
player* HashTable::createPlayer(string *n){
//  cout << "TEST for Player: " << n[1] << endl;

  player *np = new player;

  string name = n[1];
  string name2;
name2 =  getname(name);
  np->name = name2;
//cout <<"TEST for Player: "<< name2 << endl;
  np->position = n[2];
  np->age = stoi(n[3]);
  np->team = n[4];

  np->G = stoi(n[5]);
  np->GS = stoi(n[6]);
  np->MP = stoi(n[7]);
  np->FG = stoi(n[8]);
  np->FGA = stoi(n[9]);

  if (np->FG==0 && np->FGA==0) {
    np->FGP = 0;
  }
  else{
    np->FGP = stof(n[10]);
  }
  np->TP = stoi(n[11]);
  np->TPA = stoi(n[12]);
  if (np->TP==0 && np->TPA==0) {
    np->TPPer = 0;
  }
  else{
    np->TPPer = stof(n[13]);
  }
  np->TWOP = stoi(n[14]);
  np->TWOPA = stoi(n[15]);
  if (np->TWOP==0 && np->TWOPA==0) {
    np->TWOPPer = 0;
  }
  else{
    np->TWOPPer = stof(n[16]);
  }
  np->efg = stof(n[17]);
  np->FT = stoi(n[18]);
  np->FTA = stoi(n[19]);

  if (np->FT==0 && np->FTA==0) {
    np->FTper = 0;
  }
  else{
    np->FTper = stof(n[20]);
  }
  np->ORB = stoi(n[21]);
  np->DRB = stoi(n[22]);
  np->TRB = stoi(n[23]);
  np->ASS = stoi(n[24]);
  np->STL = stoi(n[25]);
  np->BLK = stoi(n[26]);
  np->TOV = stoi(n[27]);

  np->PF = stoi(n[28]);
  np->PTS = stoi(n[29]);
  return np;
}

/*
Method Name: insertItem
Purpose: inserts a node with data as 'key' into the Hash Table
return: false if 'key' already exists in the table, otherwise true
*/

bool HashTable::insertPlayer(string* players)
{
  if(searchPlayer(getname(players[1]))!=NULL)
   {

    return false;
  }
  else{
  //  int index = hashFunction(players[1]);
    player* n = createPlayer(players);

   int index = hashFunction(n->name);

        if(hashTable[index]==NULL)
        {
          hashTable[index] = n;
          return true;
        }
        else
        {

          player* temp = hashTable[index];
          hashTable[index] = n;
          hashTable[index]->next = temp;
            return true;
        }
  }
}


unsigned int HashTable::hashFunction(string key){
  int count = 0;
  for (int i = 0; i < key.length(); i++) {
    count = count + key[i];
  }
  return count % tableSize;
}


void HashTable::printPlayer(player* player){

    cout << "STATS FOR " << player->name << " FROM  " << player->team << endl;
    cout << "*********************************************************" << endl;
    cout << "POSITION: " << player->position << endl;
    cout << "GAMES PLAYED: " << player->G << endl;
    cout << "GAMES STARTED: " << player->GS << endl;
    cout << "MINUTES PLAYED: " << player->MP << endl;
    cout << "FIELG GOALS: " << player->FG << endl;
    cout << "FIELD GOALS ATTEMPTED: " << player->FGA << endl;
    cout << "FIELD GOAL PERCENTAGE: " << player->FGP << endl;
    cout << "THREE POINTERS MADE: " << player->TP << endl;
    cout << "THREE POINTERS ATTEMPTED: " << player->TPA << endl;
    cout << "TWO POINT FG MADE: " << player->TWOP << endl;
    cout << "TWO POINT FG ATTEMPTED: "  << player->TWOPA << endl;
    cout << "TWO POINT FG PERCENTAGE: " << player->TWOPPer << endl;
    cout << "EFFECTIVE FIELD GOAL PERCENTAGE: " << player->efg << endl;
    cout << "FREE THROWS MADE: " << player->FT << endl;
    cout << "FREE THROWS ATTEMPTED: " << player->FTA << endl;
    cout << "FREE THROW PERCENTAGE: " << player->FTper << endl;
    cout << "OFFENSIVE REBOUND: " << player->ORB << endl;
    cout << "DEFENSIVE REBOUND: " << player->DRB << endl;
    cout << "TOTAL REBOUND: " << player->TRB << endl;
    cout << "ASSISTS: " << player->ASS << endl;
    cout << "STEALS: " << player->STL << endl;
    cout << "BLOCKS: " << player->BLK << endl;
    cout << "TURNOVERS: " << player->TOV << endl;
    cout << "PERSONAL FOULS: " << player->PF << endl;
    cout << "POINTS: " << player->PTS << endl;

}
void HashTable::printPlayerPG(player* player){
    cout << "STATS FOR " << player->name << " FROM  " << player->team << endl;
    cout << "*********************************************************" << endl;
    cout << "POSITION: " << player->position << endl;
    cout << "GAMES PLAYED: " << player->G << endl;
    cout << "GAMES STARTED: " << player->GS << endl;
    cout << "MINUTES PLAYED: " << player->MP << endl;
    cout << "FIELG GOALS PER GAME: " << player->FG << endl;
    cout << "FIELD GOALS ATTEMPTED PER GAME: " << player->FGA << endl;
    cout << "FIELD GOAL PERCENTAGE PER GAME: " << player->FGP << endl;
    cout << "THREE POINTERS MADE PER GAME: " << player->TP << endl;
    cout << "THREE POINTERS ATTEMPTED PER GAME: " << player->TPA << endl;
    cout << "TWO POINT FG MADE PER GAME: " << player->TWOP << endl;
    cout << "TWO POINT FG ATTEMPTED PER GAME: "  << player->TWOPA << endl;
    cout << "TWO POINT FG PERCENTAGE PER GAME: " << player->TWOPPer << endl;
    cout << "EFFECTIVE FIELD GOAL PERCENTAGE PER GAME: " << player->efg << endl;
    cout << "FREE THROWS MADE PER GAME: " << player->FT << endl;
    cout << "FREE THROWS ATTEMPTED PER GAME: " << player->FTA << endl;
    cout << "FREE THROW PERCENTAGE PER GAME: " << player->FTper << endl;
    cout << "OFFENSIVE REBOUND PER GAME: " << player->ORB << endl;
    cout << "DEFENSIVE REBOUND PER GAME: " << player->DRB << endl;
    cout << "TOTAL REBOUND PER GAME: " << player->TRB << endl;
    cout << "ASSISTS PER GAME: " << player->ASS << endl;
    cout << "STEALS PER GAME: " << player->STL << endl;
    cout << "BLOCKS PER GAME: " << player->BLK << endl;
    cout << "TURNOVERS PER GAME: " << player->TOV << endl;
    cout << "PERSONAL FOULS PER GAME: " << player->PF << endl;
    cout << "POINTS PER GAME: " << player->PTS << endl;

}


/*
Method Name: searchItem
Purpose: function to search for "key" in the Hash Table
return: node with "key" as it's data if found, otherwise NULL
*/

player* HashTable::searchPlayer (string key){

  int index = hashFunction(key);
  if(hashTable[index]==NULL){
    return NULL;
  }

  player * n = hashTable[index];
  while (n) {

    if (n->name == key) {
      return n;
    }
        n = n->next;
  }

  return NULL;
}
