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
 *@brief A class built for RegularReaction
 **/
class RegularReaction : public IReaction {
 public:
  /**
   * @brief A constructor for Regularreaction
   **/
  RegularReaction() {}
  /**
   * @brief A deconstructor for regularReaction
   **/
  ~RegularReaction() override = default;
  /**
   * @brief executes the reaction happening to the drone with wind
   *
   * @param parent which is the Ientity
   * @param reaction current reaction
   * @param dt delta time
   * @param scheduler vector that holds the ientities.
   * @param wind holds a vector3
   * @return none.
   **/
  void react_wind(IEntity* parent, double* dt, std::vector<IEntity*>* scheduler,
                  Vector3 wind);
  /**
   * @brief executes the reaction happening to the drone with rain
   *
   * @param parent which is the Ientity
   * @param reaction current reaction
   * @param dt delta time
   * @param scheduler vector that holds the ientities.
   *
   * @return none.
   **/
  void react_rain(IEntity* parent, double* dt,
                  std::vector<IEntity*>* scheduler);
  /**
   * @brief executes the reaction happening to the drone with emp
   *
   * @param parent which is the Ientity
   * @param reaction current reaction
   * @param dt delta time
   * @param scheduler vector that holds the ientities.
   *
   * @return none.
   **/
  void react_emp(IEntity* parent, double* dt, std::vector<IEntity*>* scheduler);
};
#endif  // LIBS_TRANSIT_INCLUDE_REGULARREACTION_H_
