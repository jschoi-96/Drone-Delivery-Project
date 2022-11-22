#ifndef BASE_WEATHER_H
#define BASE_WEATHER_H
#include "IWeather.h"
#include "IEntity.h"
#include "IReaction.h"
#include <vector>
class BaseWeather: public IWeather {
    private:
    // there is ONLY ONE WEATHER IN THE WORLDDDDDD
    BaseWeather() {}
    static IWeather* instance;
    static IWeather* getInstance() {
        if (instance == 0) {
            instance = new BaseWeather();
        }
        return instance;
    }
    static void SetInstance(IWeather* new_instance) {
        instance = new_instance;
    }
    public:
    void execute(IEntity* parent, IReaction* reaction, double dt, std::vector<IEntity*> scheduler) {
        parent->execute(dt, scheduler);
    }
    void update(double dt, std::vector<IEntity*> scheduler) {}
    bool is_inside(IEntity* parent) {
        return true;
    }; // if the object is affected by the weather
};
#endif