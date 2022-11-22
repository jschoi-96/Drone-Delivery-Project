#ifndef CELEBRATION_DECORATOR_H_
#define CELEBRATION_DECORATOR_H_

#include <vector>

#include "IEntity.h"
#include "IReaction.h"
#include "graph.h"
#include "math/vector3.h"
#include "util/json.h"

class WeatherReactDecorator : public IEntity {
 public:
  WeatherReactDecorator(IEntity* parent_, IReaction* reaction_) {
    parent = parent_;
    reaction = raction_;
  }  float GetSpeed() const { return speed; }

  // Gets the drone position
  Vector3 GetPosition() const { return parent->GetPosition(); }

  Vector3 GetDirection() const { return parent->GetDirection(); }

  Vector3 GetDestination() const { return parent->GetDestination(); }

  JsonObject GetDetails() const { return parent->GetDetails(); }

  float GetSpeed() const {return parent->GetSpeed(); }

  bool GetAvailability() const { return parent->GetAvailability(); }

  std::string GetStrategyname() {return parent->GetStrategyname(); }

  void SetAvailability(bool choice) {parent->SetAvailability(choice); }

  // reacts to the weather, then calls the parent's update function
  void Update(double dt, std::vector<IEntity*> scheduler) {
    IWeather* weather = BaseWeather::GetInstance();
    weather->execute(parent, reaction, dt, scheduler);
  }

  void SetPosition(Vector3 pos_) { parent->SetPosition(pos_); }

  // Sets the drone's direction
  void SetDirection(Vector3 dir_) { parent->SetDirection(dir_); }

  void SetDestination(Vector3 des_) {
    parent->SetDestination(des_);  
  }

  // Rotates a drone
  void Rotate(double angle) {
    parent->rotate(angle);
  }

  void Jump(double height) {
    parent->jump(height);
  }

 protected:
  IEntity* parent;
  IReaction* reaction;
};  // close class

#endif  // CELEBRATION_DECORATOR_H_