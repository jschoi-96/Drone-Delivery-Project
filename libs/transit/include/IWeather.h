#ifndef IWEATHER_H
#define IWEATHER_H
class IWeather {
    public:
    virtual void execute(IEntity* parent, IReaction* reaction, double dt, std::vector<IEntity*> scheduler) const = 0;
    virtual void update(double dt, std::vector<IEntity*> scheduler) const = 0; // must get called once per frame
    virtual bool is_inside(IEntity* parent) const = 0; // if the object is affected by the weather
};

/**
 * execute(IEntity* parent, WeatherReact* reaction, double dt, std::vector<IEntity*> scheduler) {
 *  // wind:
 *  reaction->react_wind(parent, dt, scheduler);
 *  this->parent->execute(parent, reaction, dt, scheduler);
 *  // base weather:
 *  parent->update(dt, scheduler);
 * }
 * 
 * react_wind() {
 *  // changes the color 
 *  // may or may not change the velocity, depending on the class used
 * }
 * 
 * */
#endif