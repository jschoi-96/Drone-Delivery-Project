#ifndef IWEATHER_H
#define IWEATHER_H
#include <vector>

#include "IEntity.h"
#include "IReaction.h"
class IWeather {
 public:
  virtual void Execute(IEntity* parent, IReaction* reaction, double dt,
                       std::vector<IEntity*> scheduler) = 0;
  virtual bool IsInside(
      IEntity* parent) = 0;  // if the object is affected by the weather
};
#endif