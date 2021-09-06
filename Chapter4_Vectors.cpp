// Iuliia Orellana
// ID223 Fall2021


#include <iostream>
#include<algorithm>
#include<string>
#include<vector>

using namespace std;


int main() 
{
    cout << "\n\nLet's create a list of classes for this semester!\n\n";

    vector<string> classes;
    classes.push_back("Chemistry");
    classes.push_back("Math");
    classes.push_back("Logic");

    vector<string>:: iterator iterChange;
    vector<string>:: const_iterator iterConst;

    string userInput;

    cout << "Your classes:\n";
    for(iterConst = classes.begin(); iterConst < classes.end(); iterConst++)
    {
        cout << *iterConst << endl;
    }

    do {
        cout << "\nWhat would you like to do? \n(Type 'add' to add a class, 'delete' to remove a class from the list, 'change' to change classes, 'list' to list all of the classes, 'find' to see if the class is in the list)\n";
        cout << ">> ";
        cin >> userInput;

        if(userInput == "add" || userInput == "Add")
        {
            cout << "\nWhat class would you like to add?\n";
            cout << ">> ";
            cin >> userInput;
            classes.push_back(userInput);
            cout << userInput << " has been added to the list.\n";
        } // end of if statement to add a value

        else if (userInput == "change" || userInput == "Change")
        {
            cout << "\nWhat class would you like to change?\n";
            cout << ">> ";
            cin >> userInput;
            
            //used find() algorithm instead of for loop to change a value
            iterChange = find(classes.begin(), classes.end(), userInput);
            if (iterChange == classes.end())
            {
                cout << "\nClass is not found.\n";

            }
            else 
            {
                cout << "What would you like to change " << *iterChange << " to?\n";
                string temp = *iterChange;
                cout << ">> ";
                cin >> userInput;
                *iterChange = userInput;
                cout << "\nYou have successfully changed " << temp << " to " << *iterChange << ".\n";
            }

        } // end of else if statement to change the value


        else if(userInput == "delete" || userInput == "Delete" )
        {
            cout << "\nWhat class would you like to remove?\n";
            cout << ">> ";
            cin >> userInput;

            iterChange = find(classes.begin(), classes.end(), userInput);
            if (iterChange == classes.end())
            {
                cout << "\nClass is not found.\n";

            }
            else 
            {
                string temp = *iterChange;
                classes.erase(iterChange);
                
                cout << "\nYou have successfully deleted " << temp << ".\n";
            }

        } // end of else if statement to remove an item

        else if(userInput == "list" || userInput == "List")
        {
            sort(classes.begin(), classes.end());
            for(iterConst = classes.begin(); iterConst < classes.end(); iterConst++)
            {
                cout << *iterConst << endl;
            }
        } //end of the else if statement to list all of the items

        else if(userInput == "find" || userInput == "Find")
        {
            cout << "\n What class are you looking for?\n";
            cout << ">> ";
            cin >> userInput;
            iterChange = find(classes.begin(), classes.end(), userInput);
            if (iterChange == classes.end())
            {
                cout << "\nClass is not found.\n";

            }
            else 
            {
                cout << "\n" << *iterChange << " is in your list.\n";
            }
        } // end of else if statement to find the value 



        else if(userInput == "quit" || userInput == "Quit")
        {
            cout << "\nSee you next time!\n";
            break;
        } // end of else if statement for quiting 

        else
        {
            cout << "\nIt is not one of the options!\n";
        }

    } while(true); // end of do-while loop

    return 0;
} // end of main()