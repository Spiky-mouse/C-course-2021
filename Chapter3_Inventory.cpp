// Iuliia Orellana
// ID223 Fall 2021
// Chapter 3. Hero's Inventory  

#include <iostream>
#include <string>
using namespace std;



int main() 
{
    cout << "Let's start an Adventure!!!\n\nType the name of your character:\n>>";
    string name;
    cin >> name;

    cout << "\n\nOnce upon a time deep in the magic forest lived " << name << ". He was a strong fearless, but also very nice and friendly tiger. His only problem was that other animals were scared of him. To show them his good intentions he decided to make for them some cupcakes.\n\n";

    const int MAXITEMS = 10;
    string ingredients[MAXITEMS] = {"flour", "coconut oil", "berries"};

    cout << "Let's see what ingredients " << name << " has:\n";

    for(int i=0; i<MAXITEMS; ++i)
    {
        if(ingredients[i] != "")
        {
            cout << ingredients[i] << endl;
        } 
    }

    cout << "\nLooks like " << name << " is missing honey, milk, and vanilla. Lets find them!\n\n";
    
    cout << name << " noticed some bees flying around. He followed them and found their nest on the tree. He climed the tree and looked at the bees. They were angrilly buzzing and preparing to protect their home. But " << name << " smiled and asked for just a few spoons of their honey. Bees were so surprised that they let him take a bit of their honey.\n\n";
    int count = 0;
    for( int i = 0; i<MAXITEMS; ++i)
    {
        if(ingredients[i] != "")
        {
            count+=1;
        } 
            } 
    string honey;
    cout << "Name the honey you just got. Use one word, no spaces:\n>>";
    cin >> honey;
    ingredients[count] = honey;

    cout << "\nLets see what " << name << " has now:\n"; 

    for(int i=0; i<MAXITEMS; ++i)
    {
        if(ingredients[i] != "")
        {
            cout << ingredients[i] << endl;
        } 
    }

    cout << "\n\n" << name << " heard some loud 'Baaa!' nearby. Those were mountain goats. He followed a noise and saw a tiny goat baby stuck under the rock and the worried parents who were trying to help her. " << name << " got close and freed the baby instead of eating her. The mom was so happy that she happily gave " << name << " some of her milk.\n\n";

    count = 0;
    for( int i = 0; i<MAXITEMS; ++i)
    {
        if(ingredients[i] != "")
        {
            count+=1;
        } 
    } 

    string milk;
    cout << "Name the milk you just got. Use one word, no spaces:\n>>";
    cin >> milk;
    ingredients[count] = milk;

    cout << "\nLets see what " << name << " has now:\n"; 

    for(int i=0; i<MAXITEMS; ++i)
    {
        if(ingredients[i] != "")
        {
            cout << ingredients[i] << endl;
        } 
    }

    cout << "\n\nNow " << name << " is missing only the vanilla. Luckily, because of its strong smell it was pretty easy to find.\n" << name << " collected some vanilla beans.\n\n";

    count = 0;
    for( int i = 0; i<MAXITEMS; ++i)
    {
        if(ingredients[i] != "")
        {
            count+=1;
        } 
    } 

    string vanilla;
    cout << "Name the vanilla beans you just got. Use one word, no spaces:\n>>";
    cin >> vanilla;
    ingredients[count] = vanilla;

    cout << "\nLets see if " << name << " has all that is needed for cupcakes now:\n"; 

    for(int i=0; i<MAXITEMS; ++i)
    {
        if(ingredients[i] != "")
        {
            cout << ingredients[i] << endl;
        } 
    }

    cout << "\nYay!!! Looks like everything is in place. " << name << " makes some delicious cupcakes.\n\n";

    for (int i=0; i<MAXITEMS; ++i)
    {
        if(ingredients[i] != honey)
        {
        ingredients[i].erase(); 
        }   
    }

    cout << "Let's see what is left after making cupcakes:\n";

    count = 0;
    for( int i = 0; i<MAXITEMS; ++i)
    {
        if(ingredients[i] != "")
        {
            count+=1;
        } else continue;
    } 

    ingredients[count] = "cupcakes";

    for(int i=0; i<MAXITEMS; ++i)
    {
        if(ingredients[i] != "")
        {
            cout << ingredients[i] << endl;
        } else continue;
    }

    cout << "\n\n" << name << " was walking to share the cupcakes with the forest animals when he heard a loud noise. That was a bear, he was not in the mood and had no intention to let " << name << " pass. He was definitely looking for a fight. " << name << " tried to give the bear a cupcake but it didn't work.\nThen he remembered that he had some honey left, so he gave it to the bear. And while the bear was distructed " << name << " sneaked by.\n\n";

    int i = 0;
    while(i<MAXITEMS)
    {
       if(ingredients[i] == honey)
        {
        ingredients[i].erase(); 
        } 
        i++; 
    }

    cout << "Let's see what is left:\n";

    for(int i=0; i<MAXITEMS; ++i)
    {
        if(ingredients[i] != "")
        {
            cout << ingredients[i] << endl;
        } 
    }

    cout << "\n\nFinaly, " << name << " managed to give the cupcakes to all of the animals and make some friends. He will never be lonely again!\n\n";
    cout << "THE END";

    return 0;
}