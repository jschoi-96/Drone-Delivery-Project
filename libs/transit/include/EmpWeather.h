#ifndef EMP_WEATHER_H
#define EMP_WEATHER_H
#include "IEntity.h"
#include "IWeather.h"
#include "IZoneWeather.h"

#include <vector>

class EmpWeather: public IZoneWeather {
    private:
    IWeather* parent;
    public:
    EmpWeather(IWeather* parent_) {
        parent = parent_;
    }
    void execute(IEntity* parent, IReaction* reaction, double dt, std::vector<IEntity*> scheduler) {
        if(is_inside(parent))
            reaction->react_emp(parent, dt, scheduler);
        this->parent->execute(parent, reaction, dt, scheduler);
    }
};
#endif