#include "deff_g.h"
#include "defel_g.h"
#include "defstr.h"

void inp_f_g(f_g& lst, std::istream& in) {
    lst.h = lst.t = nullptr;
    lst.L = 0;

    while (true) {
        // пропускаем пробелы и табул€ции
        while (in.peek() == ' ' || in.peek() == '\t')
            in.get();

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

    // ≈сли строка пуста€, добавл€ем один пустой блок (дл€ единообрази€)
    if (lst.L == 0) {
        el_g* dummy = new el_g;
        dummy->T.A[0] = '\0';
        dummy->next = nullptr;
        lst.h = lst.t = dummy;
        lst.L = 1;
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

// —равнение двух строк (f_g) лексикографически, символ за символом
int cmp_f_g(const f_g& a, const f_g& b) {
    el_g* pa = a.h;
    el_g* pb = b.h;
    int ia = 0, ib = 0;

    while (pa && pb) {
        char ca = pa->T.A[ia];
        char cb = pb->T.A[ib];

        if (ca != cb)
            return (unsigned char)ca - (unsigned char)cb;

        if (ca == '\0') break; // обе строки закончились

        ia++; ib++;

        // переход к следующему блоку, если текущий исчерпан
        if (ia >= N - 1 || pa->T.A[ia] == '\0') { // или просто до '\0'
            pa = pa->next;
            ia = 0;
        }
        if (ib >= N - 1 || pb->T.A[ib] == '\0') {
            pb = pb->next;
            ib = 0;
        }
    }

    // если один список ещЄ не закончилс€, а другой закончилс€
    if (pa && !(pa->T.A[ia] == '\0' && pa->next == nullptr && ia == 0))
        return 1;
    if (pb && !(pb->T.A[ib] == '\0' && pb->next == nullptr && ib == 0))
        return -1;
    return 0;
}

void copy_f_g(f_g& dest, const f_g& src) {
    free_f_g(dest);
    if (!src.h) return;

    el_g* cur = src.h;
    el_g** tail = &dest.h;

    while (cur) {
        el_g* node = new el_g;
        node->T = cur->T;   // структурное копирование
        node->next = nullptr;
        *tail = node;
        tail = &node->next;
        cur = cur->next;
        dest.L++;
    }
    dest.t = (dest.h ? *tail : nullptr);
}