#include "EmpFactory.h"

#include "RegularReaction.h"
#include "WeatherReactDecorator.h"

IEntity* EmpFactory::CreateEntity(JsonObject& entity) {
  std::string type = entity["type"];
  if (type.compare("emp") == 0) {
    std::cout << "Emp weather Created" << std::endl;
    return new EmpWeather(entity);
  }
  return nullptr;
}
