#include "defel_v.h"

void inp_el_v(el_v*& node, std::istream& in) {
    node = new el_v;
    node->next = nullptr;
    init_f_g(node->f);
    inp_f_g(node->f, in);
}

void out_el_v(const el_v* node, std::ostream& out) {
    if (node) out_f_g(node->f, out);
}

void process_el_v(el_v* node) {
    if (node) process_f_g(node->f);
}

void free_el_v(el_v*& head) {
    while (head) {
        el_v* tmp = head;
        head = head->next;
        free_f_g(tmp->f);
        delete tmp;
    }
}