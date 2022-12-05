#ifndef EMP_FACTORY_H
#define EMP_FACTORY_H
#include <vector>

#include "EmpWeather.h"
#include "IEntity.h"
#include "IEntityFactory.h"

class EmpFactory : public IEntityFactory {
 public:
  virtual ~EmpFactory() {}
  IEntity* CreateEntity(JsonObject& entity);
};
#endif