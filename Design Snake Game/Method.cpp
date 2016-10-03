//Design a Snake game that is played on a device with screen size = width x height. Play the game online if you are not familiar with the game.
//
//The snake is initially positioned at the top left corner (0,0) with length = 1 unit.
//
//You are given a list of food's positions in row-column order. When a snake eats the food, its length and the game's score both increase by 1.
//
//Each food appears one by one on the screen. For example, the second food will not appear until the first food was eaten by the snake.
//
//When a food does appear on the screen, it is guaranteed that it will not appear on a block occupied by the snake.
//
//Example:
//Given width = 3, height = 2, and food = [[1,2],[0,1]].
//
//Snake snake = new Snake(width, height, food);
//
//Initially the snake appears at position (0,0) and the food at (1,2).
//
//|S| | |
//| | |F|
//
//snake.move("R"); -> Returns 0
//
//| |S| |
//| | |F|
//
//snake.move("D"); -> Returns 0
//
//| | | |
//| |S|F|
//
//snake.move("R"); -> Returns 1 (Snake eats the first food and right after that, the second food appears at (0,1) )
//
//| |F| |
//| |S|S|
//
//snake.move("U"); -> Returns 1
//
//| |F|S|
//| | |S|
//
//snake.move("L"); -> Returns 2 (Snake eats the second food)
//
//| |S|S|
//| | |S|
//
//snake.move("U"); -> Returns -1 (Game over because snake collides with border)

//这题主要是怎么处理蛇的运动。我们用双向队列来保存蛇的头和尾，每一次运动时，弹出尾部，获取当前头部坐标，然后按照方向得到新头部的坐标，然后从头部入队列。如果新的头部是一个食物，那么原来尾部的位置再压回去。 
//用hash_map来保存蛇的身体，以方便判断蛇是否会咬到自身。不能保存棋盘，因为耗空间太大。

class SnakeGame {

    vector<pair<int, int>> food;
    deque<pair<int,int>> snake;
    set<pair<int,int>> snakeBody;
    
    int width;
    int height;
    int foodNumber;
public:
    /** Initialize your data structure here.
        @param width - screen width
        @param height - screen height 
        @param food - A list of food positions
        E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0]. */
    SnakeGame(int width, int height, vector<pair<int, int>> food): food(food), foodNumber(0), width(width), height(height)  {
        
        snake.push_back(make_pair(0,0));
        snakeBody.insert(make_pair(0,0));
    }
    
    /** Moves the snake.
        @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down 
        @return The game's score after the move. Return -1 if game over. 
        Game over when snake crosses the screen boundary or bites its body. */
    int move(string direction) {
        
        pair<int,int> tail = snake.back();
        pair<int,int> head = snake.front();
        
        snake.pop_back();
        snakeBody.erase(tail);
        
        if(direction == "L") { 
            --head.second;
        }
        
        if(direction == "R") {
            ++head.second;
        }
        
        if(direction == "U") {
            --head.first;
        }
        
        if(direction == "D") {
            ++head.first;
        }
        
        if(head.second == width || head.first < 0 || head.first == height||head.second < 0 || snakeBody.find(head)!=snakeBody.end()) return -1;
            
        snake.push_front(head);
        snakeBody.insert(head);

        if(foodNumber<food.size() && head == food[foodNumber]) {

            ++foodNumber;
            
            snake.push_back(tail);
            snakeBody.insert(tail);
        }
            
        else {
            snakeBody.insert(head);
        }
        
        return foodNumber;
    }
};

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame obj = new SnakeGame(width, height, food);
 * int param_1 = obj.move(direction);
 */