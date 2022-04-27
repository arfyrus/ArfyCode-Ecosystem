#include <iostream>
#include <cstdlib>
#include <ctime>
#include <array>
#include <vector>
using namespace std;

class Cell {
    public:
    char lifeform, land_type;
    Cell() {
        (*this).lifeform = ' ';
    }
};

const int width = 25, height = 25;
array <Cell, width * height> plane;
int index(int x, int y) {return x + y * width;}

class Plant {
    public:
    int fruits;
    Plant() {
        (*this).fruits = (rand() % 3) + 1;
    }
};

class Chicken {
    public:
    int age, pos_x, pos_y;
    bool carrying_seed;
    Chicken() {
        (*this).carrying_seed = false;
    }
    bool consume_food(Plant berry) {
        (*this).carrying_seed = true;
        berry.fruits--;
        return (berry.fruits == 0);
        
    }
    void move(int x, int y) {
        int new_x = (*this).pos_x + x, new_y = (*this).pos_y + y;
        if (plane[index(new_x, new_y)].land_type == 'w') {

        }
    }
};

void show_grid() {
    for (int j = 0; j < height; j++) {
        for (int i = 0; i < width; i++) {
            switch (plane[index(i, j)].land_type) {
                case 'w':
                cout << "🟦";
                break;
                case 'g':
                cout << "🟫";
            }
        }
        cout << '\n';
    }
}

int main() {
    srand(time(0));
    for (int j = 0; j < height; j++) {
        for (int i = 0; i < width; i++) {
            double probability = rand() % 100, water_min = 92.5;
            bool water_surround = false;
            char result;
            for (int y = -1; y <= 1; y++) {
                for (int x = (y == 0) ? -1 : 0; x <= 1; x += 2) {
                    if (((i + x >= 0) && (i + x < width)) && ((j + y >= 0) && (j + y < height))) {
                        if (plane[index(i + x, j + y)].land_type == 'w') {
                            water_surround = true;
                            break;
                        }
                    }
                }
            }
            if (water_surround) {
                result = (probability >= ((water_min / 10) * 7)) ? 'w' : 'g';
            } else {
                result = (probability >= water_min) ? 'w' : 'g';
            }
            plane[index(i, j)].land_type = result;
        }    
    }
    for (int i = 0; i < 2; i++) {
        int spot = rand() % plane.size();
        if (plane[spot].land_type == 'w' || plane[spot].lifeform != ' ') {
            i--;
            continue;
        } else {
            plane[spot].lifeform = 'c';
        }
    }
    show_grid();
};