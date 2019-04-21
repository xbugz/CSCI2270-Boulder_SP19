#include <iostream>
#include "BSTNBA.hpp"
#define COUNT 5;
using namespace std;


BST::BST(player *playername)
{
    root->playername=playername;
}

BST::~BST()
{
  root=NULL;
}


Node* BST::createNode(player *playername)
{
    Node *newplayer=new Node;
    newplayer->playername=playername;
    newplayer->left=NULL;
    newplayer->right=NULL;
    newplayer->parent=NULL;

    return newplayer;
}

Node* BST::addHelper (Node *curr,player *playername, string stat)
{
    if (curr==NULL)
    {
        return createNode(playername);
    }

    else if (stat=="Age")
    {
      if (curr->playername->age<playername->age)
      {
        curr->right=addHelper(curr->right, playername, stat);
      }

      else if (curr->playername->age>playername->age)
      {
        curr->left=addHelper(curr->left, playername, stat);
      }
      return curr;

    }



  else if (stat=="Games" || stat=="Games Played")
    {
        if (curr->playername->G<playername->G)
      {
        curr->right=addHelper(curr->right, playername, stat);
      }

      else if (curr->playername->G>playername->G)
      {
        curr->left=addHelper(curr->left, playername, stat);
      }
      return curr;

    }

    else if (stat=="Personal Fouls" || stat=="Number of Personal Fouls")
    {
         if (curr->playername->PF<playername->PF)
      {
        curr->right=addHelper(curr->right, playername, stat);
      }

       else if (curr->playername->PF>playername->PF)
      {
        curr->left=addHelper(curr->left, playername, stat);
      }

    }

  else if (stat=="Games Started")
    {
        if (curr->playername->GS<playername->GS)
      {
        curr->right=addHelper(curr->right, playername, stat);
      }

      else if (curr->playername->GS>playername->GS)
      {
        curr->left=addHelper(curr->left, playername, stat);
      }
      return curr;

    }

  else if (stat=="Minutes Played")
    {
        if (curr->playername->MP<playername->MP)
      {
        curr->right=addHelper(curr->right, playername, stat);
      }

      else if (curr->playername->MP>playername->MP)
      {
        curr->left=addHelper(curr->left, playername, stat);
      }
      return curr;

    }

  else if (stat=="Field Goals" || stat=="Field Goals Made")
    {
        if (curr->playername->FG<playername->FG)
      {
        curr->right=addHelper(curr->right, playername, stat);
      }

      else if (curr->playername->FG>playername->FG)
      {
        curr->left=addHelper(curr->left, playername, stat);
      }
      return curr;

    }

  else if (stat=="Field Goals Attemped" || stat=="Field Goal Attempts")
    {
        if (curr->playername->FGA<playername->FGA)
      {
        curr->right=addHelper(curr->right, playername, stat);
      }

      else if (curr->playername->FGA>playername->FGA)
      {
        curr->left=addHelper(curr->left, playername, stat);
      }
      return curr;

    }

  else if (stat=="Field Goal Percentage")
    {
        if (curr->playername->FGP<playername->FGP)
      {
        curr->right=addHelper(curr->right, playername, stat);
      }

      else if (curr->playername->FGP>playername->FGP)
      {
        curr->left=addHelper(curr->left, playername, stat);
      }
      return curr;

    }

    else if (stat=="Three Pointers" || stat== "Three Pointers Made")
    {
        if (curr->playername->TP<playername->TP)
      {
        curr->right=addHelper(curr->right, playername, stat);
      }

      else if (curr->playername->TP>playername->TP)
      {
        curr->left=addHelper(curr->left, playername, stat);
      }
      return curr;

    }
    else if (stat=="Three Pointers Attempted")
    {
        if (curr->playername->TPA<playername->TPA)
      {
        curr->right=addHelper(curr->right, playername, stat);
      }

      else if (curr->playername->TPA>playername->TPA)
      {
        curr->left=addHelper(curr->left, playername, stat);
      }
      return curr;

    }
    else if (stat=="Three Point Percentage")
    {
        if (curr->playername->TPPer<playername->TPPer)
      {
        curr->right=addHelper(curr->right, playername, stat);
      }

      else if (curr->playername->TPPer>playername->TPPer)
      {
        curr->left=addHelper(curr->left, playername, stat);
      }
      return curr;

    }
    else if (stat=="Two Point Field Goals" || stat== "Two Pointers")
    {
        if (curr->playername->TWOP<playername->TWOP)
      {
        curr->right=addHelper(curr->right, playername, stat);
      }

      else if (curr->playername->TWOP>playername->TWOP)
      {
        curr->left=addHelper(curr->left, playername, stat);
      }
      return curr;

    }
    else if (stat=="Field Goals Attempted" ||stat=="Two Point Field Goals Attempted")
    {
        if (curr->playername->TWOPA<playername->TWOPA)
      {
        curr->right=addHelper(curr->right, playername, stat);
      }

      else if (curr->playername->TWOPA>playername->TWOPA)
      {
        curr->left=addHelper(curr->left, playername, stat);
      }
      return curr;

    }
    else if (stat=="Field Goal Percentage" || stat=="Two Point Field Goal Percentage")
    {
        if (curr->playername->TWOPPer<playername->TWOPPer)
      {
        curr->right=addHelper(curr->right, playername, stat);
      }

      else if (curr->playername->TWOPPer>playername->TWOPPer)
      {
        curr->left=addHelper(curr->left, playername, stat);
      }
      return curr;

    }

    else if (stat=="Effective Field Goal Percentage")
    {
      if (curr->playername->efg<playername->efg)
      {
        curr->right=addHelper(curr->right, playername, stat);
      }

      else if (curr->playername->efg>playername->efg)
      {
        curr->left=addHelper(curr->left, playername, stat);

      }
    }
    else if (stat=="Free Throws" || stat=="Free Throws Made")
    {
        if (curr->playername->FT<playername->FT)
      {
        curr->right=addHelper(curr->right, playername, stat);
      }

      else if (curr->playername->FT>playername->FT)
      {
        curr->left=addHelper(curr->left, playername, stat);
      }
      return curr;

    }
    else if (stat=="Free Throws Attempted")
    {
        if (curr->playername->FTA<playername->FTA)
      {
        curr->right=addHelper(curr->right, playername, stat);
      }

      else if (curr->playername->FTA>playername->FTA)
      {
        curr->left=addHelper(curr->left, playername, stat);
      }
      return curr;

    }
    else if (stat=="Free Throw Percentage" || stat=="Free Throw Percent")
    {
        if (curr->playername->FTper<playername->FTper)
      {
        curr->right=addHelper(curr->right, playername, stat);
      }

      else if (curr->playername->FTper>playername->FTper)
      {
        curr->left=addHelper(curr->left, playername, stat);
      }
      return curr;

    }
    else if (stat=="Offensive Rebounds" || stat== "Total Offensive Rebounds")
    {
        if (curr->playername->ORB<playername->ORB)
      {
        curr->right=addHelper(curr->right, playername, stat);
      }

      else if (curr->playername->ORB>playername->ORB)
      {
        curr->left=addHelper(curr->left, playername, stat);
      }
      return curr;

    }
    else if (stat=="Defensive Rebounds" || stat=="Total Defensive Rebounds")
    {
        if (curr->playername->DRB<playername->DRB)
      {
        curr->right=addHelper(curr->right, playername, stat);
      }

      else if (curr->playername->DRB>playername->DRB)
      {
        curr->left=addHelper(curr->left, playername, stat);
      }
      return curr;

    }


    else if (stat=="Total Rebounds")
    {
        if (curr->playername->TRB<playername->TRB)
      {
        curr->right=addHelper(curr->right, playername, stat);
      }

      else if (curr->playername->TRB>playername->TRB)
      {
        curr->left=addHelper(curr->left, playername, stat);
      }
      return curr;

    }

    else if (stat=="Total Assists" || stat=="Assists")
    {
        if (curr->playername->ASS<playername->ASS)
      {
        curr->right=addHelper(curr->right, playername, stat);
      }

      else if (curr->playername->ASS>playername->ASS)
      {
        curr->left=addHelper(curr->left, playername, stat);
      }
      return curr;

    }

    else if (stat=="Steals" || stat=="Total Steals")
    {
        if (curr->playername->STL<playername->STL)
      {
        curr->right=addHelper(curr->right, playername, stat);
      }

      else if (curr->playername->STL>playername->STL)
      {
        curr->left=addHelper(curr->left, playername, stat);
      }
      return curr;

    }

    else if (stat=="Blocks" || stat=="Total Blocks")
    {
        if (curr->playername->BLK<playername->BLK)
      {
        curr->right=addHelper(curr->right, playername, stat);
      }

      else if (curr->playername->BLK>playername->BLK)
      {
        curr->left=addHelper(curr->left, playername, stat);
      }
      return curr;

    }

    else if (stat=="Turnovers" || stat=="Total Turnovers")
    {
        if (curr->playername->TOV<playername->TOV)
      {
        curr->right=addHelper(curr->right, playername, stat);
      }

      else if (curr->playername->TOV>playername->TOV)
      {
        curr->left=addHelper(curr->left, playername, stat);
      }
      return curr;
    }


    else if (stat=="Points" || stat=="Total Points")
    {
           if (curr->playername->PTS<playername->PTS)
      {
        curr->right=addHelper(curr->right, playername, stat);
      }

      else if (curr->playername->PTS>playername->PTS)
      {
        curr->left=addHelper(curr->left, playername, stat);
      }
      return curr;

    }


    else
    {
      cout<<"Not a valid statistic. Please enter something valid."<<endl;
    }
}

