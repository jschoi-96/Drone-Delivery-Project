#ifndef RAIN_WEATHER_H
#define RAIN_WEATHER_H
#include "IEntity.h"
#include "IWeather.h"
#include "IZoneWeather.h"

#include <vector>
class RainWeather: public IZoneWeather {
    private:
    IWeather* parent;
    public:
    RainWeather(IWeather* parent_) {
        parent = parent_;
    }
    void execute(IEntity* parent, IReaction* reaction, double dt, std::vector<IEntity*> scheduler) {
        if(is_inside(parent))
            reaction->react_rain(parent, dt, scheduler);
        this->parent->execute(parent, reaction, dt, scheduler);
    }
    void update(double dt, std::vector<IEntity*> scheduler) {
        parent->update(dt, scheduler);
    }
};
#endif