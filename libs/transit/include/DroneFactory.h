#ifndef DRONE_FACTORY_H_
#define DRONE_FACTORY_H_

#include "IEntity.h"
#include "IEntityFactory.h"
#include "Drone.h"

#include <vector>

/**
*@brief Factory method for Drone class
**/
class DroneFactory : public IEntityFactory {
  public:
    /**
     * @brief Destructor for IEntityFactory class.
     * 
     * @return none.
     **/
    virtual ~DroneFactory() {}
  
    /**
     * @brief Creates entity
     * @param entity - JsonObject type obj
     * @return none.
     **/
    IEntity* CreateEntity(JsonObject& entity);
};

#endif