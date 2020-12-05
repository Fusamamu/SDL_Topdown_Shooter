//
//  GameEngine.cpp
//  TopdownShooter
//
//  Created by Sukum Duangpattra on 5/12/2563 BE.
//

#include "GameEngine.hpp"

GameEngine::GameEngine():isRunning(true){
    
}

GameEngine::~GameEngine(){
    
}

void GameEngine::Init(){
    SDL_Init(SDL_INIT_VIDEO);
    
    m_window = SDL_CreateWindow("TopdownShooter(pending title)", NULL, NULL, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_OPENGL);
    m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);

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
    
    SDL_RenderPresent(m_renderer);
}

void GameEngine::ShutDown(){
    SDL_DestroyRenderer(m_renderer);
    SDL_DestroyWindow(m_window);
    SDL_Quit();
}
