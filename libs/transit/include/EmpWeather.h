#ifndef EMP_WEATHER_H
#define EMP_WEATHER_H
#include <vector>

#include "IEntity.h"
#include "IWeather.h"
#include "IZoneWeather.h"
/**
*@brief A class built for emp weather
**/
class EmpWeather : public IZoneWeather {
 public:

/**
* @brief constructor for empWeather.
* @param obj jsonObject&
* @return nothing
**/
  EmpWeather(JsonObject& obj);

/**
* @brief deconstructor for empWeather.
* 
* @return nothing
**/
  ~EmpWeather() override = default;
/**
     * @brief executes the reaction happening to the drone with empweather.
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
};
#endif