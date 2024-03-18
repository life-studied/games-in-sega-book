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
#include <string>

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
        /// @brief      game start for init map and player
        void Start() override;

        /// @brief      game update by processing player input
        void Update() override;

        /// @brief      game end for release resources
        void End() override;

        /// @brief      get input by no-buffering
        void GetInput();

        /// @brief      test if game over
        /// @return     true if game over
        /// @see        Map::Win()
        bool Over();

        /// @brief      draw map for games
        /// @see        operator<<(std::ostream &os, Map &m)
        void Draw();

        void Save(std::string filename);

        bool NextGame();

        void ShowTips();
        
    private:
        std::unique_ptr<Map> m_map_;
        std::unique_ptr<Player> m_player_;

        MoveDirections next_step_;
    };
} // namespace FirstGame
