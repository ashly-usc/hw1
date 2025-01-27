/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"

/* Add a prototype for a helper function here if you need */

void split(Node*& in, Node*& odds, Node*& evens)
{
  Node* nextin = nullptr;
  if(in == nullptr){
    return;
  }
  nextin = in->next;
  in->next = 0;
  int num = in->value;
  if(num%2 == 0){
    evens = inner(in, evens);
  }
  else{
    odds = inner(in, odds);
  }
  in = nullptr;
  split(nextin, odds, evens);
}

/* If you needed a helper function, write it here */
Node* inner(Node* in, Node* node)
{
  if(node == nullptr){
    return in;
  }
  node->next = inner(in, node->next);
  return node;
}
