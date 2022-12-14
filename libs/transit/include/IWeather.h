#ifndef LIBS_TRANSIT_INCLUDE_IWEATHER_H_
#define LIBS_TRANSIT_INCLUDE_IWEATHER_H_
#include <vector>

#include "IEntity.h"
#include "IReaction.h"
/**
 *@brief Interface built for different weather patterns/reactions.
 **/
class IWeather {
 public:
  /**
   *@brief desconstuctor for IWeather
   @return none.
   **/
  virtual ~IWeather() {}

  /**
   * @brief executes the reaction happening to the drone for current weather pattern(s).
   *
   * @param parent which is the drone being affected by the weather.
   * @param reaction current weather reaction
   * @param dt delta time
   * @param scheduler vector that holds the Ientities.
   *
   * @return none.
   **/
  virtual void Execute(IEntity* parent, IReaction* reaction, double dt,
                       std::vector<IEntity*> scheduler) = 0;

  /**
   * @brief Checks to see if the drone is inside a weather zone.
   * @param parent drone to check if within weather bounds.
   * @return boolean - true if drone is inside weather bounds, false otherwise.
   **/
  virtual bool IsInside(
      IEntity* parent) = 0;  // if the object is affected by the weather
};
#endif  // LIBS_TRANSIT_INCLUDE_IWEATHER_H_
