#include "game.h"
using std::cout;
using std::endl;
using std::string;
using std::vector;
Game::Game()
{
    board = new Board();
    player = new Player();
}

Game::~Game()
{
    delete board;
    delete player;
}

void Game::start()
{
    cout << "You can use the following commands to play the game:" << endl;
    cout << endl;
    cout << "load <g>" << endl;
    cout << "\tg: number of the game board to load" << endl;
    cout << "init <x>,<y>,<direction>" << endl;
    cout << "\tx: horizontal position of the vacuum cleaner in the room (betwee 0 & 9)" << endl;
    cout << "\ty: vertical position of the vacuum cleaner in the room (betwee 0 & 9)" << endl;
    cout << "\tdirection: direction of the vacuum cleaner's movement (north, east, south, west)" << endl;
    cout << "forward (or f)" << endl;
    cout << "turn_left (or l)" << endl;
    cout << "turn_right (or r)" << endl;
    cout << "quit" << endl;

    cout << endl;
    cout << "Please enter to continue... ";
    Helper::readInputIgnoringEOF();

    bool boardLoaded = loadBoard();
    bool playerInitialized = false;

    if (boardLoaded)
    {
        playerInitialized = initializePlayer();
    }

    if (playerInitialized)
    {
        play();
    }
}

bool Game::loadBoard()
{
    bool quit = false;
    bool boardLoaded = false;
    while (!quit)
    {
        board->printEmptyBoard();
        cout << "At this stage of the program, only two commands are acceptable:" << endl;
        cout << "load <g> " << endl;
        cout << "quit" << endl;
        cout << endl;

        string input = Helper::readInputIgnoringEOF();
        vector<string> tokens = vector<string>();
        Helper::splitString(input, tokens, COMMAND_DELIMITER);

        bool tokenSizeIsValid = (tokens.size() == COMMAND_SIZE_WITH_SPACE_DELIMITER);
        bool commandIsLoad = false;
        bool commandArgIsValidBoard = false;

        // before accessing the tokens, check if the token size is valid to prevent seg fault
        if (tokenSizeIsValid)
        {
            commandIsLoad = (tokens[0] == COMMAND_LOAD);
            commandArgIsValidBoard = (tokens[1] == BOARD_ONE || tokens[1] == BOARD_TWO);
        }

        if (input == "quit")
        {
            quit = true;
        }
        else if (commandIsLoad && commandArgIsValidBoard)
        {
            // load the board, turn string to integer because load method takes int as parameter
            board->load(stoi(tokens[1]));
            boardLoaded = true;
            quit = true;
        }
        else
        {
            Helper::printInvalidInput();
        }
    }

    return boardLoaded;
}

bool Game::initializePlayer()
{
    bool quit = false;
    bool playerInitialized = false;
    while (!quit)
    {
        board->display(player);
        cout << "At this stage of the program, only three commands are acceptable:" << endl;
        cout << "load <g>" << endl;
        cout << "init <x>,<y>,<direction>" << endl;
        cout << "quit" << endl;
        cout << endl;
        string input = Helper::readInputIgnoringEOF();

        vector<string> tokens = vector<string>();
        Helper::splitString(input, tokens, COMMAND_DELIMITER);
        bool tokenSizeIsValid = (tokens.size() == COMMAND_SIZE_WITH_SPACE_DELIMITER);
        bool commandIsLoad = false;
        bool commandArgIsValidBoard = false;
        bool commandIsInit = false;
        bool commandArgIsValidPosition = false;

        // before accessing the tokens, check if the token size is valid to prevent seg fault
        if (tokenSizeIsValid)
        {
            commandIsLoad = (tokens[0] == COMMAND_LOAD);
            commandArgIsValidBoard = (tokens[1] == BOARD_ONE || tokens[1] == BOARD_TWO);
            commandIsInit = (tokens[0] == COMMAND_INIT);
            commandArgIsValidPosition = Helper::validateInitCommandArg(tokens[1]);
        }

        if (input == COMMAND_QUIT)
        {
            quit = true;
        }
        else if (commandIsLoad && commandArgIsValidBoard)
        {
            board->load(stoi(tokens[1]));
        }
        else if (commandIsInit && commandArgIsValidPosition)
        {
            // get the arguments of the init command
            vector<string> initArgs = vector<string>();
            Helper::splitString(tokens[1], initArgs, INIT_ARGUMENTS_DELIMETER);

            int x = stoi(initArgs[0]);
            int y = stoi(initArgs[1]);
            string directionStr = initArgs[2];
            Direction direction = stringToDirection(directionStr);

            Position position = Position(x, y);
            if (board->placePlayer(position))
            {
                player->initialisePlayer(&position, direction);
                playerInitialized = true;
                quit = true;
            }
            else
            {
                // if place player does not return true then the position is blocked
                cout << "Unable to place player at position: " << x << "," << y << endl;
            }
        }
        else
        {
            Helper::printInvalidInput();
        }
    }

    return playerInitialized;
}

void Game::play()
{
    bool quit = false;
    int totalPlayerMoves = 0;
    while (!quit)
    {
        board->display(player);
        cout << "At this stage of the program, only four commands are acceptable:" << endl;
        cout << "forward (or f)" << endl;
        cout << "turn_left (or l)" << endl;
        cout << "turn_right (or r)" << endl;
        cout << "quit" << endl;
        cout << endl;
        string input = Helper::readInputIgnoringEOF();
        if (input == COMMAND_QUIT)
        {
            cout << "Total player moves: " << totalPlayerMoves << "." << endl;
            quit = true;
        }
        else if (input == COMMAND_FORWARD || input == COMMAND_FORWARD_SHORTCUT)
        {
            PlayerMove moveStatus = board->movePlayerForward(player);
            if (moveStatus == CELL_BLOCKED)
            {
                cout << "Error: Unable to move - cell is blocked." << endl;
            }
            else if (moveStatus == OUTSIDE_BOUNDS)
            {
                cout << "Error: Unable to move - out of bounds." << endl;
            }
            else
            {
                totalPlayerMoves = totalPlayerMoves + 1;
            }
        }
        else if (input == COMMAND_TURN_LEFT || input == COMMAND_TURN_LEFT_SHORTCUT)
        {
            player->turnDirection(TURN_LEFT);
        }
        else if (input == COMMAND_TURN_RIGHT || input == COMMAND_TURN_RIGHT_SHORTCUT)
        {
            player->turnDirection(TURN_RIGHT);
        }
        else
        {
            Helper::printInvalidInput();
        }
    }
}

Direction Game::stringToDirection(std::string directionStr)
{
    Direction direction = Direction::WEST;
    if (directionStr == DIRECTION_NORTH)
    {
        direction = Direction::NORTH;
    }
    else if (directionStr == DIRECTION_SOUTH)
    {
        direction = Direction::SOUTH;
    }
    else if (directionStr == DIRECTION_EAST)
    {
        direction = Direction::EAST;
    }

    return direction;
}