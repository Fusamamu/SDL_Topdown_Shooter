//
//  GameEngine.cpp
//  TopdownShooter
//
//  Created by Sukum Duangpattra on 5/12/2563 BE.
//

#include "GameEngine.hpp"
#include "Grid.hpp"
#include "Tile.hpp"


GameEngine::GameEngine():isRunning(true){
   
}

GameEngine::~GameEngine(){
    
}

void GameEngine::Init(){
    SDL_Init(SDL_INIT_VIDEO);
    
    m_window = SDL_CreateWindow("TopdownShooter(pending title)", NULL, NULL, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_OPENGL);
    m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);
    
    
}

void GameEngine::LoadAssets(){
    m_grid = new Grid(3,3,this);
    
}

void GameEngine::RunLoop(){
    while (isRunning) {
        ProcessInput();
        Update();
        Render();
    }
}

void GameEngine::ProcessInput(){
    SDL_Event ev;
    SDL_PollEvent(&ev);
    
    switch (ev.type) {
        case SDL_QUIT:
            isRunning = false;
            break;
            
        default:
            break;
    }
}

void GameEngine::Update(){
    
}

void GameEngine::Render(){
    SDL_SetRenderDrawColor(m_renderer, 100, 100, 100, 255);
    SDL_RenderClear(m_renderer);
    
//    GameObject* go = new GameObject("textures/slot.png", 0, 0, this);
//    go->GO_Draw();
//    go->GO_DrawPrimitive(REGTANGLE);
    
//    Tile* tile = new Tile("textures/slot.png", 0, 0, this);
//    tile->GO_Draw();
//    tile->DisPlayDebug();
    

    
    
    m_grid->Render();
    
    
    SDL_RenderPresent(m_renderer);
}

void GameEngine::ShutDown(){
    SDL_DestroyRenderer(m_renderer);
    SDL_DestroyWindow(m_window);
    SDL_Quit();
}

SDL_Texture* GameEngine::LoadTexture(const char* filePath){
    SDL_Surface* sf = IMG_Load(filePath);
    SDL_Texture* tex = SDL_CreateTextureFromSurface(m_renderer, sf);
    SDL_FreeSurface(sf);
    return tex;
}

SDL_Texture* GameEngine::LoadText(const char* text, const char* font, SDL_Color c){
    TTF_Init();
    TTF_Font* f = TTF_OpenFont(font, 24);
    SDL_Surface* sf_message = TTF_RenderText_Solid(f, text, c);
    //SDL_Surface* sf_message = TTF_RenderText_Solid(f, "text", {255,255,255,255});
    SDL_Texture* tex_message = SDL_CreateTextureFromSurface(m_renderer, sf_message);
    SDL_FreeSurface(sf_message);
    return tex_message;
}

void GameEngine::AddGameObject(class GameObject* go)
{
    
}

void GameEngine::RemoveGameObject(class GameObject* go){
    
}
