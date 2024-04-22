#ifndef GAME_H
#define GAME_H

#include "helper.h"
#include "board.h"
#include "player.h"
#include <string>
#include <vector>

// strings used for input validation
#define COMMAND_LOAD "load"
#define COMMAND_INIT "init"
#define COMMAND_FORWARD "forward"
#define COMMAND_FORWARD_SHORTCUT "f"
#define COMMAND_TURN_LEFT "turn_left"
#define COMMAND_TURN_LEFT_SHORTCUT "l"
#define COMMAND_TURN_RIGHT "turn_right"
#define COMMAND_TURN_RIGHT_SHORTCUT "r"
#define COMMAND_QUIT "quit"
#define COMMAND_GENERATE_RANDOM "generate"
#define BOARD_ONE "1"
#define BOARD_TWO "2"
#define EMPTY_VECTOR_SIZE 0
#define COMMAND_DELIMITER " "
#define COMMAND_SIZE_WITH_SPACE_DELIMITER 2
class Game
{
private:
    Board *board;
    Player *player;

    /**
     * Load the board.
     * Return true if the board is loaded and false for quiting the game.
     */
    bool loadBoard();

    /**
     * Initialize the player.
     * Return true if the player is initialized and false for quiting the game.
     */
    bool initializePlayer();

    /**
     * Play the game and move the player interactively.
     */
    void play();

    /**
     * Given a string, turn it into its equivalent direction enumeration.
     */
    Direction stringToDirection(std::string direction);

public:
    // initialize and destroy the member variables
    Game();
    ~Game();

    /**
     * Main menu option 1 - play the game as per the specification.
     *
     * This method should call other methods in this class in the following order:
     * - loadBoard()
     * - initilizePlayer()
     * - play()
     *
     * These methods should in turn make all the calls to methods in board & player
     * objects and handle interaction with the user (reading inputs from the console,
     * error checking, etc...).
     */
    void start();
};

#endif
