#ifndef _MAP_H_
#define _MAP_H_

#include <array>
#include <SDL2/SDL.h>
#include <Config.h>

enum class TileType{
    air,
    wall,
    snake,
    //snake_head //disabled
    fruit
};

class Map{
public:
    static Map &instance()noexcept{//singloten
        static Map map;
        return map;
    }

    Map(const Map &) = delete;//disable copy
    Map(Map &&) = delete;//disable move
    
    Map &operator=(const Map &) = delete;//disable copy
    Map &operator=(Map &&) = delete;//disable move
    
    void set(int x,int y,TileType tile_type)noexcept;
    
    void draw(const SDL_Renderer *render)const noexcept;//render the map to the screen
protected:
private:
    Map() = default;
    ~Map() = default;

    std::array<std::array<TileType,MAP_HEIGHT>,MAP_WIDTH> m_tiles;//tiles
};

#endif
