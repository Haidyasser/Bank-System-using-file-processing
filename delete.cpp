#include "main.h"
using namespace std;

// delete ACOUNT 
void account :: delete_account()
{
    account d;
    int id = 0;
    char str[10];
    ifstream myfile("project.txt",ios::in);
    ofstream temp("Temp.txt",ios::out);

    cout << "Enter the name you want to delete the account for ";
    cin >> str;
    searchForName(str);
    cout << "Enter the id you want to delete the account for ";
    cin >> id;
    if(myfile.is_open())
    {
        while(!myfile.eof())
        {
            myfile.read((char *)&d,sizeof(d));
            if(d.id!=id)
            {
                temp.write((char *)&d,sizeof(d));
            }
        }
        myfile.close();
        temp.close();
        remove("project.txt");
        rename("Temp.txt","project.txt");
        cout << "Done operation of deletion successfully\n";
        
    }
    else
    {
        cout << "Error in opening the file\n";
    }
}
