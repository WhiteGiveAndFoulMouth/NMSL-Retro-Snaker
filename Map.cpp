#include "Map.h"

void Map::set(int x,int y,TileType tile_type)noexcept{
    m_tiles[x][y] = tile_type;
}

TileType Map::get(int x,int y)const noexcept{
    return m_tiles[x][y];
}

void Map::draw(SDL_Renderer *renderer)const noexcept{
    SDL_Rect rect;
    rect.w = TILE_SIZE;
    rect.h = TILE_SIZE;
    for(int x = 0;x < MAP_WIDTH; ++x){
        for(int y = 0;y < MAP_HEIGHT; ++y){
            if(m_tiles[x][y] == TileType::air) continue;
            rect.x = TILE_SIZE * x;
            rect.y = TILE_SIZE * y;
            if(m_tiles[x][y] == TileType::wall){
                SDL_SetRenderDrawColor(
                    renderer,
                    WALL_COLOR_RED,
                    WALL_COLOR_GREEN,
                    WALL_COLOR_BLUE,
                    255);
                SDL_RenderFillRect(renderer,&rect);
            }
            if(m_tiles[x][y] == TileType::snake_head){
                SDL_SetRenderDrawColor(
                    renderer,
                    SNAKE_HEAD_COLOR_RED,
                    SNAKE_HEAD_COLOR_GREEN,
                    SNAKE_HEAD_COLOR_BLUE,
                    255);
                SDL_RenderFillRect(renderer,&rect);
            }
            if(m_tiles[x][y] == TileType::snake){
                SDL_SetRenderDrawColor(
                    renderer,
                    SNAKE_COLOR_RED,
                    SNAKE_COLOR_GREEN,
                    SNAKE_COLOR_BLUE,
                    255);
                SDL_RenderFillRect(renderer,&rect);
            }
            if(m_tiles[x][y] == TileType::fruit){
                
            }
        }
    }
}
