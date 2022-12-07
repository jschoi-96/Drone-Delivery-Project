#ifndef EMP_WEATHER_H
#define EMP_WEATHER_H
#include <vector>

#include "IEntity.h"
#include "IWeather.h"
#include "IZoneWeather.h"

class EmpWeather : public IZoneWeather {
 public:
  EmpWeather(JsonObject& obj);
  ~EmpWeather() override = default;
  void Execute(IEntity* parent, IReaction* reaction, double dt,
               std::vector<IEntity*> scheduler);
};
#endif