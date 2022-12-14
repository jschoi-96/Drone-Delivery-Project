#ifndef LIBS_TRANSIT_INCLUDE_WINDWEATHER_H_
#define LIBS_TRANSIT_INCLUDE_WINDWEATHER_H_
#include <vector>

#include "IEntity.h"
#include "IWeather.h"
#include "IZoneWeather.h"
#include "math/vector3.h"
/**
 *@brief A class built for wind weather. Inherits from IZoneWeather.
 **/
class WindWeather : public IZoneWeather {
 public:
  /**
   * @brief constructor for WindWeather.
   * @param obj JSON object to be used for creating a WindWeather entity.
   * @return nothing
   **/
  WindWeather(const JsonObject& obj);

  /**
   * @brief destructor for windWeather.
   *
   * @return nothing
   **/
  ~WindWeather() override = default;

  /**
   * @brief executes the reaction happening to the drone with Empweather.
   *
   * @param parent The drone being affected by wind.
   * @param reaction current weather reaction
   * @param dt delta time
   * @param scheduler vector that holds the entities.
   *
   * @return none.
   **/
  void Execute(IEntity* parent, IReaction* reaction, double dt,
               std::vector<IEntity*> scheduler);
  private:
  /**
   * Vector3 representing the velocity of the wind.
   **/
  Vector3 windSpeed; 
};
#endif  // LIBS_TRANSIT_INCLUDE_WINDWEATHER_H_
