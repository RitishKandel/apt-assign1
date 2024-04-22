#include "board.h"

using std::cout;
using std::endl;
using std::vector;

const vector<vector<Cell>> Board::BOARD_1 =
    {
        {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
        {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
        {BLOCKED, BLOCKED, BLOCKED, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY},
        {EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, BLOCKED, BLOCKED, EMPTY, EMPTY},
        {EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
        {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY},
        {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY},
        {EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY},
        {EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
        {EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY}};

const vector<vector<Cell>> Board::BOARD_2 =
    {
        {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY},
        {EMPTY, BLOCKED, BLOCKED, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY},
        {EMPTY, BLOCKED, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
        {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY},
        {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY},
        {EMPTY, BLOCKED, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY},
        {EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY},
        {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY},
        {EMPTY, BLOCKED, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
        {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY}};

Board::Board()
{
    board = new vector<vector<Cell>>();
}

Board::~Board()
{
    delete board;
}

void Board::load(int boardId)
{
    if (boardId == BOARD_ONE_ID)
    {
        *board = BOARD_1;
    }
    else if (boardId == BOARD_TWO_ID)
    {
        *board = BOARD_2;
    }
}

bool Board::placePlayer(Position position)
{
    bool returnValue = false;
    if (Helper::positionWithinBounds(position.x, position.y, BOARD_NUM_ROWS, BOARD_NUM_COLUMNS))
    {
        if (board->at(position.y)[position.x] == EMPTY)
        {
            board->at(position.y)[position.x] = PLAYER;
            returnValue = true;
        }
    }
    return returnValue;
}

PlayerMove Board::movePlayerForward(Player *player)
{
    PlayerMove returnValue = PLAYER_MOVED;
    Position nextForwardPosition = player->getNextForwardPosition();

    if (!Helper::positionWithinBounds(nextForwardPosition.x, nextForwardPosition.y, BOARD_NUM_ROWS, BOARD_NUM_COLUMNS))
    {
        returnValue = OUTSIDE_BOUNDS;
    }
    else if (board->at(nextForwardPosition.y)[nextForwardPosition.x] == BLOCKED)
    {
        returnValue = CELL_BLOCKED;
    }

    if (returnValue == PLAYER_MOVED)
    {
        // set current position to player and previous position empty
        board->at(nextForwardPosition.y)[nextForwardPosition.x] = PLAYER;
        board->at(player->position.y)[player->position.x] = EMPTY;

        player->updatePosition(nextForwardPosition);
    }
    return returnValue;
}

void Board::display(Player *player)
{
    // the top label of the board
    cout << LINE_OUTPUT << EMPTY_OUTPUT << LINE_OUTPUT;
    for (unsigned topLabel = 0; topLabel < BOARD_NUM_COLUMNS; ++topLabel)
    {
        cout << topLabel << LINE_OUTPUT;
    }
    cout << endl;

    // the rest of the board
    for (unsigned row = 0; row < BOARD_NUM_ROWS; ++row)
    {

        for (unsigned col = 0; col < BOARD_NUM_COLUMNS; ++col)
        {
            if (col == 0)
            {
                cout << LINE_OUTPUT << row << LINE_OUTPUT;
            }
            if (board->at(row)[col] == EMPTY)
            {
                cout << EMPTY_OUTPUT << LINE_OUTPUT;
            }
            else if (board->at(row)[col] == BLOCKED)
            {
                cout << BLOCKED_OUTPUT << LINE_OUTPUT;
            }
            else if (board->at(row)[col] == PLAYER)
            {
                player->displayDirection();
                cout << LINE_OUTPUT;
            }
        }
        cout << endl;
    }

    cout << endl;
}

void Board::printEmptyBoard()
{
    cout << endl;
    cout << LINE_OUTPUT << EMPTY_OUTPUT << LINE_OUTPUT;
    for (unsigned topLabel = 0; topLabel < BOARD_NUM_COLUMNS; ++topLabel)
    {
        cout << topLabel << LINE_OUTPUT;
    }
    cout << endl;

    for (unsigned row = 0; row < BOARD_NUM_ROWS; ++row)
    {

        for (unsigned col = 0; col < BOARD_NUM_COLUMNS; ++col)
        {
            if (col == 0)
            {
                cout << LINE_OUTPUT << row << LINE_OUTPUT;
            }
            cout << EMPTY_OUTPUT << LINE_OUTPUT;
        }
        cout << endl;
    }
    cout << endl;
}