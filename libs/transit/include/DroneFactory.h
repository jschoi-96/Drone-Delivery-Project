#ifndef LIBS_TRANSIT_INCLUDE_DRONEFACTORY_H_
#define LIBS_TRANSIT_INCLUDE_DRONEFACTORY_H_

#include <vector>

#include "Drone.h"
#include "IEntity.h"
#include "IEntityFactory.h"

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

#endif  // LIBS_TRANSIT_INCLUDE_DRONEFACTORY_H_
