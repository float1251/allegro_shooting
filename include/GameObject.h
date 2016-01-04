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
    PLAYER_BULLET,     
    ENEMY,
} DataType;

typedef struct GameObject {
    double x;
    double y;
    void* data; // それぞれrender等で使用する独自データ
    DataType type;
    // 毎フレーム呼ばれる
    void(*render)(struct GameObject* g, double dt);
    // 削除時
    void(*delete)(struct GameObject* p);
} GameObject;

GameObject* GameObject_new();

#endif
