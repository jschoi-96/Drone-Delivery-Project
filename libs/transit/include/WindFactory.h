#ifndef LIBS_TRANSIT_INCLUDE_WINDFACTORY_H_
#define LIBS_TRANSIT_INCLUDE_WINDFACTORY_H_
#include <vector>

#include "IEntity.h"
#include "IEntityFactory.h"
#include "WindWeather.h"
/**
 *@brief A class built using the factory design pattern but for wind weather. Inherits from IEntityFactory.
 **/
class WindFactory : public IEntityFactory {
 public:
  /**
   * @brief A destructor for wind factory
   * @return nothing
   **/
  virtual ~WindFactory() {}

  /**
   * @brief Attempts to create a WindWeather IEntity. Returns the entity if it was created, otherwise returns null.
   * @param entity JSON object the WindWeather object should be created from.
   * @return the new WindWeather entity if the JSON parameter corresponds to a WindWeather. otherwise returns a nullpointer.
   **/
  IEntity* CreateEntity(const JsonObject& entity);
};
#endif  // LIBS_TRANSIT_INCLUDE_WINDFACTORY_H_
