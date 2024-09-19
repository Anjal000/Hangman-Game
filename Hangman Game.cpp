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
    switch(keynum){
        case 0:
        hint="function that expands in line when called";
        break;
        case 1:
        hint="takes loop to the starting point";
        break;
        case 2:
        hint="destroy array and objects";
        break;
        case 3:
        hint="terminates the loop";
        break;
        case 4:
        hint="prevents variables from changing";
        break;
        case 5:
        hint="shows space taken by a object in memory";
        break;
        case 6:
        hint="allocates space for lifetime of program";
        break;
        case 7:
        hint="have a crucial role in OOP";
        break;
        case 8:
        hint="stores variables of different data type";
        break;
        case 9:
        hint="provides memory to only one of its variables";
        break;
        case 10:
        hint="symbolises character with numbers";
        break;
        case 11:
        hint="stores whole number";
        break;
        case 12:
        hint="takes 1 byte memory ";
        break;
        case 13:
        hint="true/false";
        break;
        case 14:
        hint="stores multiple values of single data type";
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

