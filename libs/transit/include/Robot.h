#ifndef ROBOT_H
#define ROBOT_H

#include <vector>

#include "IEntity.h"
#include "math/vector3.h"
#include "util/json.h"

/**
*@brief A class built to manipulate movement of Robot
**/
class Robot : public IEntity {
 public:

  /**
   * @brief constructor of Robot
   * @param obj - JsonObject type obj
   */
  Robot(JsonObject& obj);

    /**
     * @brief Destructor for Robot class.
     * 
     * @return none.
     **/
  ~Robot() override = default;

  /**
   * @brief The Position of Robot
   *
   * @return return the position of robot
   */
  Vector3 GetPosition() const { return position; }

  /**
   * @brief The direction of robot
   *
   * @return return the direction of robot
   */
  Vector3 GetDirection() const { return direction; }

  /**
   * @brief The destination of robot
   *
   * @return return the destination of robot
   */
  Vector3 GetDestination() const { return destination; }

  /**
   * @brief The availability of drine
   *
   * @return return true if it is available, if not return false
   */
  bool GetAvailability() const { return available; }

  /**
   * @brief get details from JsonObject obj
   */
  JsonObject GetDetails() const override;

  /**
   * @brief The speed of robot
   *
   * @return return the speed of robot
   */
  float GetSpeed() const { return speed; }

  /**
   * @brief The strategy of robot
   *
   * @return return the name of strategy that is used 
   */
  std::string GetStrategyName() {return strategyName;}

  /**
   * @brief set availability
   *
   * @param choice - bool type 
   */
  void SetAvailability(bool choice);

  /**
   * @brief set the position of object
   * @param pos_ - Vector3 obj
   */  
  void SetPosition(Vector3 pos_) { position = pos_; }

  /**
   * @brief set the direction of object
   * @param dir_ - Vector3 obj
   */  
  void SetDirection(Vector3 dir_) { direction = dir_; }

  /**
   * @brief set the destination of obj
   * @param des_ - Vector3 obj
   */  
  void SetDestination(Vector3 des_) { destination = des_; }

  /**
   * @brief set the strategy 
   *
   * @param strategyName_ - string type, name of strategy
   */
  void SetStrategyName(std::string strategyName_) { strategyName = strategyName_;}

  /**
   * @brief rotate robot by using angle and formula
   * @param angle - angle of robot
   */  
  void Rotate(double angle);

 private:
  JsonObject details;
  Vector3 position;
  Vector3 direction;
  Vector3 destination;
  float speed;
  bool available;
  std::string strategyName;
};

#endif  // ROBOT_H