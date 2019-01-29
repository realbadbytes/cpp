/* Taken from https://www.youtube.com/watch?v=IWvbPIYQPFM
 * Given a 2d grid with colors in each grid square,
 * find the maximum number of connected colors. 
 * Connectivity cannot be diagonal.
 * Color is denoted by integer.
 *
 * Input:
 *
 * (y-axis)
 * ^
 * |
 * _________________________
 * | 1 | 1 | 2 | 1 | 2 | 3 |
 * _________________________
 * | 2 | 1 | 3 | 3 | 3 | 3 |
 * ___________________________> (x-axis)
 *
 *
 * Output: 5
 * color 3 has 5 connected squares.
 */


#include <stdio.h>
#include <vector>

using namespace std;


struct Square {
    int color;  /* Color code */
    int x;      /* x-coordinate */
    int y;      /* y-coordinate */
};


void print_square(Square s) {
    printf("(%d, %d) color: %d\n", s.x, s.y, s.color);
}


/* Helper function to check if neighbor matches current square color
 * returns 0(right), 1(top), 2(left), or 3(bot) if neighbor matches, otherwise -1 */
Square check_neighbor(vector<Square> grid, Square cur_square)
{
    int color = cur_square.color;
    int x = cur_square.x;
    int y = cur_square.y;
    printf("Checking: ");
    print_square(cur_square);

    for (Square s : grid) {
        print_square(s);
        /* check right */
        if ( s.x == x+1 && 
             s.y == y && 
             s.color == color) {
            printf("hit right\n");
            return check_neighbor(grid, s);
        }

        /* check top */
        else if ( (s.x == x) && (s.y == y+1) && s.color == color) {
            printf("hit top\n");
            return check_neighbor(grid, s);
        }

        /* check left */
        else if ( (s.x == x-1) && (s.y == y) && s.color == color) {
            printf("hit left\n");
            return check_neighbor(grid, s);
        }

        /* check bot */
        else if ( (s.x == x) && (s.y == y-1) && s.color == color) {
            printf("hit bot\n");
            return check_neighbor(grid, s);
        }

        else { 
        }
    }
}


/* Iterate over the grid, counting the max connected
 * for each color. Return max after all squares have
 * been processed
 */
int max_connected_colors(vector<Square> grid)
{
    int current_color = 0;

    Square neighbor_match = {0,0,0};

    for (Square s : grid) {
        current_color = s.color;

        /* Check surrounding squares, if match, go to that square
         * do the same thing to each adjacent square 
         * each square will have up to 4 neighbors */
        neighbor_match = check_neighbor(grid, s);
        print_square(neighbor_match);

    }

    return 0;
}


int main(int argc, char *argv[])
{
    /* Row 1 */
    Square a = {2, 1, 1};
    Square b = {1, 2, 1};
    Square c = {3, 3, 1};
    Square d = {3, 4, 1};
    Square e = {3, 5, 1};
    Square f = {3, 6, 1};

    /* Row 2 */
    Square g = {1, 1, 2};
    Square h = {1, 2, 2};
    Square i = {2, 3, 2};
    Square j = {1, 4, 2};
    Square k = {2, 5, 2};
    Square l = {3, 6, 2};

    // print_grid();
    
    /* Create the grid */
    vector<Square> grid {a, b, c, d, e, f, g, h, i, j, k, l};

    max_connected_colors(grid);

    return 0;
}
