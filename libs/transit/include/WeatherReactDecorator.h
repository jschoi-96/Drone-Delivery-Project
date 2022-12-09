#ifndef CELEBRATION_DECORATOR_H_
#define CELEBRATION_DECORATOR_H_

#include <vector>

#include "IEntity.h"
#include "IReaction.h"
#include "graph.h"
#include "math/vector3.h"
#include "util/json.h"

/**
*@brief A class built using weatherreactDecorator
**/
class WeatherReactDecorator : public IEntity {
 public:
 /**
   * @brief constructor for weatherReactDecorator class
   * @param parent_ Ientity*
   * @param reaction_ Ireaction*
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
   * @brief get speed
   * @return float type of speed
   **/
  float GetSpeed() const;

  // Gets the drone position
   /**
   * @brief get position
   * @return Vector3 type position
   **/
  Vector3 GetPosition() const;
  /**
   * @brief get direction
   * @return Vector3 type direciton
   **/
  Vector3 GetDirection() const;
  /**
   * @brief get destination
   * @return Vector3 type destination
   **/
  Vector3 GetDestination() const;
  /**
   * @brief get details 
   * @return JsonObject type details
   **/
  JsonObject GetDetails() const;
   /**
   * @brief check whether it is available
   * @return true if is available and false if not
   **/
  bool GetAvailability() const;
   /**
   * @brief The strategy of robot
   *
   * @return return the name of strategy that is used 
   */
  std::string GetStrategyName();
/** 
   * @brief set availability 
   * @param choice - bool type of choice parameter
   **/
  void SetAvailability(bool choice);
   /**
   * @brief if availablity of drone is true, then call getNearestEntity function
   * @param dt - delta time
   * @param scheduler - IEntity type vector obj
   **/
  // reacts to the weather, then calls the parent's update function
  void Update(double dt, std::vector<IEntity*> scheduler);
  /**
   * @brief set the position of object
   * @param pos_ - Vector3 obj
   **/ 
  void SetPosition(Vector3 pos_);
  /**
   * @brief set the direction of object
   * @param dir_ - Vector3 obj
   **/
  // Sets the drone's direction
  void SetDirection(Vector3 dir_);
   /**
   * @brief set the destination of obj
   * @param des_ - Vector3 obj
   **/ 
  void SetDestination(Vector3 des_);
   /**
   * @brief rotate drone by using angle and formula
   * @param angle - angle of drone
   */     
  // Rotates a drone
  void Rotate(double angle);
   /**
   * @brief rotate drone by using height and formula
   * @param height - height of drone
   */  
  void Jump(double height);
  /**
   * @brief set graph 
   * @param graph - IGraph type obj
   **/
  void SetGraph(const IGraph* graph);

  /** 
   * @brief Getter for the color field of the drone
   * 
   * @return color field of drone
   */
  std::string GetColor() const { return parent->GetColor(); }
  /**
   * @brief Sets the color field of the drone
   * 
   * @param color_ the new color for the drone 
   */
  virtual void SetColor(std::string color_) {
    parent->SetColor(color_);
  }


 protected:
  IEntity* parent;
  IReaction* reaction;
};  // close class

#endif  // CELEBRATION_DECORATOR_H_