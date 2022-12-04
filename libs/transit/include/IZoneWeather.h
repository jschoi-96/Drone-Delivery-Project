#ifndef IZONE_WEATHER
#define IZONE_WEATHER
#include <vector>

#include "IEntity.h"
#include "IWeather.h"
#include "IZoneWeather.h"
class IZoneWeather : public IWeather {
  // TBD: Has a radius and stuff
 public:
  void circle(double xCircle_, double yCircle_, double radius_);

  void rect(double xminRec_, double yminRec_, double xmaxRec_, double ymaxRec_);
  void update_real(double dt, std::vector<IEntity*> scheduler);
  void update(double dt, std::vector<IEntity*> scheduler);
  bool is_inside(IEntity* parent);  // if the object is affected by the weather

 protected:
  IWeather* parent;
  double radius;
  double xCircle;
  double yCircle;

  double xminRec;
  double yminRec;
  double xmaxRec;
  double ymaxRec;
  bool isCircle = false;
};
#endif