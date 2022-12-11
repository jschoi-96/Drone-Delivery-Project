#include "DroneFactory.h"

#include "RegularReaction.h"
#include "WeatherReactDecorator.h"

IEntity* DroneFactory::CreateEntity(JsonObject& entity) {
  std::string type = entity["type"];
  if (type.compare("drone") == 0) {
    std::cout << "Drone Created" << std::endl;
    return new WeatherReactDecorator(
        new Drone(entity),
        new RegularReaction());  // for now, drones have a regular reaction.
  }
  return nullptr;
}
