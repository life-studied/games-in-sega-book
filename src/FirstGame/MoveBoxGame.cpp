#include "MoveBoxGame.h"
#include "Input.hpp"

#include <fstream>
#include <iostream>

FirstGame::MoveBoxGame::MoveBoxGame()
{
    
}

FirstGame::MoveBoxGame::~MoveBoxGame()
{
    Save("save.txt");
}

void FirstGame::MoveBoxGame::Start()
{
    m_map_ = std::make_unique<Map>("map");
    m_player_ = std::make_unique<Player>(m_map_->GetPlayerPosition());
    m_player_->SetMap(*m_map_.get());
    ShowTips();
}

void FirstGame::MoveBoxGame::Update()
{
    switch (next_step_)
    {
    case MoveDirections::Up:
        m_player_->MoveUp();
        break;
    case MoveDirections::Down:
        m_player_->MoveDown();
        break;
    case MoveDirections::Left:
        m_player_->MoveLeft();
        break;
    case MoveDirections::Right:
        m_player_->MoveRight();
        break;
    default:
        break;

    }

    
}

void FirstGame::MoveBoxGame::End()
{
}

void FirstGame::MoveBoxGame::GetInput()
{
    char input{};
    while (true)
    {
        input = getch();
        if(input != 'w' && input != 's' && input != 'a' && input != 'd')
            continue;
        else
            break;
    }

    switch (input)
    {
    case 'w':
        next_step_ = MoveDirections::Up;
        break;
    case 's':
        next_step_ = MoveDirections::Down;
        break;
    case 'a':
        next_step_ = MoveDirections::Left;
        break;
    case 'd':
        next_step_ = MoveDirections::Right;
        break;
    default:
        break;
    }
}

bool FirstGame::MoveBoxGame::Over()
{
    return m_map_->Win();
}

void FirstGame::MoveBoxGame::Draw()
{
    system("cls");
    std::cout << *m_map_;
}

void FirstGame::MoveBoxGame::Save(std::string filename)
{
    std::ofstream ofs(filename);

    if(!ofs.is_open())
    {
        throw std::runtime_error("Error: Can't open file");
    }

    ofs << m_map_;
    ofs.close();
}

bool FirstGame::MoveBoxGame::NextGame()
{
    system("cls");
    std::cout << "game next? y/n" << '\n';
    char input{};
    while (true)
    {
        input = getch();
        if(input != 'y' && input != 'n')
            continue;
        else
            break;
    }
    if(input == 'y')
    {
        try
        {
            m_map_->NextMap();
            m_player_->SetPos(m_map_->GetPlayerPosition());
            ShowTips();
            return true;
        }
        catch(const std::exception& e)
        {
            std::cout << "bye~" << '\n';
            return false;
        }
    }
    return false;
}

void FirstGame::MoveBoxGame::ShowTips()
{
    std::cout << "The next map is:" << '\n';
    std::cout << *m_map_;
    std::cout << "press wsad to move" << '\n';
}
