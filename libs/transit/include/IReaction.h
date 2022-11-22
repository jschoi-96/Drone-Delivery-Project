#ifndef IREACTION_H
#define IREACTION_H
#include "IEntity.h"
#include <vector>
#include "math/vector3.h"

class IReaction {
    virtual void react_wind(IEntity* parent, double& dt, std::vector<IEntity*>& scheduler, Vector3 wind) const = 0;
    virtual void react_rain(IEntity* parent, double& dt, std::vector<IEntity*>& scheduler) const = 0;
    virtual void react_emp(IEntity* parent, double& dt, std::vector<IEntity*>& scheduler) const = 0;
};
#endif