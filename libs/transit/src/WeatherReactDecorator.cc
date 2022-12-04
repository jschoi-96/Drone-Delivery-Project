#include "WeatherReactDecorator.h"

#include <vector>

#include "BaseWeather.h"
#include "IEntity.h"
#include "IReaction.h"
#include "IWeather.h"
#include "graph.h"
#include "math/vector3.h"
#include "util/json.h"

WeatherReactDecorator::WeatherReactDecorator(IEntity* parent_,
                                             IReaction* reaction_) {
  parent = parent_;
  reaction = reaction_;
}
void WeatherReactDecorator::Update(double dt, std::vector<IEntity*> scheduler) {
  printf("Begin update!\n");
  IWeather* weather = BaseWeather::GetInstance();
  parent->GetDetails()["color"] =
      reaction->colors["white"];  // resets color to white
  printf("Mid update\n");
  weather->execute(parent, reaction, dt, scheduler);
  printf("End update!\n");
}