#ifndef WIND_WEATHER_H
#define WIND_WEATHER_H
class WindWeather: public IZoneWeather {
    private:
    IWeather* parent;
    Vector3 windSpeed;
    public:
    WindWeather(IWeather* parent_, Vector3 windSpeed_) {
        parent = parent_;
        windSpeed = windSpeed_;
    }
    void execute(IEntity* parent, IReaction* reaction, double dt, std::vector<IEntity*> scheduler) {
        if(is_inside(parent))
            reaction->react_wind(parent, dt, scheduler, windSpeed);
        this->parent->execute(parent, reaction, dt, scheduler);
    }
    void update(double dt, std::vector<IEntity*> scheduler) {
        parent->update(dt, scheduler);
    }
};
#endif