#include "alternas_s.h"

int main(void)
{
    Game* g = NULL;
    int res = 0;
    ALLEGRO_DISPLAY *display = NULL;
    ALLEGRO_EVENT_QUEUE *event_queue = NULL;
    timer = NULL;
    bool redraw = true;
    input = Input_new();

    if(!al_init()) {
        fprintf(stderr, "failed to initialize allegro!\n");
        res = -1;
        goto close;
    }

    if(!al_install_keyboard()) {
        fprintf(stderr, "failed to initialize the keyboard!\n");
        res = -1;
        goto close;
    }

    timer = al_create_timer(1.0 / FPS);
    if(!timer) {
        fprintf(stderr, "failed to create timer!\n");
        res = -1;
        goto close;
    }

    display = al_create_display(SCREEN_W, SCREEN_H);
    if(!display) {
        fprintf(stderr, "failed to create display!\n");
        res = -1;
        goto close;
    }

    event_queue = al_create_event_queue();
    if(!event_queue) {
        fprintf(stderr, "failed to create event_queue!\n");
        res = -1;
        goto close;
    }

    if(!al_init_primitives_addon()){
        fprintf(stderr, "failed to initialize primitves addon\n");
        res = -1;
        goto close;
    }

    al_register_event_source(event_queue, al_get_display_event_source(display));

    al_register_event_source(event_queue, al_get_timer_event_source(timer));

    al_register_event_source(event_queue, al_get_keyboard_event_source());

    al_clear_to_color(al_map_rgb(0,0,0));

    al_flip_display();

    al_start_timer(timer);

    g = Game_new(display);
    g->start();
    double startTime = al_get_time();
    while(true)
    {
        ALLEGRO_EVENT ev;
        al_wait_for_event(event_queue, &ev);

        if(ev.type == ALLEGRO_EVENT_TIMER) {
            redraw = true;
        }
        else if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
            break;
        }

        Input_update(input, &ev);

        if(redraw && al_is_event_queue_empty(event_queue)) {
            redraw = false;
            g->render(al_get_time() - startTime);
            startTime = al_get_time();
            al_flip_display();
        }
    }

close:
    if(g != NULL){
        g->delete();
        free(g);
    }
    if(timer != NULL)
        al_destroy_timer(timer);
    if(display != NULL)
        al_destroy_display(display);
    if(event_queue != NULL)
        al_destroy_event_queue(event_queue);
    return res;
}
