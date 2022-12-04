#include "BaseWeather.h"

#include "IEntity.h"
#include "IReaction.h"
#include "IWeather.h"
IWeather* BaseWeather::instance = nullptr;
IWeather* BaseWeather::GetInstance() {
  if (instance == nullptr) {
    instance = new BaseWeather();
  }
  return instance;
}
void BaseWeather::execute(IEntity* parent, IReaction* reaction, double dt,
                          std::vector<IEntity*> scheduler) {
  printf("Base was called!\n");
  parent->Update(dt, scheduler);
  printf("Base was successful!\n");
}
