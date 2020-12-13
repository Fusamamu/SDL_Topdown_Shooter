//
//  GameObject.cpp
//  TopdownShooter
//
//  Created by Sukum Duangpattra on 5/12/2563 BE.
//

#include "GameEngine.hpp"
#include "GameObject.hpp"

GameObject::GameObject(const char* tex_filePath, float posX, float posY, class GameEngine* ge):
m_gameEngine(ge),
m_tex(NULL),
m_position(Point{posX,posY}),
m_scale(1),
m_type(STATIC),
m_state(ALIVE){
    GO_GetTexture(tex_filePath);
    SetPosition(m_position);
}

GameObject::~GameObject(){
    SDL_DestroyTexture(m_tex);
}

void GameObject::GO_ProcessInput(){
    
}

void GameObject::GO_Update(float deltaTime){
    
}

void GameObject::GO_Draw(){
    m_destRect.x = m_position.x;
    m_destRect.y = m_position.y;
    m_destRect.w = m_width  * m_scale;
    m_destRect.h = m_height * m_scale;
    SDL_RenderCopy(m_gameEngine->GetRenderer(), m_tex, &m_srcRect, &m_destRect);
}

void GameObject::GO_DrawPrimitive(PRIMITIVE_TYPE type){
    switch (type) {
        case PRIMITIVE_TYPE::REGTANGLE:
        {
            __Color c;
            SDL_SetRenderDrawColor(m_gameEngine->GetRenderer(), c.white.r, c.white.g, c.white.b, c.white.a);
            SDL_RenderDrawRect(m_gameEngine->GetRenderer(), &m_destRect);
            break;;
        }
            
        case PRIMITIVE_TYPE::TRIANGLE:
        {
            break;
        }
            
        case PRIMITIVE_TYPE::CIRCLE:
        {
            break;
        }
    }
}

void GameObject::GO_GetTexture(const char* filePath){
    m_tex = m_gameEngine->LoadTexture(filePath);
    if (m_tex == NULL) { std::cout<< "Fail to load texture!" <<std::endl; }
    SDL_QueryTexture(m_tex, NULL, NULL, &m_width, &m_height);
    m_srcRect = {0, 0, static_cast<int>(m_width), static_cast<int>(m_height)};
}

void GameObject::SetPosition(Point p){
    m_position.x = p.x;
    m_position.y = p.y;
}
