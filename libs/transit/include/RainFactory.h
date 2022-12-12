#ifndef LIBS_TRANSIT_INCLUDE_RAINFACTORY_H_
#define LIBS_TRANSIT_INCLUDE_RAINFACTORY_H_
#include <vector>

#include "IEntity.h"
#include "IEntityFactory.h"
#include "RainWeather.h"
/**
 *@brief A class built using the factory design pattern but for rain weather.
 **/
class RainFactory : public IEntityFactory {
 public:
  /**
   * @brief A deconstructor for rain factory
   * @return nothing
   **/
  virtual ~RainFactory() {}
  /**
   * @brief Creates the rain weather entity.
   * @param entity jsonobj&
   * @return Ientity*
   **/
  IEntity* CreateEntity(JsonObject& entity);
};
#endif  // LIBS_TRANSIT_INCLUDE_RAINFACTORY_H_
