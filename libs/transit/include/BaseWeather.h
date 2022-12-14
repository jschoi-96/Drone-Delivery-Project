#ifndef LIBS_TRANSIT_INCLUDE_BASEWEATHER_H_
#define LIBS_TRANSIT_INCLUDE_BASEWEATHER_H_
#include <vector>

#include "IEntity.h"
#include "IReaction.h"
#include "IWeather.h"
/**
 * @brief This class inherits from the IWeather and is responsible for setting
 *  base weather. Inherits from IWeather.
 **/
class BaseWeather : public IWeather {
 public:
  /**
   * @brief Destructor for baseWeather class.
   *
   * @return none.
   **/
  ~BaseWeather() override = default;

  /**
   * @brief executes the reaction happening to the drone with base weather.
   *
   * @param parent This is the drone being affected by Baseweather.
   * @param reaction current weather reaction affecting the drone.
   * @param dt delta time.
   * @param scheduler vector that holds the ientities.
   *
   * @return none.
   **/
  void Execute(IEntity* parent, IReaction* reaction, double dt,
               std::vector<IEntity*> scheduler);

  /**
   * @brief Checks to see if the drone is inside a weather pattern.
   * @param parent drone to check if it is within the bounds of a weather pattern.
   * @return returns true if drone is inside a weather zone, and false otherwise.
   **/
  bool IsInside(IEntity* parent) { return true; }

  /**
   * @brief getter for instance of base weather.
   *
   * @return returns an Iweather* object.
   **/
  static IWeather* GetInstance();

  /**
   * @brief setter for a new instance of a Weather object.
   * @param new_instance The new Iweather* object.
   * @return none.
   **/
  static void SetInstance(IWeather* new_instance) { instance = new_instance; }

 private:
  // there is ONLY ONE WEATHER IN THE WORLDDDDDD
  /**
   * @brief constructor for baseweather
   *
   * @return none.
   **/
  BaseWeather() {}

  /**
   * instance of an IWeather* object.
   **/
  static IWeather* instance;
};
#endif  // LIBS_TRANSIT_INCLUDE_BASEWEATHER_H_

