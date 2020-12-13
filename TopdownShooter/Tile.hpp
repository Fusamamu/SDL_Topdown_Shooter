//
//  Tile.hpp
//  TopdownShooter
//
//  Created by Sukum Duangpattra  on 9/12/2563 BE.
//

#ifndef Tile_hpp
#define Tile_hpp

#include <iostream>
#include "GameObject.hpp"

class Tile: public GameObject{
public:
    Tile(const char* tex_filePath, float posX, float posY, class GameEngine* ge);
    ~Tile();
    
    void DisPlayDebug();
    
    void OnMouseHover();
    
    float Get_G_Cost() const { return g_cost; }
    float Get_H_Cost() const { return h_cost; }
    float Get_F_Cost() const { return g_cost + h_cost; }
    
private:
    int iX; //index x, row
    int iY; //index y, column
    
    float g_cost;
    float h_cost;
    float f_cost;

    Tile* parent;

    bool m_isActive;
    
    SDL_Texture* m_text;
    
};

#endif /* Tile_hpp */
