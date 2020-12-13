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
            //m_tileWidth should be set just one time not in loop//
            m_tileWidth = t->GetWidth() * 0.25f;
            t->SetScale(0.25f);
            m_tileArray.push_back(t);
        }
    }
}

void Grid::Render(){
    for(auto t: m_tileArray){
        t->GO_Draw();
    }
}


