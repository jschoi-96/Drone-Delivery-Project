#ifndef LIBS_TRANSIT_INCLUDE_IZONEWEATHER_H_
#define LIBS_TRANSIT_INCLUDE_IZONEWEATHER_H_
#include <vector>

#include "IEntity.h"
#include "IWeather.h"
#include "IZoneWeather.h"
/**
 * @brief class that holds the IZoneweather. Responsible for setting/moving/maintaining weather boundaries. inherits from IWeather and IEntity.
 **/
class IZoneWeather : public IWeather, public IEntity {
  // TBD: Has a radius and stuff
 public:
   /**
   * @brief Checks to see if the drone is inside a weather zone.
   * @param parent drone to check if within weather bounds.
   * @return boolean - true if drone is inside weather bounds, false otherwise.
   **/
  bool IsInside(IEntity* parent);  // if the object is affected by the weather

  /**
   * @brief Destructor for IZoneWeather class.
   *
   * @return none.
   **/
  ~IZoneWeather() override = default;

  /**
   * @brief getter for the position of the weather zone.
   * @return Vector3 representing the weather zone's position
   **/
  virtual Vector3 GetPosition() const { return pos; }

    /**
   * @brief getter for the direction of the weather zone.
   * @return Vector3 representing the weather zone's direction.
   **/
  virtual Vector3 GetDirection() const { return direction; }

  /**
   * @brief getter for the destination of the weather zone.
   * @return Vector3 representing the weather zone's destination.
   **/
  virtual Vector3 GetDestination() const { return Vector3(0, 0, 0); }

  /**
   * @brief getter for the JSON object of the weather entity.
   * @return JsonObject for the weather entity.
   **/
  virtual JsonObject GetDetails() const { return details; }

  /**
   * @brief getter for the speed of the weather zone.
   * @return float representing the weather zone's destination.
   **/
  virtual float GetSpeed() const { return speed; }
  /**
   * @brief check whether weather is available (pun intended)
   * @return true if is available and false if not (always false in the case of weather entities)
   **/
  virtual bool GetAvailability() const { return false; }

  /**
   * @brief Getter for movement strategy of the weather
   *
   * @return return the name of strategy that is used (Nothing for weather entities)
   */
  virtual std::string GetStrategyName() { return ""; }

  /**
   * @brief setter availability
   * @param choice - bool type - choice parameter
   **/
  virtual void SetAvailability(bool choice) {}

  /**
   * @brief updates the position/affects of the weather zone over time
   * @param dt - delta time
   * @param scheduler - Vector of all entities in the simulation.
   **/
  virtual void Update(double dt, std::vector<IEntity*> scheduler);

  /**
   * @brief seter for the graph of the weather zone.
   * @param graph - IGraph object to set as the graph.
   **/
  virtual void SetGraph(const IGraph* graph) { this->graph = graph; }

 protected:
  /**
  * JSON object representing the weather zone in the simulation.
  **/
  JsonObject details;
  /**
  * IWeather object representing the type of weather for this weather zone.
  **/
  IWeather* parent;

  /**
   * Vector3 representing the weather zone's position.
   **/
  Vector3 pos;
  /**
   * Vector3 representing the weather zone's direction.
   **/
  Vector3 direction;
  /**
   * Vector3 representing the weather zone's width. Used only for square shaped zones.
   **/
  Vector3 width;  // for squares
  /**
   * Vector3 representing the weather zone's width. Used only for circle shaped zones.
   **/
  float radius;   // for circles
  /**
   * float representing the weather zone's speed.
   **/
  float speed = 0;
  /**
   * boolean determining if the zone is a circle. If true, zone is a circle. Otherwise, the zone is square shaped.
   **/
  bool isCircle = false;
};
#endif  // LIBS_TRANSIT_INCLUDE_IZONEWEATHER_H_
