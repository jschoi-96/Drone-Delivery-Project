
#include "EmpWeather.h"

#include <vector>

#include "IEntity.h"
#include "IWeather.h"
#include "IZoneWeather.h"
void EmpWeather::execute(IEntity* parent, IReaction* reaction, double dt,
                         std::vector<IEntity*> scheduler) {
  if (is_inside(parent)) reaction->react_emp(parent, dt, scheduler);
  this->parent->execute(parent, reaction, dt, scheduler);
}
EmpWeather::EmpWeather(IWeather* parent_, double xCircle_, double yCircle_,
                       double radius_) {
  parent = parent_;
  circle(xCircle_, yCircle_, radius_);
}
EmpWeather::EmpWeather(IWeather* parent_, double xminRec_, double yminRec_,
                       double xmaxRec_, double ymaxRec_) {
  parent = parent_;
  rect(xminRec_, yminRec_, xmaxRec_, ymaxRec_);
}