#include "defel_v.h"
#include "deff_g.h"

void inp_el_v(el_v*& node, std::istream& in) {
    node = new el_v;
    node->f.h = node->f.t = nullptr;
    node->f.L = 0;
    node->next = nullptr;
    inp_f_g(node->f, in);
}

void free_el_v(el_v*& head) {
    while (head) {
        el_v* tmp = head;
        head = head->next;
        free_f_g(tmp->f);
        delete tmp;
    }
}