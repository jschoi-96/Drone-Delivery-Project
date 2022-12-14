#ifndef LIBS_TRANSIT_INCLUDE_CELEBRATIONDECORATOR_H_
#define LIBS_TRANSIT_INCLUDE_CELEBRATIONDECORATOR_H_

#include <vector>

#include "IStrategy.h"

/**
 *@brief Decorator method to implement other feature. Inherits from IStrategy.
 **/
class CelebrationDecorator : public IStrategy {
  /**
   *@brief Constructore for CelebrationDecorator
   *
   *@param strategy_ IStrategy type obj
   **/
 public:
  CelebrationDecorator(IStrategy *strategy_) {
    strategy = strategy_;
    time = 0;
  }

  /**
   * @brief Used for moving drone/robot pairs towards their destination
   *
   * @param entity entity to move.
   * @param dt amount of time that the entity will be moving.
   * @return none.
   **/
  void Move(IEntity *entity, double dt);

  /**
   * @brief Checks if the decorator has been completed
   *
   * @return true if completed, if not, return false.
   **/
  bool IsCompleted();

 protected:
  /**
   * Curent Movement strategy of the entity being moved.
   **/
  IStrategy *strategy;
  /**
   * Amount of time elapsed during the celebration so far.
   **/
  float time;
};  // close class

#endif  // LIBS_TRANSIT_INCLUDE_CELEBRATIONDECORATOR_H_
