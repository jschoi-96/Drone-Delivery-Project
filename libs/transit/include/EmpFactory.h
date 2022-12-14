#ifndef LIBS_TRANSIT_INCLUDE_EMPFACTORY_H_
#define LIBS_TRANSIT_INCLUDE_EMPFACTORY_H_
#include <vector>

#include "EmpWeather.h"
#include "IEntity.h"
#include "IEntityFactory.h"
/**
 *@brief A class built using the factory design pattern but for emp weather. Inherits from IEntityFactory.
 **/
class EmpFactory : public IEntityFactory {
 public:
  /**
   * @brief A deconstructor for emp factory
   * @return nothing
   **/
  virtual ~EmpFactory() {}

  /**
   * @brief Attempts to create an EmpWeather IEntity. Returns the entity if it was created, otherwise returns null.
   * @param entity JSON object the EmpWeather object should be created from.
   * @return the new EmpWeather entity if the JSON parameter corresponds to an EmpWeather. otherwise returns a nullpointer.
   **/
  IEntity* CreateEntity(const JsonObject& entity);
};
#endif  // LIBS_TRANSIT_INCLUDE_EMPFACTORY_H_
