#include "Map.h"

#include <exception>
#include <fstream>


FirstGame::Map::Map()
{

}

FirstGame::Map::Map(std::string filename)
{
    InitByFilename(filename);
}

FirstGame::Map::Map(std::vector<std::string>& map_data)
{
    try
    {
        if(!GetMapDataFromVector(map_data))
        {
            throw std::runtime_error("Error: Map data is invalid.");
        }
        else
        {
            GetPlayerPositionFromMap();
            GetTargetPositionsFromMap();
            if(!CheckMapValid())
            {
                throw std::runtime_error("Error: Map data is invalid.");
            }
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

FirstGame::Map::~Map()
{
}

std::vector<std::string> FirstGame::Map::GetMapData()
{
    return map_data_;
}

std::tuple<int, int> FirstGame::Map::GetPlayerPosition()
{
    return std::tuple<int, int>(player_x_, player_y_);
}

void FirstGame::Map::NextMap()
{
    if(map_file_path_.empty())
        throw std::runtime_error("Error: Map file path is empty.");

    try
    {
        InitByFilename(map_file_path_);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        throw e;
    }
}

void FirstGame::Map::InitByFilename(std::string& filename)
{
    try
    {
        if(!GetMapDataFromFile(filename))
        {
            throw std::runtime_error("Error: Map file not found.");
        }
        else
        {
            GetPlayerPositionFromMap();
            GetTargetPositionsFromMap();
            if(!CheckMapValid())
            {
                throw std::runtime_error("Error: Map data is invalid.");
            }
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        if(e.what() == "Error: Map file not found.")
            throw std::runtime_error("Sorry, no next game~");
    }
}

bool FirstGame::Map::GetMapDataFromFile(std::string filename)
{
    if(map_file_path_.empty())
        map_file_path_ = filename;
    
    std::ifstream ifs(filename + std::to_string(map_index_++));
    if(!ifs.is_open())
    {
        throw std::runtime_error("Error: Map file not found.");
    }
    map_data_.clear();
    std::string line;
    while(std::getline(ifs, line))
    {
        map_data_.push_back(line);
    }
    ifs.close();
    map_height_ = map_data_.size();
    map_width_ = map_data_[0].size();
    return true;
}

bool FirstGame::Map::GetMapDataFromVector(std::vector<std::string>& map_data)
{
    map_data_.clear();
    for(auto& i : map_data)
    {
        map_data_.push_back(i);
    }
    map_height_ = map_data_.size();
    map_width_ = map_data_[0].size();
    return true;
}

bool FirstGame::Map::CheckMapValid()
{
    if(map_data_.size() < 3)
    {
        return false;
    }

    for(auto & i : map_data_)
    {
        if(i.size() != map_width_)
        {
            return false;
        }
    }

    if(map_width_ < 3)
    {
        return false;
    }

    bool has_player = false;
    for(auto & i : map_data_)
    {
        for(auto & j : i)
        {
            // check element valid
            if(j != ' ' && j != '#' && j != '.' && j != 'o' && j != 'p')
            {
                return false;
            }

            // check only one player position
            if(j == 'p' && has_player)
            {
                return false;
            }
            else if(j == 'p' && !has_player)
            {
                has_player = true;
            }
        }
    }

    // check wall valid
    for(int i = 1; i < map_data_.size() - 1; i++)
    {
        if(map_data_[i][0] != '#' || map_data_[i][map_width_ - 1] != '#')
            return false;
    }
    if(map_data_[0].find_first_not_of('#') != std::string::npos || map_data_[map_data_.size() - 1].find_first_not_of('#') != std::string::npos)
        return false;
    
    return true;
}

void FirstGame::Map::ClearMapData()
{
    map_data_.clear();
    map_width_ = 0;
    map_height_ = 0;
    player_x_ = 0;
    player_y_ = 0;
}

void FirstGame::Map::GetPlayerPositionFromMap()
{
    for(int i = 0; i < map_height_; i++)
    {
        for(int j = 0; j < map_width_; j++)
        {
            if(map_data_[i][j] == 'p')
            {
                player_x_ = i;
                player_y_ = j;
                return;
            }
        }
    }

    throw std::runtime_error("Player position not found in map");
}

void FirstGame::Map::GetTargetPositionsFromMap()
{
    targets_.clear();
    for(int i = 0; i < map_height_; i++)
    {
        for(int j = 0; j < map_width_; j++)
        {
            if(map_data_[i][j] == '.')
            {
                targets_.push_back(std::make_tuple(i,j));
            }
        }
    }
}

bool FirstGame::Map::Win()
{
    for(auto & i : targets_)
    {
        if(map_data_[std::get<0>(i)][std::get<1>(i)] != 'o')
            return false;
    }
    return true;
}

bool FirstGame::Map::Move(int x, int y)
{
    if(CanMove(x, y))
    {
        if(map_data_[x][y] == 'o')
        {
            map_data_[x + (x - player_x_)][y + (y - player_y_)] = map_data_[x][y];
        }
        map_data_[x][y] = 'p';
        map_data_[player_x_][player_y_] = ' ';
        player_x_ = x;
        player_y_ = y;
    }
    else
        return false;
    return true;
}

bool FirstGame::Map::CanMove(int x, int y)
{
    if(x <= 0 || x >= map_height_ - 1 || y <= 0 || y >= map_width_ - 1)
        return false;
    
    if(map_data_[x][y] == '#')
        return false;

    if(abs(x - player_x_) + abs(y - player_y_) != 1)
        return false;

    if(map_data_[x][y] == 'o')
    {
        if(map_data_[x + (x - player_x_)][y + (y - player_y_)] == ' ' || map_data_[x + (x - player_x_)][y + (y - player_y_)] == '.')
        {
            return true;
        }
        else
            return false;
    }

    return true;
}

std::ostream &FirstGame::operator<<(std::ostream &os, Map &m)
{
    for(auto& i : m.map_data_)
    {
        os << i << std::endl;
    }
    return os;
}
