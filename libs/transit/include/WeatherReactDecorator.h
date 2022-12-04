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
  WeatherReactDecorator(IEntity* parent_, IReaction* reaction_);
  float GetSpeed() const { return parent->GetSpeed(); }

  // Gets the drone position
  Vector3 GetPosition() const { return parent->GetPosition(); }

  Vector3 GetDirection() const { return parent->GetDirection(); }

  Vector3 GetDestination() const { return parent->GetDestination(); }

  JsonObject GetDetails() const { return parent->GetDetails(); }

  bool GetAvailability() const { return parent->GetAvailability(); }

  std::string GetStrategyName() { return parent->GetStrategyName(); }

  void SetAvailability(bool choice) { parent->SetAvailability(choice); }

  // reacts to the weather, then calls the parent's update function
  void Update(double dt, std::vector<IEntity*> scheduler);

  void SetPosition(Vector3 pos_) { parent->SetPosition(pos_); }

  // Sets the drone's direction
  void SetDirection(Vector3 dir_) { parent->SetDirection(dir_); }

  void SetDestination(Vector3 des_) { parent->SetDestination(des_); }

  // Rotates a drone
  void Rotate(double angle) { parent->Rotate(angle); }

  void Jump(double height) { parent->Jump(height); }

 protected:
  IEntity* parent;
  IReaction* reaction;
};  // close class

#endif  // CELEBRATION_DECORATOR_H_