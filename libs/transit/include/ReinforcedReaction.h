#ifndef REINFORCED_REACTION_H
#define REINFORCED_REACTION_H
#include "IReaction.h"
#include "math/Vector3.h"
#include "IEntity.h"

#include <vector>
class ReinforcedReaction : IReaction {
    void react_wind(IEntity* parent, double& dt, std::vector<IEntity*>& scheduler, Vector3 wind) {
        // changes the color first, and then...
        if(parent->GetDetails()["color"] == parent->Dronecolors["red"]) {  //case where rain goes into wind zone
            parent->GetDetails()["color"] = parent->Dronecolors["orange"];
        }
        if(parent->GetDetails()["color"] == parent->Dronecolors["blue"]) {  // case where emp goes into wind zone
            parent->GetDetails()["color"] = parent->Dronecolors["green"];
        }
        if(parent->GetDetails()["color"] == parent->Dronecolors["purple"]) {  // case where emp + rain into wind zone
            parent->GetDetails()["color"] = parent->Dronecolors["brown"];
        }
        parent->SetPosition(parent->GetPosition() + wind);
    }
    void react_rain(IEntity* parent, double& dt, std::vector<IEntity*>& scheduler) {
        // changes the color first, and then...
        if(parent->GetDetails()["color"] == parent->Dronecolors["yellow"]) { //case where wind goes into rain zone
            parent->GetDetails()["color"] = parent->Dronecolors["orange"];
        }
        if(parent->GetDetails()["color"] == parent->Dronecolors["blue"]) {  //case where emp goes into rain zone
            parent->GetDetails()["color"] = parent->Dronecolors["purple"];
        }
        if(parent->GetDetails()["color"] == parent->Dronecolors["green"]) { //case where emp + wnd goes into rain zone
            parent->GetDetails()["color"] = parent->Dronecolors["brown"];
        }
        dt *= 0.75; // resistant to rain
    }
    void react_emp(IEntity* parent, double& dt, std::vector<IEntity*>& scheduler) {
        // changes the color first, and then...
        // immune to EMP
        if(parent->GetDetails()["color"] == parent->Dronecolors["yellow"]) {  //case where wind geos into emp zone
            parent->GetDetails()["color"] = parent->Dronecolors["green"];
        }
        if(parent->GetDetails()["color"] == parent->Dronecolors["red"]) {  //case where rain goes into emp zone
            parent->GetDetails()["color"] = parent->Dronecolors["purple"];
        }
        if(parent->GetDetails()["color"] == parent->Dronecolors["orange"]) { //case where rain + wind goes into emp zone.
            parent->GetDetails()["color"] = parent->Dronecolors["brown"];
        }
    }
};
#endif
