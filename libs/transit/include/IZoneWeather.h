#ifndef IZONE_WEATHER
#define IZONE_WEATHER
class IZoneWeather: public IWeather {
    // TBD: Has a radius and stuff
    public:
    void update_real(double dt, std::vector<IEntity*>* scheduler) {
        // TBD: Updates pos and whatever
    }
    bool is_inside(IEntity* parent) {
        return true; // returns if parent intersects with 
    }; // if the object is affected by the weather
};
#endif