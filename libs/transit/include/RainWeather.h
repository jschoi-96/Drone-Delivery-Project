#ifndef LIBS_TRANSIT_INCLUDE_RAINWEATHER_H_
#define LIBS_TRANSIT_INCLUDE_RAINWEATHER_H_
#include <vector>

#include "IEntity.h"
#include "IWeather.h"
#include "IZoneWeather.h"
/**
 *@brief A class built for rain weather. Inherits from IZoneWeather.
 **/
class RainWeather : public IZoneWeather {
 public:
  /**
   * @brief destructor for rainWeather.
   *
   * @return nothing
   **/
  ~RainWeather() override = default;

  /**
   * @brief constructor for RainWeather.
   * @param obj JSON object to be used for creating a RainWeather entity.
   * @return nothing
   **/
  RainWeather(const JsonObject& obj);

  /**
   * @brief executes the reaction happening to the drone with Rainweather.
   *
   * @param parent The drone being affected by rain.
   * @param reaction current weather reaction
   * @param dt delta time
   * @param scheduler vector that holds the entities.
   *
   * @return none.
   **/
  void Execute(IEntity* parent, IReaction* reaction, double dt,
               std::vector<IEntity*> scheduler);
};
#endif  // LIBS_TRANSIT_INCLUDE_RAINWEATHER_H_
