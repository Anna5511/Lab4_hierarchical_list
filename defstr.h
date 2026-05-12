#ifndef DEFSTR_H
#define DEFSTR_H

#include "str.h"
#include <iostream>

void inp_str(str& s, std::istream& in);
void out_str(const str& s, std::ostream& out);
void process_str(str& s);

#endif