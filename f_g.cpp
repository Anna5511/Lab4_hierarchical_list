#include "deff_g.h"
#include "defel_g.h"
#include "defstr.h"

void inp_f_g(f_g& lst, std::istream& in) {
    lst.h = lst.t = nullptr;
    lst.L = 0;

    while (true) {
        while (in.peek() == ' ' || in.peek() == '\t') {
            char c;
            in.get(c);
        }

        int p = in.peek();
        if (p == '\n' || p == '\r' || p == EOF) {
            if (p != EOF) {
                char c;
                in.get(c);
                if (c == '\r' && in.peek() == '\n') in.get(c);
            }
            break;
        }

        el_g* node = nullptr;
        inp_el_g(node, in);

        if (!lst.h) lst.h = node;
        else lst.t->next = node;
        lst.t = node;
        lst.L++;
    }
}

void out_f_g(const f_g& lst, std::ostream& out) {
    if (!lst.h) {
        out << "[]";
        return;
    }

    out << "[";
    el_g* cur = lst.h;
    bool first = true;
    while (cur) {
        if (!first) out << ", ";
        out_el_g(cur, out);
        first = false;
        cur = cur->next;
    }
    out << "]";
}

void free_f_g(f_g& lst) {
    free_el_g(lst.h);
    lst.h = lst.t = nullptr;
    lst.L = 0;
}

int cmp_f_g(const f_g& a, const f_g& b) {
    el_g* pa = a.h;
    el_g* pb = b.h;

    while (pa && pb) {
        int c = cmp_str(pa->T, pb->T);
        if (c != 0) return c;
        pa = pa->next;
        pb = pb->next;
    }

    // Если один список длиннее другого
    if (pa && !(pa->T.A[0] == '\0' && pa->next == nullptr)) return 1;
    if (pb && !(pb->T.A[0] == '\0' && pb->next == nullptr)) return -1;
    return 0;
}

void copy_f_g(f_g& dest, const f_g& src) {
    free_f_g(dest);

    if (!src.h) return;

    el_g* p = src.h;
    el_g** tail = &dest.h;

    while (p) {
        el_g* node = new el_g;
        node->T = p->T;
        node->next = nullptr;
        *tail = node;
        tail = &node->next;
        p = p->next;
        dest.L++;
    }
    dest.t = (dest.h ? *tail : nullptr);
}