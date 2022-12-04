#ifndef EMP_WEATHER_H
#define EMP_WEATHER_H
#include <vector>

#include "IEntity.h"
#include "IWeather.h"
#include "IZoneWeather.h"

class EmpWeather : public IZoneWeather {
 public:
  EmpWeather(IWeather* parent_, double xCircle_, double yCircle_,
             double radius_);
  EmpWeather(IWeather* parent, double xminRec_, double yminRec_,
             double xmaxRec_, double ymaxRec_);
  void execute(IEntity* parent, IReaction* reaction, double dt,
               std::vector<IEntity*> scheduler);
};
#endif