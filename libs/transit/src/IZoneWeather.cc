
#include "IZoneWeather.h"

#include <vector>

#include "IEntity.h"
#include "IWeather.h"

void IZoneWeather::circle(double xCircle_, double yCircle_, double radius_) {
  xCircle = xCircle_;
  yCircle = yCircle_;
  radius = radius_;
  isCircle = true;
}

void IZoneWeather::rect(double xminRec_, double yminRec_, double xmaxRec_,
                        double ymaxRec_) {
  xminRec = xminRec_;
  yminRec = yminRec_;
  xmaxRec = xmaxRec_;
  ymaxRec = ymaxRec_;
  isCircle = false;
}
void IZoneWeather::update_real(double dt, std::vector<IEntity*> scheduler) {
  // TBD: Updates pos and whatever
}
void IZoneWeather::update(double dt, std::vector<IEntity*> scheduler) {
  update_real(dt, scheduler);
  parent->update(dt, scheduler);
}
bool IZoneWeather::is_inside(IEntity* parent) {
  Vector3 pos = parent->GetPosition();
  pos.z = 0;  // nullify z value because weather zones are 2d

  if (this->isCircle) {             // if circle
    pos.x = pos.x - this->xCircle;  // position - center of circle
    pos.y = pos.y - this->yCircle;

    float dis = pos.Magnitude();
    if (dis < this->radius) {
      return true;
    }
  } else {
    if (pos.x >= this->xminRec && pos.x <= this->xmaxRec &&
        pos.y >= this->yminRec && pos.y <= this->ymaxRec) {
      return true;
    }
  }
}  // if the object is affected by the weather