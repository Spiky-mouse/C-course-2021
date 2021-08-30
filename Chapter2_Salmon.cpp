#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

int main() 
{
    //Welvome message

    cout << "\n\nHello my fluffy friend! Meow! >^..^<\n\n";
    cout << "Are you ready to start your adventure?\n\n";

    // Seting up the game

    cout << "How should I call you, my brave, wiskered opportunist?\n";
    string playerName;
    cout << ">>";
    cin >> playerName;

    char gameStat;
    cout << "\nWould you like to see the numbers used in the game? Type 'y' for yes or 'n' for no.\n";
    cout << ">>";
    cin >> gameStat;

    srand(time(0));

    int health = 8;
    int tries = 0;
    int triesMax = rand() % 6 + 3;
    int pawReach, shrekKittyEyes, humanStrength; 

    // Beginning of the game

    cout <<"\n\nToday was an avarege lazy morning. " << playerName << ", as any other hardworking kitty, was sleeping on the sofa after entertaining his humans at night.\nEvery cat knows that people absolutely love to hear loud meowing, scratching, and running through their sleep.\n\n";

    cout << "Suddenly, an amazingly delicious smell reached " << playerName << "'s nose. He lifted his head, sniffed, and ...\n\n";

    char playYesNo;

    cout << "Press 'y' to explore, 'n' to continue sleeping.";
    cout << "\n>>";
    cin >> playYesNo;

    if (playYesNo == 'n') 
    {
        cout << endl << playerName << " went back to sleep.\nSee you next time!";
    } 
    else if (playYesNo == 'y')
    {
        cout << endl << playerName << " decided to check what it is. He went to the kitchen and saw a beautiful piece of baked salmon cooling down on the kitchen table. He absolutely had to try it. " << playerName << " hid under the table, waiting for a good time to reach out his paw and steal the fish.\n\n" ;

       
        do 
        {
            tries++;
            
            int pawReach = rand() % 4 + 1;
            int shrekKittyEyes = rand() % 4 +1;
            int humanStrength = rand() % 5 + 1;

            if(gameStat == 'y')
            {
                cout << "Paw reach score is " << pawReach <<"\nAdorableness level of the Shrek kitty eyes is "<< shrekKittyEyes << "\nHuman strength is " << humanStrength << "\nAmount of tries is " << triesMax << "\nHealth level is " << health << endl << endl;
            }

            cout << playerName << " reached his paw out and ...";

            if (pawReach >= humanStrength)
            {
                cout << " Yummy! " << playerName << " had succesfuly touched the fish.\n\n";
                continue; 
            }
            else if (humanStrength > pawReach)
            {
                cout << " Oh, no! " << playerName << " had been noticed.\nPress 'y' to make an adorable face expression (like the kitty from Shrek) or press 'n' to hide under the table.\n\n";

                char cuteEyes;

                cout << ">>";
                cin >> cuteEyes;

                switch(cuteEyes) 
                {
                    case 'y':
                            if (humanStrength > shrekKittyEyes)
                            {
                                cout << "Ooops! It didn't work. Hide!\n\n";
                                health -= humanStrength;
                                break;
                            }
                            else 
                            {
                                cout << "Awww! Such a cute kitty. Human pretends he doesn't see " << playerName << "'s paw and lets " << playerName << " get a bit of fish.\n\n";
                            
                            }
                            break;
                            
                    case 'n':
                            
                            cout << playerName << " hid under the table.\n\n";
                            health -= humanStrength;
                            break;
                            
                    default:
                            
                            cout << "Sorry! Didn't recognize you answer.\n\n";
                            break;
                            
                            
                }
                if (health <= 3)
                {
                    char pawLick;
                    cout <<" Should " << playerName << " lick his paw to restore health? Type 'y' for yes or 'n' for no.\n";
                    cout << ">>";
                    cin >> pawLick;

                    switch(pawLick) 
                    {
                        case 'y':
                                cout << "\nLick... Lick... Lick...\n\n";
                                health +=3;
                                break;
                        case 'n':
                                cout << "\n Ok...\n";
                                break;
                        default:
                                cout << "\n Sorry, didn't quite get it.\n";
                                break;
                    }

                }
            }


        } while(health > 0 && tries < triesMax);

        if (health > 0)
        {
            cout << "Yay!!! " << playerName << " ate all of the fish! Yummy! Now, he can nap again.\n\n";
        }
        else
        {
            cout << "Looks like it is not " << playerName << "'s day. Take a nap and try again.\n";
        }

    }
    else
    {
        cout << "Sorry! I didn't quite get it. Start again!\n";
    }


    return 0;
}    