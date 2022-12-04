#ifndef RAIN_WEATHER_H
#define RAIN_WEATHER_H
#include <vector>

#include "IEntity.h"
#include "IWeather.h"
#include "IZoneWeather.h"
class RainWeather : public IZoneWeather {
 public:
  RainWeather(IWeather* parent_, double xCircle_, double yCircle_,
              double radius_);
  RainWeather(IWeather* parent, double xminRec_, double yminRec_,
              double xmaxRec_, double ymaxRec_);
  void execute(IEntity* parent, IReaction* reaction, double dt,
               std::vector<IEntity*> scheduler);
};
#endif