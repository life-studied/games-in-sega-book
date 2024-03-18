/**
 * @file Game.h 
 * @author yunyin (yunyin_jayyi@qq.com)
 * @brief This File defines the Game class which control the game loop and the start,end of each games
 * @version 0.1
 * @date 2024-03-18
 * 
 * @copyright Copyright (c) 2024
 * 
*/

#pragma once

namespace FirstGame
{
    class Game
    {
    public:
        /// @brief      control the game object start
        virtual void Start() = 0;

        /// @brief      control the game object end
        virtual void End() = 0;

        /// @brief      control the game update
        virtual void Update() = 0;
    public:
        Game();
        ~Game();
    };
} // namespace FirstGame
