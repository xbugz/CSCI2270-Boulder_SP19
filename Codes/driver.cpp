#include <iostream>
#include "hash.hpp"
#include "heap.hpp"
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

void dispmenu(){
  cout << "Pick an option: " << endl;
  cout << "1: Select a Player " << endl;
  cout << "2: Compare Similar Players " << endl;
  cout << "3: Compare any Players " << endl;
  cout << "4: Best at **CHOOSE A STAT** " << endl;
  cout << "5: Choose a team " << endl;
  cout << "6: Quit" << endl;
}

void dispStats()
{
  cout<<"For field goals enter: FG"<<endl;
  cout<<"For field goal attempts enter: FGA"<<endl;
  cout<<"For field goal percentage enter: FGP"<<endl;
  cout<<"For three pointers made enter: TP"<<endl;
  cout<<"For three pointers attempts enter: TPA"<<endl;
  cout<<"For three pointer percent enter: TPPer"<<endl;
  cout<<"For two pointers made enter: TWOP"<<endl;
  cout<<"For two pointers attempts enter: TWOPA"<<endl;
  cout<<"For two pointer percentage enter: TWOPer"<<endl;
  cout<<"For effective fielg goal percentage enter: efg"<<endl;
  cout<<"For free throws made enter: FT"<<endl;
  cout<<"For free throw attempts enter: FTA"<<endl;
  cout<<"For free throws percentage enter: FTper"<<endl;
  cout<<"For offensive rebounds enter: ORB"<<endl;
  cout<<"For defenseive rebounds enter: DRB"<<endl;
  cout<<"For total rebounds enter: TRB"<<endl;
  cout<<"For total assists enter: ASS"<<endl;
  cout<<"For total steals enter: STL"<<endl;
  cout<<"For total blocks enter: BLK"<<endl;
  cout<<"For total turnovers enter: TOV"<<endl;
  cout<<"For total personal fouls enter: PF"<<endl;
  cout<<"For total points enter: PTS"<<endl;
}

