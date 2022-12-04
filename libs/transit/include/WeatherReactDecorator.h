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
  float GetSpeed() const;

  // Gets the drone position
  Vector3 GetPosition() const;

  Vector3 GetDirection() const;

  Vector3 GetDestination() const;

  JsonObject GetDetails() const;

  bool GetAvailability() const;

  std::string GetStrategyName();

  void SetAvailability(bool choice);

  // reacts to the weather, then calls the parent's update function
  void Update(double dt, std::vector<IEntity*> scheduler);

  void SetPosition(Vector3 pos_);

  // Sets the drone's direction
  void SetDirection(Vector3 dir_);

  void SetDestination(Vector3 des_);

  // Rotates a drone
  void Rotate(double angle);

  void Jump(double height);

  void SetGraph(const IGraph* graph);

 protected:
  IEntity* parent;
  IReaction* reaction;
};  // close class

#endif  // CELEBRATION_DECORATOR_H_