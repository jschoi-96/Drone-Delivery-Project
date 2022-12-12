#ifndef LIBS_TRANSIT_INCLUDE_EMPFACTORY_H_
#define LIBS_TRANSIT_INCLUDE_EMPFACTORY_H_
#include <vector>

#include "EmpWeather.h"
#include "IEntity.h"
#include "IEntityFactory.h"
/**
 *@brief A class built using the factory design pattern but for emp weather.
 **/
class EmpFactory : public IEntityFactory {
 public:
  /**
   * @brief A deconstructor for emp factory
   * @return nothing
   **/
  virtual ~EmpFactory() {}

  /**
   * @brief Creates the emp weather entity.
   * @param entity jsonobj&
   * @return Ientity*
   **/
  IEntity* CreateEntity(const JsonObject& entity);
};
#endif  // LIBS_TRANSIT_INCLUDE_EMPFACTORY_H_
