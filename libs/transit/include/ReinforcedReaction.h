#ifndef LIBS_TRANSIT_INCLUDE_REINFORCEDREACTION_H_
#define LIBS_TRANSIT_INCLUDE_REINFORCEDREACTION_H_
#include <vector>

#include "IEntity.h"
#include "IReaction.h"
/**
 *@brief A class built for ReinforcedReactions. Inherits from IReaction.
 **/
class ReinforcedReaction : public IReaction {
 public:
  /**
   * @brief A constructor for Reinforcedreaction
   * @return none.
   **/
  ReinforcedReaction() {}

  /**
   * @brief A deconstructor for reinforcedReaction
   * @return none.
   **/
  ~ReinforcedReaction() override = default;


  /**
   * @brief executes the reaction that is supposed to happen when a drone is affected by wind.
   *
   * @param parent This is the drone being affected by wind.
   * @param dt delta time
   * @param scheduler vector that holds the entities.
   * @param wind Vector3 holding the details of the wind velocity.
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
#endif  //  LIBS_TRANSIT_INCLUDE_REINFORCEDREACTION_H_
