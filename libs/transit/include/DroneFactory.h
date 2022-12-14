#ifndef LIBS_TRANSIT_INCLUDE_DRONEFACTORY_H_
#define LIBS_TRANSIT_INCLUDE_DRONEFACTORY_H_

#include <vector>

#include "Drone.h"
#include "IEntity.h"
#include "IEntityFactory.h"

/**
 *@brief Factory method for Drone class. Inherits from IEntityFactory.
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
   * @brief Creates a new drone entity.
   * @param entity - JsonObject to represent the drone in the simulation.
   * @return none.
   **/
  IEntity* CreateEntity(const JsonObject& entity);
};

#endif  // LIBS_TRANSIT_INCLUDE_DRONEFACTORY_H_
