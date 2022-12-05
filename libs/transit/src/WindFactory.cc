#include "WindFactory.h"

#include "RegularReaction.h"
#include "WeatherReactDecorator.h"

IEntity* WindFactory::CreateEntity(JsonObject& entity) {
  std::string type = entity["type"];
  if (type.compare("wind") == 0) {
    std::cout << "Wind weather Created" << std::endl;
    return new WindWeather(entity);
  }
  return nullptr;
}
