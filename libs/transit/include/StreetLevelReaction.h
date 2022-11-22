#ifndef STREET_LEVEL_REACTION_H
#define STREET_LEVEL_REACTION_H
#include "IReaction.h"
#include "math/Vector3.h"
#include "IEntity.h"

#include <vector>
class StreetLevelReaction : IReaction {
    void react_wind(IEntity* parent, double& dt, std::vector<IEntity*>& scheduler, Vector3 wind) {
        // changes the color first, and then...
        // unaffected by wind, as the buildings protect it
    }
    void react_rain(IEntity* parent, double& dt, std::vector<IEntity*>& scheduler) {
        // changes the color first, and then...
        dt *= 0.5;
    }
    void react_emp(IEntity* parent, double& dt, std::vector<IEntity*>& scheduler) {
        // changes the color first, and then...
        dt = 0;
    }
};
#endif
