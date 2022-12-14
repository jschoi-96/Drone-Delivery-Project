#ifndef LIBS_TRANSIT_INCLUDE_IREACTION_H_
#define LIBS_TRANSIT_INCLUDE_IREACTION_H_
#include <vector>

#include "IEntity.h"
#include "math/vector3.h"

/**
 * @brief IReaction class. Responsible for the physical affects of different weather patterns on entities.
 **/
class IReaction {
 public:
  /**
   * @brief A destructor for the IReaction class.
   **/
  virtual ~IReaction() {}

  /**
   * @brief A dictionary map that holds colors and corresponding hexcodes.
   **/
  std::map<std::string, std::string> colors = {
      {"white", "#ffffff"},  {"red", "#ff0000"},    {"yellow", "#ffff00"},
      {"blue", "#0000ff"},   {"orange", "#ffa500"}, {"green", "#00ff00"},
      {"purple", "#a020f0"}, {"brown", "#964b00"},  {"black", "#000000"}};

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
  virtual void react_wind(IEntity* parent, double* dt,
                          std::vector<IEntity*>* scheduler, Vector3 wind) = 0;

  /**
   * @brief executes the reaction that is supposed to happen when a drone is affected by rain.
   *
   * @param parent This is the drone being affected by rain.
   * @param dt delta time
   * @param scheduler vector that holds the entities.
   *
   * @return none.
   **/
  virtual void react_rain(IEntity* parent, double* dt,
                          std::vector<IEntity*>* scheduler) = 0;

  /**
   * @brief executes the reaction that is supposed to happen when a drone is affected by an EMP.
   *
   * @param parent This is the drone being affected by an EMP.
   * @param dt delta time
   * @param scheduler vector that holds the entities.
   *
   * @return none.
   **/
  virtual void react_emp(IEntity* parent, double* dt,
                         std::vector<IEntity*>* scheduler) = 0;
};
#endif  // LIBS_TRANSIT_INCLUDE_IREACTION_H_
