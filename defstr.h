#ifndef DEFSTR_H
#define DEFSTR_H

#include "str.h"
#include <iostream>

void inp_str(str& s, std::istream& in);
void out_str(const str& s, std::ostream& out);
int cmp_str(const str& a, const str& b);

#endif