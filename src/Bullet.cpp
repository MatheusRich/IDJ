#include "Bullet.h"
#include "Sprite.h"
#include "Collider.h"

Bullet::Bullet(GameObject &associated, float angle, float speed, int damage, float maxDistance,
               std::string sprite, int frameCount, float frameTime, bool targetsPlayer) : Component(associated) {
  this->associated.AddComponent(new Sprite(associated, sprite, frameCount, frameTime));
  this->associated.AddComponent(new Collider(associated));
  this->associated.angleDeg = angle;
  this->speed = Vec2::GetSpeed(angle) * speed;
  this->damage = damage;
  this->distanceLeft = maxDistance;
  this->targetsPlayer = targetsPlayer;
}

void Bullet::Update(float dt) {
  if (this->distanceLeft > 0) {
    this->associated.box.UpdatePos(speed * dt);
    this->distanceLeft -= Vec2().GetDistance(speed * dt);
  } else {
    this->associated.RequestDelete();
  }
}

void Bullet::Render() {

}

bool Bullet::Is(std::string type) {
  return type == "Bullet";
}

int Bullet::GetDamage() {
  return this->damage;
}

void Bullet::NotifyCollision(GameObject &other) {
  if (this->targetsPlayer) {
    if (other.GetComponent("PenguinBody") != nullptr || other.GetComponent("PenguinCannon") != nullptr) {
      this->associated.RequestDelete();
    }
  } else {
    if (other.GetComponent("Alien") != nullptr || other.GetComponent("Minion") != nullptr) {
      this->associated.RequestDelete();
    }
  }
}

bool Bullet::TargetsPlayer() {
  return this->targetsPlayer;
}
