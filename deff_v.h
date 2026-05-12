#ifndef DEFF_V_H
#define DEFF_V_H

#include "f_v.h"
#include "defel_v.h"

void inp_f_v(f_v& lst, const char* filename);
void out_f_v(const f_v& lst, std::ostream& out);
void process_f_v(f_v& lst);
void free_f_v(f_v& lst);
void symmetric_difference_f_v(const f_v& l1, const f_v& l2, f_v& l3);

#endif