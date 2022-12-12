#ifndef LIBS_TRANSIT_INCLUDE_WINDWEATHER_H_
#define LIBS_TRANSIT_INCLUDE_WINDWEATHER_H_
#include <vector>

#include "IEntity.h"
#include "IWeather.h"
#include "IZoneWeather.h"
#include "math/vector3.h"
/**
 *@brief A class built for wind weather
 **/
class WindWeather : public IZoneWeather {
 private:
  Vector3 windSpeed;

 public:
  /**
   * @brief constructor for rainWeather.
   * @param obj jsonObject&
   * @return nothing
   **/
  WindWeather(const JsonObject& obj);
  /**
   * @brief deconstructor for windWeather.
   *
   * @return nothing
   **/
  ~WindWeather() override = default;
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
#endif  // LIBS_TRANSIT_INCLUDE_WINDWEATHER_H_
