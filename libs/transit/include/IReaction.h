#ifndef IREACTION_H
#define IREACTION_H
#include <vector>

#include "IEntity.h"
#include "math/vector3.h"

/**
*@brief A class built for IReaction
**/
class IReaction {
 protected: 
  int counter = 0;
 public:

 /**
* @brief A deconstructor for IReaction
**/
  virtual ~IReaction(){}

/**
* @brief A dictionary map that holds the color and hexcodes.
**/
  std::map<std::string, std::string> colors = {
      {"white", "0xffffff"},  {"red", "0xff0000"},    {"yellow", "0xffff00"},
      {"blue", "0x0000ff"},   {"orange", "0xffa500"}, {"green", "0x00ff00"},
      {"purple", "0xa020f0"}, {"brown", "0x964b00"},  {"black", "0x000000"}};

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
  virtual void react_wind(IEntity* parent, double& dt,
                          std::vector<IEntity*>& scheduler, Vector3 wind) = 0;

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
  virtual void react_rain(IEntity* parent, double& dt,
                          std::vector<IEntity*>& scheduler) = 0;

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
  virtual void react_emp(IEntity* parent, double& dt,
                         std::vector<IEntity*>& scheduler) = 0;
};
#endif
