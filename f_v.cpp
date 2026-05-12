#include "deff_v.h"
#include "defel_v.h"
#include "deff_g.h"

void inp_f_v(f_v& lst, const char* filename) {
    std::ifstream file(filename);
    if (!file) {
        lst.h = lst.t = nullptr;
        lst.L = 0;
        return;
    }

    lst.h = lst.t = nullptr;
    lst.L = 0;

    while (true) {
        if (file.eof()) break;

        while (file.peek() == ' ' || file.peek() == '\t') {
            char c;
            file.get(c);
        }

        if (file.eof()) break;

        el_v* node = nullptr;
        inp_el_v(node, file);
        if (!node) break;

        node->next = nullptr;
        if (lst.t) lst.t->next = node;
        else lst.h = node;
        lst.t = node;
        lst.L++;
    }

    file.close();
}

void out_f_v(const f_v& lst, std::ostream& out) {
    if (!lst.h) {
        out << "[]\n";
        return;
    }

    out << "[\n";
    el_v* cur = lst.h;
    int idx = 0;
    while (cur) {
        out << "  " << idx++ << ": ";
        out_f_g(cur->f, out);
        if (cur->next) out << ",";
        out << "\n";
        cur = cur->next;
    }
    out << "]\n";
}

void free_f_v(f_v& lst) {
    free_el_v(lst.h);
    lst.h = lst.t = nullptr;
    lst.L = 0;
}

void symmetric_difference(f_v& l3, const f_v& l1, const f_v& l2) {
    free_f_v(l3);

    el_v* p1 = l1.h;
    el_v* p2 = l2.h;
    el_v** tail = &l3.h;

    while (p1 && p2) {
        int c = cmp_f_g(p1->f, p2->f);

        if (c < 0) {
            el_v* node = new el_v;
            copy_f_g(node->f, p1->f);
            node->next = nullptr;
            *tail = node;
            tail = &node->next;
            l3.L++;
            p1 = p1->next;
        }
        else if (c > 0) {
            el_v* node = new el_v;
            copy_f_g(node->f, p2->f);
            node->next = nullptr;
            *tail = node;
            tail = &node->next;
            l3.L++;
            p2 = p2->next;
        }
        else {
            p1 = p1->next;
            p2 = p2->next;
        }
    }

    while (p1) {
        el_v* node = new el_v;
        copy_f_g(node->f, p1->f);
        node->next = nullptr;
        *tail = node;
        tail = &node->next;
        l3.L++;
        p1 = p1->next;
    }

    while (p2) {
        el_v* node = new el_v;
        copy_f_g(node->f, p2->f);
        node->next = nullptr;
        *tail = node;
        tail = &node->next;
        l3.L++;
        p2 = p2->next;
    }

    l3.t = (l3.h ? *tail : nullptr);
}