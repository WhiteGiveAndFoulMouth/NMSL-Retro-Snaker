#ifndef _SNAKE_H_
#define _SNAKE_H_

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
        :m_direction(direction){
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
    Direction m_direction;
    std::list<std::pair<int,int>> m_snake;
    
};

#endif
