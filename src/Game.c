#include "alternas_s.h"

Game* Game_new(ALLEGRO_DISPLAY* d) {
    Game *g = malloc(sizeof(Game));
    g->start = Game_start;
    g->render = Game_render;
    g->delete = Game_delete;
    g->display = d;
    return g;
}

void Game_start() {
    player = GameObject_new();
    player->render = Player_render;
    // TODO 変える
    player->delete = PlayerBullet_delete;
    goList = List_new();
}

void Game_render(double dt){
    al_clear_to_color(al_map_rgb(0, 0, 0));
    // GameObjectの描画
    if(goList != NULL) {
        Node* node = goList->head; 
        while(node != NULL){
            ((GameObject*)node->data)->render(node->data, dt);
            node = node->next;
        }
    }
    // Playerの描画
    player->render(player, dt);
    // 自機から弾を発射する
    if(al_get_timer_count(timer) % 10 == 0) {
        Node* node = Node_new();
        GameObject* g = GameObject_new();
        g->type = PLAYER_BULLET;
        Vector* v = Vector_new();
        v->x = 10;
        g->data = v;
        g->render = PlayerBullet_render;
        g->delete = PlayerBullet_delete;
        g->x = player->x;
        g->y = player->y;
        node->data = g;
        List_insert(goList, node);
    }

    // 敵を出現させる
    if(al_get_timer_count(timer) % 20 == 0) {
        Node* node = Node_new();
        GameObject* g = GameObject_new();
        g->type = PLAYER_BULLET;
        Vector* v = Vector_new();
        v->x = -5;
        v->y = 0;
        g->data = v;
        g->render = PlayerBullet_render;
        g->delete = PlayerBullet_delete;
        g->x = SCREEN_W + 10;
        g->y = rand() % SCREEN_H;
        node->data = g;
        List_insert(goList, node);
    }
    // TODO 敵から弾を発射させる
}

void Game_delete() {
    if(player != NULL)
        free(player);
    if(goList != NULL) {
        Node* node = goList->head;
        while(node != NULL){
            // TODO dataも削除する
            Node* tmp = node->next;
            if(node->data != NULL)
                ((GameObject*)node->data)->delete(node->data);
            Node_delete(node);
            node = tmp;
        }
    }
}
