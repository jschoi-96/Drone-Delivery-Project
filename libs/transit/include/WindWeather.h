#ifndef WIND_WEATHER_H
#define WIND_WEATHER_H
#include <vector>

#include "IEntity.h"
#include "IWeather.h"
#include "IZoneWeather.h"
#include "math/vector3.h"
class WindWeather : public IZoneWeather {
 private:
  Vector3 windSpeed;

 public:
  WindWeather(JsonObject& obj);

  void Execute(IEntity* parent, IReaction* reaction, double dt,
               std::vector<IEntity*> scheduler);
};
#endif