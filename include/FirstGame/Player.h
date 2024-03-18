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

#include <tuple>

namespace FirstGame
{
    class Map;

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
        Player(std::tuple<int, int>&& pos);

        /// @brief default destruct
        ~Player();

        /// @brief delete copy construct
        /// @param  
        Player(const Player&) = delete;

        /// @brief call player to move up
        /// @warning must set map first!
        void MoveUp();

        /// @brief call player to move down
        /// @warning must set map first!
        void MoveDown();

        /// @brief call player to move left
        /// @warning must set map first!
        void MoveLeft();

        /// @brief call player to move right
        /// @warning must set map first!
        void MoveRight();

        /// @brief      set player pos for restart game
        /// @param x 
        /// @param y 
        void SetPos(int x, int y);

        void SetPos(std::tuple<int, int>&& pos);

        /// @brief      get map for this game
        /// @param map  game map
        void SetMap(Map& map);

    private:
        /// @brief  check map is set
        /// @return true if map is not nullptr, otherwise false
        /// @see    SetMap(Map& map)
        bool CheckMapIsValid();
    private:

        int x_;                 ///< pos x
        int y_;                 ///< pos y
        Map* map_ = nullptr;    ///< map
    }; // class Player

} // namespace FirstGame
