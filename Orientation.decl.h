#ifndef _ORIENTATION_DECL_H_INCLUDED
#define _ORIENTATION_DECL_H_INCLUDED

#include<ostream>
#include<string>
#include"Node.h"

class Orientation{
  private:
     //Orientation();
    std::string _name;
    void setStrategies();

  public:
     // for now public member variables
     // which I want to assign strategies
     tmb::Node<double> _pitch_deg;
     tmb::Node<double> _pitch_rad;
     tmb::Node<double> _roll_deg;
     tmb::Node<double> _roll_rad;
     tmb::Node<double> _yaw_deg;
     tmb::Node<double> _yaw_rad;

     Orientation();
     Orientation(std::string name);
     virtual ~Orientation();
     std::string description() const;
};

std::ostream& operator<<(std::ostream& os, const Orientation& obj);

#endif
