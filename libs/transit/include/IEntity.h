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
 *@brief A class built to see interface
 **/
class IEntity {
 public:
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
   * @brief get ID from specific obj
   * @return int type of id
   **/
  virtual int GetId() const { return id; }

  /**
   * @brief get position
   * @return Vector3 type position
   **/
  virtual Vector3 GetPosition() const = 0;

  /**
   * @brief get direction
   * @return Vector3 type direciton
   **/
  virtual Vector3 GetDirection() const = 0;

  /**
   * @brief get destination
   * @return Vector3 type destination
   **/
  virtual Vector3 GetDestination() const = 0;

  /**
   * @brief get details
   * @return JsonObject type details
   **/
  virtual JsonObject GetDetails() const = 0;

  /**
   * @brief get speed
   * @return float type of speed
   **/
  virtual float GetSpeed() const = 0;

  /**
   * @brief check whether it is available
   * @return true if is available and false if not
   **/
  virtual bool GetAvailability() const {}

  /**
   * @brief The strategy of robot
   *
   * @return return the name of strategy that is used
   */
  virtual std::string GetStrategyName() {}

  /**
   * @brief Getter for the color field of the drone
   *
   * @return color field of drone
   */
  virtual std::string GetColor() const { return color; }
  /**
   * @brief Sets the color field of the drone
   *
   * @param color_ the new color for the drone
   */
  virtual void SetColor(std::string color_) { color = color_; }

  /**
   * @brief set availability
   * @param choice - bool type of choice parameter
   **/
  virtual void SetAvailability(bool choice) {}

  /**
   * @brief if availablity of drone is true, then call getNearestEntity function
   * @param dt - delta time
   * @param scheduler - IEntity type vector obj
   **/
  virtual void Update(double dt, std::vector<IEntity*> scheduler) {}

  /**
   * @brief set graph
   * @param graph - IGraph type obj
   **/
  virtual void SetGraph(const IGraph* graph) { this->graph = graph; }

  /**
   * @brief set the position of object
   * @param pos_ - Vector3 obj
   **/
  virtual void SetPosition(Vector3 pos_) {}

  /**
   * @brief set the direction of object
   * @param dir_ - Vector3 obj
   **/
  virtual void SetDirection(Vector3 dir_) {}

  /**
   * @brief set the destination of obj
   * @param des_ - Vector3 obj
   **/
  virtual void SetDestination(Vector3 des_) {}

  /**
   * @brief set the strategy
   *
   * @param strategyName_ - string type, name of strategy
   */
  virtual void SetStrategyName(std::string strategyName_) {}

  /**
   * @brief rotate drone by using angle and formula
   * @param angle - angle of drone
   */
  virtual void Rotate(double angle) {}

  /**
   * @brief rotate drone by using height and formula
   * @param height - height of drone
   */
  virtual void Jump(double height) {}

  std::string color = "None";  // None means default color

 protected:
  int id;
  const IGraph* graph;
};

#endif  // LIBS_TRANSIT_INCLUDE_IENTITY_H_

