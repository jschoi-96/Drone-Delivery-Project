#ifndef BEELINE_H_
#define BEELINE_H_

/**
 * include
 */
#include "math/vector3.h"
#include <vector>
#include "IStrategy.h"
#include "IEntity.h"
/**
* @brief Implementation of Beeline strategy for drone movement. Inherits from IStrategy.
**/
class BeelineStrategy : public IStrategy {
public:
    /**
     * @brief Constructor for BeelineStrategy class.
     * 
     * @param position_ current position of the entity to move.
     * @param destination_ destination of entity to move.
     * @param graph_ pointer to graph to be used to generate beeline pathing.
     * @return none.
     **/
    BeelineStrategy(Vector3 position, Vector3 destination);
    /**
     * @brief Destructor for BeelineStrategy class.
     * 
     * @return none.
     **/
    ~BeelineStrategy();
    /**
     * @brief Used for moving drones to robots in a straight line.
     * 
     * @param entity entity (always a drone) to move.
     * @param dt amount of time that the drone will be moving.
     * @return none.
     **/
    void Move(IEntity* entity, double dt);
    /**
     * @brief Checks if the route has been completed.
     * 
     * @return true if completed, if not, return false.
     **/
    bool IsCompleted();

private:
    Vector3 position;
    Vector3 destination;
}; //end class
#endif // BEELINE_H_