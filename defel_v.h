#ifndef DEFEL_V_H
#define DEFEL_V_H

#include "el_v.h"
#include <iostream>

void inp_el_v(el_v*& node, std::istream& in);
void out_el_v(const el_v* node, std::ostream& out);
void free_el_v(el_v*& head);

#endif