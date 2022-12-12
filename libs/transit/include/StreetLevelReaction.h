#ifndef  LIBS_TRANSIT_INCLUDE_STREETLEVELREACTION_H_
#define  LIBS_TRANSIT_INCLUDE_STREETLEVELREACTION_H_
#include <vector>

#include "IEntity.h"
#include "IReaction.h"
/**
 *@brief A class built for streetlevelReaction
 **/
class StreetLevelReaction : public IReaction {
 public:
  /**
   *  @brief A constructor for streetlevelreaction
   **/
  StreetLevelReaction() {}
  /**
   * @brief A deconstructor for streetlevelReaction
   **/
  ~StreetLevelReaction() override = default;
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
  void react_wind(IEntity* parent, const double& dt,
  const std::vector<IEntity*>& scheduler,
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
  void react_rain(IEntity* parent, const double& dt,
                  const std::vector<IEntity*>& scheduler);

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
  void react_emp(IEntity* parent, const double& dt,
  const std::vector<IEntity*>& scheduler);
};
#endif  //  LIBS_TRANSIT_INCLUDE_STREETLEVELREACTION_H_

