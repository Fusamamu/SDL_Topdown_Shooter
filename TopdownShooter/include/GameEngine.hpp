//
//  GameEngine.hpp
//  TopdownShooter
//
//  Created by Sukum Duangpattra on 5/12/2563 BE.
//

#ifndef GameEngine_hpp
#define GameEngine_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include "SDL2/SDL.h"


class GameEngine{
public:
    GameEngine();
    ~GameEngine();
    void Init();
    void RunLoop();
    void ProcessInput();
    void Update();
    void Render();
    void ShutDown();
    
    void AddGameObject(class GameObject* go);
    void RemoveGameObject(class GameObject* go);
    
    std::vector<class GameObject*>& Get_POOL() { return m_gameobject_POOL; }
    
private:
    SDL_Renderer* m_renderer;
    SDL_Window* m_window;
    const float SCREEN_WIDTH  = 640;
    const float SCREEN_HEIGHT = 480;
    bool isRunning = true;
    
    std::vector<class GameObject*> m_gameobject_POOL;
    
 
};

#endif /* GameEngine_hpp */
