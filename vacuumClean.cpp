

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