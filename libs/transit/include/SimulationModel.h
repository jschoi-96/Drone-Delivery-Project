#ifndef LIBS_TRANSIT_INCLUDE_SIMULATIONMODEL_H_
#define LIBS_TRANSIT_INCLUDE_SIMULATIONMODEL_H_

#include "CompositeFactory.h"
#include "IController.h"
#include "IEntity.h"
#include "graph.h"
using namespace routing;

//--------------------  Model ----------------------------

/// Simulation Model handling the transit simulation.  The model can communicate
/// with the controller.

/**
 *@brief A class built to Simulate Model
 **/
class SimulationModel {
 public:
  /**
   * @brief SimulationModel constructor
   * @param controller - Icontroller type obj
   */
  SimulationModel(IController* controller);

  /**
   * @brief set graph
   * @param graph - IGraph type obj
   */
  void SetGraph(const IGraph* graph) { this->graph = graph; }

  /// Creates an simulation entity
  /**
   * @brief create type, name, and position for entity
   * @param entity - JsonObject type obj
   */
  void CreateEntity(const JsonObject& entity);

  /// Schedules a trip for an object in the scene
  /**
   * @brief Schedule a trip for an object
   * @param details - JsonObject type obj
   */
  void ScheduleTrip(const JsonObject& details);

  /// Updates the simulation
  /**
   * @brief change entities and call updateEntity function
   * @param dt - delta time
   */
  void Update(double dt);

  // Adds a new entity type
  /**
   * @brief adding a new entity type by using factory mehtod
   * @param factory - IEntityFactory type obj
   */
  void AddFactory(IEntityFactory* factory);

 protected:
  IController* controller;
  std::vector<IEntity*> entities;
  std::vector<IEntity*> scheduler;
  const IGraph* graph;
  CompositeFactory* compFactory;
};

#endif  // LIBS_TRANSIT_INCLUDE_SIMULATIONMODEL_H_
