#include "MoveBoxGame.h"

FirstGame::MoveBoxGame::MoveBoxGame() : m_map_(std::move(std::make_unique<Map>("map.txt"))), 
    m_player_(std::move(std::make_unique<Player>(m_map_->GetPlayerPosition())))
{
    
}
