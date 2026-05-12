#include "deff_v.h"
#include <fstream>

void inp_f_v(f_v& lst, const char* filename) {
    std::ifstream file(filename);
    if (!file) {
        lst.h = lst.t = nullptr;
        lst.L = 0;
        return;
    }
    lst.h = lst.t = nullptr;
    lst.L = 0;
    while (!file.eof()) {
        el_v* node = nullptr;
        inp_el_v(node, file);
        if (!node) break;
        if (!lst.h) lst.h = node;
        else lst.t->next = node;
        lst.t = node;
        lst.L++;
    }
}

void out_f_v(const f_v& lst, std::ostream& out) {
    if (!lst.h) {
        out << "NULL\n";
        return;
    }
    el_v* cur = lst.h;
    while (cur) {
        out_f_g(cur->f, out);
        if (cur->next) {
            out << "\n|\nv\n";
        }
        cur = cur->next;
    }
    out << "\nNULL\n";
}

void process_f_v(f_v& lst) {
    el_v* cur = lst.h;
    while (cur) { process_el_v(cur); cur = cur->next; }
}

void free_f_v(f_v& lst) {
    free_el_v(lst.h);
    lst.h = lst.t = nullptr;
    lst.L = 0;
}

void symmetric_difference_f_v(const f_v& l1, const f_v& l2, f_v& l3) {
    l3.h = l3.t = nullptr;
    l3.L = 0;
    el_v* p1 = l1.h;
    el_v* p2 = l2.h;

    while (p1 && p2) {
        int cmp = fg_compare(p1->f, p2->f);
        if (cmp == 0) {
            p1 = p1->next;
            p2 = p2->next;
        }
        else if (cmp < 0) {
            el_v* node = new el_v;
            node->next = nullptr;
            init_f_g(node->f);
            copy_f_g(node->f, p1->f);
            if (!l3.h) l3.h = node;
            else l3.t->next = node;
            l3.t = node;
            l3.L++;
            p1 = p1->next;
        }
        else {
            el_v* node = new el_v;
            node->next = nullptr;
            init_f_g(node->f);
            copy_f_g(node->f, p2->f);
            if (!l3.h) l3.h = node;
            else l3.t->next = node;
            l3.t = node;
            l3.L++;
            p2 = p2->next;
        }
    }

    while (p1) {
        el_v* node = new el_v;
        node->next = nullptr;
        init_f_g(node->f);
        copy_f_g(node->f, p1->f);
        if (!l3.h) l3.h = node;
        else l3.t->next = node;
        l3.t = node;
        l3.L++;
        p1 = p1->next;
    }

    while (p2) {
        el_v* node = new el_v;
        node->next = nullptr;
        init_f_g(node->f);
        copy_f_g(node->f, p2->f);
        if (!l3.h) l3.h = node;
        else l3.t->next = node;
        l3.t = node;
        l3.L++;
        p2 = p2->next;
    }
}