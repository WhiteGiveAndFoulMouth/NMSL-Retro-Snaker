#ifndef NMSL_RETRO_SNAKER_FRUIT_H
#define NMSL_RETRO_SNAKER_FRUIT_H

#include <list>
#include <utility>
#include <stdlib.h>
#include <time.h>
#include "Config.h"
#include "Map.h"

class Fruit {
public:
    static void generate(){
        auto[x,y] = std::make_pair(rand() % MAP_WIDTH,rand() % MAP_HEIGHT);
        for(;Map::instance().get(x,y) != TileType::air; x = rand() % MAP_WIDTH ,y = rand() % MAP_HEIGHT){}
        Map::instance().set(x,y,TileType::fruit);
    }
protected:
private:
};


#endif //NMSL_RETRO_SNAKER_FRUIT_H
