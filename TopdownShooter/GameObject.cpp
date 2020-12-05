//
//  GameObject.cpp
//  TopdownShooter
//
//  Created by Sukum Duangpattra on 5/12/2563 BE.
//

#include "GameObject.hpp"

GameObject::GameObject(class GameEngine* ge):
m_gameEngine(ge),
m_position(Point{0,0}),
m_tex(NULL),
m_type(STATIC),
m_state(ALIVE){
    
}

GameObject::~GameObject(){
    SDL_DestroyTexture(m_tex);
}

void GameObject::GO_ProcessInput(){
    
}

void GameObject::GO_Update(float deltaTime){
    
}

void GameObject::GO_Draw(){
    
}

void GameObject::SetPosition(Point p){
    m_position.x = p.x;
    m_position.y = p.y;
}
