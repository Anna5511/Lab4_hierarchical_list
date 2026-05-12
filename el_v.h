#ifndef EL_V_H
#define EL_V_H

#include "f_g.h"

struct el_v {
    f_g f;
    el_v* next;
};

#endif