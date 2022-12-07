#ifndef INDICATOR_REACTION_H
#define INDICATOR_REACTION_H
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
class IndicatorReaction : public IReaction {
 public:
  IndicatorReaction() {}
  ~IndicatorReaction() override = default;
  void react_wind(IEntity* parent, double& dt, std::vector<IEntity*>& scheduler,
                  Vector3 wind);
  void react_rain(IEntity* parent, double& dt,
                  std::vector<IEntity*>& scheduler);
  void react_emp(IEntity* parent, double& dt, std::vector<IEntity*>& scheduler);
};
#endif