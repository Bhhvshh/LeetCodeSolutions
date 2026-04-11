class Robot {
public:
int height, width;
int round;
int currDir;
bool moved = false;
vector<string> Directions = {
    "East",
    "North",
    "West",
    "South"
};
vector<pair<int,int>> dir = {
        {1, 0},   // right
        {0, 1},   // down
        {-1, 0},  // left
        {0, -1}   // up
    };

int x, y;
    Robot(int width, int height) {
          this->height = height;
          this->width = width;
          round = 2*(height + width) -4; 
          currDir = 0;
          x = y = 0;   
    }
    
    void step(int num) {
        num = num % round;
        moved = true;
      while (num--) {
        int nx = x + dir[currDir].first;
        int ny = y + dir[currDir].second;

        // check if next is still on boundary
        if (nx < 0 || nx >= width|| ny < 0 || ny >= height ) {
            
            // change direction anticlockwise
            currDir = (currDir + 1) % 4;

            nx = x + dir[currDir].first;
            ny = y + dir[currDir].second;
        }

        x = nx;
        y = ny;
    }

    }
    
    vector<int> getPos() {
        return {x,y};
        
    }
    
    string getDir() {
        if(x == 0 && y == 0 && moved) return "South";
        return Directions[currDir];
        
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */