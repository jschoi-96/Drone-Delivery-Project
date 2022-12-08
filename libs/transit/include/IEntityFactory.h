#ifndef I_ENTITY_FACTORY_H_
#define I_ENTITY_FACTORY_H_

#include "util/json.h"

#include "IEntity.h"
#include "IEntityFactory.h"
#include "Drone.h"

/**
*@brief Factory method for IEntity class
**/
class IEntityFactory {
  public:
    /**
     * @brief Destructor for IEntityFactory class.
     * 
     * @return none.
     **/
    virtual ~IEntityFactory() {}

    /**
     * @brief Creates entity
     * @param entity - JsonObject type obj
     * @return none.
     **/
    virtual IEntity* CreateEntity(JsonObject& entity) = 0;
};

#endif