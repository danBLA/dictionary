#ifndef _GLOBALSTRATEGIES_H_INCLUDED
#define _GLOBALSTRATEGIES_H_INCLUDED
#include <iostream>
#include <cmath>
#include "FunctorWrapper.h"

static double degree2radiants(double& alpha_deg) {
   return alpha_deg / 180.0 * M_PI;
}

static double radiants2degree(double& alpha_rad) {
   return alpha_rad * 180.0 / M_PI;
}

static double sum2double(double& length1, double& length2) {
   return length1 + length2;
}

// define functors
static Loki::Functor<double,LOKI_TYPELIST_1(double&) > functor_degree2radiants(&degree2radiants);
static Loki::Functor<double,LOKI_TYPELIST_1(double&) > functor_radiants2degree(&radiants2degree);
static Loki::Functor<double,LOKI_TYPELIST_2(double&,double&) > functor_sum2double(&sum2double);
static Loki::Functor<double,LOKI_TYPELIST_1(double) > functor_sin(&(sin));
static Loki::Functor<double,LOKI_TYPELIST_1(double) > functor_cos(&(cos));

#endif
