#include <iostream>
#include <vector>
#include <array>
using namespace std;

class Cell {
    public:
    int hcost, gcost, fcost;
    bool start, end;
    Cell() : start(false), end(false) {}
    void update() {
        (*this).fcost = (*this).hcost + (*this).gcost;
    }
};

const int width = 10, height = 10;
int index(int x, int y) {return x + y * width;}
array <Cell, width * height> grid;
array <int, 3> spcell = {
    index(1, 1), width - 2, height - 2
};

int find_gcost(int x, int y, int end_cell_x, int end_cell_y) {
    if (x != end_cell_x) {
        int boxb = (x > end_cell_x) ? x - end_cell_x : end_cell_x - x;
        return boxb * 10 + find_gcost(boxb, y, end_cell_x, end_cell_y);
    } else if (y != end_cell_y) {
        int boxa = (y > end_cell_y) ? y - end_cell_y : end_cell_y - y;
        return boxa * 10 + find_gcost(x, boxa, end_cell_x, end_cell_y);
    }
    return 0;
}

void evaluate_neighbors(int x, int y) {
    for (int j = -1; j <= 1; j++) {
        for (int i = (j == 0) ? -1 : 0; i <= 1; i += 2) {
            if (x + 1 >= 0 && x + 1 < width && y + j >= 0 && y + j < 10) {
                int spot = index(x + i, y + j);
                grid[spot].hcost = grid[index(x , y)]. hcost + 10;
                grid[spot].gcost = 
                find_gcost(
                    x + i, y + j, spcell[1], spcell[2]
                );
                grid[spot].update();
            }
        }
    }
}

int main() {
    grid[index(1, 1)].start = true;
    grid[index(spcell[1], spcell[2])].end = true;

    

}