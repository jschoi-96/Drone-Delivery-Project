#include "WeatherReactDecorator.h"

#include <vector>

#include "BaseWeather.h"
#include "IEntity.h"
#include "IReaction.h"
#include "IWeather.h"
#include "graph.h"
#include "math/vector3.h"
#include "util/json.h"

WeatherReactDecorator::WeatherReactDecorator(IEntity* parent_,
                                             IReaction* reaction_) {
  parent = parent_;
  reaction = reaction_;
}
void WeatherReactDecorator::Update(double dt, std::vector<IEntity*> scheduler) {
  IWeather* weather = BaseWeather::GetInstance();
  parent->SetColor(reaction->colors["white"]);  // resets color to white
  weather->Execute(parent, reaction, dt, scheduler);
}
float WeatherReactDecorator::GetSpeed() const { return parent->GetSpeed(); }

// Gets the drone position
Vector3 WeatherReactDecorator::GetPosition() const {
  return parent->GetPosition();
}

Vector3 WeatherReactDecorator::GetDirection() const {
  return parent->GetDirection();
}

Vector3 WeatherReactDecorator::GetDestination() const {
  return parent->GetDestination();
}

JsonObject WeatherReactDecorator::GetDetails() const {
  return parent->GetDetails();
}

bool WeatherReactDecorator::GetAvailability() const {
  return parent->GetAvailability();
}

std::string WeatherReactDecorator::GetStrategyName() {
  return parent->GetStrategyName();
}

void WeatherReactDecorator::SetAvailability(bool choice) {
  parent->SetAvailability(choice);
}

void WeatherReactDecorator::SetPosition(Vector3 pos_) {
  parent->SetPosition(pos_);
}

// Sets the drone's direction
void WeatherReactDecorator::SetDirection(Vector3 dir_) {
  parent->SetDirection(dir_);
}

void WeatherReactDecorator::SetDestination(Vector3 des_) {
  parent->SetDestination(des_);
}
void WeatherReactDecorator::SetGraph(const IGraph* graph) {
  parent->SetGraph(graph);
}

// Rotates a drone
void WeatherReactDecorator::Rotate(double angle) { parent->Rotate(angle); }

void WeatherReactDecorator::Jump(double height) { parent->Jump(height); }