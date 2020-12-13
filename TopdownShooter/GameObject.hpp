//
//  GameObject.hpp
//  TopdownShooter
//
//  Created by Sukum Duangpattra on 5/12/2563 BE.
//

#ifndef GameObject_hpp
#define GameObject_hpp



//#include "GameEngine.hpp"
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

enum PRIMITIVE_TYPE{
    REGTANGLE,
    TRIANGLE,
    CIRCLE,
};

//class GameEngine;

class GameObject{
public:
    GameObject(const char* tex_filePath, float posX, float posY, class GameEngine* ge);
    ~GameObject();
    
    void GO_ProcessInput();
    void GO_Update(float deltaTime);
    void GO_Draw();
    void GO_DrawPrimitive(PRIMITIVE_TYPE type);
    
    void GO_GetTexture(const char* filePath);
    
    class GameEngine* GetGameEngine() { return m_gameEngine; }
    
    const Point& GetPosition() const { return m_position; }
    void SetPosition(Point p);
    void SetScale(float scale){ m_scale = scale; }
    
    const int& GetWidth() const { return m_width; }
    const int& GetHeight() const { return m_height; }
    
    
private:
    class GameEngine* m_gameEngine;
    Point m_position;
    int m_width;
    int m_height;
    float m_scale;
    
    SDL_Texture* m_tex;
    SDL_Rect m_srcRect;
    SDL_Rect m_destRect;
    
    OBJECT_TYPE      m_type;
    GAMEOBJECT_STATE m_state;
};

#endif /* GameObject_hpp */
