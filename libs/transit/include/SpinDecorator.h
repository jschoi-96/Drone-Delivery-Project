#ifndef LIBS_TRANSIT_INCLUDE_SPINDECORATOR_H_
#define LIBS_TRANSIT_INCLUDE_SPINDECORATOR_H_

#include <vector>

#include "CelebrationDecorator.h"
#include "IStrategy.h"

/**
 *@brief Decorator method to spin object
 **/
class SpinDecorator : public CelebrationDecorator {
 public:
  /**
   *@brief Constructore for SpinDecorator
   *
   *@param strategy_ IStrategy type obj
   **/
  SpinDecorator(IStrategy* strategy_) : CelebrationDecorator(strategy_) {}

  /**
   * @brief Checks if the decorator has been completed
   *
   * @return true if completed, if not, return false.
   **/
  bool IsCompleted();

  /**
   * @brief Used for moving drone/robot pairs towards their destination
   *
   * @param entity entity to move.
   * @param dt amount of time that the entity will be moving.
   * @return none.
   **/
  void Move(IEntity* entity, double dt);
};  // close class

#endif  // LIBS_TRANSIT_INCLUDE_SPINDECORATOR_H_
