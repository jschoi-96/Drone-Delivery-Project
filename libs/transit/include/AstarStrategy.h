#ifndef ASTAR_STRATEGY_H_
#define ASTAR_STRATEGY_H_

/**
 * include
 */
#include "math/vector3.h"
#include <vector>
#include "IStrategy.h"
#include "IEntity.h"
/**
* @brief Implementation of Astar strategy for entity movement. Inherits from IStrategy.
**/
class AstarStrategy : public IStrategy {
public:
    /**
     * @brief Constructor for AstarStrategy class.
     * 
     * @param position_ current position of the entity to move.
     * @param destination_ destination of entity to move.
     * @param graph_ pointer to graph to be used to generate beeline pathing.
     * @return none.
     **/
    AstarStrategy(Vector3 position, Vector3 destination, const IGraph* graph);
    /**
     * @brief Destructor for AstarStrategy class.
     * 
     * @return none.
     **/
    ~AstarStrategy();
    /**
     * @brief Used for moving drone/robot pairs towards their destination using the astar movement strategy.
     * 
     * @param entity entity to move.
     * @param dt amount of time that the entity will be moving.
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
    /**
    * vector of float vectors. Each float vector represents a node in the path.
    **/
    std::vector<std::vector<float>> path;
   /**
    * current index of the position nodes in the path.
    **/
    int currentIndex;
   /**
    * maximum index of position nodes in the path.
    **/
    int maxIndex;
}; //end class
#endif // ASTAR_STRATEGY_H_