void BST::addNode(player *playername, string stat)
{
    addHelper(root, playername, stat);

}

 void BST::printHelper(Node *node, int space, string stat)
 {//should print the players and the trees to provide a visual representation
     // Base case
    if (node == NULL)
        return;

    // Increase distance between levels
    space += COUNT;

    // Process right child first
    printHelper(node->right, space, stat);

    // Print current node after space
    // count
    printf("\n");
    for (int i = 5;i<space; i++)
        printf(" ");


   if (stat=="Age")
   {
     printf("%d\n", node->playername->name);
     printf("%d\n", node->playername->age);

   }

   else if (stat=="Effective Field Goal Percentage")
   {
     printf("%d\n", node->playername->name);
     printf("%d\n", node->playername->efg);

   }

   else if (stat=="Position")
   {
     printf("%d\n", node->playername->name);
     printf("%d\n", node->playername->position);

   }

   else if (stat=="Games Played" || stat=="Games")
   {
     printf("%d\n", node->playername->name);
     printf("%d\n", node->playername->G);

   }
   else if (stat=="Games Started")
   {
     printf("%d\n", node->playername->name);
     printf("%d\n", node->playername->GS);

   }
   else if (stat=="Minutes Played")
   {
     printf("%d\n", node->playername->name);
     printf("%d\n", node->playername->MP);

   }
   else if (stat=="Field Goals" || stat=="Field Goals Made")
   {
     printf("%d\n", node->playername->name);
     printf("%d\n", node->playername->FG);

   }
   else if (stat=="Field Goals Attempted")
   {
     printf("%d\n", node->playername->name);
     printf("%d\n", node->playername->FGA);

   }
   else if (stat=="Field Goal Percentage")
   {
     printf("%d\n", node->playername->name);
     printf("%d\n", node->playername->FGP);

   }
   else if (stat=="Three Pointers" || stat=="Three Pointers Made")
   {
     printf("%d\n", node->playername->name);
     printf("%d\n", node->playername->TP);

   }
   else if (stat=="Three Pointers Attempted")
   {
     printf("%d\n", node->playername->name);
     printf("%d\n", node->playername->TPA);

   }
   else if (stat=="Three Point Percentage")
   {
     printf("%d\n", node->playername->name);
     printf("%d\n", node->playername->TPPer);

   }
   else if (stat=="Two Point Field Goals" || stat=="Two Pointers")
   {
     printf("%d\n", node->playername->name);
     printf("%d\n", node->playername->TWOP);

   }
   else if (stat=="Two Point Field Goal Attempts" || stat=="Two Point Field Goals Attempted")
   {
     printf("%d\n", node->playername->name);
     printf("%d\n", node->playername->TWOPA);

   }
   else if (stat=="Two Point Field Goal Percentage")
   {
     printf("%d\n", node->playername->name);
     printf("%d\n", node->playername->TWOPPer);

   }
   else if (stat=="Free Throws" || stat=="Free Throws Made")
   {
     printf("%d\n", node->playername->name);
     printf("%d\n", node->playername->FT);

   }
   else if (stat=="Free Throws Attempted")
   {
     printf("%d\n", node->playername->name);
     printf("%d\n", node->playername->FTA);

   }
   else if (stat=="Free Throw Percentage" || stat=="Free Throw Percent")
   {
     printf("%d\n", node->playername->name);
     printf("%d\n", node->playername->FTper);

   }
   else if (stat=="Offensive Rebounds" || stat=="Total Offensive Rebounds")
   {
     printf("%d\n", node->playername->name);
     printf("%d\n", node->playername->ORB);

   }
   else if (stat=="Defensive Rebounds" || stat=="Total Defensive Reobunds")
   {
     printf("%d\n", node->playername->name);
     printf("%d\n", node->playername->DRB);

   }


   else if (stat=="Total Rebounds")
   {
     printf("%d\n", node->playername->name);
     printf("%d\n", node->playername->TRB);

   }

   else if (stat=="Total Assists" || stat=="Assists")
   {
     printf("%d\n", node->playername->name);
     printf("%d\n", node->playername->ASS);

   }

   else if (stat=="Steals" || stat=="Total Steals")
   {
     printf("%d\n", node->playername->name);
     printf("%d\n", node->playername->STL);

   }


    else if (stat=="Blocks" || stat=="Total Blocks")
   {
     printf("%d\n", node->playername->name);
     printf("%d\n", node->playername->BLK);

   }



    else if (stat=="Turnovers"|| stat=="Total Turnovers")
   {
     printf("%d\n", node->playername->name);
     printf("%d\n", node->playername->TOV);

   }

    else if (stat=="Total Points" || stat=="Points")
   {
     printf("%d\n", node->playername->name);
     printf("%d\n", node->playername->PTS);

   }
    // Process left child
    printHelper(node->left, space, stat);

 }

void BST::printTree(int space, string stat)
{
  printHelper (root, space, stat);


}

void deleteNode()
{

}
