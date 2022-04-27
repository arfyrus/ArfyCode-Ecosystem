#include <iostream>
#include <vector>
#include <array>
using namespace std;

class Cell {
    public:
    int hcost, gcost, fcost;
    bool start, end;
    Cell() : start(false), end(false) {}
};

const int width = 10, height = 10;
array <Cell, width * height> grid;

int index(int x, int y) {return x + y * width;}

int find_gcost(int x, int y, int end_cell) {
    if (x == end_cell && y == end_cell) {
        return 0;
    } else if (x != end_cell) {
        int boxb = (x > end_cell) ? x - end_cell : end_cell - x;
        return boxb * 10 + find_gcost(boxb, y, end_cell);
    } else if (y != end_cell) {
        int boxa = (y > end_cell) ? y - end_cell : end_cell - y;
        return boxa * 10 + find_gcost(x, boxa, end_cell);
    }
}

int main() {
    array <int, 2> spcell = {
        index(1, 1), index(width - 2, height - 2)
    };
    grid[spcell[0]].start = true;
    grid[spcell[1]].end = true;

}