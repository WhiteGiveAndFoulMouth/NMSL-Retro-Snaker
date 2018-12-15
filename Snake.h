#ifndef _SNAKE_H_
#define _SNAKE_H_

#include <list>
#include "Config.h"
#include "Map.h"
#include "Fruit.h"

class Snake{
public:
    enum class Direction{
        left,
        right,
        up,
        down
    };

    static Snake &instance()noexcept{
        static Snake snake;
        return snake;
    }

    Snake():m_incresed(false),
            m_now_direction(Direction::right),
            m_last_direction(Direction::right),
            m_snake(){
        m_snake.emplace_back(MAP_WIDTH >> 1, MAP_HEIGHT >> 1 );
    }
    Snake(const Snake &) = delete;
    Snake(Snake &&) = delete;
    ~Snake() = default;
    
    Snake &operator=(const Snake &) = delete;
    Snake &operator=(Snake &&) = delete;
    
    int get_length()const noexcept;
    void increse_length();
    
    void set_direction(Direction direction);
    
    bool update(); //return true if died

    void clear();
protected:
private:
    bool m_incresed;
    Direction m_now_direction,m_last_direction;
    std::list<std::pair<int,int>> m_snake;
    
};

#endif
