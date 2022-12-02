#ifndef IZONE_WEATHER
#define IZONE_WEATHER
#include "IEntity.h"
#include "IWeather.h"
#include "IZoneWeather.h"

#include <vector>
class IZoneWeather: public IWeather {
    // TBD: Has a radius and stuff
    public:
    void update_real(double dt, std::vector<IEntity*>* scheduler) {
        // TBD: Updates pos and whatever
    }
    void update(double dt, std::vector<IEntity*> scheduler) {
        update_real(dt, scheduler);
        parent->update(dt, scheduler);
    }
    bool is_inside(IEntity* parent) {
        Vector3 pos = parent->GetPosition();
        pos.z = 0; // nullify z value because weather zones are 2d

        if (this->isCircle){ // if circle
            pos.x = pos.x - this->xCircle; // position - center of circle
            pos.y = pos.y - this->yCircle;

            float dis = pos.Magnitude();
            if (dis < this->radius){
                return true; 
            }
        }

        else {
            if (pos.x >= this->xminRec && pos.x <= this->xmaxRec &&
                pos.y >= this->yminRec && pos.y <= this->ymaxRec) {
                    return true;
            }
        }
        
        return false;
    }; // if the object is affected by the weather

    void Circle(double xCircle_, double yCircle_ , double radius_ , bool isCircle){
        xCircle = xCircle_;
        yCircle = yCircle_;
        radius = radius_;
        isCircle = true;
    }

    void Rectangle(double xminRec_ , double yminRec_, double xmaxRec_, double ymaxRec_, bool isCircle){
        xminRec = xminRec_;
        yminRec = yminRec_;
        xmaxRec = xmaxRec_;
        ymaxRec = ymaxRec_;
        isCircle = false;
    }


    private:
        double radius;
        double xCircle;
        double yCircle;

        double xminRec;
        double yminRec;
        double xmaxRec;
        double ymaxRec;
        bool isCircle = false;        
};
#endif