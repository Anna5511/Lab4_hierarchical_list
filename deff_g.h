#ifndef DEFF_G_H
#define DEFF_G_H

#include "f_g.h"
#include "defel_g.h"

void init_f_g(f_g& lst);
void inp_f_g(f_g& lst, std::istream& in);
void out_f_g(const f_g& lst, std::ostream& out);
void process_f_g(f_g& lst);
void free_f_g(f_g& lst);
void copy_f_g(f_g& dest, const f_g& src);
bool fg_equal(const f_g& a, const f_g& b);
int  fg_compare(const f_g& a, const f_g& b);

#endif
