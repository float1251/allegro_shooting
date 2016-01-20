#include "alternas_s.h"

// 方向弾 ------------------------
GameObject* EDirectional_Shooter_new(float speed, float angle) {
    GameObject *g = GameObject_new();
    g->type = EDIRECTIONAL_SHOOTER;
    // 弾用の角度と速度を設定
    DicrectionalShooterData* d = malloc(sizeof(DicrectionalShooterData));
    d->speed = speed;
    d->angle = angle;
    g->data = d; 
    g->render = EDirectinal_Shooter_render;
    g->delete = EDirectinal_Shooter_delete;
    g->onCollide = Bullet_onCollide;
    return g;
}

void EDirectinal_Shooter_render(GameObject* g, double dt) {
    DicrectionalShooterData *d = g->data;
    GameObject* b = GameObject_new_args(g->x, g->y, d->angle, 0, d->speed, 0, Bullet_render, Bullet_delete, Bullet_onCollide);
    Node* node = Node_new();
    node->data = b;
    List_insert(goList, node);
}

void EDirectinal_Shooter_delete(GameObject* g) {
    if(g->data != NULL) {
        free(g->data);
    }
    free(g);
}
// ------------------------------


// 渦巻弾 -----------------------
GameObject* ESpiral_Shooter_new(float shot_angle, float shot_angle_rate, float shot_speed) {
    GameObject *g = GameObject_new();
    g->type = ESPIRAL_SHOOTER;
    // 弾用の角度と速度を設定
    SpiralShooterData* d = malloc(sizeof(SpiralShooterData));
    d->shot_angle = shot_angle;
    d->shot_angle_rate = shot_angle_rate;
    d->shot_speed = shot_speed;
    g->data = d; 
    g->render = ESpiral_Shooter_render;
    g->delete = ESpiral_Shooter_delete;
    g->onCollide = Bullet_onCollide;
    return g;
}

void ESpiral_Shooter_render(GameObject* g, double dt) {
    if(al_get_timer_count(timer) %10 == 0){
        SpiralShooterData* d = g->data; 
        GameObject* b = GameObject_new_args(g->x, g->y, d->shot_angle, 0, d->shot_speed, 0.002, Bullet_render, Bullet_delete, Bullet_onCollide);
        Node* node = Node_new();
        node->data = b;
        List_insert(goList, node);

        // 発射角度を変化させる
        d->shot_angle += d->shot_angle_rate;

        // 浮動小数点の精度を保つための処理
        d->shot_angle -= floor(d->shot_angle);
    }
    al_draw_filled_circle(g->x, g->y, 5, al_map_rgb(0, 255, 0));
}

void ESpiral_Shooter_delete(GameObject* g) {
    if(g->data != NULL) {
        free(g->data);
    }
    free(g);
}

// ------------------------------

// 多方向渦巻弾 -----------------
GameObject* EMultiple_Spiral_Shooter_new(float shot_angle, float shot_angle_rate, float shot_speed, int shot_count) {
    GameObject *g = GameObject_new();
    g->type = EMULTIPLE_SPIRAL_SHOOTER;
    // 弾用の角度と速度を設定
    MultipleSpiralShooterData* d = malloc(sizeof(MultipleSpiralShooterData));
    d->shot_angle = shot_angle;
    d->shot_angle_rate = shot_angle_rate;
    d->shot_speed = shot_speed;
    d->shot_count = shot_count;
    g->data = d; 
    g->render = EMultiple_Spiral_Shooter_render;
    g->delete = EMultiple_Spiral_Shooter_delete;
    g->onCollide = Bullet_onCollide;
    return g;
}


void EMultiple_Spiral_Shooter_render(GameObject* g, double dt) {

    if(al_get_timer_count(timer) %10 == 0){
        MultipleSpiralShooterData* d = g->data;
        for(int i=0; i< d->shot_count; i++) {
            GameObject* b = GameObject_new_args(g->x, g->y, d->shot_angle+(float)i/d->shot_count,
                0, d->shot_speed, 0.002, Bullet_render, Bullet_delete, Bullet_onCollide);
            Node* node = Node_new();
            node->data = b;
            List_insert(goList, node);
        }
        // 発射角度を変化させる
        d->shot_angle += d->shot_angle_rate;

        // 浮動小数点の精度を保つための処理
        d->shot_angle -= floor(d->shot_angle);
    }

    al_draw_filled_circle(g->x, g->y, 5, al_map_rgb(0, 255, 0));
}

void EMultiple_Spiral_Shooter_delete(GameObject* g) {
    if(g->data != NULL) {
        free(g->data);
    }
    free(g);
}


// ------------------------------
