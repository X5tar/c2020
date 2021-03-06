#include <stdio.h>
#include <stdlib.h>
#include "conio.h"
#include "boxes.h"

int main() {
    unsigned int ch;
    Game game;
    int in_place = 0;

    while (1) {
        printf("Please enter the filename: ");
        scanf("%s", game.filename);
        getchar();
        init_game(&game);
        if (game.map == NULL) {
            printf("%s not found!\n", game.filename);
        } else {
            break;
        }
    }

    system("CLS");
    print_map(&game);
    printf("Use arrow keys or wasd to move or enter q to quit.\n");
    printf("Moves: %d\n", game.moves);

    while ((ch = getch()) != 'q') {
        if (ch == 0 || ch == 224) {
            // Use arrow keys
            switch (getch()) {
                case 72: // Up
                    move(&game, 0);
                    break;

                case 80: // Down
                    move(&game, 1);
                    break;

                case 77: // Right
                    move(&game, 2);
                    break;

                case 75: // Lift
                    move(&game, 3);
                    break;

                default:
                    break;
            }
        } else {
            // Use w a s d
            switch (ch) {
                case 'w':
                case 'W': // Up
                    move(&game, 0);
                    break;

                case 's':
                case 'S': // Down
                    move(&game, 1);
                    break;

                case 'd':
                case 'D': // Right
                    move(&game, 2);
                    break;

                case 'a':
                case 'A': // Lift
                    move(&game, 3);
                    break;

                default:
                    break;
            }
        }

        system("CLS");
        print_map(&game);

        for (int i = 0; i < game.boxes; i++) {
            for (int j = 0; j < game.boxes; j++) {
                if (game.boxes_x[i] == game.targets_x[j] && game.boxes_y[i] == game.targets_y[j]) {
                    in_place++;
                }
            }
        }

        if (in_place == game.boxes) {
            printf("Success!\n");
            while (1) {
                printf("Save or not?[y/n]");
                ch = getch();
                if (ch == 'y' || ch == 'Y') {
                    save_game(&game);
                    break;
                } else if (ch == 'n' || ch == 'N') {
                    break;
                } else {
                    printf("\n");
                }
            }
            break;
        } else {
            in_place = 0;
            printf("Use arrow keys or wasd to move or enter q to quit.\n");
            printf("Moves: %d\n", game.moves);
        }
    }

    printf("\nThe game is quiting...\n");
    quit_game(&game);
    printf("Everything is done!\n");
    printf("Bye!\n");
    getchar();

    return 0;
}
