#ifndef IZONE_WEATHER
#define IZONE_WEATHER
#include <vector>

#include "IEntity.h"
#include "IWeather.h"
#include "IZoneWeather.h"
class IZoneWeather : public IWeather, public IEntity {
  // TBD: Has a radius and stuff
 public:
  bool IsInside(IEntity* parent);  // if the object is affected by the weather
  ~IZoneWeather() override = default;

  virtual Vector3 GetPosition() const { return pos; }
  virtual Vector3 GetDirection() const { return direction; }
  virtual Vector3 GetDestination() const { return Vector3(0, 0, 0); }
  virtual JsonObject GetDetails() const { return details; };
  virtual float GetSpeed() const { return speed; };
  virtual bool GetAvailability() const { return false; }
  virtual std::string GetStrategyName() { return ""; }
  virtual void SetAvailability(bool choice) {}
  virtual void Update(double dt, std::vector<IEntity*> scheduler);
  virtual void SetGraph(const IGraph* graph) { this->graph = graph; }

 protected:
  JsonObject details;
  IWeather* parent;

  Vector3 pos;
  Vector3 direction;  // what direction the weather moves in

  Vector3 width;  // for squares
  float radius;   // for circles
  float speed = 0;
  bool isCircle = false;
};
#endif