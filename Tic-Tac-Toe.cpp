// Iuliia Orellana
// ID223 Fal2021
// Chapter 6. References: Tic-Tac-Toe 


// 1st step. Including files that we will need.
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/* 2nd step. Writing global constants definitions. 
We will use them for values that should not change and should be accesible at any part of the program. */ 

const char X = 'X'; // represents a piece on the game board
const char O = 'O'; // represents a piece on the game board
const char EMPTY = ' '; // represents an emty square on the game board
const char TIE = 'T'; // represents game ending in a tie
const char NO_ONE = 'N'; // represents that no one has won yet

// 3rd step. Writing functions prototypes.

void instructions();
    /* Function that displays game instructions on the screen.
    It doesn't return anything and takes no arguments. */
char askYesNo(string question);
    /* Function that asks a yes or no question. It returns a char 'y' or 'n' and 
    takes a string as an argument. */
int askNumber(string question, int high, int low = 0);
    /* Function that asks for a number within a range from high to low. It returns an integer and takes 3 arguments: string, integer, and an integer argument with a default value. */
char humanPiece();
    /* Function that determines if human will use X or O pieces.
    It returns a char 'X' or 'Y' and takes no arguments. */
char opponent(char piece);
    /* Function that determines an opposite piese to a given one.
     It returns a char 'X' or 'Y' and takes a char argument. */
void displayBoard(const vector<char>& board);
    /* Function that displays the board on the screen. It doesn't return anything.
    It takes a constant reference to a vector of char elements as an argument. */
char winner(const vector<char>& board);
    /* Function that determines the game winner. It returns a char value. 
    It takes a constant reference to a vector of char elements as an argument. */
bool isLegal(const vector<char>& board, int move);
    /* Function that determines if a move is legal. It returns a bool value.
    It takes a constant reference to a vector of char elements and an integer as arguments. */
int humanMove(const vector<char>& board, char human);
    /* Function that gets a human move. It returns an integer value. 
    It takes a constant reference to a vector of char elements and an char element as arguments. */
int computerMove(vector<char> board, char computer);
    /* Function that calculates a computer move. It returns an integer value. 
    It takes a vector of char elements and an char element as arguments. */
void announceWinner(char winner, char computer, char human);
    /* Function that congratulates a winner or declares a tie. It doesn't return a value. 
    It takes 3 char arguments. */


// 4th step. Writing main() function.


int main() 
{
    int move; // creating an int variable 'move'
    const int NUM_SQUARES = 9; // creating a constant variable that holds the number of squares on the board
    vector<char> board(NUM_SQUARES, EMPTY); /* creating a vector of char elements
        using the number of squares on the board (NUM_SQUARES) and global constant EMPTY (' ') as arguments,
        which represents an empty game board */

    instructions(); // calling instructions() function to display instructions
    
    // determining who plays with what pieces
    char human = humanPiece(); /* creating a char variable 'human' and
        assigning to it a char variable returned by humanPiece() function */
    char computer = opponent(human); /* creating a char variable 'computer' and
        assigning to it a char variable returned by opponent() function
        that takes a char variable 'human' as an argument  */

    char turn = X; // creating a char value 'turn' that will help calculate whose turn it is
    displayBoard(board); // calling a displayBoard() function with a vector 'board' as an argument (passed as a constant reference) to display a board

    //creating a function that will be getting human's and calculating computer's  moves
    while (winner(board) == NO_ONE) /* checking if someone has already won a game
        by comparing the returned value of winner() function to a global constant NO_ONE */
    {
        // creating a nested if-else statement to see whose turn it is
        if (turn == human) // checking if it is a human's turn by comparing 'turn' and 'human' values 
        {
            move = humanMove(board, human); // assignes a square number where human wants to move to a 'move' variable 
            board[move] = human; // puts a human's piece on the chosen square by changing the value in the vector 'board' to a char variable 'human'
        }
        else // writing a code that executes if it is not a human's turn
        {
            move = computerMove(board, computer); //  assignes a square number calculated for computer's move to a 'move' variable 
            board[move] = computer; // puts a computer's piece on the calculated square by changing the value in the vector 'board' to a char variable 'computer'
        }
        displayBoard(board); // calling the displayBoard() function with a vector 'board' as an argument (passed as a constant reference) to show the updated game board
        turn = opponent(turn); // changes whose turn it is now
    }

    announceWinner(winner(board), computer, human); // calling announceWinner() function to announce the winner or declare a tie


    return 0; // end of the main function

}

