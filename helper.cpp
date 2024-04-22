#include "helper.h"

using std::string;
using std::vector;

Helper::Helper() {}

void Helper::printInvalidInput()
{

    std::cout << "Invalid input.\n"
              << std::endl;
}

// This below function does not comply to our C++ Style Guide,
// as it uses the banned keyword "break" twice. The marker will
// not deduct marks in this case if you use this function, though
// this is not ideal. Nevertheless, feel free to revise this
// function to make it complied to style guide (this is optional).
bool Helper::isNumber(string s)
{
    string::const_iterator it = s.begin();
    char dot = '.';
    int nb_dots = 0;
    while (it != s.end())
    {
        if (*it == dot)
        {
            nb_dots++;
            if (nb_dots > 1)
            {
                break;
            }
        }
        else if (!isdigit(*it))
        {
            break;
        }

        ++it;
    }
    return !s.empty() && s[0] != dot && it == s.end();
}

void Helper::splitString(string s, vector<string> &tokens, string delimeter)
{
    tokens.clear();
    char *_s = new char[s.length() + 1];
    strcpy(_s, s.c_str());

    char *pch;
    pch = strtok(_s, delimeter.c_str());
    while (pch != NULL)
    {
        tokens.push_back(pch);
        pch = strtok(NULL, delimeter.c_str());
    }
    delete[] _s;
}

string Helper::readInput()
{
    string input;
    std::getline(std::cin, input);

    return input;
}

string Helper::readInputIgnoringEOF()
{
    std::cin.clear();
    string input = Helper::readInput();
    if (std::cin.eof())
    {
        std::cout << std::endl;
        clearerr(stdin);
    }
    std::cout << std::endl;
    return input;
}

bool Helper::validateInitCommandArg(string args)
{
    bool returnValue = false;
    vector<string> initArgs = vector<string>();
    Helper::splitString(args, initArgs, INIT_ARGUMENTS_DELIMETER);
    if (initArgs.size() == INIT_ARGUMENTS_LENGTH)
    {
        string xStr = initArgs[0];
        string yStr = initArgs[1];
        string directionStr = initArgs[2];

        bool xyAreNumbers = Helper::isNumber(xStr) && Helper::isNumber(yStr);
        bool xyAreOneDigit = (xStr.length() == LENGTH_OF_ONE_DIGIT) && (yStr.length() == LENGTH_OF_ONE_DIGIT);
        bool directionIsValid = (directionStr == DIRECTION_EAST || directionStr == DIRECTION_SOUTH || directionStr == DIRECTION_WEST || directionStr == DIRECTION_NORTH);

        returnValue = xyAreNumbers && xyAreOneDigit && directionIsValid;
    }

    return returnValue;
}

bool Helper::positionWithinBounds(int x, int y, int xSize, int ySize)
{
    return (x >= 0 && x < xSize && y >= 0 && y < ySize);
}