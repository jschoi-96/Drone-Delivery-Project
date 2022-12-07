#ifndef BASE_WEATHER_H
#define BASE_WEATHER_H
#include <vector>

#include "IEntity.h"
#include "IReaction.h"
#include "IWeather.h"
/**
* @brief This class inherits from the IWeather and is responsible for setting base weather 
**/
class BaseWeather : public IWeather {
 public:
  ~BaseWeather() override = default;
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