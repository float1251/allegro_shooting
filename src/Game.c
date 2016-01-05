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
    player->delete = Bullet_delete;
    goList = List_new();

    Node* node = Node_new();
    //GameObject* g = EDirectional_Shooter_new(-5, 0.1);
    GameObject* g = ESpiral_Shooter_new(.5, 0.03, 5);
    g->speed = 0;
    g->x = 800;
    g->y = SCREEN_H / 2;
    node->data = g;
    List_insert(goList, node);

}

void Game_render(double dt){
    al_clear_to_color(al_map_rgb(0, 0, 0));
    // GameObjectの描画
    if(goList != NULL) {
        Node* node = goList->head; 
        while(node != NULL){
            GameObject* g = node->data;
            g->render(g, dt);
            node = node->next;
        }
        // node = goList->head;
        // while(node != NULL){
        //     GameObject* g = node->data;
        //      if(!g->alive){
        //         node = node->next;
        //         Node* tmp = node;
        //         List_remove(goList, tmp);
        //         // g->delete(g);
        //         Node_delete(tmp);
        //      }else{
        //         node = node->next;
        //     }
        //      
        // }
    }
    // Playerの描画
    player->render(player, dt);
    // 自機から弾を発射する
    if(al_get_timer_count(timer) % 10 == 0) {
        //Node* node = Node_new();
        //GameObject* g = GameObject_new();
        //g->type = BULLET;
        //g->speed = 5;
        //g->speed_rate = 1;
        //g->render = Bullet_render;
        //g->delete = Bullet_delete;
        //g->x = player->x;
        //g->y = player->y;
        //node->data = g;
        //List_insert(goList, node);
    }

    // 敵を出現させる
    // if(al_get_timer_count(timer) % 20 == 0) {
    //     Node* node = Node_new();
    //     GameObject* g = GameObject_new();
    //     g->type = BULLET;
    //     g->speed = -10;
    //     g->render = Bullet_render;
    //     g->delete = Bullet_delete;
    //     g->x = SCREEN_W + 10;
    //     g->y = rand() % SCREEN_H;
    //     node->data = g;
    //     List_insert(goList, node);
    // }
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
