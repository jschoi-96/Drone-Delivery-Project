#include "RainFactory.h"

#include "RegularReaction.h"
#include "WeatherReactDecorator.h"

IEntity* RainFactory::CreateEntity(JsonObject& entity) {
  std::string type = entity["type"];
  if (type.compare("rain") == 0) {
    std::cout << "Rain weather Created" << std::endl;
    return new RainWeather(entity);
  }
  return nullptr;
}
