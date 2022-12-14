#ifndef LIBS_TRANSIT_INCLUDE_STREETLEVELREACTION_H_
#define LIBS_TRANSIT_INCLUDE_STREETLEVELREACTION_H_
#include <vector>

#include "IEntity.h"
#include "IReaction.h"
/**
 *@brief A class built for streetlevelReaction. Inherits from IReaction.
 **/
class StreetLevelReaction : public IReaction {
 public:
  /**
   *  @brief A constructor for streetlevelreaction
   **/
  StreetLevelReaction() {}

  /**
   * @brief A destructor for streetlevelReaction
   **/
  ~StreetLevelReaction() override = default;

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
#endif  //  LIBS_TRANSIT_INCLUDE_STREETLEVELREACTION_H_
