//
//  Tile.cpp
//  TopdownShooter
//
//  Created by Sukum Duangpattra  on 9/12/2563 BE.
//

#include "GameEngine.hpp"
#include "Tile.hpp"


Tile::Tile(const char* tex_filePath, float posX, float posY, class GameEngine* ge):
GameObject(tex_filePath, posX, posY, ge),
m_isActive(false){
    
    debugLabel = "0 0 0";
    
    __Color c;
    m_text = GetGameEngine()->LoadText(debugLabel, "fonts/ARCADECLASSIC.TTF", c.black);
    if(m_text == NULL){ std::cout<<"Failed to load Text"<<std::endl; }
}

Tile::~Tile(){
    SDL_DestroyTexture(m_text);
}

void Tile::DisPlayDebug(){
    
    SDL_Rect text_dest;
    text_dest.x = GetPosition().x;
    text_dest.y = GetPosition().y;
    text_dest.w = 50;
    text_dest.h = 20;
    
    SDL_RenderCopy(GetGameEngine()->GetRenderer(), m_text, NULL, &text_dest);
}

void Tile::OnMouseHover(){
    
}

void Tile::SetActive(){
    if(m_isActive){
        SDL_SetRenderDrawColor(GetGameEngine()->GetRenderer(), 255, 0, 0, 85);
        SDL_SetRenderDrawBlendMode(GetGameEngine()->GetRenderer(), SDL_BLENDMODE_BLEND);
        SDL_Rect r = GetDestRect();
        SDL_RenderFillRect(GetGameEngine()->GetRenderer(), &r);
        
    }
}

