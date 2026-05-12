#include "defel_g.h"

void inp_el_g(el_g*& node, std::istream& in) {
    node = new el_g;
    node->next = nullptr;
    inp_str(node->T, in);
}

void out_el_g(const el_g* node, std::ostream& out) {
    if (node) out_str(node->T, out);
}

void process_el_g(el_g* node) {
    if (node) process_str(node->T);
}

void free_el_g(el_g*& head) {
    while (head) {
        el_g* tmp = head;
        head = head->next;
        delete tmp;
    }
}