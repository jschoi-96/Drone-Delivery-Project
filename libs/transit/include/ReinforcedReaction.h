#ifndef REINFORCED_REACTION_H
#define REINFORCED_REACTION_H
#include <vector>

#include "IEntity.h"
#include "IReaction.h"
class ReinforcedReaction : public IReaction {
  void react_wind(IEntity* parent, double& dt, std::vector<IEntity*>& scheduler,
                  Vector3 wind);
  void react_rain(IEntity* parent, double& dt,
                  std::vector<IEntity*>& scheduler);
  void react_emp(IEntity* parent, double& dt, std::vector<IEntity*>& scheduler);
};
#endif
