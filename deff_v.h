#ifndef DEFF_V_H
#define DEFF_V_H

#include "f_v.h"
#include <iostream>
#include <fstream>

void init_f_v(f_v& lst);
void inp_f_v(f_v& lst, const char* filename);
void out_f_v(const f_v& lst, std::ostream& out);
void free_f_v(f_v& lst);
void symmetric_difference(f_v& result, const f_v& l1, const f_v& l2);

#endif