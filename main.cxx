#include <iostream>
#include "Node.h"
#include "FunctorWrapper.h"
#include <time.h> /* clock_t, clock, CLOCKS_PER_SEC */
#include <cmath>
#include <sstream>
#include "Wing.h"
#include "GlobalStrategies.h"
#include "Orientation.h"

int main() {

   tmb::Node<double> total_length("total_length");
   tmb::Node<double> height("height");
   tmb::Node<double> width("width");

   tmb::Node<double> angle_deg("angle_deg");
   tmb::Node<double> angle_rad("angle_rad");
   tmb::Node<double> pitch_deg("pitch_deg");
   tmb::Node<double> pitch_rad("pitch_rad");
   tmb::Node<double> roll_deg("roll_deg");
   tmb::Node<double> roll_rad("roll_rad");
   tmb::Node<double> yaw_deg("yaw_deg");
   tmb::Node<double> yaw_rad("yaw_rad");

   Wing wing_vertical("wing_vertical");
   Wing wing_horizontal("wing_horizontal");

   wing_vertical.  set_length(1.0);
   wing_vertical.  set_height(0.015);
   wing_vertical.  set_span  (0.2);
   wing_horizontal.set_length(1.0);
   wing_horizontal.set_height(0.015);
   wing_horizontal.set_span  (0.2);

   Orientation orientation("orientation");

   angle_rad.addStrategy(&functor_degree2radiants,
                         &angle_deg,
                         "degree2radiants");


   total_length.addStrategy(&functor_sum2double,
                            &(wing_horizontal._length),
                            &(wing_vertical  ._length),
                            "sum2double");

   wing_horizontal._length.addStrategy(&Wing::functor_length_w2,
                                       &angle_rad,
                                       &width,
                                       "length_w2");

   wing_horizontal._normal_x.addStrategy(&functor_cos,
                                         &angle_rad,
                                         "normal_x=cos(alpha)");

   wing_horizontal._normal_y.addStrategy(&functor_sin,
                                         &angle_rad,
                                         "normal_x=sin(alpha)");

   wing_vertical.  _length.addStrategy(&Wing::functor_length_w1,
                                             &angle_rad,
                                             &height,
                                             &width,
                                             "length_w1");

   height.set(1.0);
   width.set(0.3);
   angle_deg.set(45.0);
   orientation._pitch_deg.set(10.0);

   std::cout<<wing_vertical<<std::endl;
   std::cout<<wing_horizontal<<std::endl;
   std::cout<<orientation<<std::endl;
   std::cout<<"Total length: "<<total_length.get()<<std::endl;

   tmb::draw_dot_graph(&(total_length), "test_node.dot", 5);
   return 0;
}
