#ifndef REINFORCED_REACTION_H
#define REINFORCED_REACTION_H
#include "IReaction.h"
#include "math/Vector3.h"
#include "IEntity.h"

#include <vector>
class ReinforcedReaction : IReaction {
    void react_wind(IEntity* parent, double& dt, std::vector<IEntity*>& scheduler, Vector3 wind) {
        // changes the color first, and then...
        parent->SetPosition(parent->GetPosition() + wind);
    }
    void react_rain(IEntity* parent, double& dt, std::vector<IEntity*>& scheduler) {
        // changes the color first, and then...
        dt *= 0.75; // resistant to rain
    }
    void react_emp(IEntity* parent, double& dt, std::vector<IEntity*>& scheduler) {
        // changes the color first, and then...
        // immune to EMP
    }
};
#endif
