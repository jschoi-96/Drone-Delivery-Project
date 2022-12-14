#ifndef LIBS_TRANSIT_INCLUDE_ICONTROLLER_H_
#define LIBS_TRANSIT_INCLUDE_ICONTROLLER_H_

#include "IEntity.h"
#include "util/json.h"

//--------------------  Controller Interface ----------------------------

/// Abstract controller class used in the Transit Service.  Uses the Model View
/// Controller Pattern

/**
 *@brief A class built to see controller
 **/
class IController {
 public:
  /**
   * @brief Destructor for IController
   *
   * @return none.
   **/
  virtual ~IController() {}

  /// Adds an entity to the program
  /**
   * @brief Adds an entity to the program
   * @param entity IEntity to add to the program.
   **/
  virtual void AddEntity(const IEntity& entity) = 0;

  /// Adds an entity to the program
  /**
   * @brief Updates an entity in the program
   * @param entity Ientity to update in the program.
   **/
  virtual void UpdateEntity(const IEntity& entity) = 0;

  /// Removes an entity from the program
  /**
   * @brief Removes an entity from the program
   * @param id integer that uniquely identifies an entity
   **/
  virtual void RemoveEntity(int id) = 0;

  /// Adds a path to the program
  /**
   * @brief Adds a path to the program
   * @param id - int variable that uniquely identifies a path
   * @param path - 2d dimention vector that has a path
   **/
  virtual void AddPath(int id,
                       const std::vector<std::vector<float> >& path) = 0;

  /// Removes a path from the program
  /**
   * @brief Removes a path from the program
   * @param id - int variable that uniquely identifies a path
   **/
  virtual void RemovePath(int id) = 0;

  /// Allows messages to be passed back to the view
  /**
   * @brief Allows messages to be passed back to the view
   * @param event - string variable. Name of event to send to sim view.
   * @param details - JsonObject of the entity who is responsible for the event.
   **/
  virtual void SendEventToView(const std::string& event,
                               const JsonObject& details) = 0;
};

#endif  // LIBS_TRANSIT_INCLUDE_ICONTROLLER_H_

