#include "Orientation.h"
#include <sstream>
#include "GlobalStrategies.h"

Orientation::Orientation():_name("noname"),
                           _pitch_deg("Orientation__pitch_deg"),
                           _pitch_rad("Orientation__pitch_rad"),
                           _roll_deg ("Orientation__roll_deg" ),
                           _roll_rad ("Orientation__roll_rad" ),
                           _yaw_deg  ("Orientation__yaw_deg"  ),
                           _yaw_rad  ("Orientation__yaw_rad"  ) {
}

Orientation::Orientation(std::string name):_name("noname"),
                           _pitch_deg("Orientation__pitch_deg"),
                           _pitch_rad("Orientation__pitch_rad"),
                           _roll_deg ("Orientation__roll_deg" ),
                           _roll_rad ("Orientation__roll_rad" ),
                           _yaw_deg  ("Orientation__yaw_deg"  ),
                           _yaw_rad  ("Orientation__yaw_rad"  ) {
   _name = name;
   _pitch_deg.get_name() = _name + "__pitch_deg";
   _pitch_rad.get_name() = _name + "__pitch_rad";
   _roll_deg .get_name() = _name + "__roll_deg";
   _roll_rad .get_name() = _name + "__roll_rad";
   _yaw_deg  .get_name() = _name + "__yaw_deg";
   _yaw_rad  .get_name() = _name + "__yaw_rad";

   setStrategies();

   _pitch_deg.set(0.0);
   _roll_deg .set(0.0);
   _yaw_deg  .set(0.0);
}

void Orientation::setStrategies(){
   _pitch_rad.addStrategy(&functor_degree2radiants,
                          &_pitch_deg,
                          "degree2radiants");

   _roll_rad.addStrategy(&functor_degree2radiants,
                         &_roll_deg,
                         "degree2radiants");

   _yaw_rad.addStrategy(&functor_degree2radiants,
                        &_yaw_deg,
                        "degree2radiants");
}

Orientation::~Orientation(){}

std::string Orientation::description() const {
   std::stringstream sstream;
   sstream << _name.c_str() << "\n";
   sstream << " (degree):\n";
   sstream << " * "<<_pitch_deg.  get_name_const()<<": "<< _pitch_deg.  get_const_ref() << "\n";
   sstream << " * "<<_roll_deg.   get_name_const()<<": "<< _roll_deg.   get_const_ref() << "\n";
   sstream << " * "<<_yaw_deg.    get_name_const()<<": "<< _yaw_deg.    get_const_ref() << "\n";
   sstream << " (radiant):\n";
   sstream << " * "<<_pitch_rad.  get_name_const()<<": "<< _pitch_rad.  get_const_ref() << "\n";
   sstream << " * "<<_roll_rad.   get_name_const()<<": "<< _roll_rad.   get_const_ref() << "\n";
   sstream << " * "<<_yaw_rad.    get_name_const()<<": "<< _yaw_rad.    get_const_ref() << "\n";
   return sstream.str();
}

std::ostream& operator<<(std::ostream& os, const Orientation& obj)
{
  // write obj to stream
   os << obj.description();
   return os;
}
