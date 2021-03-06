/**
Created by: Christopher Ruiz-Rodriguez
File: llist.h
Purpose:Creates the llist class & Node struct
*/

typedef char el_t;


struct Node
{
  el_t Elem; //The character value of the NEXT necessary input that needs to be read in  
  el_t E1;   //to progress through the finite automata
  el_t E2;
  el_t E3;

  Node *Next; //A node pointer that points to the next node on the list
};

class llist
{
 protected:
  Node *Front;
  Node *Rear;
  int Count;
  
 public:
  class Underflow{};
  class OutOfRange {};

  llist();
  ~llist();

  bool isEmpty();

  void displayAll();

  void addFront(el_t newNum);

  void addRear(el_t newNum);

  void deleteFront(el_t& OldNum);

  void createList();

  int manState(int &state,char x);
};
