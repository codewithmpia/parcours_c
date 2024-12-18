/*
    1. Prérequis:
    -------------
        Si ce n'est pas dejà fait, il faut installé ncurses

        - Sur ubuntu: sudo apt-get install libncurses5-dev libncursesw5-dev
        - Sur macOs: brew install ncurses

    2. Compilation:
    ---------------
        gcc -W 11.5.jeu_snake.c -o 11.5.jeu_snake -lncurses
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ncurses.h>
#include <unistd.h>

#define WIDTH 40
#define HEIGHT 20
#define SNAKE_MAX_LENGTH 100
#define DELAY 100000 // Microsecondes (100ms)

typedef struct {
    int x, y;
} Position;

typedef struct {
    Position body[SNAKE_MAX_LENGTH];
    int length;
    Position direction;
} Snake;

typedef struct {
    Position pos;
} Food;

void init_game(Snake *snake, Food *food);
void draw_game(Snake *snake, Food *food);
void move_snake(Snake *snake);
int check_collision(Snake *snake, Food *food);
int check_self_collision(Snake *snake);
void generate_food(Food *food, Snake *snake);

int main() {
    Snake snake;
    Food food;
    int game_over = 0;

    initscr();               // Initialisation de ncurses
    noecho();                // Désactive l'affichage automatique des touches
    curs_set(FALSE);         // Cache le curseur
    keypad(stdscr, TRUE);    // Active les touches fléchées
    nodelay(stdscr, TRUE);   // Pas d'attente sur l'entrée utilisateur

    init_game(&snake, &food);

    while (!game_over) {
        clear();             // Efface l'écran
        draw_game(&snake, &food);
        refresh();           // Met à jour l'écran

        // Gestion des entrées utilisateur
        int ch = getch();
        switch (ch) {
            case KEY_UP:
                if (snake.direction.y != 1) {
                    snake.direction.x = 0;
                    snake.direction.y = -1;
                }
                break;
            case KEY_DOWN:
                if (snake.direction.y != -1) {
                    snake.direction.x = 0;
                    snake.direction.y = 1;
                }
                break;
            case KEY_LEFT:
                if (snake.direction.x != 1) {
                    snake.direction.x = -1;
                    snake.direction.y = 0;
                }
                break;
            case KEY_RIGHT:
                if (snake.direction.x != -1) {
                    snake.direction.x = 1;
                    snake.direction.y = 0;
                }
                break;
            case 'q': // Quitter le jeu
                game_over = 1;
                break;
        }

        move_snake(&snake);

        if (check_collision(&snake, &food)) {
            snake.length++;
            generate_food(&food, &snake);
        }

        if (check_self_collision(&snake)) {
            game_over = 1;
        }

        usleep(DELAY);
    }

    endwin(); // Fin de ncurses
    printf("Game Over! Votre score est : %d\n", snake.length - 1);
    return 0;
}

void init_game(Snake *snake, Food *food) {
    snake->length = 1;
    snake->body[0].x = WIDTH / 2;
    snake->body[0].y = HEIGHT / 2;
    snake->direction.x = 1;
    snake->direction.y = 0;
    generate_food(food, snake);
}

void draw_game(Snake *snake, Food *food) {
    // Dessiner les bordures
    for (int i = 0; i <= WIDTH + 1; i++) mvprintw(0, i, "#");
    for (int i = 0; i <= WIDTH + 1; i++) mvprintw(HEIGHT + 1, i, "#");
    for (int i = 0; i <= HEIGHT + 1; i++) {
        mvprintw(i, 0, "#");
        mvprintw(i, WIDTH + 1, "#");
    }

    // Dessiner le serpent
    for (int i = 0; i < snake->length; i++) {
        mvprintw(snake->body[i].y + 1, snake->body[i].x + 1, "O");
    }

    // Dessiner la nourriture
    mvprintw(food->pos.y + 1, food->pos.x + 1, "*");
}

void move_snake(Snake *snake) {
    for (int i = snake->length - 1; i > 0; i--) {
        snake->body[i] = snake->body[i - 1];
    }

    snake->body[0].x += snake->direction.x;
    snake->body[0].y += snake->direction.y;

    // Gérer le dépassement des bords
    if (snake->body[0].x < 0) snake->body[0].x = WIDTH - 1;
    if (snake->body[0].x >= WIDTH) snake->body[0].x = 0;
    if (snake->body[0].y < 0) snake->body[0].y = HEIGHT - 1;
    if (snake->body[0].y >= HEIGHT) snake->body[0].y = 0;
}

int check_collision(Snake *snake, Food *food) {
    if (snake->body[0].x == food->pos.x && snake->body[0].y == food->pos.y) {
        return 1;
    }
    return 0;
}

int check_self_collision(Snake *snake) {
    for (int i = 1; i < snake->length; i++) {
        if (snake->body[0].x == snake->body[i].x && snake->body[0].y == snake->body[i].y) {
            return 1;
        }
    }
    return 0;
}

void generate_food(Food *food, Snake *snake) {
    int valid = 0;

    while (!valid) {
        food->pos.x = rand() % WIDTH;
        food->pos.y = rand() % HEIGHT;
        valid = 1;

        // Vérifier que la nourriture n'apparaît pas sur le serpent
        for (int i = 0; i < snake->length; i++) {
            if (snake->body[i].x == food->pos.x && snake->body[i].y == food->pos.y) {
                valid = 0;
                break;
            }
        }
    }
}
