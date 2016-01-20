#ifndef BULLET_H
#define BULLET_H

// PlayerのBulletの描画関数
void Bullet_render(struct GameObject* g, double dt);

void Bullet_delete(struct GameObject* g);
void Bullet_onCollide(GameObject* self, GameObject* other);
#endif
