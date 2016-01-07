#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

/**
 * 画面に描画されるものはすべてGameObjectとして管理する。
 * GameObjectのdelete、renderでそれぞれ独自の描画、削除処理を実行される。
 * dataはtypeでキャストの判別をし、dataの削除はGameObject->delete内で実行する。
 **/

// GameObjectにデータを持たせて、
// それをどのタイプにキャストするか判定する際に使用する
typedef enum DataType {
    BULLET,     
    ENEMY,
    EDIRECTIONAL_SHOOTER, // 方向団を撃つ敵
    ESPIRAL_SHOOTER, // 渦巻弾を撃つ敵
    EMULTIPLE_SPIRAL_SHOOTER, // 多方向渦巻弾を撃つ敵
} DataType;

typedef struct GameObject {
    // 位置
    float x;
    float y;
    //------------------------------
    // 基本的に弾、敵にしか使わない
    float angle; // 角度
    float angle_rate; // 角速度
    float speed;       // 速度
    float speed_rate;  // 加速度
    //------------------------------
    bool alive; // falseなら削除される
    void* data; // それぞれrender等で使用する独自データ
    DataType type;
    // 毎フレーム呼ばれる
    void(*render)(struct GameObject* g, double dt);
    // 削除時
    void(*delete)(struct GameObject* p);
} GameObject;

GameObject* GameObject_new();

GameObject* GameObject_new_args(float x, float y, float angle, float angle_rate, 
    float speed, float speed_rate, 
    void(*render)(GameObject* g, double dt), 
    void(*delete)(GameObject* g));
#endif
