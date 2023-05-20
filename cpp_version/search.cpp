#include "main.h"
using namespace std;

bool compare(char a[],char b[])
{
    int i=0;
    while(a[i]!='\0'&&b[i]!='\0')
    {
        if(a[i]!=b[i])
            return false;
        i++;
    }
    if(a[i]=='\0'&&b[i]=='\0')
        return true;
    else
        return false;
}
//search by name and display all the erecords with that name
void account :: search(char name[])
{
    fstream f;
    account c;
    bool flag = 0;
    int id=0;
    f.open("project.txt",ios::in);
    while(!f.eof()){
    	f.read((char *)&c,sizeof(c));
    	if(compare(c.name, name) &&c.id!=id){
    		flag = 1;
    		cout<<c.id<<"\t"<<c.name<<"\t"<<c.balance<<"\t"<<c.age<<"\n";
    		id=c.id;
    	}
    }
    if(!flag)
    	cout << "account not found\n";

    f.close();
}

