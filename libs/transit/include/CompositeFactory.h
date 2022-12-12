#ifndef LIBS_TRANSIT_INCLUDE_COMPOSITEFACTORY_H_
#define LIBS_TRANSIT_INCLUDE_COMPOSITEFACTORY_H_

#include "IEntityFactory.h"

/**
 *@brief Factory method for composite class
 **/
class CompositeFactory : public IEntityFactory {
 public:
  /**
   * @brief Creates Factory
   * @param entity - JsonObject type obj
   * @return none.
   **/
  IEntity* CreateEntity(JsonObject& entity);

  /**
   * @brief Adds Factory
   * @param factoryEntity - IEntityFactory type obj
   * @return none.
   **/
  void AddFactory(IEntityFactory* factoryEntity);

  /**
   * @brief Destructor for CompositeFactory class.
   *
   * @return none.
   **/
  virtual ~CompositeFactory();

 private:
  std::vector<IEntityFactory*> componentFactories;
};

#endif  // LIBS_TRANSIT_INCLUDE_COMPOSITEFACTORY_H_
