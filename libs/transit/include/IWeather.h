#ifndef IWEATHER_H
#define IWEATHER_H
#include <vector>

#include "IEntity.h"
#include "IReaction.h"
/**
*@brief A class built for IWeather
**/
class IWeather {
 public:
 /**
*@brief desconstuctor for IWeather
**/
  virtual ~IWeather() {}
  /**
     * @brief executes the reaction happening to the drone with base weather.
     * 
     * @param parent which is the Ientity
     * @param reaction current reaction
     * @param dt delta time
     * @param scheduler vector that holds the ientities.
     * 
     * @return none.
 **/
  virtual void Execute(IEntity* parent, IReaction* reaction, double dt,
                       std::vector<IEntity*> scheduler) = 0;
/**
     * @brief Checks to see if the drone is inside the base weather.
     * @param parent Ientity
     * @return true.
 **/
  virtual bool IsInside(
      IEntity* parent) = 0;  // if the object is affected by the weather
};
#endif