// 5th step. Defining functions.


void instructions() // displays game instructions on the screen; returns nothing; takes no arguments
{
    cout << "Welcome to the ultimate man-maschine showdown: Tic-Tac_toe.\n";
    cout << "-- where human brain is pit against silicon processor\n\n";

    cout << "Make your move known by entering a number, 0-8. The number\n";
    cout << "corresponds to the desired board position, as illustrated:\n\n";

    cout << "          0 | 1 | 2\n";
    cout << "         -----------\n";
    cout << "          3 | 4 | 5\n";
    cout << "         -----------\n";
    cout << "          6 | 7 | 8\n";

    cout << "Prepare yourself, human. The battle is about to begging.\n\n";
}




char askYesNo(string question) // asks a yes or no question, returns a char 'y' or 'n', takes a string as an argument.
{
    char response; // creating a local variable 'response'
    do // creating a do-while statement that will keep asking a question untill the player will answer 'y' or 'n'
    {
        cout << question << " (y/n): ";
        cin >> response; // geting a player's input and assigning it to the variable 'response'
    } while (response != 'y' && response != 'n'); // checking if players input not equals to 'y' and 'n'

    return response; // end of the function, returns a char variable 'response'
}




int askNumber(string question, int high, int low) // asks for a number in the range from high to low; returns an integer; takes a string, integer, and integer with a default number (specified in the function declaration).
{
    int number; // creating a local variable 'number'
    do // creating a do-while statement that will keep asking a question untill the player will input the number within a range
    {
        cout << question << " (" << low << " - " << high <<"): ";
        cin >> number; // geting a player's input and assigning it to the variable 'number'

    } while (number > high || number < low); // checking if players input lower than high and higher than low

    return number; // end of the function, returns a int variable 'number'
}




char humanPiece() // determines if human will use X or O pieces, returns a char 'X' or 'Y', takes no arguments.
{
    char go_first = askYesNo("Do you require the first move?"); // assigning a returned by function askYesNo() char variable to a local variaable go_first
    if (go_first == 'y') // using if-else statement to choose what variable to return based on the 'go_first' value
    {
        cout << "\nThen take the first move. You will need it.\n";
        return X;

    }
    else
    {
        cout << "\nYour bravery will be your undoing... I will go first.\n";
        return O;
    }
}




char opponent(char piece) // determines an opposite piese to a given one, returns a char variable and takes a char argument
{
    if(piece == X) // using if-else statement to choose what variable to return based on the 'piece' variable value
    {
        return O;

    }
    else
    {
        return X;
    }

}




void displayBoard(const vector<char>& board) // displays the board on the screen, doesn't return any values, takes a constant reference to a vector of char elements as an argument. We pass the argument through a constant reference because we don't want any changes to be made to the vector and we want it to be passed efficiently without creating a copy
{
    cout << "\n\t" << board[0] << " | " << board[1] << " | " << board[2]; // displaying the elements of the vector on the screen
    cout << "\n\t" << "-----------";
    cout << "\n\t" << board[3] << " | " << board[4] << " | " << board[5];
    cout << "\n\t" << "-----------";
    cout << "\n\t" << board[6] << " | " << board[7] << " | " << board[8];
    cout << "\n\n";
}




char winner(const vector<char>& board) // determines the game winner; returns a char value; takes a constant reference to a vector of char elements as an argument, because we don't want any changes to be made to the vector and we want it to be passed efficiently without creating a copy
{
    const int WINNING_ROWS[8][3] = {{0,1,2}, 
                                    {3,4,5},
                                    {6,7,8},
                                    {0,3,6},
                                    {1,4,7},
                                    {2,5,8},
                                    {0,4,8},
                                    {2,4,6}}; // creating a constant, two-dimensional array of integers that is holding all possible winning combinations

    const int TOTAL_ROWS = 8;

    for(int row =0; row < TOTAL_ROWS; ++row) // creating for loop with nested if statement that will go through the winning rows on the board and see if any of them has a three same not empty values
    {
        if( (board[WINNING_ROWS[row][0]] != EMPTY) && 
            (board[WINNING_ROWS[row][0]] == board[WINNING_ROWS[row][1]])&& 
            (board[WINNING_ROWS[row][1]] == board[WINNING_ROWS[row][2]] ))
            {
                return board[WINNING_ROWS[row][0]] ;// if there are three same not empty values in a row the function will end and return a char in the first (since all three are the same) position in a winning row that will determine who won 
            }
    }

    if (count(board.begin(), board.end(), EMPTY) == 0) // using the 'count' algorithm in an if statement to count how many empty squares on the board, if the value equals to 0 the function will return a 'TIE'
    {
        return TIE;
    }  
    
    return NO_ONE; //  ends function and returns global constant 'NO_ONE' if no one won and the game is not a tie

}




