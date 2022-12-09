#ifndef IZONE_WEATHER
#define IZONE_WEATHER
#include <vector>

#include "IEntity.h"
#include "IWeather.h"
#include "IZoneWeather.h"
/**
* @brief class that holds the IZoneweather inherits from iweather and ientity.
**/
class IZoneWeather : public IWeather, public IEntity {
  // TBD: Has a radius and stuff
 public:
  bool IsInside(IEntity* parent);  // if the object is affected by the weather

   /**
   * @brief Destructor for IZoneWeather class.
   * 
   * @return none.
   **/
  ~IZoneWeather() override = default;


  /**
   * @brief get position
   * @return Vector3 type position
   **/
  virtual Vector3 GetPosition() const { return pos; }

   /**
   * @brief get direction
   * @return Vector3 type direciton
   **/
  virtual Vector3 GetDirection() const { return direction; }
   /**
   * @brief get destination
   * @return Vector3 type destination
   **/
  virtual Vector3 GetDestination() const { return Vector3(0, 0, 0); }

  /**
   * @brief get details 
   * @return JsonObject type details
   **/
  virtual JsonObject GetDetails() const { return details; };
  /**
   * @brief get speed
   * @return float type of speed
   **/
  virtual float GetSpeed() const { return speed; };
   /**
   * @brief check whether it is available
   * @return true if is available and false if not
   **/
  virtual bool GetAvailability() const { return false; }
   /**
   * @brief The strategy of robot
   *
   * @return return the name of strategy that is used 
   */
  virtual std::string GetStrategyName() { return ""; }
   /**
   * @brief set availability 
   * @param choice - bool type of choice parameter
   **/
  virtual void SetAvailability(bool choice) {}
  /**
   * @brief if availablity of drone is true, then call getNearestEntity function
   * @param dt - delta time
   * @param scheduler - IEntity type vector obj
   **/
  virtual void Update(double dt, std::vector<IEntity*> scheduler);
   /**
   * @brief set graph 
   * @param graph - IGraph type obj
   **/
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