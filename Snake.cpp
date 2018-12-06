#include "Snake.h"

#include <iostream>
using namespace std;

int Snake::get_length()const noexcept{
    return static_cast<int>(m_snake.size());
}

void Snake::increse_length(){
    if(m_incresed)
        return;
    m_snake.emplace_back(m_snake.back().first,m_snake.back().second);
}

void Snake::set_direction(Direction direction){
    if(m_direction == Direction::left && direction == Direction::right) return;
    if(m_direction == Direction::right && direction == Direction::left) return;
    if(m_direction == Direction::up && direction == Direction::down) return;
    if(m_direction == Direction::down && direction == Direction::up) return;
    m_direction = direction;
}

bool Snake::update(){
    m_incresed = false;

    int x = m_snake.front().first;
    int y = m_snake.front().second;
    switch(m_direction){
        case Direction::left:
            x -= 1;
            break;
        case Direction::right:
            x += 1;
            break;
        case Direction::up:
            y -= 1;
            break;
        case Direction::down:
            y += 1;
            break;
    }

    if(x < 0) x = MAP_WIDTH - 1;
    if(x >= MAP_WIDTH) x = 0;
    if(y < 0) y = MAP_WIDTH - 1;
    if(y >= MAP_WIDTH) y = 0;

    for(auto &p:m_snake){
        if(Map::instance().get(p.first,p.second) == TileType::wall)continue;
        if(Map::instance().get(p.first,p.second) == TileType::fruit)continue;
        Map::instance().set(p.first,p.second,TileType::air);
        if(x == p.first && y == p.second)return true;
    }

    m_snake.emplace_front(x,y);
    if(Map::instance().get(m_snake.front().first,m_snake.front().second) == TileType::wall)
        return true;


    m_snake.erase(std::prev(m_snake.end()));
    
    auto itr = m_snake.begin();
    Map::instance().set(itr->first,itr->second,TileType::snake_head);
    for(++itr;itr != m_snake.end(); ++itr){
        Map::instance().set(itr->first,itr->second,TileType::snake);
    }
    return false;
}
