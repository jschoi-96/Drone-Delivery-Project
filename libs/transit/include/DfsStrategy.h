#ifndef LIBS_TRANSIT_INCLUDE_DFSSTRATEGY_H_
#define LIBS_TRANSIT_INCLUDE_DFSSTRATEGY_H_

/**
 * include
 */
#include <vector>

#include "IEntity.h"
#include "IStrategy.h"
#include "math/vector3.h"
/**
 * @brief Implementation of Depth-first-search strategy for entity movement.
 *Inherits from IStrategy.
 **/
class DfsStrategy : public IStrategy {
 public:
  /**
   * @brief Constructor for DfsStrategy class.
   *
   * @param position_ current position of the entity to move.
   * @param destination_ destination of entity to move.
   * @param graph_ pointer to graph to be used to generate beeline pathing.
   * @return none.
   **/
  DfsStrategy(Vector3 position, Vector3 destination, const IGraph* graph);
  /**
   * @brief Destructor for DfsStrategy class.
   *
   * @return none.
   **/
  ~DfsStrategy();
  /**
   * @brief Used for moving drone/robot pairs towards their destination using
   *the dfs movement strategy.
   *
   * @param entity entity to move.
   * @param dt amount of time that the entity will be moving.
   * @return none.
   **/
  void Move(IEntity* entity, double dt);
  /**
   * @brief Checks if the route has been completed.
   *
   * @return true if completed, if not, return false.
   **/
  bool IsCompleted();

 private:
  std::vector<std::vector<float>> path;
  int currentIndex;
  int maxIndex;
};      // end class
#endif  // LIBS_TRANSIT_INCLUDE_DFSSTRATEGY_H_