inline bool isLegal(int move, const vector<char>& board) //checks if a square on the board represented by an integer 'move' is empty, takes integer and constant reference to a vector of char elements as parametrs, returns a bool variable. The function is inlined because it is very small, inlining creates a copy of a function everytime it is called, this will speed up a program a bit 
{
    return (board[move] == EMPTY);
}




int humanMove(const vector<char>& board, char human) // gets a human move, returns an integer value that represent a square number where player wants to move, takes a constant reference to a vector of char elements and an char element as parameters
{
    int move = askNumber("Where will you move?", (board.size() - 1)); // assignes a returned by the function askNumber() value to the local variable 'move' 
    while (!isLegal(move, board)) // checks if square is empty
    {
        cout << "\nThat square is already taken, foolish human.\n";
        move = askNumber("Where will you move?", (board.size()-1));
    }
    cout << "Fine... \n";
    return move; // ends the function and returns an integer variable 'move'
}


int computerMove(vector<char>board, char computer) // calculates a computer's move, returns an integer value, takes a vector of char elements and an char element as arguments. The vector is passed by value because we need to modify its copy inside the function and keep the original vector outside the function not changed. 
{
    unsigned int move = 0;
    bool found = false;

    // checking if computer can win on the next move 
    while (!found && move < board.size()) // creating a while loop to check all the possible moves
    {
        if(isLegal(move, board)) // checking if the square is empty
        {
            board[move] = computer; // making a move
            found = winner(board) == computer; // checking if computer is a winner
            board[move] = EMPTY; // undoing the move
        }

        if (!found) // if the previous move didn't bring victory, moving on to a next move
        {
            ++move;
        }
    }

    // if winning move wasn't found (variable 'found' equals to false) checking if the player can win on the next move 
    if(!found)
    {
        move = 0;
        char human = opponent(computer);

        while(!found && move < board.size()) // creating a while loop to check all the possible moves
        {
            if(isLegal(move, board)) // checking if the square is empty
            {
                board[move] = human; // making a move
                found = winner(board) == human; // checking if computer is a winner
                board[move] = EMPTY; // undoing the move
            
            }

            if(!found)
            {
                ++move;
            }
        }
    }

    // if the move wasn't found (variable 'found' equals to false) choosing the best possible move 
    if(!found)
    {
        move = 0;
        unsigned int i = 0;

        const int BEST_MOVES[] = {4, 0, 2, 6, 8, 1, 3, 5, 7}; // creating a constant array  containing integers representing the best moves
        while(!found && i < board.size()) // creating a while loop to find the first possible best move
        {
            move = BEST_MOVES[i];
            if(isLegal(move, board))
            {
                found = true;
            }

            ++i;
        }
    }

    cout << "I should take square number " << move << endl;
    return move; // returning the move that was found
}


void announceWinner(char winner, char computer, char human) // congratulates a winner or declares a tie, doesn't return a value, takes 3 char arguments
{
    // creating if-else statement to compare char variable 'winner' to char variables 'computer' and 'human' to choose a winner's announcement
    if(winner == computer)  
    {
        cout << winner << "'s won!\n";
        cout << "As predicted, human, I am triumphant once more -- proof\n";
        cout << "that computers are superior to humans in all regards.\n";
    }
    else if(winner == human)
    {
        cout << winner << "'s won!\n";
        cout << "No, no! It cannot be! Somehow you tricked m, human.\n";
        cout << "But never again! I, the computer, so swear it!\n";
    }
    else
    {
        cout << "It is a tie.\n";
        cout << "You were most lucky, human, and somehow managed to tie me.\n";
        cout << "Celebrate... for this is the best you will ever achive.\n";
    }

}