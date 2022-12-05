
#include "WindWeather.h"

#include <vector>

#include "BaseWeather.h"
#include "IEntity.h"
#include "IWeather.h"
#include "IZoneWeather.h"
void WindWeather::Execute(IEntity* parent, IReaction* reaction, double dt,
                          std::vector<IEntity*> scheduler) {
  if (IsInside(parent)) reaction->react_wind(parent, dt, scheduler, windSpeed);
  this->parent->Execute(parent, reaction, dt, scheduler);
}

WindWeather::WindWeather(JsonObject& obj) {
  details = obj;
  parent = BaseWeather::GetInstance();
  JsonArray position(obj["position"]);
  pos = {position[0], position[1], position[2]};
  JsonArray dir(obj["direction"]);
  direction = {dir[0], dir[1], dir[2]};
  speed = direction.Magnitude();
  JsonArray windSpeed(obj["windSpeed"]);
  this->windSpeed = {windSpeed[0], windSpeed[1], windSpeed[2]};
  bool isCircle = obj["isCircle"];
  this->isCircle = isCircle;
  if (isCircle) {
    float radius = obj["radius"];
    this->radius = radius;
  } else {
    JsonArray width(obj["width"]);
    this->width = {width[0], width[1], width[2]};
  }
  BaseWeather::SetInstance(this);
}
