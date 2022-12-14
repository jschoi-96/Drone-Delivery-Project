#ifndef LIBS_TRANSIT_INCLUDE_WEATHERREACTDECORATOR_H_
#define LIBS_TRANSIT_INCLUDE_WEATHERREACTDECORATOR_H_

#include <vector>

#include "IEntity.h"
#include "IReaction.h"
#include "graph.h"
#include "math/vector3.h"
#include "util/json.h"

/**
 *@brief A class built using weatherreactDecorator. Inherits from IEntity.
 **/
class WeatherReactDecorator : public IEntity {
 public:
  /**
   * @brief constructor for weatherReactDecorator class
   * @param parent_ Ientity* being affected by this weather
   * @param reaction_ Ireaction* - reaction of entity being affected by this weather.
   * @return none.
   **/
  WeatherReactDecorator(IEntity* parent_, IReaction* reaction_);

  /**
   * @brief Destructor for weatherReactDecorator class.
   *
   * @return none.
   **/
  ~WeatherReactDecorator() override = default;

  /**
   * @brief getter for speed of the weather.
   * @return float representing the speed of the weather.
   **/
  float GetSpeed() const;

  /**
   * @brief getter for the position of the weather.
   *
   * @return Vector3 representing the weather entities position.
   **/
  Vector3 GetPosition() const;

  /**
   * @brief getter for the direction of the weather.
   *
   * @return Vector3 representing the weather entities direction.
   **/
  Vector3 GetDirection() const;

  /**
   * @brief getter for the destination of the weather.
   *
   * @return Vector3 representing the weather entities destination.
   **/
  Vector3 GetDestination() const;

  /**
   * @brief getter for the JSON object for the weather entity.
   * @return JsonObject representing the weather entity.
   **/
  JsonObject GetDetails() const;

  /**
   * @brief check whether weather is available (pun intended)
   * @return true if is available and false if not
   **/
  bool GetAvailability() const;

  /**
   * @brief Getter for the movement strategy of the weather
   *
   * @return string - the name of the movement strategy that is used
   */
  std::string GetStrategyName();

  /**
   * @brief setter for weathers availability
   * @param choice - bool - true if available, false if not available.
   * @return none.
   **/
  void SetAvailability(bool choice);

  /**
   * @brief has drones react to the weather, then calls the parent's update function
   * @param dt - delta time
   * @param scheduler - vector holding all entities. 
   * @return none.
   **/
  void Update(double dt, std::vector<IEntity*> scheduler);

  /**
   * @brief setter for the position of the weather
   * @param pos_ - Vector3 representing the position of the weather.
   * @return none.
   **/
  void SetPosition(Vector3 pos_);

  /**
   * @brief setter for the direction of the weather
   * @param dir_ - Vector3 representing the direction of the weather.
   * @return none.
   **/
  void SetDirection(Vector3 dir_);

  /**
   * @brief setter for the destination of the weather
   * @param dir_ - Vector3 representing the destination of the weather.
   * @return none.
   **/
  void SetDestination(Vector3 des_);

  /**
   * @brief rotate weather by using angle and formula
   * @param angle - angle to use while rotating the weather.
   * @return none.
   */
  void Rotate(double angle);

  /**
   * @brief Used for "jumping" the weather
   * @param height - double - height of weather
   * @return none.
   */
  void Jump(double height);

  /**
   * @brief setter for the graph field
   * @param graph - IGraph to set as graph field
   * @return none.
   **/
  void SetGraph(const IGraph* graph);

  /**
   * @brief Getter for the color field of the weather
   *
   * @return string - color field of weather
   */
  std::string GetColor() const { return parent->GetColor(); }

  /**
   * @brief Sets the color field of the weather
   *
   * @param color_ the new color for the weather
   */
  virtual void SetColor(std::string color_) { parent->SetColor(color_); }

 protected:
 /**
  * Drone being affected by the weather.
  **/
  IEntity* parent;
  /**
   * reaction of the drone being affected by the weather.
   **/
  IReaction* reaction;
};  // close class

#endif  // LIBS_TRANSIT_INCLUDE_WEATHERREACTDECORATOR_H_