int main(int argc, char const *argv[]) {
  HashTable playerseason(5000);
  HashTable playerpergame(5000);
  player * np;
  string word, word2;
  string players[30];
  string name;
  int datatype;
  player **c3;
  int num;

  ifstream file("nbatotaldata.txt");
  if (file.is_open()) {
    while (getline(file,word)) {
      stringstream s(word);
      int c = 0 ;
      while (getline(s,word2,',')) {
            players[c] = word2;
            c++;
      }
      if (stoi(players[0])==14) {
        break;
      }
        playerseason.insertPlayer(players);
    }
  }


  ifstream file2("nbapergamedata.txt");
  if (file2.is_open()) {
    while (getline(file2,word)) {
      stringstream s(word);
      int c = 0 ;
      while (getline(s,word2,',')) {
            players[c] = word2;
            c++;
      }
        if (stoi(players[0])==100){
          break;
        }
        playerpergame.insertPlayer(players);
    }
  }

  int menu = 0;
  while (menu != 6) {
    dispmenu();
    cin >> menu;

    switch (menu) {

      case 1:
      {
      cout << "Enter 1 for season statistics" << endl << "Enter 2 for per game statistics " << endl;
      cin >> datatype;
      cin.ignore();
      cout << "Enter Player Full Name: " << endl;
      getline(cin, name);
      if (datatype == 1) {

        np = playerseason.searchPlayer(name);
          if (np!=nullptr) {
            cout << endl;
              playerseason.printPlayer(np);
              cout << endl;
          }
          else{
            cout << "Invalid entry, try again!" << endl;
          }
      }


      else if(datatype == 2){

        np = playerpergame.searchPlayer(name);
            if (np!=nullptr) {
                playerpergame.printPlayerPG(np);
            }
            else{
              cout << "Invalid entry, try again!" << endl;
            }
      }
      else{
        cout << " Be sure to enter a 1 or a 2!" << endl;
      }
      };
      break;

      case 2:{
      //IMPLEMENT BST
      cout<<"case 2";};
      break;

      case 3:{
    //  int num;

    cout << "How many players would you like to look at it?" << endl;
    cin >> num;
    cin.ignore();
  *c3 = c3[num];
    for (int i = 0; i < num; i++) {

      string names;
      cout << "Enter Player " << i+1 << endl;
      getline(cin,names);

      if (playerseason.searchPlayer(names)!=NULL) {
          c3[i] = playerseason.searchPlayer(names);
      }
      else
      {
        cout << "Invalid Entry! Try Again!" << endl;
        i--;
      }
    }

    for (int i = 0; i < num; i++) {
      cout << endl;
      playerseason.printPlayer(c3[i]);
      cout << endl;
      }
    };
      break;

      case 4:{//max heap
        cout<<"\n";
        cout<<"You chose option: "<<menu<<endl;
        cout<<"\n";
        string stat;
        string stat_type;
        bool done;
        done = false;
        Heap h(500);
        cout<<"Insert Statistic you want to see: \n";
        dispStats();
        cin>>stat;
        cout<<"Season Total "<<stat<<"? or "<<stat<<" Per game?"<<endl;
        cin>>stat_type;
        cout<<"\n";
cout<<"Printing np[x] " << getline(cin,names)<<endl;
}
        if(stat_type == "total" || stat_type=="Total")
        {
          if(stat=="FG")
          {
            // h.addToHeap();
          }
          if(stat=="FGA")
          {
          // h.addToHeap();
          }
          if(stat=="FGP")
          {
          // h.addToHeap();
          }
          if(stat=="TP")
          {
          // h.addToHeap();
          }
          if(stat=="TPA")
          {
          // h.addToHeap();
          }
          if(stat=="TPPer")
          {
          // h.addToHeap();
          }
          if(stat=="TWOP")
          {
          // h.addToHeap();
          }
          if(stat=="TWOPA")
          {
          // h.addToHeap();
          }
          if(stat=="TWOPPer")
          {
          // h.addToHeap();
          }
          if(stat=="efg")
          {
          // h.addToHeap();
          }
          if(stat=="FT")
          {
          // h.addToHeap();
          }
          if(stat=="FTA")
          {
          // h.addToHeap();
          }
          if(stat=="FTper")
          {
          // h.addToHeap();
          }
          if(stat=="ORB")
          {
          // h.addToHeap();
          }
          if(stat=="TRB")
          {
          // h.addToHeap();
          }
          if(stat=="ASS")
          {
          // h.addToHeap();
          }
          if(stat=="STL")
          {
          // h.addToHeap();
          }
          if(stat=="BLK")
          {
          // h.addToHeap();
          }
          if(stat=="tOV")
          {
          // h.addToHeap();
          }
          if(stat=="PF")
          {
          // h.addToHeap();
          }
          if(stat=="PTS")
          {
          // h.addToHeap();
          }
        }
        else if(stat_type == "per game" || stat_type=="Per game")
        {
          if(stat=="FG")
          {
            // h.addToHeap();
          }
          if(stat=="FGA")
          {
          // h.addToHeap();
          }
          if(stat=="FGP")
          {
          // h.addToHeap();
          }
          if(stat=="TP")
          {
          // h.addToHeap();
          }
          if(stat=="TPA")
          {
          // h.addToHeap();
          }
          if(stat=="TPPer")
          {
          // h.addToHeap();
          }
          if(stat=="TWOP")
          {
          // h.addToHeap();
          }
          if(stat=="TWOPA")
          {
          // h.addToHeap();
          }
          if(stat=="TWOPPer")
          {
          // h.addToHeap();
          }
          if(stat=="efg")
          {
          // h.addToHeap();
          }
          if(stat=="FT")
          {
          // h.addToHeap();
          }
          if(stat=="FTA")
          {
          // h.addToHeap();
          }
          if(stat=="FTper")
          {
          // h.addToHeap();
          }
          if(stat=="ORB")
          {
          // h.addToHeap();
          }
          if(stat=="TRB")
          {
          // h.addToHeap();
          }
          if(stat=="ASS")
          {
          // h.addToHeap();
          }
          if(stat=="STL")
          {
          // h.addToHeap();
          }
          if(stat=="BLK")
          {
          // h.addToHeap();
          }
          if(stat=="tOV")
          {
          // h.addToHeap();
          }
          if(stat=="PF")
          {
          //// h.addToHeap();
          }
          if(stat=="PTS")
          {
        //  // h.addToHeap();
          }

        }
        else
        {
          cout<<"Please enter either Total or Per game ";
        };
      cout<<"Creating Max heap with stat: "<<stat<<endl;
      if(stat == "FG")
      for(int x = 0;x<29;x++){
    //  h.removeFromHeap();
    cout<<"printing Heap"<<endl;
    //  h.printHeap();
    };
      break;

      case 5:{
      //IMPLEMENT EITHER BST OR MAXHEAP
      cout<<"case 5";
    };
      break;
      case 6:
        menu = 6;
      cout<<"Thanks for using our program!"<<endl;
      break;
    }
  }

  return 0;
}
