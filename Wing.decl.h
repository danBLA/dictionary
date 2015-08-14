#ifndef _WING_DECL_H_INCLUDED
#define _WING_DECL_H_INCLUDED

#include<ostream>
#include<string>
#include<cmath>
#include"Node.h"

class Wing{
  private:
     //Wing();
    std::string _name;

  public:
     // for now public member variables
     // which I want to assign strategies
     tmb::Node<double> _length;
     tmb::Node<double> _height;
     tmb::Node<double> _span;
     tmb::Node<double> _center_x;
     tmb::Node<double> _center_y;
     tmb::Node<double> _normal_x;
     tmb::Node<double> _normal_y;

     Wing();
     Wing(std::string name);
     virtual ~Wing();
     std::string description() const;
     void set_length(double length);
     void set_height(double height);
     void set_span  (double span  );

     static Loki::Functor<double,LOKI_TYPELIST_3(double&,double&,double&) > functor_length_w1;
     static Loki::Functor<double,LOKI_TYPELIST_2(double&,double&) > functor_length_w2;

     static double length_w1(double& alpha, double& h, double& w) {
        return h - w/std::tan(alpha);
     }

     static double length_w2(double& alpha, double& w) {
        return w/std::sin(alpha);
     }

};

std::ostream& operator<<(std::ostream& os, const Wing& obj);

#endif
