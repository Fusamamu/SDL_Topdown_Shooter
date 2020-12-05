//
//  GameObject.hpp
//  TopdownShooter
//
//  Created by Sukum Duangpattra on 5/12/2563 BE.
//

#ifndef GameObject_hpp
#define GameObject_hpp

#include <stdio.h>
#include <iostream>
#include "SDL2/SDL.h"
#include "Utility.hpp"

enum OBJECT_TYPE{
    DYNAMIC,
    STATIC
};

enum GAMEOBJECT_STATE{
    ALIVE,
    DEAD
};

class GameObject{
public:
    GameObject(class GameEngine* ge);
    ~GameObject();
    
    void GO_ProcessInput();
    void GO_Update(float deltaTime);
    void GO_Draw();
    
    const Point& GetPosition() const { return m_position; }
    void SetPosition(Point p);
    
    
private:
    class GameEngine* m_gameEngine;
    Point m_position;
    SDL_Texture* m_tex;
    SDL_Rect m_srcRect;
    SDL_Rect m_destRect;
    
    OBJECT_TYPE      m_type;
    GAMEOBJECT_STATE m_state;
};

#endif /* GameObject_hpp */
