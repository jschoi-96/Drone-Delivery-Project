#ifndef LIBS_TRANSIT_INCLUDE_JUMPDECORATOR_H_
#define LIBS_TRANSIT_INCLUDE_JUMPDECORATOR_H_

#include <vector>

#include "CelebrationDecorator.h"
#include "IStrategy.h"

/**
 *@brief Decorator class for the jump celebration. Inherits from CelebrationDecorator.
 **/
class JumpDecorator : public CelebrationDecorator {
 public:
  /**
   *@brief Constructor for JumpDecorator
   *
   *@param strategy_ IStrategy object. The jumping entities current movement strategy.
   **/
  JumpDecorator(IStrategy* strategy_) : CelebrationDecorator(strategy_) {}

  /**
   * @brief Checks if the decorator (jump) has been completed
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

#endif  // LIBS_TRANSIT_INCLUDE_JUMPDECORATOR_H_
