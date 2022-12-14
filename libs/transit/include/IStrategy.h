#ifndef LIBS_TRANSIT_INCLUDE_ISTRATEGY_H_
#define LIBS_TRANSIT_INCLUDE_ISTRATEGY_H_

#include <vector>

#include "IEntity.h"
#include "graph.h"

using namespace routing;

/**
 *@brief A class built for Istrategy. Parent class for drone movement strategy classes.
 **/
class IStrategy {
 public:
  /**
   * @brief moves the entity based on strategy.
   * @param entity Ientity* to be moved using given strategy.
   * @param dt delta time double
   * @return nothing
   */
  virtual void Move(IEntity* entity, double dt) = 0;
  /**
   * @brief method to tell if stragety is completed.
   *
   * @return boolean. True if strategy completed, false otherwise.
   */
  virtual bool IsCompleted() = 0;

 protected:
  /**
   * IGraph object to be used in the simulation.
   **/
  const IGraph* graph;
};  // close class

#endif  // LIBS_TRANSIT_INCLUDE_ISTRATEGY_H_
