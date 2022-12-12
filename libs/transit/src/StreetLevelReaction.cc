#include "StreetLevelReaction.h"

#include <vector>

#include "IEntity.h"
#include "IReaction.h"

void StreetLevelReaction::react_wind(IEntity* parent, double* dt,
                                     std::vector<IEntity*>* scheduler,
                                     Vector3 wind) {
  std::string color = parent->GetColor();
  if (color == colors["red"]) {  // case where rain goes into wind zone
    std::string c = ("orange");
    parent->SetColor(c);
  } else if (color == colors["blue"]) {  // case where emp goes
                                         // into wind zone
    std::string c = ("green");
    parent->SetColor(c);
  } else if (color == colors["purple"]) {  // case where emp +
                                           // rain into wind zone
    std::string c = ("brown");
    parent->SetColor(c);
  } else if (color == colors["white"]) {  // case where nothing
                                          // goes into wind zone
    std::string c = ("yellow");
    parent->SetColor(c);
  }
}
void StreetLevelReaction::react_rain(IEntity* parent, double* dt,
                                     std::vector<IEntity*>* scheduler) {
  std::string color = parent->GetColor();
  if (color == colors["yellow"]) {  // case where wind goes into rain zone
    std::string c = ("orange");
    parent->SetColor(c);
  } else if (color == colors["blue"]) {  // case where emp goes
                                         // into rain zone
    std::string c = ("purple");
    parent->SetColor(c);
  } else if (color == colors["green"]) {  // case where emp + wnd
                                          // goes into rain zone
    std::string c = ("brown");
    parent->SetColor(c);
  } else if (color == colors["white"]) {  // case where nothing
                                          // goes into rain zone
    std::string c = ("red");
    parent->SetColor(c);
  }
  *dt *= 0.5;
}
void StreetLevelReaction::react_emp(IEntity* parent, double* dt,
                                    std::vector<IEntity*>* scheduler) {
  std::string color = parent->GetColor();
  if (color == colors["yellow"]) {  // case where wind geos into emp zone
    std::string c = ("green");
    parent->SetColor(c);
  } else if (color == colors["red"]) {  // case where rain goes
                                        // into emp zone
    std::string c = ("purple");
    parent->SetColor(c);
  } else if (color == colors["orange"]) {  // case where rain + wind goes
                                           // into emp zone.
    std::string c = ("brown");
    parent->SetColor(c);
  } else if (color == colors["white"]) {  // care where nothing
                                          // goes into emp zone
    std::string c = ("blue");
    parent->SetColor(c);
  }
  // changes the color first, and then...
  *dt = 0;
}
