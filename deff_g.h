#ifndef DEFF_G_H
#define DEFF_G_H

#include "f_g.h"
#include <iostream>

void inp_f_g(f_g& lst, std::istream& in);
void out_f_g(const f_g& lst, std::ostream& out);
void free_f_g(f_g& lst);
int cmp_f_g(const f_g& a, const f_g& b);
void copy_f_g(f_g& dest, const f_g& src);

#endif