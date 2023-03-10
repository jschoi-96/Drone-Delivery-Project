#ifndef LIBS_TRANSIT_INCLUDE_DRONE_H_
#define LIBS_TRANSIT_INCLUDE_DRONE_H_

#include <map>
#include <vector>

#include "IEntity.h"
#include "IStrategy.h"
#include "math/vector3.h"

// Represents a drone in a physical system.
// Drones move using euler integration based on a specified
// velocity and direction.

/**
 *@brief A class built to manipulate movement of drone. Inherits from IEntity.
 **/
class Drone : public IEntity {
 public:
  /**
   * @brief Constructor for the Drone class.
   * 
   * @return none.
   **/
  Drone(const JsonObject& obj);

  /**
   * @brief Destructor for Drone class.
   *
   * @return none.
   **/
  ~Drone();

  /**
   * @brief The speed of drone
   *
   * @return return the speed of drone
   */
  float GetSpeed() const { return speed; }

  // Gets the drone position
  /**
   * @brief The speed of drone
   *
   * @return return the speed of drone
   */
  Vector3 GetPosition() const { return position; }

  /**
   * @brief The direction of drone
   *
   * @return return the speed of drone
   */

  Vector3 GetDirection() const { return direction; }

  /**
   * @brief The destination of drone
   *
   * @return return the destination of drone
   */
  Vector3 GetDestination() const { return destination; }

  /**
   * @brief The details of JsonObject
   *
   * @return return the details of JsonObject
   */
  JsonObject GetDetails() const { return details; }

  /**
   * @brief Check availability of drone
   *
   * @return If drone is available, returns true and else, return false
   */
  bool GetAvailability() const { return available; }

  /**
   * @brief find the distance of entity and set it to minimum value
   * @param scheduler - IEntity type vector obj
   */
  void GetNearestEntity(std::vector<IEntity*> scheduler);

  // Updates the drone's position

  /**
   * @brief if availablity of drone is true, then call getNearestEntity function
   * @param dt - delta time
   * @param scheduler - IEntity type vector obj
   */
  void Update(double dt, std::vector<IEntity*> scheduler);

  /**
   * @brief set the position of object
   * @param pos_ - Vector3 obj
   */
  void SetPosition(Vector3 pos_) { position = pos_; }

  // Sets the drone's direction
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

  // Rotates a drone

  /**
   * @brief rotate drone by using angle and formula
   * @param angle - angle to use while rotating the drone.
   */
  void Rotate(double angle);

  /**
   * @brief rotate drone by using height and formula
   * @param height - height of drone
   */
  void Jump(double height);

  // Removing the copy constructor and assignment operator
  // so that drones cannot be coppied.

  /**
   * @brief Removing the copy constructor
   * @param drone - drone obj
   */
  Drone(const Drone& drone) = delete;

  /**
   * @brief Removing assignment operator
   * @param drone - drone obj
   */
  Drone& operator=(const Drone& drone) = delete;

 private:
 /**
  * JSON object representing the drone in the simulation.
  **/
  JsonObject details;
  /**
  * position of the drone. 
  **/
  Vector3 position;
  /**
  * direction of the drone. 
  **/
  Vector3 direction;
  /**
  * height for drone to jump when celebrating. 
  **/
  float jumpHeight = 0;
  /**
  * jump helper 
  **/
  bool goUp = true;
  /**
  * destination of the drone. 
  **/
  Vector3 destination;
  /**
  * speed of the drone. 
  **/
  float speed;
  /**
  * availability of the drone. 
  **/
  bool available;
  /**
  * boolean determining if the drone has a robot currently picked up. 
  **/
  bool pickedUp;
  /**
  * current movement strategy being used by the drone. 
  **/
  std::string strategyName;
  /**
  * current nearest entity to the drone. 
  **/
  IEntity* nearestEntity = NULL;
  /**
  * movement strategy the drone should use when moving towards a pickup location. 
  **/
  IStrategy* toTargetPosStrategy = NULL;
  /**
  * movement strategy the drone should use when moving towards a drop off location. 
  **/
  IStrategy* toTargetDestStrategy = NULL;
};

#endif  // LIBS_TRANSIT_INCLUDE_DRONE_H_
