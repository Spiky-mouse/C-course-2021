// Iuliia Orellana
// ID223 Fal2021
// Chapter 5. Do You Want to Keep Adventuring? 

#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;


int health = 10;
int totalTreasure = 0;



void story();
bool askYesNo(string question);
int rollDye(int sides = 6);
void ending();
void adventure();



int main() 
{
    story();

    srand(time(0));
    
    if ( askYesNo("Do you want to try to get the bouncing balls?") == true)
    {
        adventure();

        ending(); 

    } 
    else 
    {
        cout << "OK. See you next time!\n";
    }

    return 0;
}



void story()
{
    string name;
    cout << "What is your name?\n";
    cout << ">> ";
    cin >> name;

    cout << "\n\nGreetings, " << name << "!\n";
    cout << "Today, you are a Maine Coon, the largest domesticated cat. You've just seen the neighbor leaving a bunch of bouncing balls in her garden. What a treasure! Those are your favorite toys! Unfortunatly, there are her three annoying chihuahuas playing with them. But luckily, you are much bigger than they are, so you should have no problem getting the balls from them.\n\n";
    return;
}

bool askYesNo(string question)
{
    char answer;
     bool YesNo;
    do 
    {
        cout << question << endl;
        cout << "(y/n) >> ";
        cin >> answer;
        if (answer == 'y')
        {
            YesNo = true;
        }
        if (answer == 'n')
        {
            YesNo = false;
        }
    } while (answer != 'y' && answer != 'n');

    return YesNo;
}

void ending()
{
    if(health > 0)
    {
        cout << "\nYour health is " << health << endl;
        cout << "\nYou've got " << totalTreasure << " bouncing balls! Good Job!\n";
    }
    else 
    {
        cout << "\nOh no! Chihuahuas turned out stronger than they looked. Game Over!";
    }
    return;

}

int rollDye(int sides)
{
    int points = rand() % sides + 1;
    return points;
}

void adventure()
{   
    bool playAgain;
    cout << "You went to the neighbours garden to get the balls. Chihuahuas were not happy to see you.\n";
    do 
    {
        int enemyAttack = rollDye();
        int block = rollDye();
        int treasure = rollDye(4);

        if (enemyAttack > block)
        {
            cout << "\nYou got bitten and could not get a ball.\n";
            health -= enemyAttack;
            if (health >= 0)
            {
                cout << "Your health is " << health << ".\n";
            }

        }
        else if (enemyAttack < block)
        {
            totalTreasure += treasure;
            cout << "\nYou have succesfully took " << treasure << " bouncing balls.\n";
            cout << "Now, you have " << totalTreasure << " balls in total.\n";
            cout << "Your health is " << health << ".\n";
        }
        else
        {
            cout << "\nYou couldn't get the balls from chihuahuas, but you didn't get bitten.\n"; 
            cout << "You still have " << totalTreasure << " balls in total.\n";
            cout << "Your health is " << health << ".\n";
        }

        
        if (health > 0)
        {
            playAgain = askYesNo("Would you like to try to get more balls?"); 
        } 
        else break;
    } while ( playAgain == true );

    return;   
}