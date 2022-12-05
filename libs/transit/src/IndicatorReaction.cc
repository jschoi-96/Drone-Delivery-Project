#include "IndicatorReaction.h"

#include <vector>

#include "IEntity.h"
#include "IReaction.h"

void IndicatorReaction::react_wind(IEntity* parent, double& dt,
                                   std::vector<IEntity*>& scheduler,
                                   Vector3 wind) {
  printf("An entity is in the wind!\n");
  std::string color = parent->GetDetails()["color"];
  if (color == colors["red"]) {  // case where rain goes into wind zone
    parent->GetDetails()["color"] = colors["orange"];
  } else if (color == colors["blue"]) {  // case where emp goes
                                         // into wind zone
    parent->GetDetails()["color"] = colors["green"];
  } else if (color == colors["purple"]) {  // case where emp +
                                           // rain into wind zone
    parent->GetDetails()["color"] = colors["brown"];
  } else if (color == colors["white"]) {  // case where nothing
                                          // goes into wind zone
    parent->GetDetails()["color"] = colors["yellow"];
  }
}
void IndicatorReaction::react_rain(IEntity* parent, double& dt,
                                   std::vector<IEntity*>& scheduler) {
  printf("An entity is in the rain!\n");
  std::string color = parent->GetDetails()["color"];
  if (color == colors["yellow"]) {  // case where wind goes into rain zone
    parent->GetDetails()["color"] = colors["orange"];
  } else if (color == colors["blue"]) {  // case where emp goes
                                         // into rain zone
    parent->GetDetails()["color"] = colors["purple"];
  } else if (color == colors["green"]) {  // case where emp + wnd
                                          // goes into rain zone
    parent->GetDetails()["color"] = colors["brown"];
  } else if (color == colors["white"]) {  // case where nothing
                                          // goes into rain zone
    parent->GetDetails()["color"] = colors["red"];
  }
}
void IndicatorReaction::react_emp(IEntity* parent, double& dt,
                                  std::vector<IEntity*>& scheduler) {
  printf("An entity is in the EMP blast!\n");
  std::string color = parent->GetDetails()["color"];
  if (color == colors["yellow"]) {  // case where wind geos into emp zone
    parent->GetDetails()["color"] = colors["green"];
  } else if (color == colors["red"]) {  // case where rain goes
                                        // into emp zone
    parent->GetDetails()["color"] = colors["purple"];
  } else if (color == colors["orange"]) {  // case where rain + wind goes
                                           // into emp zone.
    parent->GetDetails()["color"] = colors["brown"];
  } else if (color == colors["white"]) {  // care where nothing
                                          // goes into emp zone
    parent->GetDetails()["color"] = colors["blue"];
  }
}