#ifndef Dijkstra_STRATEGY_H_
#define Dijkstra_STRATEGY_H_

/**
 * include
 */
#include "math/vector3.h"
#include <vector>
#include "IStrategy.h"
#include "IEntity.h"
/**
* @brief Implementation of Dijkstra strategy for entity movement. Inherits from IStrategy.
**/
class DijkstraStrategy : public IStrategy {
public:
    /**
     * @brief Constructor for DijkstraStrategy class.
     * 
     * @param position_ current position of the entity to move.
     * @param destination_ destination of entity to move.
     * @param graph_ pointer to graph to be used to generate beeline pathing.
     * @return none.
     **/
    DijkstraStrategy(Vector3 position, Vector3 destination, const IGraph* graph);
    /**
     * @brief Destructor for DijkstraStrategy class.
     * 
     * @return none.
     **/
    ~DijkstraStrategy();
    /**
     * @brief Used for moving drone/robot pairs towards their destination using the dijkstra movement strategy.
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
    std::vector<std::vector<float>> path;
    int currentIndex;
    int maxIndex;
}; //end class
#endif // Dijkstra_STRATEGY_H_