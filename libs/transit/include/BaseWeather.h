#ifndef BASE_WEATHER_H
#define BASE_WEATHER_H
#include <vector>

#include "IEntity.h"
#include "IReaction.h"
#include "IWeather.h"
/**
* @brief This class inherits from the IWeather and is responsible for setting base weather 
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
     * @param parent which is the Ientity
     * @param reaction current reaction
     * @param dt delta time
     * @param scheduler vector that holds the ientities.
     * 
     * @return none.
 **/
  void Execute(IEntity* parent, IReaction* reaction, double dt,
               std::vector<IEntity*> scheduler);
/**
     * @brief Checks to see if the drone is inside the base weather.
     * @param parent Ientity
     * @return true.
 **/
  bool IsInside(IEntity* parent) { return true; }
 /**
     * @brief getter for instance of base weather.
     * 
     * @return Iweather*
 **/
  static IWeather* GetInstance();
   /**
     * @brief setter for instance of baseWeather class.
     * @param new_instance Iweather*
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


  static IWeather* instance;
};
#endif
