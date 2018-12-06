#ifndef _SNAKE_H_
#define _SNAKE_H_

#include <list>
#include "Map.h"

class Snake{
public:
    enum class Direction{
        left,
        right,
        up,
        down
    };
    explicit Snake(int x,int y,Direction direction = Direction::right)
        :m_incresed(false),
         m_now_direction(direction),
         m_last_direction(direction){
         m_snake.emplace_back(x,y);
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
protected:
private:
    bool m_incresed;
    Direction m_now_direction,m_last_direction;
    std::list<std::pair<int,int>> m_snake;
    
};

#endif
