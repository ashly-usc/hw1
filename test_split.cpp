/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include "split.h"

int main(int argc, char* argv[])
{
    Node* odds = 0;
    Node* evens = 0;
    Node* susa = new Node(2,0);
    Node* charl = new Node(15, susa);
    Node* bob = new Node(20, charl);
    

    split(bob,odds,evens);

}
