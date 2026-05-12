#ifndef DEFEL_G_H
#define DEFEL_G_H

#include "el_g.h"
#include "defstr.h"

void inp_el_g(el_g*& node, std::istream& in);
void out_el_g(const el_g* node, std::ostream& out);
void process_el_g(el_g* node);
void free_el_g(el_g*& head);

#endif