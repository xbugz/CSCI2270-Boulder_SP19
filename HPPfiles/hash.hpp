#ifndef HASH_HPP
#define HASH_HPP

using namespace std;

// Struct for a player
struct player
{
  int age; // player age
  string position; // player position
  int G;  // games played
  int GS; // games started
  int MP; // Minutes played
  int FG; // Field goals
  int FGA; // field goal attempts
  float FGP; // field goal percentage
  int TP; // three pointers made
  int TPA; // three pointers attemp
  float TPPer; // three pointer percentage
  int TWOP; // Two pointers field goal
  int TWOPA; // two point field goal attemps
  float TWOPPer; // two point field goal percentage
  int FT; // free throws
  int FTA; // free throw attempts
  float FTper; // free throw percentage
  int ORB; // offensive reb
  int DRB; // defensive rebounds
  float ORBpg; // offensive rebounds per game
  float DRBpg; // defensive rebounds per game
  int TRB; // total rebounds
  float TRBpg; // total rebounds per game
  int ASS; // total assists
  float ASSpg; // assisst per games
  int STL; // steals
  float STLpg; // steals per game
  int BLK; // blocks
  float BLKpg; // blocks per game
  int TOV; // turnovers
  float TOVpg; // turnovers per game
  int PTS; // points
  float Ppg; // points per game
  
    
    struct player* next; // pointer to the next player
};

class HashTable
{
    // No. of buckets (Size of the Hash Table)
    int tableSize;

    // Pointer to an array containing buckets (the Hash Table)
    player **hashTable;

  	/*
  	Method Name: createNode
  	Purpose: Create a node with data as 'key'
    return: pointer to the new node
  	*/
    
    player* createPlayer(int ); // unfinished... do we really need to have 32 inputs to create a player???? might create players from driver file

    public:

    /*
    constructor
    Purpose: perform all operations necessary to instantiate a class object
    Param: Size of the Hash Table
    return: none
    */
    
    HashTable(int bsize);

    /*
    destructor
    Purpose: perform all operations necessary to destroy class object
    return: none
    */
    
    ~HashTable();

  	/*
  	Method Name: insertItem
  	Purpose: inserts a node with data as 'key' into the Hash Table
    return: false if 'key' already exists in the table, otherwise true
  	*/
    
    bool insertPlayer(int key);

    /*
  	Method Name: hashFunction
  	Purpose: function to hash "key" into an index
    return: index in the Hash Table
  	*/
    
    unsigned int hashFunction(int key);

    /*
  	Method Name: printTable
  	Purpose: function to display the Hash Table
    return: none
  	*/
    
    void printPlayer();

    /*
  	Method Name: searchItem
  	Purpose: function to search for "key" in the Hash Table
    return: node with "key" as it's data if found, otherwise NULL
  	*/

    player* searchPlayer (string key);

};
#endif
