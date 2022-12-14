#ifndef LIBS_TRANSIT_INCLUDE_REGULARREACTION_H_
#define LIBS_TRANSIT_INCLUDE_REGULARREACTION_H_
#include <vector>

#include "IEntity.h"
#include "IReaction.h"

/* yellow = wind
   red = rain
   blue = emp
   orange = wind + rain
   green = wind + emp
   purple = rain + emp
   brown = all 3
   */
/**
 *@brief A class built for RegularReactions. Inherits from IReaction.
 **/
class RegularReaction : public IReaction {
 public:
  /**
   * @brief A constructor for Regularreaction
   * @return none.
   **/
  RegularReaction() {}

  /**
   * @brief A destructor for regularReaction
   * @return none.
   **/
  ~RegularReaction() override = default;

  /**
   * @brief executes the reaction that is supposed to happen when a drone is affected by wind.
   *
   * @param parent This is the drone being affected by wind.
   * @param dt delta time
   * @param scheduler vector that holds the entities.
   * @param wind holds a vector3 with details of the wind strength.
   *
   * @return none.
   **/
  void react_wind(IEntity* parent, double* dt, std::vector<IEntity*>* scheduler,
                  Vector3 wind);

  /**
   * @brief executes the reaction that is supposed to happen when a drone is affected by rain.
   *
   * @param parent This is the drone being affected by rain.
   * @param dt delta time
   * @param scheduler vector that holds the entities.
   *
   * @return none.
   **/
  void react_rain(IEntity* parent, double* dt,
                  std::vector<IEntity*>* scheduler);

  /**
   * @brief executes the reaction that is supposed to happen when a drone is affected by an EMP.
   *
   * @param parent This is the drone being affected by an EMP.
   * @param dt delta time
   * @param scheduler vector that holds the entities.
   *
   * @return none.
   **/
  void react_emp(IEntity* parent, double* dt, std::vector<IEntity*>* scheduler);
};
#endif  // LIBS_TRANSIT_INCLUDE_REGULARREACTION_H_
