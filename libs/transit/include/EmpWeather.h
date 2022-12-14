#ifndef LIBS_TRANSIT_INCLUDE_EMPWEATHER_H_
#define LIBS_TRANSIT_INCLUDE_EMPWEATHER_H_
#include <vector>

#include "IEntity.h"
#include "IWeather.h"
#include "IZoneWeather.h"
/**
 *@brief A class built for emp weather. Inherits from IZoneWeather.
 **/
class EmpWeather : public IZoneWeather {
 public:
  /**
   * @brief constructor for empWeather.
   * @param obj JSON object to be used for creating an EmpWeather entity.
   * @return nothing
   **/
  EmpWeather(const JsonObject& obj);

  /**
   * @brief deconstructor for empWeather.
   *
   * @return nothing
   **/
  ~EmpWeather() override = default;

  /**
   * @brief executes the reaction happening to the drone with Empweather.
   *
   * @param parent The drone being affected by the EMP.
   * @param reaction current weather reaction
   * @param dt delta time
   * @param scheduler vector that holds the entities.
   *
   * @return none.
   **/
  void Execute(IEntity* parent, IReaction* reaction, double dt,
               std::vector<IEntity*> scheduler);
};
#endif  // LIBS_TRANSIT_INCLUDE_EMPWEATHER_H_
