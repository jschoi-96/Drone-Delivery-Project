#ifndef RAIN_FACTORY_H
#define RAIN_FACTORY_H
#include <vector>

#include "IEntity.h"
#include "IEntityFactory.h"
#include "RainWeather.h"

class RainFactory : public IEntityFactory {
 public:
  virtual ~RainFactory() {}
  IEntity* CreateEntity(JsonObject& entity);
};
#endif