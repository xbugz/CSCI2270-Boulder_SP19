#include <iostream>
#include "hash.hpp"
#include <fstream>
#include <string>
#include <sstream>
#include "heap.hpp"
#include "BSTNBA.hpp"

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
int count = 0;
  ifstream file("nbatotaldata.txt");
  if (file.is_open()) {
    while (getline(file,word)) {
      stringstream s(word);
      int c = 0 ;
      while (getline(s,word2,',')) {
            players[c] = word2;
            c++;
      }
    //  if (stoi(players[0])==100) {
        //break;
      //}
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
      //  if (stoi(players[0])==100){
        //  break;
      //  }
        playerpergame.insertPlayer(players);
    }
  }


  int menu = 0;
  while (menu != 6) {
    dispmenu();
    cin >> menu;

    switch (menu) {
      case 1:


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
break;


      case 2:{
      //this is where the BST comes in
          string playername;
          cout<<"Enter the primary player you want to compare"<<endl;
          cin>>playername;
          player *newplayer=playerseason.searchPlayer(playername);
          BST players(newplayer);
          string stat;
          cout<<"Enter the stat you want to compare"<<endl;
          cin>>stat;

          int choice;
          while (choice!=2)
          {
            cout<<"Enter 1 to enter more players and 2 to quit"<<endl;
            cin>>choice;

            switch (choice)
            {
              case 1:
              {
              string newplayername;
              cout<<"Enter the player's name"<<endl;
              getline(cin, newplayername);
              player *anewplayer=playerseason.searchPlayer(newplayername);
              players.addNode(anewplayer, stat);
              break;
              }

              case 2:
              cout<<"This is a representation of all the players you selected and how they fare against "<<playername<<endl;
              players.printTree(5, stat);
              break;
              }
            }
          }
      break;

      case 3:{
    //  int num;

    cout << "How many players would you like to look at?" << endl;
    cin >> num;
    cin.ignore();
  *c3 = c3[num];
    for (int i = 0; i < num; i++) {

      string names;
      cout << "Enter Player " << i+1 << endl;
      getline(cin,names);

      if (playerseason.searchPlayer(names)!=nullptr) {
          c3[i] = playerseason.searchPlayer(names);
      }
      else{
        cout << "Invalid Entry! Try Again!" << endl;
        i--;
      }

    }

    for (int i = 0; i < num; i++) {
      cout << endl;
      playerseason.printPlayer(c3[i]);
      cout << endl;
    }
  }
      break;
      case 4:
      {//max heap
              cout<<"\n";
              cout<<"You chose option: "<<menu<<endl;
              cout<<"\n";
              string stat;
              string name;
              string stat_type;
              bool done;
              done = false;
              cout<<"Insert Statistic you want to see: \n";
              dispStats();
              cin>>stat;
              cout<<"Season Total (total) "<<stat<<"? or "<<stat<<" Per game (game) ?"<<endl;
              cin>>stat_type;
              cout<<"\n";
              if(stat_type == "total" || stat_type=="Total")
              {
                if(stat=="FG")
                {
                  Heap fg(5000); //initialize heap with size == # of buckets
                   for (int i = 0; i < 5000; i++) //go through TOTAL hash bucket players and read in the FG stat
                   {
                     if(playerpergame.returnindex(i)!=nullptr)
                     {
                         fg.addToHeap(playerpergame.returnindex(i)->FG); //add fg stat to heap
                         if(fg.getMax() == playerpergame.returnindex(i)->FG)
                         {
                           np = playerpergame.returnindex(i);
                         }
                     }

                   }
                   string d;
                   cout<<"Do you want to see all stats? Y or N **Warning chosing Y prints a lot of stats so be ready** "<<endl;
                   cin>>d;
                   if(d=="Y"||d=="y"){fg.printHeap();}
                 cout<<np->name<<" on team "<<np->team<<" has the highest "<<stat<<" which is: "<<fg.getMax()<<endl; //print out Highest stat
                }
                if(stat=="FGA")
                {
                  Heap fga(5000); //initialize heap with size == # of buckets
                   for (int i = 0; i < 5000; i++) //go through TOTAL hash bucket players and read in the FG stat
                   {
                     if(playerpergame.returnindex(i)!=nullptr)
                     {
                         fga.addToHeap(playerpergame.returnindex(i)->FGA); //add fg stat to heap
                         if(fga.getMax() == playerpergame.returnindex(i)->FGA)
                         {
                           np = playerpergame.returnindex(i);
                         }
                     }

                   }
                   string d;
                   cout<<"Do you want to see all stats? Y or N **Warning chosing Y prints a lot of stats so be ready** "<<endl;
                   cin>>d;
                   if(d=="Y"||d=="y"){fga.printHeap();}
                 cout<<np->name<<" on team "<<np->team<<" has the highest "<<stat<<" which is: "<<fga.getMax()<<endl; //print out Highest stat
                }
                if(stat=="FGP")
                {
                  Heap fgp(5000); //initialize heap with size == # of buckets
                   for (int i = 0; i < 5000; i++) //go through TOTAL hash bucket players and read in the FG stat
                   {
                     if(playerpergame.returnindex(i)!=nullptr)
                     {
                         fgp.addToHeap(playerpergame.returnindex(i)->FGP); //add fg stat to heap
                         if(fgp.getMax() == playerpergame.returnindex(i)->FGP)
                         {
                           np = playerpergame.returnindex(i);
                         }
                     }

                   }
                   string d;
                   cout<<"Do you want to see all stats? Y or N **Warning chosing Y prints a lot of stats so be ready** "<<endl;
                   cin>>d;
                   if(d=="Y"||d=="y"){fgp.printHeap();}
                 cout<<np->name<<" on team "<<np->team<<" has the highest "<<stat<<" which is: "<<fgp.getMax()<<endl; //print out Highest stat
                }
                if(stat=="TP")
                {
                  Heap tp(5000); //initialize heap with size == # of buckets
                   for (int i = 0; i < 5000; i++) //go through TOTAL hash bucket players and read in the FG stat
                   {
                     if(playerpergame.returnindex(i)!=nullptr)
                     {
                         tp.addToHeap(playerpergame.returnindex(i)->TP); //add fg stat to heap
                         if(tp.getMax() == playerpergame.returnindex(i)->TP)
                         {
                           np = playerpergame.returnindex(i);
                         }
                     }

                   }
                   string d;
                   cout<<"Do you want to see all stats? Y or N **Warning chosing Y prints a lot of stats so be ready** "<<endl;
                   cin>>d;
                   if(d=="Y"||d=="y"){tp.printHeap();}
                 cout<<np->name<<" on team "<<np->team<<" has the highest "<<stat<<" which is: "<<tp.getMax()<<endl; //print out Highest stat
                }
                if(stat=="TPA")
                {
                  Heap tpa(5000); //initialize heap with size == # of buckets
                   for (int i = 0; i < 5000; i++) //go through TOTAL hash bucket players and read in the FG stat
                   {
                     if(playerpergame.returnindex(i)!=nullptr)
                     {
                         tpa.addToHeap(playerpergame.returnindex(i)->TPA); //add fg stat to heap
                         if(tpa.getMax() == playerpergame.returnindex(i)->TPA)
                         {
                           np = playerpergame.returnindex(i);
                         }
                     }

                   }
                   string d;
                   cout<<"Do you want to see all stats? Y or N **Warning chosing Y prints a lot of stats so be ready** "<<endl;
                   cin>>d;
                   if(d=="Y"||d=="y"){tpa.printHeap();}
                 cout<<np->name<<" on team "<<np->team<<" has the highest "<<stat<<" which is: "<<tpa.getMax()<<endl; //print out Highest stat
                }
                if(stat=="TPPer")
                {
                  Heap tpper(5000); //initialize heap with size == # of buckets
                   for (int i = 0; i < 5000; i++) //go through TOTAL hash bucket players and read in the stat
                   {
                     if(playerpergame.returnindex(i)!=nullptr)
                     {
                         tpper.addToHeap(playerpergame.returnindex(i)->TPPer); //add stat to heap
                         if(tpper.getMax() == playerpergame.returnindex(i)->TPPer)
                         {
                           np = playerpergame.returnindex(i);
                         }
                     }

                   }
                   string d;
                   cout<<"Do you want to see all stats? Y or N **Warning chosing Y prints a lot of stats so be ready** "<<endl;
                   cin>>d;
                   if(d=="Y"||d=="y"){tpper.printHeap();}
                 cout<<np->name<<" on team "<<np->team<<" has the highest "<<stat<<" which is: "<<tpper.getMax()<<endl; //print out Highest stat
                }
                if(stat=="TWOP")
                {
                  Heap twop(5000); //initialize heap with size == # of buckets
                   for (int i = 0; i < 5000; i++) //go through TOTAL hash bucket players and read in the FG stat
                   {
                     if(playerpergame.returnindex(i)!=nullptr)
                     {
                         twop.addToHeap(playerpergame.returnindex(i)->TWOP); //add stat to heap
                         if(twop.getMax() == playerpergame.returnindex(i)->TWOP)
                         {
                           np = playerpergame.returnindex(i);
                         }
                     }

                   }
                   string d;
                   cout<<"Do you want to see all stats? Y or N **Warning chosing Y prints a lot of stats so be ready** "<<endl;
                   cin>>d;
                   if(d=="Y"||d=="y"){twop.printHeap();}
                 cout<<np->name<<" on team "<<np->team<<" has the highest "<<stat<<" which is: "<<twop.getMax()<<endl; //print out Highest stat
                }
                if(stat=="TWOPA")
                {
                  Heap twopa(5000); //initialize heap with size == # of buckets
                   for (int i = 0; i < 5000; i++) //go through TOTAL hash bucket players and read in the FG stat
                   {
                     if(playerpergame.returnindex(i)!=nullptr)
                     {
                         twopa.addToHeap(playerpergame.returnindex(i)->TWOPA); //add stat to heap
                         if(twopa.getMax() == playerpergame.returnindex(i)->TWOPA)
                         {
                           np = playerpergame.returnindex(i);
                         }
                     }

                   }
                   string d;
                   cout<<"Do you want to see all stats? Y or N **Warning chosing Y prints a lot of stats so be ready** "<<endl;
                   cin>>d;
                   if(d=="Y"||d=="y"){twopa.printHeap();}
                 cout<<np->name<<" on team "<<np->team<<" has the highest "<<stat<<" which is: "<<twopa.getMax()<<endl; //print out Highest stat
                }
                if(stat=="TWOPPer")
                {
                  Heap twopper(5000); //initialize heap with size == # of buckets
                   for (int i = 0; i < 5000; i++) //go through TOTAL hash bucket players and read in the FG stat
                   {
                     if(playerpergame.returnindex(i)!=nullptr)
                     {
                         twopper.addToHeap(playerpergame.returnindex(i)->TWOPPer); //add fg stat to heap
                         if(twopper.getMax() == playerpergame.returnindex(i)->TWOPPer)
                         {
                           np = playerpergame.returnindex(i);
                         }
                     }

                   }
                   string d;
                   cout<<"Do you want to see all stats? Y or N **Warning chosing Y prints a lot of stats so be ready** "<<endl;
                   cin>>d;
                   if(d=="Y"||d=="y"){twopper.printHeap();}
                 cout<<np->name<<" on team "<<np->team<<" has the highest "<<stat<<" which is: "<<twopper.getMax()<<endl; //print out Highest stat
                }
                if(stat=="efg")
                {
                  Heap efg(5000); //initialize heap with size == # of buckets
                   for (int i = 0; i < 5000; i++) //go through TOTAL hash bucket players and read in the FG stat
                   {
                     if(playerpergame.returnindex(i)!=nullptr)
                     {
                         efg.addToHeap(playerpergame.returnindex(i)->efg); //add fg stat to heap
                         if(efg.getMax() == playerpergame.returnindex(i)->efg)
                         {
                           np = playerpergame.returnindex(i);
                         }
                     }

                   }
                   string d;
                   cout<<"Do you want to see all stats? Y or N **Warning chosing Y prints a lot of stats so be ready** "<<endl;
                   cin>>d;
                   if(d=="Y"||d=="y"){efg.printHeap();}
                 cout<<np->name<<" on team "<<np->team<<" has the highest "<<stat<<" which is: "<<efg.getMax()<<endl; //print out Highest stat
                }
                if(stat=="FT")
                {
                  Heap ft(5000); //initialize heap with size == # of buckets
                   for (int i = 0; i < 5000; i++) //go through TOTAL hash bucket players and read in the stat
                   {
                     if(playerpergame.returnindex(i)!=nullptr)
                     {
                         ft.addToHeap(playerpergame.returnindex(i)->FT); //add stat to heap
                         if(ft.getMax() == playerpergame.returnindex(i)->FT)
                         {
                           np = playerpergame.returnindex(i);
                         }
                     }

                   }
                   string d;
                   cout<<"Do you want to see all stats? Y or N **Warning chosing Y prints a lot of stats so be ready** "<<endl;
                   cin>>d;
                   if(d=="Y"||d=="y"){ft.printHeap();}
                 cout<<np->name<<" on team "<<np->team<<" has the highest "<<stat<<" which is: "<<ft.getMax()<<endl; //print out Highest stat
                }
                if(stat=="FTA")
                {
                  Heap fta(5000); //initialize heap with size == # of buckets
                   for (int i = 0; i < 5000; i++) //go through TOTAL hash bucket players and read in the stat
                   {
                     if(playerpergame.returnindex(i)!=nullptr)
                     {
                         fta.addToHeap(playerpergame.returnindex(i)->FTA); //add stat to heap
                         if(fta.getMax() == playerpergame.returnindex(i)->FTA)
                         {
                           np = playerpergame.returnindex(i);
                         }
                     }

                   }
                   string d;
                   cout<<"Do you want to see all stats? Y or N  (warning this can be a lot of stats) "<<endl;
                   cin>>d;
                   if(d=="Y"||d=="y"){fta.printHeap();}
                 cout<<np->name<<" on team "<<np->team<<" has the highest "<<stat<<" which is: "<<fta.getMax()<<endl; //print out Highest stat
                 }
                if(stat=="FTper")
                {
                  Heap ftper(5000); //initialize heap with size == # of buckets
                   for (int i = 0; i < 5000; i++) //go through TOTAL hash bucket players and read in the stat
                   {
                     if(playerpergame.returnindex(i)!=nullptr)
                     {
                         ftper.addToHeap(playerpergame.returnindex(i)->FTper); //add stat to heap
                         if(ftper.getMax() == playerpergame.returnindex(i)->FTper)
                         {
                           np = playerpergame.returnindex(i);
                         }
                     }

                   }
                   string d;
                   cout<<"Do you want to see all stats? Y or N **Warning chosing Y prints a lot of stats so be ready** "<<endl;
                   cin>>d;
                   if(d=="Y"||d=="y"){ftper.printHeap();}
                 cout<<np->name<<" on team "<<np->team<<" has the highest "<<stat<<" which is: "<<ftper.getMax()<<endl; //print out Highest stat
                }
                if(stat=="ORB")
                {
                  Heap orb(5000); //initialize heap with size == # of buckets
                   for (int i = 0; i < 5000; i++) //go through TOTAL hash bucket players and read in the stat
                   {
                     if(playerpergame.returnindex(i)!=nullptr)
                     {
                         orb.addToHeap(playerpergame.returnindex(i)->ORB); //add stat to heap
                         if(orb.getMax() == playerpergame.returnindex(i)->ORB)
                         {
                           np = playerpergame.returnindex(i);
                         }
                     }

                   }
                   string d;
                   cout<<"Do you want to see all stats? Y or N **Warning chosing Y prints a lot of stats so be ready** "<<endl;
                   cin>>d;
                   if(d=="Y"||d=="y"){orb.printHeap();}
                 cout<<np->name<<" on team "<<np->team<<" has the highest "<<stat<<" which is: "<<orb.getMax()<<endl; //print out Highest stat
                }
                if(stat=="TRB")
                {
                  Heap trb(5000); //initialize heap with size == # of buckets
                   for (int i = 0; i < 5000; i++) //go through TOTAL hash bucket players and read in the stat
                   {
                     if(playerpergame.returnindex(i)!=nullptr)
                     {
                         trb.addToHeap(playerpergame.returnindex(i)->TRB); //add stat to heap
                         if(trb.getMax() == playerpergame.returnindex(i)->TRB)
                         {
                           np = playerpergame.returnindex(i);
                         }
                     }

                   }
                   string d;
                   cout<<"Do you want to see all stats? Y or N **Warning chosing Y prints a lot of stats so be ready** "<<endl;
                   cin>>d;
                   if(d=="Y"||d=="y"){trb.printHeap();}
                 cout<<np->name<<" on team "<<np->team<<" has the highest "<<stat<<" which is: "<<trb.getMax()<<endl; //print out Highest stat
                 }
                if(stat=="ASS")
                {
                  Heap ass(5000); //initialize heap with size == # of buckets
                   for (int i = 0; i < 5000; i++) //go through TOTAL hash bucket players and read in the stat
                   {
                     if(playerpergame.returnindex(i)!=nullptr)
                     {
                         ass.addToHeap(playerpergame.returnindex(i)->ASS); //add stat to heap
                         if(ass.getMax() == playerpergame.returnindex(i)->ASS)
                         {
                           np = playerpergame.returnindex(i);
                         }
                     }

                   }
                   string d;
                   cout<<"Do you want to see all stats? Y or N **Warning chosing Y prints a lot of stats so be ready** "<<endl;
                   cin>>d;
                   if(d=="Y"||d=="y"){ass.printHeap();}
                 cout<<np->name<<" on team "<<np->team<<" has the highest "<<stat<<" which is: "<<ass.getMax()<<endl; //print out Highest stat
                }
                if(stat=="STL")
                {
                  Heap stl(5000); //initialize heap with size == # of buckets
                   for (int i = 0; i < 5000; i++) //go through TOTAL hash bucket players and read in the stat
                   {
                     if(playerpergame.returnindex(i)!=nullptr)
                     {
                         stl.addToHeap(playerpergame.returnindex(i)->STL); //add stat to heap
                         if(stl.getMax() == playerpergame.returnindex(i)->STL)
                         {
                           np = playerpergame.returnindex(i);
                         }
                     }

                   }
                   string d;
                   cout<<"Do you want to see all stats? Y or N **Warning chosing Y prints a lot of stats so be ready** "<<endl;
                   cin>>d;
                   if(d=="Y"||d=="y"){stl.printHeap();}
                 cout<<np->name<<" on team "<<np->team<<" has the highest "<<stat<<" which is: "<<stl.getMax()<<endl; //print out Highest stat
                  }
                if(stat=="BLK")
                {
                  Heap blk(5000); //initialize heap with size == # of buckets
                   for (int i = 0; i < 5000; i++) //go through TOTAL hash bucket players and read in the stat
                   {
                     if(playerpergame.returnindex(i)!=nullptr)
                     {
                         blk.addToHeap(playerpergame.returnindex(i)->BLK); //add stat to heap
                         if(blk.getMax() == playerpergame.returnindex(i)->BLK)
                         {
                           np = playerpergame.returnindex(i);
                         }
                     }
                   }
                   string d;
                   cout<<"Do you want to see all stats? Y or N **Warning chosing Y prints a lot of stats so be ready** "<<endl;
                   cin>>d;
                   if(d=="Y"||d=="y"){blk.printHeap();}
                 cout<<np->name<<" on team "<<np->team<<" has the highest "<<stat<<" which is: "<<blk.getMax()<<endl; //print out Highest stat
                  }
                if(stat=="TOV")
                {
                  Heap tov(5000); //initialize heap with size == # of buckets
                   for (int i = 0; i < 5000; i++) //go through TOTAL hash bucket players and read in the stat
                   {
                     if(playerpergame.returnindex(i)!=nullptr)
                     {
                         tov.addToHeap(playerpergame.returnindex(i)->TOV); //add stat to heap
                         if(tov.getMax() == playerpergame.returnindex(i)->TOV)
                         {
                           np = playerpergame.returnindex(i);
                         }
                     }

                   }
                   string d;
                   cout<<"Do you want to see all stats? Y or N **Warning chosing Y prints a lot of stats so be ready** "<<endl;
                   cin>>d;
                   if(d=="Y"||d=="y"){tov.printHeap();}
                 cout<<np->name<<" on team "<<np->team<<" has the highest "<<stat<<" which is: "<<tov.getMax()<<endl; //print out Highest stat
                   }
                if(stat=="PF")
                {
                 Heap pf(5000); //initialize heap with size == # of buckets
                 for (int i = 0; i < 5000; i++) //go through TOTAL hash bucket players and read in the stat
                 {
                   if(playerpergame.returnindex(i)!=nullptr)
                   {
                       pf.addToHeap(playerpergame.returnindex(i)->PF); //add stat to heap
                       if(pf.getMax() == playerpergame.returnindex(i)->PF)
                       {
                         np = playerpergame.returnindex(i);
                       }
                   }


                 }
                 string d;
                 cout<<"Do you want to see all stats? Y or N **Warning chosing Y prints a lot of stats so be ready** "<<endl;
                 cin>>d;
                 if(d=="Y"||d=="y"){pf.printHeap();}
                 cout<<np->name<<" on team "<<np->team<<" has the highest "<<stat<<" which is: "<<pf.getMax()<<endl; //print out Highest stat
                }
                if(stat=="PTS")
                {
                  Heap pts(5000); //initialize heap with size == # of buckets
                   for (int i = 0; i < 5000; i++) //go through TOTAL hash bucket players and read in the stat
                   {
                     if(playerpergame.returnindex(i)!=nullptr)
                     {
                         pts.addToHeap(playerpergame.returnindex(i)->PTS); //add stat to heap

                         if(pts.getMax() == playerpergame.returnindex(i)->PTS)
                         {
                           np = playerpergame.returnindex(i);
                         }
                     }
                   }
                   string d;
                   cout<<"Do you want to see all stats? Y or N **Warning chosing Y prints a lot of stats so be ready** "<<endl;
                   cin>>d;
                   if(d=="Y"||d=="y"){pts.printHeap();}
                   cout<<np->name<<" on team "<<np->team<<" has the highest "<<stat<<" which is: "<<pts.getMax()<<endl; //print out Highest stat
                }
              }
              if(stat_type == "game" || stat_type=="game")
              {

                                                if(stat=="FG")
                                                {

                                                  Heap pgfg(5000); //initialize heap with size == # of buckets
                                                   for (int i = 0; i < 5000; i++) //go through TOTAL hash bucket players and read in the FG stat
                                                   {
                                                     if(playerpergame.returnindex(i)!=nullptr)
                                                     {
                                                         pgfg.addToHeap(playerpergame.returnindex(i)->FG); //add fg stat to heap
                                                         if(pgfg.getMax() == playerpergame.returnindex(i)->FG)
                                                         {
                                                           np = playerpergame.returnindex(i);
                                                         }
                                                     }

                                                   }
                                                   string d;
                                                   cout<<"Do you want to see all stats? Y or N **Warning chosing Y prints a lot of stats so be ready** "<<endl;
                                                   cin>>d;
                                                   if(d=="Y"||d=="y"){pgfg.printHeap();}
                                                 cout<<np->name<<" on team "<<np->team<<" has the highest "<<stat<<" which is: "<<pgfg.getMax()<<endl;//print out Highest stat
                                                }
                                                if(stat=="FGA")
                                                {
                                                  Heap pgfga(5000); //initialize heap with size == # of buckets
                                                   for (int i = 0; i < 5000; i++) //go through TOTAL hash bucket players and read in the FG stat
                                                   {
                                                     if(playerpergame.returnindex(i)!=nullptr)
                                                     {
                                                         pgfga.addToHeap(playerpergame.returnindex(i)->FGA); //add fg stat to heap
                                                         if(pgfga.getMax() == playerpergame.returnindex(i)->FGA)
                                                         {
                                                           np = playerpergame.returnindex(i);
                                                         }
                                                     }

                                                   }
                                                   string d;
                                                   cout<<"Do you want to see all stats? Y or N **Warning chosing Y prints a lot of stats so be ready** "<<endl;
                                                   cin>>d;
                                                   if(d=="Y"||d=="y"){pgfga.printHeap();}
                                                 cout<<np->name<<" on team "<<np->team<<" has the highest "<<stat<<" which is: "<<pgfga.getMax()<<endl; //print out Highest stat
                                                }
                                                if(stat=="FGP")
                                                {
                                                  Heap pgfgp(5000); //initialize heap with size == # of buckets
                                                   for (int i = 0; i < 5000; i++) //go through TOTAL hash bucket players and read in the FG stat
                                                   {
                                                     if(playerpergame.returnindex(i)!=nullptr)
                                                     {
                                                         pgfgp.addToHeap(playerpergame.returnindex(i)->FGP); //add fg stat to heap
                                                         if(pgfgp.getMax() == playerpergame.returnindex(i)->FGP)
                                                         {
                                                           np = playerpergame.returnindex(i);
                                                         }
                                                     }

                                                   }
                                                   string d;
                                                   cout<<"Do you want to see all stats? Y or N **Warning chosing Y prints a lot of stats so be ready** "<<endl;
                                                   cin>>d;
                                                   if(d=="Y"||d=="y"){pgfgp.printHeap();}
                                                 cout<<np->name<<" on team "<<np->team<<" has the highest "<<stat<<" which is: "<<pgfgp.getMax()<<endl; //print out Highest stat
                                                }
                                                if(stat=="TP")
                                                {
                                                  Heap pgtp(5000); //initialize heap with size == # of buckets
                                                   for (int i = 0; i < 5000; i++) //go through TOTAL hash bucket players and read in the FG stat
                                                   {
                                                     if(playerpergame.returnindex(i)!=nullptr)
                                                     {
                                                         pgtp.addToHeap(playerpergame.returnindex(i)->TP); //add fg stat to heap
                                                         if(pgtp.getMax() == playerpergame.returnindex(i)->TP)
                                                         {
                                                           np = playerpergame.returnindex(i);
                                                         }
                                                     }

                                                   }
                                                   string d;
                                                   cout<<"Do you want to see all stats? Y or N **Warning chosing Y prints a lot of stats so be ready** "<<endl;
                                                   cin>>d;
                                                   if(d=="Y"||d=="y"){pgtp.printHeap();}
                                                 cout<<np->name<<" on team "<<np->team<<" has the highest "<<stat<<" which is: "<<pgtp.getMax()<<endl; //print out Highest stat
                                                }
                                                if(stat=="TPA")
                                                {
                                                  Heap pgtpa(5000); //initialize heap with size == # of buckets
                                                   for (int i = 0; i < 5000; i++) //go through TOTAL hash bucket players and read in the FG stat
                                                   {
                                                     if(playerpergame.returnindex(i)!=nullptr)
                                                     {
                                                         pgtpa.addToHeap(playerpergame.returnindex(i)->TPA); //add fg stat to heap
                                                         if(pgtpa.getMax() == playerpergame.returnindex(i)->TPA)
                                                         {
                                                           np = playerpergame.returnindex(i);
                                                         }
                                                     }

                                                   }
                                                   string d;
                                                   cout<<"Do you want to see all stats? Y or N **Warning chosing Y prints a lot of stats so be ready** "<<endl;
                                                   cin>>d;
                                                   if(d=="Y"||d=="y"){pgtpa.printHeap();}
                                                 cout<<np->name<<" on team "<<np->team<<" has the highest "<<stat<<" which is: "<<pgtpa.getMax()<<endl; //print out Highest stat
                                                }
                                                if(stat=="TPPer")
                                                {
                                                  Heap pgtpper(5000); //initialize heap with size == # of buckets
                                                   for (int i = 0; i < 5000; i++) //go through TOTAL hash bucket players and read in the stat
                                                   {
                                                     if(playerpergame.returnindex(i)!=nullptr)
                                                     {
                                                         pgtpper.addToHeap(playerpergame.returnindex(i)->TPPer); //add stat to heap
                                                         if(pgtpper.getMax() == playerpergame.returnindex(i)->TPPer)
                                                         {
                                                           np = playerpergame.returnindex(i);
                                                         }
                                                     }

                                                   }
                                                   string d;
                                                   cout<<"Do you want to see all stats? Y or N **Warning chosing Y prints a lot of stats so be ready** "<<endl;
                                                   cin>>d;
                                                   if(d=="Y"||d=="y"){pgtpper.printHeap();}
                                                 cout<<np->name<<" on team "<<np->team<<" has the highest "<<stat<<" which is: "<<pgtpper.getMax()<<endl; //print out Highest stat
                                                }
                                                if(stat=="TWOP")
                                                {
                                                  Heap pgtwop(5000); //initialize heap with size == # of buckets
                                                   for (int i = 0; i < 5000; i++) //go through TOTAL hash bucket players and read in the FG stat
                                                   {
                                                     if(playerpergame.returnindex(i)!=nullptr)
                                                     {
                                                         pgtwop.addToHeap(playerpergame.returnindex(i)->TWOP); //add stat to heap
                                                         if(pgtwop.getMax() == playerpergame.returnindex(i)->TWOP)
                                                         {
                                                           np = playerpergame.returnindex(i);
                                                         }
                                                     }

                                                   }
                                                   string d;
                                                   cout<<"Do you want to see all stats? Y or N **Warning chosing Y prints a lot of stats so be ready** "<<endl;
                                                   cin>>d;
                                                   if(d=="Y"||d=="y"){pgtwop.printHeap();}
                                                 cout<<np->name<<" on team "<<np->team<<" has the highest "<<stat<<" which is: "<<pgtwop.getMax()<<endl; //print out Highest stat
                                                }
                                                if(stat=="TWOPA")
                                                {
                                                  Heap pgtwopa(5000); //initialize heap with size == # of buckets
                                                   for (int i = 0; i < 5000; i++) //go through TOTAL hash bucket players and read in the FG stat
                                                   {
                                                     if(playerpergame.returnindex(i)!=nullptr)
                                                     {
                                                         pgtwopa.addToHeap(playerpergame.returnindex(i)->TWOPA); //add stat to heap
                                                         if(pgtwopa.getMax() == playerpergame.returnindex(i)->TWOPA)
                                                         {
                                                           np = playerpergame.returnindex(i);
                                                         }
                                                     }

                                                   }
                                                   string d;
                                                   cout<<"Do you want to see all stats? Y or N **Warning chosing Y prints a lot of stats so be ready** "<<endl;
                                                   cin>>d;
                                                   if(d=="Y"||d=="y"){pgtwopa.printHeap();}
                                                 cout<<np->name<<" on team "<<np->team<<" has the highest "<<stat<<" which is: "<<pgtwopa.getMax()<<endl; //print out Highest stat
                                                }
                                                if(stat=="TWOPPer")
                                                {
                                                  Heap pgtwopper(5000); //initialize heap with size == # of buckets
                                                   for (int i = 0; i < 5000; i++) //go through TOTAL hash bucket players and read in the FG stat
                                                   {
                                                     if(playerpergame.returnindex(i)!=nullptr)
                                                     {
                                                         pgtwopper.addToHeap(playerpergame.returnindex(i)->TWOPPer); //add fg stat to heap
                                                         if(pgtwopper.getMax() == playerpergame.returnindex(i)->TWOPPer)
                                                         {
                                                           np = playerpergame.returnindex(i);
                                                         }
                                                     }

                                                   }
                                                   string d;
                                                   cout<<"Do you want to see all stats? Y or N **Warning chosing Y prints a lot of stats so be ready** "<<endl;
                                                   cin>>d;
                                                   if(d=="Y"||d=="y"){pgtwopper.printHeap();}
                                                 cout<<np->name<<" on team "<<np->team<<" has the highest "<<stat<<" which is: "<<pgtwopper.getMax()<<endl; //print out Highest stat
                                                }
                                                if(stat=="efg")
                                                {
                                                  Heap pgefg(5000); //initialize heap with size == # of buckets
                                                   for (int i = 0; i < 5000; i++) //go through TOTAL hash bucket players and read in the FG stat
                                                   {
                                                     if(playerpergame.returnindex(i)!=nullptr)
                                                     {
                                                         pgefg.addToHeap(playerpergame.returnindex(i)->efg); //add fg stat to heap
                                                         if(pgefg.getMax() == playerpergame.returnindex(i)->efg)
                                                         {
                                                           np = playerpergame.returnindex(i);
                                                         }
                                                     }

                                                   }
                                                   string d;
                                                   cout<<"Do you want to see all stats? Y or N **Warning chosing Y prints a lot of stats so be ready** "<<endl;
                                                   cin>>d;
                                                   if(d=="Y"||d=="y"){pgefg.printHeap();}
                                                 cout<<np->name<<" on team "<<np->team<<" has the highest "<<stat<<" which is: "<<pgefg.getMax()<<endl; //print out Highest stat
                                                }
                                                if(stat=="FT")
                                                {
                                                  Heap pgft(5000); //initialize heap with size == # of buckets
                                                   for (int i = 0; i < 5000; i++) //go through TOTAL hash bucket players and read in the stat
                                                   {
                                                     if(playerpergame.returnindex(i)!=nullptr)
                                                     {
                                                         pgft.addToHeap(playerpergame.returnindex(i)->FT); //add stat to heap
                                                         if(pgft.getMax() == playerpergame.returnindex(i)->FT)
                                                         {
                                                           np = playerpergame.returnindex(i);
                                                         }
                                                     }

                                                   }
                                                   string d;
                                                   cout<<"Do you want to see all stats? Y or N **Warning chosing Y prints a lot of stats so be ready** "<<endl;
                                                   cin>>d;
                                                   if(d=="Y"||d=="y"){pgft.printHeap();}
                                                 cout<<np->name<<" on team "<<np->team<<" has the highest "<<stat<<" which is: "<<pgft.getMax()<<endl; //print out Highest stat
                                                }
                                                if(stat=="FTA")
                                                {
                                                  Heap pgfta(5000); //initialize heap with size == # of buckets
                                                   for (int i = 0; i < 5000; i++) //go through TOTAL hash bucket players and read in the stat
                                                   {
                                                     if(playerpergame.returnindex(i)!=nullptr)
                                                     {
                                                         pgfta.addToHeap(playerpergame.returnindex(i)->FTA); //add stat to heap
                                                         if(pgfta.getMax() == playerpergame.returnindex(i)->FTA)
                                                         {
                                                           np = playerpergame.returnindex(i);
                                                         }
                                                     }

                                                   }
                                                   string d;
                                                   cout<<"Do you want to see all stats? Y or N  (warning this can be a lot of stats) "<<endl;
                                                   cin>>d;
                                                   if(d=="Y"||d=="y"){pgfta.printHeap();}
                                                 cout<<np->name<<" on team "<<np->team<<" has the highest "<<stat<<" which is: "<<pgfta.getMax()<<endl; //print out Highest stat
                                                 }
                                                if(stat=="FTper")
                                                {
                                                  Heap pgftper(5000); //initialize heap with size == # of buckets
                                                   for (int i = 0; i < 5000; i++) //go through TOTAL hash bucket players and read in the stat
                                                   {
                                                     if(playerpergame.returnindex(i)!=nullptr)
                                                     {
                                                         pgftper.addToHeap(playerpergame.returnindex(i)->FTper); //add stat to heap
                                                         if(pgftper.getMax() == playerpergame.returnindex(i)->FTper)
                                                         {
                                                           np = playerpergame.returnindex(i);
                                                         }
                                                     }

                                                   }
                                                   string d;
                                                   cout<<"Do you want to see all stats? Y or N **Warning chosing Y prints a lot of stats so be ready** "<<endl;
                                                   cin>>d;
                                                   if(d=="Y"||d=="y"){pgftper.printHeap();}
                                                 cout<<np->name<<" on team "<<np->team<<" has the highest "<<stat<<" which is: "<<pgftper.getMax()<<endl; //print out Highest stat
                                                }
                                                if(stat=="ORB")
                                                {
                                                  Heap pgorb(5000); //initialize heap with size == # of buckets
                                                   for (int i = 0; i < 5000; i++) //go through TOTAL hash bucket players and read in the stat
                                                   {
                                                     if(playerpergame.returnindex(i)!=nullptr)
                                                     {
                                                         pgorb.addToHeap(playerpergame.returnindex(i)->ORB); //add stat to heap
                                                         if(pgorb.getMax() == playerpergame.returnindex(i)->ORB)
                                                         {
                                                           np = playerpergame.returnindex(i);
                                                         }
                                                     }

                                                   }
                                                   string d;
                                                   cout<<"Do you want to see all stats? Y or N **Warning chosing Y prints a lot of stats so be ready** "<<endl;
                                                   cin>>d;
                                                   if(d=="Y"||d=="y"){pgorb.printHeap();}
                                                 cout<<np->name<<" on team "<<np->team<<" has the highest "<<stat<<" which is: "<<pgorb.getMax()<<endl; //print out Highest stat
                                                }
                                                if(stat=="TRB")
                                                {
                                                  Heap pgtrb(5000); //initialize heap with size == # of buckets
                                                   for (int i = 0; i < 5000; i++) //go through TOTAL hash bucket players and read in the stat
                                                   {
                                                     if(playerpergame.returnindex(i)!=nullptr)
                                                     {
                                                         pgtrb.addToHeap(playerpergame.returnindex(i)->TRB); //add stat to heap
                                                         if(pgtrb.getMax() == playerpergame.returnindex(i)->TRB)
                                                         {
                                                           np = playerpergame.returnindex(i);
                                                         }
                                                     }

                                                   }
                                                   string d;
                                                   cout<<"Do you want to see all stats? Y or N **Warning chosing Y prints a lot of stats so be ready** "<<endl;
                                                   cin>>d;
                                                   if(d=="Y"||d=="y"){pgtrb.printHeap();}
                                                 cout<<np->name<<" on team "<<np->team<<" has the highest "<<stat<<" which is: "<<pgtrb.getMax()<<endl; //print out Highest stat
                                                 }
                                                if(stat=="ASS")
                                                {
                                                  Heap pgass(5000); //initialize heap with size == # of buckets
                                                   for (int i = 0; i < 5000; i++) //go through TOTAL hash bucket players and read in the stat
                                                   {
                                                     if(playerpergame.returnindex(i)!=nullptr)
                                                     {
                                                         pgass.addToHeap(playerpergame.returnindex(i)->ASS); //add stat to heap
                                                         if(pgass.getMax() == playerpergame.returnindex(i)->ASS)
                                                         {
                                                           np = playerpergame.returnindex(i);
                                                         }
                                                     }

                                                   }
                                                   string d;
                                                   cout<<"Do you want to see all stats? Y or N **Warning chosing Y prints a lot of stats so be ready** "<<endl;
                                                   cin>>d;
                                                   if(d=="Y"||d=="y"){pgass.printHeap();}
                                                 cout<<np->name<<" on team "<<np->team<<" has the highest "<<stat<<" which is: "<<pgass.getMax()<<endl; //print out Highest stat
                                                }
                                                if(stat=="STL")
                                                {
                                                  Heap pgstl(5000); //initialize heap with size == # of buckets
                                                   for (int i = 0; i < 5000; i++) //go through TOTAL hash bucket players and read in the stat
                                                   {
                                                     if(playerpergame.returnindex(i)!=nullptr)
                                                     {
                                                         pgstl.addToHeap(playerpergame.returnindex(i)->STL); //add stat to heap
                                                         if(pgstl.getMax() == playerpergame.returnindex(i)->STL)
                                                         {
                                                           np = playerpergame.returnindex(i);
                                                         }
                                                     }

                                                   }
                                                   string d;
                                                   cout<<"Do you want to see all stats? Y or N **Warning chosing Y prints a lot of stats so be ready** "<<endl;
                                                   cin>>d;
                                                   if(d=="Y"||d=="y"){pgstl.printHeap();}
                                                 cout<<np->name<<" on team "<<np->team<<" has the highest "<<stat<<" which is: "<<pgstl.getMax()<<endl; //print out Highest stat
                                                  }
                                                if(stat=="BLK")
                                                {
                                                  Heap pgblk(5000); //initialize heap with size == # of buckets
                                                   for (int i = 0; i < 5000; i++) //go through TOTAL hash bucket players and read in the stat
                                                   {
                                                     if(playerpergame.returnindex(i)!=nullptr)
                                                     {
                                                         pgblk.addToHeap(playerpergame.returnindex(i)->BLK); //add stat to heap
                                                         if(pgblk.getMax() == playerpergame.returnindex(i)->BLK)
                                                         {
                                                           np = playerpergame.returnindex(i);
                                                         }
                                                     }
                                                   }
                                                   string d;
                                                   cout<<"Do you want to see all stats? Y or N **Warning chosing Y prints a lot of stats so be ready** "<<endl;
                                                   cin>>d;
                                                   if(d=="Y"||d=="y"){pgblk.printHeap();}
                                                 cout<<np->name<<" on team "<<np->team<<" has the highest "<<stat<<" which is: "<<pgblk.getMax()<<endl; //print out Highest stat
                                                  }
                                                if(stat=="TOV")
                                                {
                                                  Heap pgtov(5000); //initialize heap with size == # of buckets
                                                   for (int i = 0; i < 5000; i++) //go through TOTAL hash bucket players and read in the stat
                                                   {
                                                     if(playerpergame.returnindex(i)!=nullptr)
                                                     {
                                                         pgtov.addToHeap(playerpergame.returnindex(i)->TOV); //add stat to heap
                                                         if(pgtov.getMax() == playerpergame.returnindex(i)->TOV)
                                                         {
                                                           np = playerpergame.returnindex(i);
                                                         }
                                                     }

                                                   }
                                                   string d;
                                                   cout<<"Do you want to see all stats? Y or N **Warning chosing Y prints a lot of stats so be ready** "<<endl;
                                                   cin>>d;
                                                   if(d=="Y"||d=="y"){pgtov.printHeap();}
                                                 cout<<np->name<<" on team "<<np->team<<" has the highest "<<stat<<" which is: "<<pgtov.getMax()<<endl; //print out Highest stat
                                                   }
                                                if(stat=="PF")
                                                {
                                                 Heap pgpf(5000); //initialize heap with size == # of buckets
                                                 for (int i = 0; i < 5000; i++) //go through TOTAL hash bucket players and read in the stat
                                                 {
                                                   if(playerpergame.returnindex(i)!=nullptr)
                                                   {
                                                       pgpf.addToHeap(playerpergame.returnindex(i)->PF); //add stat to heap
                                                       if(pgpf.getMax() == playerpergame.returnindex(i)->PF)
                                                       {
                                                         np = playerpergame.returnindex(i);
                                                       }
                                                   }


                                                 }
                                                 string d;
                                                 cout<<"Do you want to see all stats? Y or N **Warning chosing Y prints a lot of stats so be ready** "<<endl;
                                                 cin>>d;
                                                 if(d=="Y"||d=="y"){pgpf.printHeap();}
                                                 cout<<np->name<<" on team "<<np->team<<" has the highest "<<stat<<" which is: "<<pgpf.getMax()<<endl; //print out Highest stat
                                                }
                                                if(stat=="PTS")
                                                {
                                                  Heap pgpts(5000); //initialize heap with size == # of buckets
                                                   for (int i = 0; i < 5000; i++) //go through TOTAL hash bucket players and read in the stat
                                                   {
                                                     if(playerpergame.returnindex(i)!=nullptr)
                                                     {
                                                         pgpts.addToHeap(playerpergame.returnindex(i)->PTS); //add stat to heap

                                                         if(pgpts.getMax() == playerpergame.returnindex(i)->PTS)
                                                         {
                                                           np = playerpergame.returnindex(i);
                                                         }
                                                     }
                                                   }
                                                   string d;
                                                   cout<<"Do you want to see all stats? Y or N **Warning chosing Y prints a lot of stats so be ready** "<<endl;
                                                   cin>>d;
                                                   if(d=="Y"||d=="y"){pgpts.printHeap();}
                                                   cout<<np->name<<" on team "<<np->team<<" has the highest "<<stat<<" which is: "<<pgpts.getMax()<<endl; //print out Highest stat
                                                }

              }
              else
              {
                cout<<"\nExiting to main menu\n";
                break;
              }
          };
            break;
      break;

      case 5:
      {
        string teamname;
        string allteams;
        string playernames;
        int c;
        cout<<"Enter Team Abbreviation in all CAPS\n";
        cin>>teamname;
        cout<<"Enter 1 to print the team players and Total stats\n";
        cout<<"Enter 2 to print only team player names\n";
        cin>>c;
        for (int i = 0; i < 5000; i++) //go through TOTAL hash bucket players and read in the stat
        {
          if(playerpergame.returnindex(i)!=nullptr)
          {
            allteams = playerpergame.returnindex(i)->team;
            if(teamname == allteams)
            {
              //get players and put into array
              np = playerpergame.returnindex(i);
              if(c==1)
              {
                  playerpergame.printPlayer(np);
              }
              if(c==2)
              {
                cout<<np->name<<"\n";
              }
            }
          }
        }

      }
    break;

      case 6:
      cout <<" Thanks for using our program! GOODBYE!" << endl;
      break;
default:
cout<<"You did not chose a valid option. This program will now exit and you will have to run it again"<<endl;
return 0;
    }
  }
  return 0;
}
