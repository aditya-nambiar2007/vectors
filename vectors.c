#include <math.h>
struct vector{
    //components
    double x;
    double y;
    double z;
    
    //methods
    double magnitude(){return pow((this->x*this->x + this->y*this->y + this->z*this->z), 0.5); }

    vector add (vector param){vector res= {this->x+param.x,this->y+param.y,this->z+param.z}; return res; }
    vector multiply (double param){vector res= {this->x*param,this->y*param,this->z*param}; return res; }
    vector subtract (vector param){return this->add(param.multiply(-1)); }
    vector divide (double param){return this->multiply(1/param); }

    vector direction(){return this->divide(this->magnitude());}

    double dot(vector param){return this->x*param.x+this->y*param.y+this->z*param.z;}
    vector cross(vector param){vector res = {this->y*param.z-this->z*param.y,   this->z*param.x-this->x*param.z,    this->x*param.y-this->y*param.x} ;return res;} ;   
    };

double angle( vector a , vector b){    return  acos( a.dot(b)/(a.magnitude()*a.magnitude()) );  }