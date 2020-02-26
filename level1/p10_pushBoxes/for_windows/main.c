#include <stdio.h>
#include <stdlib.h>
#include "conio.h"
#include "boxes.h"

int main() {
    int ch;
    int in_place = 0;
    int x = 1; // height
    int y = 2; // width
    int boxes_x[BOXES] = {5, 6};
    int boxes_y[BOXES] = {4, 4};
    int targets_x[BOXES] = {8, 8};
    int targets_y[BOXES] = {2, 26};
    char map[HEIGHT][WIDTH] =
            {{'+', ' ', '+', ' ', '+', ' ', '+', ' ', '+', ' ', '+', ' ', '+', ' ', '+', ' ', '+', ' ', '+', ' ', '+', ' ', '+', ' ', '+', ' ', '+', ' ', '+'},
             {'+', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '+'},
             {'+', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '+'},
             {'+', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '+'},
             {'+', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '+'},
             {'+', ' ', ' ', ' ', '@', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '+'},
             {'+', ' ', ' ', ' ', '@', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '+'},
             {'+', ' ', '+', ' ', '+', ' ', '+', ' ', '+', ' ', '+', ' ', '+', ' ', ' ', ' ', '+', ' ', '+', ' ', '+', ' ', '+', ' ', '+', ' ', '+', ' ', '+'},
             {'+', ' ', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', '+'},
             {'+', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '+'},
             {'+', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '+'},
             {'+', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '+'},
             {'+', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '+'},
             {'+', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '+'},
             {'+', ' ', '+', ' ', '+', ' ', '+', ' ', '+', ' ', '+', ' ', '+', ' ', '+', ' ', '+', ' ', '+', ' ', '+', ' ', '+', ' ', '+', ' ', '+', ' ', '+'}};

    system("CLS");
    print_map(map);
    printf("Use arrow keys or wasd to move or enter q to quit.\n");

    while ((ch = getch()) != 'q') {
        if (ch == 0 || ch == 224) {
            // Use arrow keys
            switch (getch()) {
                case 72: // Up
                    move(map, &x, &y, boxes_x, boxes_y, targets_x, targets_y, 0);
                    break;

                case 80: // Down
                    move(map, &x, &y, boxes_x, boxes_y, targets_x, targets_y, 1);
                    break;

                case 77: // Right
                    move(map, &x, &y, boxes_x, boxes_y, targets_x, targets_y, 2);
                    break;

                case 75: // Lift
                    move(map, &x, &y, boxes_x, boxes_y, targets_x, targets_y, 3);
                    break;

                default:
                    break;
            }
        } else {
            // Use w a s d
            switch (ch) {
                case 'w':
                case 'W': // Up
                    move(map, &x, &y, boxes_x, boxes_y, targets_x, targets_y, 0);
                    break;

                case 's':
                case 'S': // Down
                    move(map, &x, &y, boxes_x, boxes_y, targets_x, targets_y, 1);
                    break;

                case 'd':
                case 'D': // Right
                    move(map, &x, &y, boxes_x, boxes_y, targets_x, targets_y, 2);
                    break;

                case 'a':
                case 'A': // Lift
                    move(map, &x, &y, boxes_x, boxes_y, targets_x, targets_y, 3);
                    break;

                default:
                    break;
            }
        }

        system("CLS");
        print_map(map);

        for (int i = 0; i < BOXES; i++) {
            for (int j = 0; j < BOXES; j++) {
                if (boxes_x[i] == targets_x[j] && boxes_y[i] == targets_y[j]) {
                    in_place++;
                }
            }
        }

        if (in_place == BOXES) {
            printf("Success!\n");
            getchar();
            break;
        } else {
            in_place = 0;
            printf("Use arrow keys or wasd to move or enter q to quit.\n");
        }
    }


    return 0;
}
