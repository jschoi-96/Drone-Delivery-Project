#ifndef STREET_LEVEL_REACTION_H
#define STREET_LEVEL_REACTION_H
#include <vector>

#include "IEntity.h"
#include "IReaction.h"

class StreetLevelReaction : public IReaction {
 public:
  StreetLevelReaction() {}
  ~StreetLevelReaction() override = default;
  void react_wind(IEntity* parent, double& dt, std::vector<IEntity*>& scheduler,
                  Vector3 wind);
  void react_rain(IEntity* parent, double& dt,
                  std::vector<IEntity*>& scheduler);
  void react_emp(IEntity* parent, double& dt, std::vector<IEntity*>& scheduler);
};
#endif
