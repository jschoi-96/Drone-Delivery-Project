#ifndef BASE_WEATHER_H
#define BASE_WEATHER_H
#include <vector>

#include "IEntity.h"
#include "IReaction.h"
#include "IWeather.h"
class BaseWeather : public IWeather {
 public:
  void Execute(IEntity* parent, IReaction* reaction, double dt,
               std::vector<IEntity*> scheduler);
  virtual void update(double dt, std::vector<IEntity*> scheduler) {}
  virtual bool IsInside(IEntity* parent) { return true; }

  static IWeather* GetInstance();
  static void SetInstance(IWeather* new_instance) { instance = new_instance; }

 private:
  // there is ONLY ONE WEATHER IN THE WORLDDDDDD
  BaseWeather() {}
  static IWeather* instance;
};
#endif