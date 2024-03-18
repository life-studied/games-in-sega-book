/**
 * @file MoveBoxGame.h 
 * @author yunyin (yunyin_jayyi@qq.com)
 * @brief This file define the MoveBoxGame which extern the Game Class as core mode
 * @version 0.1
 * @date 2024-03-18
 * 
 * @copyright Copyright (c) 2024
 * 
*/

#pragma once
#include "Game.h"
#include "Player.h"
#include "Map.h"

#include <memory>

namespace FirstGame
{
    class MoveBoxGame : public Game
    {
    public:
        /// @brief default construct
        MoveBoxGame();

        /// @brief default destruct
        ~MoveBoxGame();

    public:
        void Start() override;
        void Update() override;
        void End() override;

    private:
        std::unique_ptr<Map> m_map_;
        std::unique_ptr<Player> m_player_;
    };
} // namespace FirstGame
