#ifndef ROBOT_FACTORY_H_
#define ROBOT_FACTORY_H_

#include "IEntity.h"
#include "IEntityFactory.h"
#include "Robot.h"

#include <vector>

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

#endif