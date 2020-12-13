//
//  Tile.cpp
//  TopdownShooter
//
//  Created by Sukum Duangpattra  on 9/12/2563 BE.
//

#include "GameEngine.hpp"
#include "Tile.hpp"


Tile::Tile(const char* tex_filePath, float posX, float posY, class GameEngine* ge):
GameObject(tex_filePath, posX, posY, ge){
    __Color c;
    m_text = GetGameEngine()->LoadText("Test", "fonts/ARCADECLASSIC.TTF", c.white);
    if(m_text == NULL){ std::cout<<"Failed to load Text"<<std::endl; }
}

Tile::~Tile(){
    
}

void Tile::DisPlayDebug(){
    
    SDL_Rect text_dest;
    text_dest.x = GetPosition().x;
    text_dest.y = GetPosition().y;
    text_dest.w = 200;
    text_dest.h = 200;
    
    SDL_RenderCopy(GetGameEngine()->GetRenderer(), m_text, &text_dest, &text_dest);
}

void Tile::OnMouseHover(){
    
}

