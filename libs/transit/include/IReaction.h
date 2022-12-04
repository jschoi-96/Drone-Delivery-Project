#ifndef IREACTION_H
#define IREACTION_H
#include <vector>

#include "IEntity.h"
#include "math/vector3.h"

class IReaction {
 public:
  std::map<std::string, std::string> colors = {
      {"white", "0xffffff"},  {"red", "0xff0000"},    {"yellow", "0xffff00"},
      {"blue", "0x0000ff"},   {"orange", "0xffa500"}, {"green", "0x00ff00"},
      {"purple", "0xa020f0"}, {"brown", "0x964b00"},  {"black", "0x000000"}};
  virtual void react_wind(IEntity* parent, double& dt,
                          std::vector<IEntity*>& scheduler,
                          Vector3 wind) const = 0;
  virtual void react_rain(IEntity* parent, double& dt,
                          std::vector<IEntity*>& scheduler) const = 0;
  virtual void react_emp(IEntity* parent, double& dt,
                         std::vector<IEntity*>& scheduler) const = 0;
};
#endif