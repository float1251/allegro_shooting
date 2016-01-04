#ifndef GAME_H
#define GAME_H

typedef struct Game {
    ALLEGRO_DISPLAY* display;
    void(*start)(void);
    void(*render)(double dt);
    void(*delete)();
} Game;

Game* Game_new(ALLEGRO_DISPLAY* d);

void Game_start();
void Game_render();
void Game_delete();

#endif
