#include "main.h"
using namespace std;

//DEPOSITE 
void account::dep(int x, account *acc)
{
    acc -> balance+=x;
}
void account::deposit(int id){
  int amount ;
  fstream file ;
  bool found = false ;
  account acc ;
 
  file.open("project.txt" , ios::in | ios::out);
  if (!file.is_open()){
    cout<<"File couldn't be open ...  press any kay to exit ...";
    return ;
  }
  while(!file.eof()){
    file.read((char *)&acc , sizeof(acc));
    if (acc.id == id){
      cout<<"Enter The Amount You Want To Deposit : ";
      cin>>amount ;
      acc.dep(amount, &acc);
    }
    // modify function 
    //modify(&acc, acc.id);
    found = true ;
  }
  file.close();
  if (found == false ) cout<<"Customer Not Found ";
}
