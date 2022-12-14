#ifndef LIBS_TRANSIT_INCLUDE_SPINDECORATOR_H_
#define LIBS_TRANSIT_INCLUDE_SPINDECORATOR_H_

#include <vector>

#include "CelebrationDecorator.h"
#include "IStrategy.h"

/**
 *@brief Decorator class for the spin celebration. Inherits from CelebrationDecorator.
 **/
class SpinDecorator : public CelebrationDecorator {
 public:
  /**
   *@brief Constructor for SpinDecorator
   *
   *@param strategy_ IStrategy object. The spinning entities current movement strategy.
   **/
  SpinDecorator(IStrategy* strategy_) : CelebrationDecorator(strategy_) {}

  /**
   * @brief Checks if the decorator (spin) has been completed
   *
   * @return boolean. true if completed. if not, returns false.
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
