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
 * @brief Simulation Model handling the transit simulation.  The model can communicate with the controller.
 **/
class SimulationModel {
 public:
  /**
   * @brief SimulationModel constructor
   * @param controller - Icontroller object handling running the simulation.
   */
  SimulationModel(IController* controller);

  /**
   * @brief setter for the graph variable.
   * @param graph - IGraph type object to set as the graph.
   */
  void SetGraph(const IGraph* graph) { this->graph = graph; }

  /// Creates an simulation entity
  /**
   * @brief create type, name, and position for a new entity
   * @param entity - JsonObject that wil  /**
   * @brief executes the reaction happening to the drone with rainweather.
   *
   * @param parent which is the Ientity
   * @param reaction current reaction
   * @param dt delta time
   * @param scheduler vector that holds the ientities.
   *
   * @return none.
   **/
  void CreateEntity(const JsonObject& entity);

  /// Schedules a trip for an object in the scene
  /**
   * @brief Schedule a trip for an entity
   * @param details - JsonObject of the entity involved in the trip.
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
   * @param factory - IEntityFactory to add as a new factory for the new entity type.
   */
  void AddFactory(IEntityFactory* factory);

 protected:
 /**
  * IController overseeing the simlulation.
  **/
  IController* controller;
  /**
   * vector holding all entities in the simulation.
   **/
  std::vector<IEntity*> entities;
  /**
   * vector holding all entities in the simulation. Used for scheduling trips instead of just an "entity ledger".
   **/
  std::vector<IEntity*> scheduler;
  /**
   * Current SimulationModel graph.
   **/
  const IGraph* graph;
  /**
   * CompositeFactory that is responsible for the details of adding new entity types to the simulation.
   **/
  CompositeFactory* compFactory;
};

#endif  // LIBS_TRANSIT_INCLUDE_SIMULATIONMODEL_H_
