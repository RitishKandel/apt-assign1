#include "player.h"
using std::cout;

Position::Position()
{
    x = 0;
    y = 0;
}

Position::Position(int x, int y)
{
    this->x = x;
    this->y = y;
}

Player::Player()
{
}

void Player::initialisePlayer(Position *position, Direction direction)
{

    this->position = *position;
    this->direction = direction;
}

void Player::turnDirection(TurnDirection turnDirection)
{
    if (turnDirection == TURN_RIGHT)
    {
        if (direction == NORTH)
        {
            direction = EAST;
        }
        else if (direction == WEST)
        {
            direction = NORTH;
        }
        else if (direction == SOUTH)
        {
            direction = WEST;
        }
        else if (direction == EAST)
        {
            direction = SOUTH;
        }
    }
    else if (turnDirection == TURN_LEFT)
    {
        if (direction == NORTH)
        {
            direction = WEST;
        }
        else if (direction == WEST)
        {
            direction = SOUTH;
        }
        else if (direction == SOUTH)
        {
            direction = EAST;
        }
        else if (direction == EAST)
        {
            direction = NORTH;
        }
    }
}

Position Player::getNextForwardPosition()
{
    Position nextForwardPosition = Position(position.x, position.y);
    if (direction == NORTH)
    {
        nextForwardPosition.y = position.y - POSITION_OFFSET;
    }
    else if (direction == EAST)
    {
        nextForwardPosition.x = position.x + POSITION_OFFSET;
    }
    else if (direction == WEST)
    {
        nextForwardPosition.x = position.x - POSITION_OFFSET;
    }
    else if (direction == SOUTH)
    {
        nextForwardPosition.y = position.y + POSITION_OFFSET;
    }
    return nextForwardPosition;
}

void Player::updatePosition(Position position)
{
    this->position = position;
}

void Player::displayDirection()
{
    if (direction == NORTH)
    {
        cout << DIRECTION_ARROW_OUTPUT_NORTH;
    }
    else if (direction == EAST)
    {
        cout << DIRECTION_ARROW_OUTPUT_EAST;
    }
    else if (direction == WEST)
    {
        cout << DIRECTION_ARROW_OUTPUT_WEST;
    }
    else if (direction == SOUTH)
    {
        cout << DIRECTION_ARROW_OUTPUT_SOUTH;
    }
}
