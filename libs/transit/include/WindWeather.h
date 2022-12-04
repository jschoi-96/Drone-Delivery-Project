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
  WindWeather(IWeather* parent_, Vector3 windSpeed_, double xCircle_,
              double yCircle_, double radius_);
  WindWeather(IWeather* parent, Vector3 windSpeed_, double xminRec_,
              double yminRec_, double xmaxRec_, double ymaxRec_);
  void execute(IEntity* parent, IReaction* reaction, double dt,
               std::vector<IEntity*> scheduler);
};
#endif