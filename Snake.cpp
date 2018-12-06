#include "Snake.h"

int Snake::get_length()const noexcept{
    return m_snake.size();
}

void Snake::increse_length()noexcept{
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
    for(auto &p:m_snake){
        if(Map::instance().get(p.first,p.second) == TileType::wall)continue;
        if(Map::instance().get(p.first,p.second) == TileType::fruit)continue;
        Map::instance().set(p.first,p.second,TileType::air);
    }
    
    int dx = 0;
    int dy = 0;
    switch(m_direction){
        case Direction::left:
            dx = -1;
            break;
        case Direction::right:
            dx = 1;
            break;
        case Direction::up:
            dy = -1;
            break;
        case Direction::down:
            dy = 1;
            break;
    }
    
    m_snake.emplace_front(
        m_snake.front().first + dx,
        m_snake.front().second + dy);
    if(Map::instance().get(m_snake.front().first,m_snake.front().second) == TileType::wall)
        return true;
    m_snake.erase(m_snake.rbegin());
    
    auto itr = m_snake.begin();
    Map::instance().set(itr->first,itr->second,TileType::snake_head);
    for(++itr;itr != m_snake.end(); ++itr){
        Map::instance().set(itr->first,itr->second,TileType::snake);
    }
    return false;
}
