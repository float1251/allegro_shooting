#ifndef ENEMY_H
#define ENEMY_H

// --------------------------------------------------------
// 方向弾
typedef struct {
    float angle; // 角度
    float speed; // 速度
} DicrectionalShooterData;
GameObject* EDirectional_Shooter_new(float speed, float angle);
void EDirectinal_Shooter_render(GameObject* g, double dt);
void EDirectinal_Shooter_delete(GameObject* g);
// --------------------------------------------------------

// --------------------------------------------------------
// 渦巻弾
typedef struct {
    float shot_angle;
    float shot_angle_rate;
    float shot_speed;
} SpiralShooterData;
GameObject* ESpiral_Shooter_new(float shot_angle, float shot_angle_rate, float shot_speed);
void ESpiral_Shooter_render(GameObject* g, double dt);
void ESpiral_Shooter_delete(GameObject* g);
// --------------------------------------------------------

// --------------------------------------------------------
// 多方向渦巻弾
typedef struct {
    float shot_angle;
    float shot_angle_rate;
    float shot_speed;
    int shot_count;
} MultipleSpiralShooterData;
GameObject* EMultiple_Spiral_Shooter_new(float shot_angle, float shot_angle_rate, float shot_speed, int shot_count);
void EMultiple_Spiral_Shooter_render(GameObject* g, double dt);
void EMultiple_Spiral_Shooter_delete(GameObject* g);
#endif
