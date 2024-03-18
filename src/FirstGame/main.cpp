#include <iostream>
#include "MoveBoxGame.h"


int main(int argc, char const *argv[])
{
    FirstGame::MoveBoxGame game;
    game.Start();
    do
    {
        while (!game.Over())
        {
            game.GetInput();
            game.Update();
            game.Draw();
        }
    } while(game.NextGame());
    
    game.End();
    
    return 0;
}
