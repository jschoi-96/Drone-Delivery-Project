#ifndef LIBS_TRANSIT_INCLUDE_IENTITY_H_
#define LIBS_TRANSIT_INCLUDE_IENTITY_H_

#include <vector>

#include "graph.h"
#include "math/vector3.h"
#include "util/json.h"

using namespace routing;

//--------------------  Controller Interface ----------------------------

/// Abstract controller class used in the Transit Service.  Uses the Model View
/// Controller Pattern

/**
 *@brief A class built to for moving/updating entities in the simulation.
 **/
class IEntity {
 public:
  /**
   * @brief Constructor for IEntity class.
   *
   * @return none.
   **/
  IEntity() {
    static int currentId = 0;
    id = currentId;
    currentId++;
  }

  /**
   * @brief Destructor for IEntity class.
   *
   * @return none.
   **/
  virtual ~IEntity() {}

  /**
   * @brief getter for the unique id that entity has.
   * @return int that uniquely identifies the entity.
   **/
  virtual int GetId() const { return id; }

  /**
   * @brief getter for the entities position
   * @return Vector3 representing the entities position
   **/
  virtual Vector3 GetPosition() const = 0;

  /**
   * @brief getter for the entities direction
   * @return Vector3 representing the entities direciton
   **/
  virtual Vector3 GetDirection() const = 0;

  /**
   * @brief getter for the entities destination
   * @return Vector3 representing the entities destination
   **/
  virtual Vector3 GetDestination() const = 0;

  /**
   * @brief getter for the JSON object for the entity.
   * @return JsonObject for the entity
   **/
  virtual JsonObject GetDetails() const = 0;

  /**
   * @brief getter for the entitie's speed
   * @return float representing the speed of the entity.
   **/
  virtual float GetSpeed() const = 0;

  /**
   * @brief check whether the entity is available
   * @return boolean that is true if entity is available and false if not
   **/
  virtual bool GetAvailability() const {}

  /**
   * @brief The strategy for robot movement
   *
   * @return return the name of strategy that is used (Always None for robots)
   */
  virtual std::string GetStrategyName() { return "None"; }

  /**
   * @brief Getter for the color field of the entity
   *
   * @return string color field of entity
   */
  virtual std::string GetColor() const { return color; }

  /**
   * @brief Sets the color field of the entity
   *
   * @param color_ the new color for the entity
   * 
   * @return none.
   */
  virtual void SetColor(std::string color_) { color = color_; }

  /**
   * @brief set availability of the entity
   * @param choice - boolean representing entities availability.
   * @return none.
   **/
  virtual void SetAvailability(bool choice) {}

  /**
   * @brief if availablity of drone is true, then calls getNearestEntity function and updates entity variables accordingly.
   * @param dt - double - delta time
   * @param scheduler - Vector holding all entities in the simulation.
   * @return none.
   **/
  virtual void Update(double dt, std::vector<IEntity*> scheduler) {}

  /**
   * @brief setter for the entities graph
   * @param graph - IGraph object to set as entities graph
   * @return none.
   **/
  virtual void SetGraph(const IGraph* graph) { this->graph = graph; }

  /**
   * @brief set the position of the entity
   * @param pos_ - Vector3 to set as entities new position.
   * @return none.
   **/
  virtual void SetPosition(Vector3 pos_) {}

  /**
   * @brief set the direction of the entity
   * @param dir_ - Vector3 to set as entities new direction.
   **/
  virtual void SetDirection(Vector3 dir_) {}

  /**
   * @brief set the destination of the entity
   * @param des_ - Vector3 representing the entities new destination.
   **/
  virtual void SetDestination(Vector3 des_) {}

  /**
   * @brief set the movement strategy of the entity.
   *
   * @param strategyName_ - string type, name of strategy
   */
  virtual void SetStrategyName(std::string strategyName_) {}

  /**  /**
   * @brief executes the reaction happening to the drone with rainweather.
   *
   * @param parent which is the Ientity
   * @param reaction current reaction
   * @param dt delta time
   * @param scheduler vector that holds the ientities.
   *
   * @return none.
   **/
  virtual void Rotate(double angle) {}

  /**
   * @brief rotate drone by using height and formula
   * @param height double - height to rotate entity by
   */
  virtual void Jump(double height) {}

/**
 * color field of the entity.
 **/ 
  std::string color = "None";  // None means default color

 protected:
  /**
  * unique identifier for the entity. 
  **/
  int id;
  /**
  * graph for the entity.
  **/ 
  const IGraph* graph;
};

#endif  // LIBS_TRANSIT_INCLUDE_IENTITY_H_
