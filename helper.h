#ifndef HELPER_H
#define HELPER_H

#include <iostream>
#include <string>
#include <cassert>
#include <sstream>
#include <vector>
#include <iostream>
#include <string.h>
#include <random>

#define DIRECTION_NORTH "north"
#define DIRECTION_EAST "east"
#define DIRECTION_SOUTH "south"
#define DIRECTION_WEST "west"
#define INIT_ARGUMENTS_DELIMETER ","
#define INIT_ARGUMENTS_LENGTH 3
#define LENGTH_OF_ONE_DIGIT 1
class Helper
{
private:
    Helper();

public:
    /**
     * @brief Check whether the given string is an integer or a float
     *
     * @param s The given string
     * @return true if the string is an integer or a float
     * @return false if the string is neither an integer nor a float
     */
    static bool isNumber(std::string s);

    /**
     * @brief Split the given string given a delimeter. For instance, given the string "1,2,3" and the delimeter ",",
     *        This string will be splited into "1","2","3", and they will be put into the vector.
     *
     * @param s The given string
     * @param tokens The vector containing the results
     * @param delimeter the string based on which splitting is performed
     */
    static void splitString(std::string s, std::vector<std::string> &tokens, std::string delimeter);

    /**
     * @brief Read the user input (a line) from keyboard
     *
     * @return the user input.
     */
    static std::string readInput();

    /**
     * @brief Read the user input (a line) from keyboard ignoring eof
     *
     * @return the user input.
     */
    static std::string readInputIgnoringEOF();

    static void printInvalidInput();

    /**
     * @brief Validate the arguments of the init command given the arguments strored in vectors
     *
     * @param args arguments of the init command in string
     * @return true if the arguments are valid
     * @return false if the arguments are invalid
     */
    static bool validateInitCommandArg(std::string args);

    /**
     * @brief Validates if the x and y value are within the board
     *
     * @param x x value of the position
     * @param y y value of the position
     * @param xSize x size of the board
     * @param ySize y size of the board
     * @return true if the position is within the board
     */

    static bool positionWithinBounds(int x, int y, int xSize, int ySize);
};
#endif