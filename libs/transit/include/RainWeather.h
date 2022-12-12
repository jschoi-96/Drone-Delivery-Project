#ifndef LIBS_TRANSIT_INCLUDE_RAINWEATHER_H_
#define LIBS_TRANSIT_INCLUDE_RAINWEATHER_H_
#include <vector>

#include "IEntity.h"
#include "IWeather.h"
#include "IZoneWeather.h"
/**
 *@brief A class built for rain weather
 **/
class RainWeather : public IZoneWeather {
 public:
  /**
   * @brief deconstructor for rainWeather.
   *
   * @return nothing
   **/
  ~RainWeather() override = default;
  /**
   * @brief constructor for rainWeather.
   * @param obj jsonObject&
   * @return nothing
   **/
  RainWeather(JsonObject& obj);
  /**
   * @brief executes the reaction happening to the drone with rainweather.
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
#endif  // LIBS_TRANSIT_INCLUDE_RAINWEATHER_H_
