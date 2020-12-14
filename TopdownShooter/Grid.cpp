//
//  Grid.cpp
//  TopdownShooter
//
//  Created by Sukum Duangpattra  on 9/12/2563 BE.
//

#include "GameEngine.hpp"
#include "Grid.hpp"
#include "Tile.hpp"


Grid::Grid(int row, int column, GameEngine* ge):
m_row(row),
m_column(column),
m_tileWidth(10),
m_ge(ge){
    
    GenerateTiles();
}

Grid::~Grid(){
    
}

void Grid::GenerateTiles(){
    for(int i = 0; i < m_row; ++i){
        for (int j = 0; j < m_column; ++j) {
            Tile* t = new Tile("textures/slot.png", i * m_tileWidth, j * m_tileWidth, m_ge);
            t->SetPosition(Point{t->GetPosition().x + 50, t->GetPosition().y + 50});
            
            //m_tileWidth should be set just one time not in loop//
            m_tileWidth = t->GetWidth() * 0.2f;
            t->SetScale(0.2f);
            m_tileArray.push_back(t);
        }
    }
}

void Grid::Render(){
    for(auto t: m_tileArray){
        t->GO_Draw();
        t->GO_DrawPrimitive(REGTANGLE);
        t->DisPlayDebug();
        t->SetActive();
    }
}

void Grid::ProcessInput(SDL_Event e){
    
    SDL_Point p;
    SDL_GetMouseState(&p.x, &p.y);
    
    if(e.type == SDL_MOUSEBUTTONDOWN){
        for(auto t: m_tileArray){
                if(SDL_PointInRect(&p, &(t->GetDestRect()))){
                    t->SetActive(true);
                }
        }
    }
}


