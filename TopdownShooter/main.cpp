//
//  main.cpp
//  TopdownShooter
//
//  Created by Sukum Duangpattra on 5/12/2563 BE.
//

#include <iostream>
#include "GameEngine.hpp"

int main(int argc, const char * argv[]) {
    GameEngine* GE = new GameEngine;
    
    GE->Init();
    GE->RunLoop();
    GE->ShutDown();

    
    return 0;
}
