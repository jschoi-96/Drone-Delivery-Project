#ifndef LIBS_TRANSIT_INCLUDE_ROBOTFACTORY_H_
#define LIBS_TRANSIT_INCLUDE_ROBOTFACTORY_H_

#include <vector>

#include "IEntity.h"
#include "IEntityFactory.h"
#include "Robot.h"

/**
 *@brief Factory method for Robot class
 **/
class RobotFactory : public IEntityFactory {
 public:
  /**
   * @brief Creates entity
   * @param entity - JsonObject type obj
   * @return none.
   **/
  IEntity* CreateEntity(JsonObject& entity);
};

#endif  // LIBS_TRANSIT_INCLUDE_ROBOTFACTORY_H_
