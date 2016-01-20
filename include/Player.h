#ifndef PLAYER_H
#define PLAYER_H

void Player_render(GameObject* g, double dt);

void Player_onCollide(GameObject* self, GameObject* other);
#endif
