#include "Wing.h"
#include <sstream>

Loki::Functor<double,LOKI_TYPELIST_3(double&,double&,double&) > Wing::functor_length_w1(&Wing::length_w1);
Loki::Functor<double,LOKI_TYPELIST_2(double&,double&) > Wing::functor_length_w2(&Wing::length_w2);

Wing::Wing():_name("noname"),
             _length("Wing__length"),
             _height("Wing__height"),
             _span("Wing__span"),
             _center_x("Wing__center_x"),
             _center_y("Wing__center_y"),
             _normal_x("Wing__normal_x"),
             _normal_y("Wing__normal_y"){
   _length.  set(0.0);
   _height.  set(0.015);
   _span.    set(0.2);
   _center_x.set(0.0);
   _center_y.set(0.0);
   _normal_x.set(1.0);
   _normal_y.set(0.0);
}

Wing::Wing(std::string name):_name("noname"),
                             _length("Wing__length"),
                             _height("Wing__height"),
                             _span("Wing__span"),
                             _center_x("Wing__center_x"),
                             _center_y("Wing__center_y"),
                             _normal_x("Wing__normal_x"),
                             _normal_y("Wing__normal_y"){
   _name = name;
   _length.  get_name() = _name + "__length";
   _height.  get_name() = _name + "__height";
   _span.    get_name() = _name + "__span";
   _center_x.get_name() = _name + "__center_x";
   _center_y.get_name() = _name + "__center_y";
   _normal_x.get_name() = _name + "__normal_x";
   _normal_y.get_name() = _name + "__normal_y";

   _length.  set(0.0);
   _height.  set(0.015);
   _span.    set(0.2);
   _center_x.set(0.0);
   _center_y.set(0.0);
   _normal_x.set(1.0);
   _normal_y.set(0.0);
}

Wing::~Wing(){}

std::string Wing::description() const {
   std::stringstream sstream;
   sstream << _name.c_str() << "\n";
   sstream << " * "<<_length.  get_name_const()<<": "<< _length.  get_const_ref() << "\n";
   sstream << " * "<<_height.  get_name_const()<<": "<< _height.  get_const_ref() << "\n";
   sstream << " * "<<_span  .  get_name_const()<<": "<< _span.    get_const_ref() << "\n";
   sstream << " * "<<_center_x.get_name_const()<<": "<< _center_x.get_const_ref() << "\n";
   sstream << " * "<<_center_y.get_name_const()<<": "<< _center_y.get_const_ref() << "\n";
   sstream << " * "<<_normal_x.get_name_const()<<": "<< _normal_x.get_const_ref() << "\n";
   sstream << " * "<<_normal_y.get_name_const()<<": "<< _normal_y.get_const_ref() << "\n";
   return sstream.str();
}

std::ostream& operator<<(std::ostream& os, const Wing& obj)
{
  // write obj to stream
   os << obj.description();
   return os;
}

void Wing::set_length(double length){_length.set(length);}
void Wing::set_height(double height){_height.set(height);}
void Wing::set_span  (double span  ){_span  .set(span  );}
