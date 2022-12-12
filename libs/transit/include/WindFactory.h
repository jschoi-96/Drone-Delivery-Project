#ifndef LIBS_TRANSIT_INCLUDE_WINDFACTORY_H_
#define LIBS_TRANSIT_INCLUDE_WINDFACTORY_H_
#include <vector>

#include "IEntity.h"
#include "IEntityFactory.h"
#include "WindWeather.h"
/**
 *@brief A class built using the factory design pattern but for wind weather.
 **/
class WindFactory : public IEntityFactory {
 public:
  /**
   * @brief A deconstructor for wind factory
   * @return nothing
   **/
  virtual ~WindFactory() {}
  /**
   * @brief Creates the wind weather entity.
   * @param entity jsonobj&
   * @return Ientity*
   **/
  IEntity* CreateEntity(JsonObject& entity);
};
#endif  // LIBS_TRANSIT_INCLUDE_WINDFACTORY_H_
