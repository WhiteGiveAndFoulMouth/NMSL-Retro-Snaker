#include "Level.h"

void Level::clear() noexcept {
    for(int x = 0;x < MAP_WIDTH;++x){
        for(int y = 0;y < MAP_HEIGHT;++y){
            Map::instance().set(x,y,TileType::air);
        }
    }
    Snake::instance().clear();
}

void Level::genLevel1() noexcept {
    for(int x = 0;x < MAP_WIDTH;++x){
        Map::instance().set(x,0,TileType::wall);
        Map::instance().set(x,MAP_HEIGHT - 1,TileType::wall);
    }
    for(int y = 0;y < MAP_HEIGHT;++y){
        Map::instance().set(0,y,TileType::wall);
        Map::instance().set(MAP_WIDTH - 1,y,TileType::wall);
    }
}
