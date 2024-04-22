/*
Understanding the given code was crucial in implementing the project. Initial approach was to just get it working before anything else which
might not have been a great approach if multiple people were working on it. After the project was working, the code was refactored. One of
biggest issue was keeping the code clean without the use of break and multiple return. Initially, lots of boolean flags outside the loops were used.
Segregated if statements made life harder. Later on, the code was refactored to use else if statements instead of segregated if statements.
One of the biggest downside of this approach is that even if a user wants to quit, all the computation for all other command permutations
are done which is not ideal if performance is a concern.In terms of improvements, the menu system could have been better designed. Instead
of all the menu items being loaded from the same class, the menu items could be made into their own class. This would promote better
extensibility in the future.
*/

#include "game.h"
#include "helper.h"
#include <string>

#define OPTION_ONE "1"
#define OPTION_TWO "2"
#define OPTION_THREE "3"

using std::cout;
using std::endl;
using std::string;

void showStudentInformation(string name, string id, string email)
{
    cout << endl;
    cout << "-----------------------------------" << endl;
    cout << "Name: " << name << endl;
    cout << "Student ID: " << id << endl;
    cout << "Email: " << email << endl;
    cout << "-----------------------------------" << endl;
}

int main()
{

    bool quit = false;
    while (!quit)
    {
        cout << "Welcome to Vaccum Cleaning Game!" << endl;
        cout << "--------------------" << endl;
        cout << "1. Play Game" << endl;
        cout << "2. Show Student Information" << endl;
        cout << "3. Quit" << endl;

        cout << endl;
        cout << "Please enter your choice: ";
        string inputString = Helper::readInputIgnoringEOF();

        if (inputString == OPTION_ONE)
        {
            Game *game = new Game();
            game->start();
            delete game;
        }
        else if (inputString == OPTION_TWO)
        {
            showStudentInformation("Ritish Kandel", "3947204", "s3947204@student.rmit.edu.au");
            cout << endl;
        }
        else if (inputString == OPTION_THREE)
        {
            quit = true;
        }
        else
        {
            Helper::printInvalidInput();
        }
    }
    cout << endl;
    cout << "Good Bye!" << endl;
    return EXIT_SUCCESS;
}