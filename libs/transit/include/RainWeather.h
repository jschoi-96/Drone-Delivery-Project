#ifndef RAIN_WEATHER_H
#define RAIN_WEATHER_H
#include <vector>

#include "IEntity.h"
#include "IWeather.h"
#include "IZoneWeather.h"
class RainWeather : public IZoneWeather {
 public:
  virtual ~RainWeather() override = default;
  RainWeather(JsonObject& obj);
  void Execute(IEntity* parent, IReaction* reaction, double dt,
               std::vector<IEntity*> scheduler);
};
#endif