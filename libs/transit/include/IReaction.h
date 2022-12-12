#ifndef LIBS_TRANSIT_INCLUDE_IREACTION_H_
#define LIBS_TRANSIT_INCLUDE_IREACTION_H_
#include <vector>

#include "IEntity.h"
#include "math/vector3.h"

/**
 *@brief A class built for IReaction
 **/
class IReaction {
 public:
  /**
   * @brief A deconstructor for IReaction
   **/
  virtual ~IReaction() {}

  /**
   * @brief A dictionary map that holds the color and hexcodes.
   **/
  std::map<std::string, std::string> colors = {
      {"white", "#ffffff"},  {"red", "#ff0000"},    {"yellow", "#ffff00"},
      {"blue", "#0000ff"},   {"orange", "#ffa500"}, {"green", "#00ff00"},
      {"purple", "#a020f0"}, {"brown", "#964b00"},  {"black", "#000000"}};

  /**
   * @brief executes the reaction happening to the drone with wind
   *
   * @param parent which is the Ientity
   * @param reaction current reaction
   * @param dt delta time
   * @param scheduler vector that holds the ientities.
   * @param wind holds a vector3
   *
   * @return none.
   **/
  virtual void react_wind(IEntity* parent, double* dt,
                          std::vector<IEntity*>* scheduler, Vector3 wind) = 0;

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
  virtual void react_rain(IEntity* parent, double* dt,
                          std::vector<IEntity*>* scheduler) = 0;

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
  virtual void react_emp(IEntity* parent, double* dt,
                         std::vector<IEntity*>* scheduler) = 0;
};
#endif  // LIBS_TRANSIT_INCLUDE_IREACTION_H_
