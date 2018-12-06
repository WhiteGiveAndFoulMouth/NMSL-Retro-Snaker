#include "Map.h"

void Map::set(int x,int y,TileType tile_type)noexcept{
    m_tiles[x][y] = tile_type;
}

void Map::draw(const SDL_Renderer *renderer)const noexcept{
    SDL_Rect rect;
    rect.w = TILE_SIZE;
    rect.h = TILE_SIZE;
    for(int x = 0;x < MAP_WIDTH; ++x){
        for(int y = 0;y < MAP_HEIGHT; ++y){
            if(m_tiles[x][y] == TileType::air) continue;
            if(m_tiles[x][y] == TileType::wall){
                //too many draw calls
                //some of draw calls can be merged to one
                //why not SDL_RenderFillRects?
                //it need another way to manager data
                //that is not suitable for this
                rect.x = TILE_SIZE * x;
                rect.y = TILE_SIZE * y;
                SDLL_SetRenderDrawColor(
                    renderer,
                    WALL_COLOR_RED,
                    WALL_COLOR_GREEN,
                    WALL_COLOR_BLUE,
                    255);
                SDL_RenderFillRect(renderer,&rect);
            }
            if(m_tiles[x][y] == TileType::snake){
                
            }
            if(m_tiles[x][y] == TileType::fruit){
                
            }
        }
    }
}
