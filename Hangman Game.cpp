#include <iostream>
#include<ctime>
using namespace std;

void hangman(char t);
int checkguess(char,string,string &);

string message="You have 3 chances";

int main()
{
    char letter,choice;
    string key,hint;
    int tries,keynum,play=0,won=0,lose=0;
    
    string keys[]={
        "inline",
        "continue",
        "delete",
        "break",
        "const",
        "sizeof",
        "static",
        "class",
        "structure",
        "union",
        "enumeration",
        "integer",
        "character",
        "boolean",
        "array"
    };
    
    do{
    play++;
    tries=3;
    srand(time(NULL));
    keynum=rand()%15;
    key=keys[keynum];
    if(keynum>6)
    {
        hint="datatype of cpp";
    }
    else
    {
        hint="keyword of cpp";
    }
    
    string hidden(key.length(),'X');
    
    system("cls");
    
    while(tries)
    {
        hangman('n');
        cout<<"\t\t\t\tLife: "<<tries<<"\t\t\t\tHINT:"<<hint<<endl;
        cout<<"\t\t\t\t"<<hidden<<endl;
        cout<<"\t\t\t\tGuess a letter: ";
        cin>>letter;
        
        system("cls");
        
        if(!checkguess(letter,key,hidden))
        {
            message="Incorrect letter";
            tries--;
        }
        else
        {
            message="Correct Guess";
        }
        if(hidden==key)
        {
            won++;
            message="You are free";
            hangman('f');
            cout<<"\t\t\t\tLife: "<<tries<<endl;
            cout<<"\t\t\t\tThe word is: "<<key<<endl;
            break;
        }
        
        
    }
    if(!tries)
    {
        lose++;
        message="You are hanged";
        hangman('h');
        cout<<"\t\t\t\tLife: "<<tries<<endl;
        cout<<"\t\t\t\tThe word is: "<<key<<endl;
    }
    
    cout<<"Want to play again(Y/N): ";
    cin>>choice;
    }while(choice=='Y');
    
    cout<<"\t\t\t\tPlayed:"<<"\t  Won:"<<"\tLose:"<<endl;
    cout<<"\t\t\t\t  "<<play<<"\t   "<<won<<"\t "<<lose;

    return 0;
}


int checkguess(char letter,string key,string & hidden)
{
    int count=0;
    for(int i=0;i<key.length();i++)
    {
        if(key[i]==letter)
        {
            count++;
            hidden[i]=key[i];
        }
    }
    return count;
}

void hangman(char you)
{
    char hand='|';
    char rope='|';
    string ground="=====";
    if(you=='h')
    {
        hand='/';
        ground="     ";
    }
    else if(you=='f')
    {
        hand='\\';
        rope=' ';
    }
    cout<<"\t\t\t\t____________________"<<endl;
    cout<<"\t\t\t\t         "<<rope<<"          |"<<endl;
    cout<<"\t\t\t\t         O          |"<<endl;
    cout<<"\t\t\t\t        / \\         |"<<"\t        "<<message<<endl;
    cout<<"\t\t\t\t         |          |"<<"\t          /"<<endl;
    cout<<"\t\t\t\t        / \\         |"<<"\t         O "<<endl;
    cout<<"\t\t\t\t    ==="<<ground<<"====    |"<<"\t        / \\ "<<endl;
    cout<<"\t\t\t\t    |          |    |"<<"\t   "<<hand<<"     | "<<endl;
    cout<<"\t\t\t\t    |          |    |"<<"\t =====  / \\ "<<endl;
    cout<<"\t\t\t\t=========================|   |============="<<endl;
}

