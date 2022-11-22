#ifndef IWEATHER_H
#define IWEATHER_H
#include "IEntity.h"
#include "IReaction.h"
#include <vector>
class IWeather {
    public:
    virtual void execute(IEntity* parent, IReaction* reaction, double dt, std::vector<IEntity*> scheduler) const = 0;
    virtual void update(double dt, std::vector<IEntity*> scheduler) const = 0; // must get called once per frame
    virtual bool is_inside(IEntity* parent) const = 0; // if the object is affected by the weather
};
#endif