//
//  Grid.hpp
//  TopdownShooter
//
//  Created by Sukum Duangpattra  on 9/12/2563 BE.
//

#ifndef Grid_hpp
#define Grid_hpp

#include <stdio.h>
#include <vector>

class Grid{
public:
    Grid(int row, int column, class GameEngine* ge);
    ~Grid();
    
    void GenerateTiles();
    void Render();
    
    class Tile* GetTile(int row, int column) const;
    class Tile* GetTile(float posX, float posY) const;
    
private:
    int m_row;
    int m_column;
    
    float m_tileWidth;
    
    std::vector<class Tile*> m_tileArray;
    
    class GameEngine* m_ge;
    
};

#endif /* Grid_hpp */
