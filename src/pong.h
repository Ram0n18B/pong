/*
    ISPPJ1 2024
    Study Case: Pong

    Author: Alejandro Mujica
    alejandro.j.mujic4@gmail.com

    This file contains the definition of a pong game and the declaration
    of the functions to init it, update it, and render it.
*/

#include <src/paddle.h>
#include <src/ball.h>
#include <src/sounds.h>

enum PongState
{
    START,
    SERVE,
    PLAY,
    DONE,
    SERVE_IA,
    SERVE_BIIA,
    PLAY_IA,
    PLAY_BIIA
};

struct Pong
{
    struct Paddle player1;
    struct Paddle player2;
    struct Ball ball;

    enum PongState state;

    int player1_score;
    int player2_score;
    int serving_player;
    int winning_player;

    struct Sounds* sounds;

    bool paddle_ia_band; // (true) activa el paddle2_IA (false) lo desactiva
    bool paddle_bia_band; // (true) activa las dos paddles en IA
};

void init_pong(struct Pong* pong, struct Sounds* sounds);

void handle_input_pong(struct Pong* pong, ALLEGRO_KEYBOARD_STATE* state);

void handle_paddle_ia(struct Ball *ball, struct Paddle *paddle, int paddle_index);

void update_pong(struct Pong* pong, double dt);

void render_pong(struct Pong pong, struct Fonts fonts);
