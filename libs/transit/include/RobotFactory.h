#ifndef LIBS_TRANSIT_INCLUDE_ROBOTFACTORY_H_
#define LIBS_TRANSIT_INCLUDE_ROBOTFACTORY_H_

#include <vector>

#include "IEntity.h"
#include "IEntityFactory.h"
#include "Robot.h"

/**
 *@brief Factory method for Robot class. Inherits from IEntityFactory.
 **/
class RobotFactory : public IEntityFactory {
 public:
  /**
   * @brief Creates a new drone entity.
   * @param entity - JsonObject to represent the drone in the simulation.
   * @return none.
   **/
  IEntity* CreateEntity(const JsonObject& entity);
};

#endif  // LIBS_TRANSIT_INCLUDE_ROBOTFACTORY_H_
