#ifndef WIND_FACTORY_H
#define WIND_FACTORY_H
#include <vector>

#include "IEntity.h"
#include "IEntityFactory.h"
#include "WindWeather.h"

class WindFactory : public IEntityFactory {
 public:
  virtual ~WindFactory() {}
  IEntity* CreateEntity(JsonObject& entity);
};
#endif