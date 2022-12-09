#ifndef ISTRATEGY_H_
#define ISTRATEGY_H_

#include <vector>
#include "graph.h"
#include "IEntity.h"

using namespace routing;

/**
*@brief A class built for Istrategy
**/
class IStrategy {
    public:
    /**
   * @brief moves the entity based on strategy.
   * @param entity Ientity*
   * @param dt delta time double
   * @return nothing
   */  
        virtual void Move(IEntity* entity, double dt) = 0;
     /**
   * @brief method to tell if stragety is completed.
   * 
   * @return boolean
   */
        virtual bool IsCompleted() = 0;
    protected:
        // IGraph object to be used in the simulation.
        const IGraph* graph;
}; //close class 

#endif // ISTRATEGY_H_