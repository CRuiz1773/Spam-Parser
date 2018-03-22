/**
Created by: Christopher Ruiz-Rodriguez
File: ruiz.cpp
Purpose: Driver for programming assignment 1
 */

#include <iostream>
#include <string.h>
#include <vector>
#include <fstream>
#include "llist.h"

using namespace std;

int main()
{
  char x;
  int state = 0;
  string s,s1,s2;     //Strings will be used to record which messages are spam
  vector <string> v;  //This vector will hold all strings
  bool flag = false;
  
  //Initialize linked list
  llist L1;
  L1.createList();
  //L1.displayAll();
  
  //Begin reading
  fstream fin;
  fin.open("messagefile.txt");
  x = fin.get();
  while(x != EOF)
    {
      if(state == 17)
	{
	  //cout<<"We made it here!"<<endl;
	  s = "";
	  while(x >= 48 && x <= 57)
	    {
	      s+=x;
	      x = fin.get();
	    }
	  //cout<<s<<endl;
	}
      state = L1.manState(state, x);
      if(x == '\n')
        cout<<"Input:New line\tState: "<<state<<endl;
      else
        cout<<"Input: "<<x<<"\tState: "<<state<<endl;

      if(state == 83 || state == 74)
	flag = true;
      //RestFA & message
      if(state == 89 && flag == true)
	{
	  s1 = "Message #";
	  s2 = " is spam.";
	  s1 += s;
	  s1 += s2;
	  v.push_back(s1);	  
	  state = 0;
	  flag = false;
	  //cout<<"Flag was set to true"<<endl;
	}
      else if(state == 89)
	{
	  state = 0;
	  flag = false;
	  //cout<<"Flag was set to false"<<endl;
	}
      x = fin.get();
    }
  fin.close();  
  //Keep track & print all messages that are spam
  if(v.size() != 0)
    {
      cout<<"\nSpam Messages"<<endl;
      cout<<"-----------------------------------------------"<<endl;
      for(int i = 0;i < v.size();i++)
	{
	  cout<<v[i]<<endl;
	}
    }
  else
    cout<<"There are no spam messages."<<endl;
  return 0;
}
