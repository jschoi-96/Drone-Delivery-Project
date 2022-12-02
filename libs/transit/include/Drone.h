#ifndef DRONE_H_
#define DRONE_H_

#include <vector>

#include "IEntity.h"
#include "IStrategy.h"
#include "math/vector3.h"
#include <map>

// Represents a drone in a physical system.
// Drones move using euler integration based on a specified
// velocity and direction.
class Drone : public IEntity {
 public:
  std::map<std::string, std::string> Dronecolors = {
    {"red", "0xff0000"},
    {"yellow", "0xffff00"},
    {"blue", "0x0000FF"},
    {"orange", "0xffa500"},
    {"green", "0x00ff00"},
    {"purple", "0xa020f0"},
    {"brown", "0x964b00"},
    {"black", "0x000000"}
  };
  // Drones are created with a name
  Drone(JsonObject& obj);
  // Destructor
  ~Drone();

  float GetSpeed() const { return speed; }

  // Gets the drone position
  Vector3 GetPosition() const { return position; }

  Vector3 GetDirection() const { return direction; }

  Vector3 GetDestination() const { return destination; }

  JsonObject GetDetails() const { return details; }

  bool GetAvailability() const { return available; }

  void GetNearestEntity(std::vector<IEntity*> scheduler);

  // Updates the drone's position
  void Update(double dt, std::vector<IEntity*> scheduler);

  void SetPosition(Vector3 pos_) { position = pos_; }

  // Sets the drone's direction
  void SetDirection(Vector3 dir_) { direction = dir_; }

  void SetDestination(Vector3 des_) { destination = des_; }

  // Rotates a drone
  void Rotate(double angle);

  void Jump(double height);

  // Removing the copy constructor and assignment operator
  // so that drones cannot be coppied.
  Drone(const Drone& drone) = delete;
  Drone& operator=(const Drone& drone) = delete;

 private:
  JsonObject details;
  Vector3 position;
  Vector3 direction;
  float jumpHeight = 0;
  bool goUp = true; // jump helper
  Vector3 destination;
  float speed;
  bool available;
  bool pickedUp;
  std::string strategyName;
  IEntity* nearestEntity = NULL;
  IStrategy* toTargetPosStrategy = NULL;
  IStrategy* toTargetDestStrategy = NULL;
 
};

#endif
