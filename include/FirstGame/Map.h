/**
 * @file Map.h
 * @author yunyin (yunyin_jayyi@qq.com)
 * @brief This file define a map class for game.
 * @version 0.1
 * @date 2024-03-18
 * 
 * @copyright Copyright (c) 2024
 * 
*/

#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <tuple>

namespace FirstGame
{
    /// @brief      Map class defined with characters.
    /// @details    # for wall. p for character. . for target. o for box
    class Map
    {
    public:
        /// @brief default construct
        Map();

        /// @brief          construct with a file name which include the map data
        /// @param filename file which has the map data
        /// @warning        file not exists file throw an exception!
        Map(std::string filename);

        /// @brief          construct with the map data which organized by line in vector
        /// @param map_data lines of map data
        /// @warning        map must has four wall which will be checked. throw exception when check failed.
        Map(std::vector<std::string>& map_data);

        /// @brief  default destruct
        ~Map();
    
    public:
        /// @brief          get map data
        /// @return         lines of map data
        std::vector<std::string> GetMapData();

        /// @brief          get player pos
        /// @return         x and y tuple
        std::tuple<int, int> GetPlayerPosition();

        /// @brief          test if game win by targets_
        /// @return         true if targets_ all fulled
        /// @see            GetTargetPositionsFromMap()
        bool Win();

        /// @brief          move to pos(x, y), it will use CanMove to check the pos
        /// @param x        move to x
        /// @param y        move to y
        /// @return         true if success, otherwise false
        bool Move(int x, int y);

        /// @brief          make it easy to output
        /// @param os       osteam object
        /// @param map      output map
        /// @return         os reference
        friend std::ostream& operator<<(std::ostream&, Map&);

        void NextMap();
    private:
        void InitByFilename(std::string& filename);

        /// @brief          read map from file
        /// @param filename file which has the map data
        /// @return         true if read success, false if file not exists
        bool GetMapDataFromFile(std::string filename);

        /// @brief          read map from vector which include line data
        /// @param map_data map format by lines
        /// @return         true if read success, otherwise false.
        bool GetMapDataFromVector(std::vector<std::string>& map_data);

        /// @brief          check if map has four walls
        /// @return         true if check passes, false by wrong format.
        bool CheckMapValid();

        /// @brief          clear all data in map
        void ClearMapData();

        /// @brief          update player postion from map data
        void GetPlayerPositionFromMap();

        /// @brief          collect targets in map, call it after map init and before game start
        void GetTargetPositionsFromMap();

        /// @brief          check pos(x, y) can player move to
        /// @param x        move to x
        /// @param y        move to y
        /// @return         true if success, otherwise false
        bool CanMove(int x, int y);
    private:
        std::vector<std::string> map_data_;     ///< here stores map data
        int map_width_;                         ///< width of map
        int map_height_;                        ///< height of map
        int player_x_;                          ///< x position of player
        int player_y_;                          ///< y position of player

        int map_index_ = 1;                     ///< map file index
        std::string map_file_path_;             ///< map file path
        std::vector<std::tuple<int, int>> targets_;  ///< targets need to be covered
    };
}