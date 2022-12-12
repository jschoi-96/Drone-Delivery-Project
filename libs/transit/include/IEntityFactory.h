#ifndef LIBS_TRANSIT_INCLUDE_IENTITYFACTORY_H_
#define LIBS_TRANSIT_INCLUDE_IENTITYFACTORY_H_

#include "Drone.h"
#include "IEntity.h"
#include "IEntityFactory.h"
#include "util/json.h"

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
  virtual IEntity* CreateEntity(const JsonObject& entity) = 0;
};

#endif  // LIBS_TRANSIT_INCLUDE_IENTITYFACTORY_H_
