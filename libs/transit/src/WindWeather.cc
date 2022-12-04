
#include "WindWeather.h"

#include <vector>

#include "IEntity.h"
#include "IWeather.h"
#include "IZoneWeather.h"
void WindWeather::execute(IEntity* parent, IReaction* reaction, double dt,
                          std::vector<IEntity*> scheduler) {
  if (is_inside(parent)) reaction->react_wind(parent, dt, scheduler, windSpeed);
  this->parent->execute(parent, reaction, dt, scheduler);
}
WindWeather::WindWeather(IWeather* parent_, Vector3 windSpeed_, double xCircle_,
                         double yCircle_, double radius_) {
  parent = parent_;
  windSpeed = windSpeed_;
  circle(xCircle_, yCircle_, radius_);
}
WindWeather::WindWeather(IWeather* parent_, Vector3 windSpeed_, double xminRec_,
                         double yminRec_, double xmaxRec_, double ymaxRec_) {
  parent = parent_;
  windSpeed = windSpeed_;
  rect(xminRec_, yminRec_, xmaxRec_, ymaxRec_);
}