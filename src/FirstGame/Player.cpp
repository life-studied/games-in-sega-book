#include "Player.h"
#include "Map.h"

FirstGame::Player::Player(int x, int y) : x_(x), y_(y)
{
}

FirstGame::Player::Player(std::tuple<int, int>&& pos) : Player(std::get<0>(pos), std::get<1>(pos))
{
}

FirstGame::Player::~Player()
{
}

void FirstGame::Player::MoveUp()
{
    if (CheckMapIsValid())
    {
        if(map_->Move(x_ - 1, y_))
            x_--;
    }
    else
        throw std::runtime_error("Map is not set");
}

void FirstGame::Player::MoveDown()
{
    if (CheckMapIsValid())
    {
        if(map_->Move(x_ + 1, y_))
            x_++;
    }
    else
        throw std::runtime_error("Map is not set");
}

void FirstGame::Player::MoveRight()
{
    if (CheckMapIsValid())
    {
        if(map_->Move(x_, y_ + 1))
            y_++;
    }
    else
        throw std::runtime_error("Map is not set");
}

void FirstGame::Player::MoveLeft()
{
    if (CheckMapIsValid())
    {
        if(map_->Move(x_, y_ - 1))
            y_--;
    }
    else
        throw std::runtime_error("Map is not set");
}

void FirstGame::Player::SetPos(int x, int y)
{
    x_ = x; y_ = y;
}

void FirstGame::Player::SetPos(std::tuple<int, int> &&pos)
{
    SetPos(std::get<0>(pos), std::get<1>(pos));
}

void FirstGame::Player::SetMap(Map &map)
{
    map_ = &map;
}

bool FirstGame::Player::CheckMapIsValid()
{
    return map_ != nullptr;
}
