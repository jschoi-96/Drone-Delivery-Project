#include "IZoneWeather.h"

#include <vector>

#include "IEntity.h"
#include "IWeather.h"

void IZoneWeather::Update(double dt, std::vector<IEntity*> scheduler) {
  pos = pos + direction * dt;  // changes the pos
}
bool IZoneWeather::IsInside(IEntity* parent) {
  Vector3 parent_pos = parent->GetPosition();

  if (this->isCircle) {  // if circle
    parent_pos.y = 0;    // nullify y value because weather zones are 2d
    parent_pos.x = parent_pos.x - pos.x;  // position - center of circle
    parent_pos.z = parent_pos.z - pos.z;
    return parent_pos.Magnitude() <= radius;
  } else {
    return parent_pos.x >= pos.x && parent_pos.x <= pos.x + width.x &&
           parent_pos.z >= pos.z && parent_pos.z <= pos.z + width.z;
  }
}
