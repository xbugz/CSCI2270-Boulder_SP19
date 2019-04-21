
#ifndef BST_HPP
#define BST_HPP
#include "hash.hpp"
#include <iostream>
#include <string>

using namespace std;



struct Node
{
    player *playername;
    Node *parent=NULL;
    Node *left=NULL;
    Node *right=NULL;
};

class BST
{
    public:

    BST(player *playername);
    ~BST();
    void addNode(player *playername, string stat);
    void printTree(int space, string stat);
    void deleteNode();

    private:
    Node *root;
    Node *createNode(player *playername);
    Node *addHelper(Node *curr,player *playername, string stat);
    void printHelper(Node *node, int space, string stat);
};
#endif
