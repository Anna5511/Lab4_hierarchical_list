#ifndef F_G_H
#define F_G_H

#include "el_g.h"

struct f_g {
    unsigned L;      // количество блоков (el_g)
    el_g* h;
    el_g* t;
};

#endif