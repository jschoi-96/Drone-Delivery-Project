#ifndef REGULAR_REACTION_H
#define REGULAR_REACTION_H
#include "IReaction.h"
#include "math/Vector3.h"
#include "IEntity.h"

#include <vector>

/* yellow = wind
   red = rain
   blue = emp
   orange = wind + rain
   green = wind + emp
   purple = rain + emp
   brown = all 3
   */
class RegularReaction : IReaction {
    void react_wind(IEntity* parent, double& dt, std::vector<IEntity*>& scheduler, Vector3 wind) {
        if(parent->GetDetails()["color"] == parent->Dronecolors["red"]) {  //case where rain goes into wind zone
            parent->GetDetails()["color"] = parent->Dronecolors["orange"];
        }
        if(parent->GetDetails()["color"] == parent->Dronecolors["blue"]) {  // case where emp goes into wind zone
            parent->GetDetails()["color"] = parent->Dronecolors["green"];
        }
        if(parent->GetDetails()["color"] == parent->Dronecolors["purple"]) {  // case where emp + rain into wind zone
            parent->GetDetails()["color"] = parent->Dronecolors["brown"];
        }
        // changes the color first, and then...
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
        dt *= 0.5;
    }
    void react_emp(IEntity* parent, double& dt, std::vector<IEntity*>& scheduler) {
        if(parent->GetDetails()["color"] == parent->Dronecolors["yellow"]) {  //case where wind geos into emp zone
            parent->GetDetails()["color"] = parent->Dronecolors["green"];
        }
        if(parent->GetDetails()["color"] == parent->Dronecolors["red"]) {  //case where rain goes into emp zone
            parent->GetDetails()["color"] = parent->Dronecolors["purple"];
        }
        if(parent->GetDetails()["color"] == parent->Dronecolors["orange"]) { //case where rain + wind goes into emp zone.
            parent->GetDetails()["color"] = parent->Dronecolors["brown"];
        }
        // changes the color first, and then...
        dt = 0;
    }
}