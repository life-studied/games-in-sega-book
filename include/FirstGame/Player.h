/**
 * @file Player.h
 * @author yunyin (yunyin_jayyi@qq.com)
 * @brief This file defines the player class for game.
 * @version 0.1
 * @date 2024-03-18
 * 
 * @copyright Copyright (c) 2024
 * 
*/

#pragma once

namespace FirstGame
{
    /// @brief      Enum MoveDirections define the directions player can move.
    enum class MoveDirections
    {
        Up,
        Down,
        Left,
        Right,
    };

    /// @brief      Class Player define the postion and the operations.
    /// @details    player should be operated by MoveDirection Enum
    class Player
    {
    public:
        /// @brief      default construct
        Player();

        /// @brief      construct a player by x and y
        /// @param x    pos x
        /// @param y    pos y
        Player(int x, int y);

        /// @brief      construct a player by x and y
        /// @param pos tuple with x and y
        Player(std::tuple<int, int> pos);

        /// @brief default destruct
        ~Player();
    private:

        int x_;         ///< pos x
        int y_;         ///< pos y
    }; // class Player

} // namespace FirstGame
