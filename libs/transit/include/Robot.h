#ifndef LIBS_TRANSIT_INCLUDE_ROBOT_H_
#define LIBS_TRANSIT_INCLUDE_ROBOT_H_

#include <vector>

#include "IEntity.h"
#include "math/vector3.h"
#include "util/json.h"

/**
 *@brief A class built to manipulate movement of Robots. Inherits from IEntity.
 **/
class Robot : public IEntity {
 public:
  /**
   * @brief constructor for Robot class.
   * @param obj - JsonObject to represent the robot in the simulation.
   */
  Robot(const JsonObject& obj);

  /**
   * @brief Destructor for Robot class.
   *
   * @return none.
   **/
  ~Robot() override = default;

  /**
   * @brief Getter for the Position of Robot
   *
   * @return return a Vector3 representing the position of the robot
   */
  Vector3 GetPosition() const { return position; }

  /**
   * @brief Getter for the direction of robot
   *
   * @return return a Vector3 representing the direction of robot
   */
  Vector3 GetDirection() const { return direction; }

  /**
   * @brief Getter for the destination of robot
   *
   * @return return a Vector3 representing the destination of robot
   */
  Vector3 GetDestination() const { return destination; }

  /**
   * @brief The availability of the robot
   *
   * @return return true if it is available, if not return false
   */
  bool GetAvailability() const { return available; }

  /**
   * @brief get details from JsonObject corresponding to this robot.
   */
  JsonObject GetDetails() const override;

  /**
   * @brief Getter for the speed of robot
   *
   * @return return a float representing the speed of robot
   */
  float GetSpeed() const { return speed; }

  /**
   * @brief Getter for the movement strategy of robot
   *
   * @return return the name of strategy that is used (a string)
   */
  std::string GetStrategyName() { return strategyName; }

  /**
   * @brief set availability
   *
   * @param choice - bool type. True if available, false if not available.
   */
  void SetAvailability(bool choice);

  /**
   * @brief set the position of the robot.
   * @param pos_ - Vector3 representing the robot's new position.
   */
  void SetPosition(Vector3 pos_) { position = pos_; }

  /**
   * @brief set the direction of the robot.
   * @param dir_ - Vector3 representing the robot's new direction.
   */
  void SetDirection(Vector3 dir_) { direction = dir_; }

  /**
   * @brief set the destination of the robot.
   * @param des_ - Vector3 representing the new destination of the robot.
   */
  void SetDestination(Vector3 des_) { destination = des_; }

  /**
   * @brief set the strategy movement strategy of the robot.
   *
   * @param strategyName_ - string type, name of strategy
   */
  void SetStrategyName(std::string strategyName_) {
    strategyName = strategyName_;
  }

  /**
   * @brief rotate robot by using angle and formula
   * @param angle - double representing the angle to use for rotating the robot.
   */
  void Rotate(double angle);

 private:
  /**
  * JSON object representing the robot in the simulation.
  **/
  JsonObject details;
  /**
  * position of the robot. 
  **/
  Vector3 position;
  /**
  * direction of the robot. 
  **/
  Vector3 direction;
  /**
  * destination of the robot. 
  **/
  Vector3 destination;
  /**
  * speed of the robot. 
  **/
  float speed;
  /**
  * availability of the robot. 
  **/
  bool available;
  /**
  * current movement strategy being used by the robot. 
  **/
  std::string strategyName;
  /**
  * current nearest entity to the robot. 
  **/
};

#endif  // LIBS_TRANSIT_INCLUDE_ROBOT_H_
