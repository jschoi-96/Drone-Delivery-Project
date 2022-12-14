#ifndef LIBS_TRANSIT_INCLUDE_RAINFACTORY_H_
#define LIBS_TRANSIT_INCLUDE_RAINFACTORY_H_
#include <vector>

#include "IEntity.h"
#include "IEntityFactory.h"
#include "RainWeather.h"
/**
 *@brief A class built using the factory design pattern but for rain weather. Inherits from IEntityFactory.
 **/
class RainFactory : public IEntityFactory {
 public:
  /**
   * @brief A destructor for rain factory
   * @return nothing
   **/
  virtual ~RainFactory() {}

  /**
   * @brief Attempts to create a RainWeather IEntity. Returns the entity if it was created, otherwise returns null.
   * @param entity JSON object the RainWeather object should be created from.
   * @return the new EmpWeather entity if the JSON parameter corresponds to a RainWeather object. otherwise returns a nullpointer.
   **/
  IEntity* CreateEntity(const JsonObject& entity);
};
#endif  // LIBS_TRANSIT_INCLUDE_RAINFACTORY_H_
