#include "deff_g.h"
#include <cstring>

void init_f_g(f_g& lst) {
    lst.h = lst.t = nullptr;
    lst.L = 0;
}

void inp_f_g(f_g& lst, std::istream& in) {
    init_f_g(lst);
    // Пропускаем возможные пустые строки в начале
    while (in.peek() == '\n' || in.peek() == '\r')
        in.get();
    if (in.eof()) return;

    bool end_of_line = false;
    while (!end_of_line && !in.eof()) {
        el_g* node = new el_g;
        node->next = nullptr;
        inp_str(node->T, in);
        if (!lst.h) lst.h = node;
        else lst.t->next = node;
        lst.t = node;
        lst.L++;

        // Проверяем, что после блока идёт конец строки
        if (in.eof()) break;
        if (in.peek() == '\n') {
            in.get();
            end_of_line = true;
        }
        else if (in.peek() == '\r') {
            in.get();
            if (in.peek() == '\n') in.get();
            end_of_line = true;
        }
        // Иначе строка продолжается (следующий блок)
    }

    // Если строка была пустой (не добавлено ни одного блока)
    if (lst.L == 0) {
        el_g* n = new el_g;
        n->next = nullptr;
        n->T.A[0] = '\0';
        lst.h = lst.t = n;
        lst.L = 1;
    }
}

void out_f_g(const f_g& lst, std::ostream& out) {
    if (lst.L == 1 && lst.h && lst.h->T.A[0] == '\0') {
        out << "[empty]";
        return;
    }
    el_g* p = lst.h;
    while (p) {
        out_el_g(p, out);
        out << "->";
        p = p->next;
    }
    out << "NULL";
}

void process_f_g(f_g& lst) {
    el_g* p = lst.h;
    while (p) {
        process_el_g(p);
        p = p->next;
    }
}

void free_f_g(f_g& lst) {
    free_el_g(lst.h);
    init_f_g(lst);
}

void copy_f_g(f_g& dest, const f_g& src) {
    init_f_g(dest);
    el_g* cur = src.h;
    while (cur) {
        el_g* node = new el_g;
        node->next = nullptr;
        std::memcpy(node->T.A, cur->T.A, N);
        if (!dest.h) dest.h = node;
        else dest.t->next = node;
        dest.t = node;
        dest.L++;
        cur = cur->next;
    }
}

bool fg_equal(const f_g& a, const f_g& b) {
    return fg_compare(a, b) == 0;
}

int fg_compare(const f_g& a, const f_g& b) {
    el_g* pa = a.h;
    el_g* pb = b.h;
    int pos_a = 0, pos_b = 0;
    while (pa && pb) {
        // Сравниваем символы текущих блоков
        while (pos_a < N && pa->T.A[pos_a] != '\0' &&
            pos_b < N && pb->T.A[pos_b] != '\0' &&
            pa->T.A[pos_a] == pb->T.A[pos_b]) {
            pos_a++; pos_b++;
        }
        if (pos_a == N || pa->T.A[pos_a] == '\0' ||
            pos_b == N || pb->T.A[pos_b] == '\0' ||
            pa->T.A[pos_a] != pb->T.A[pos_b]) {
            unsigned char ca = (pos_a < N && pa->T.A[pos_a] != '\0') ? (unsigned char)pa->T.A[pos_a] : 0;
            unsigned char cb = (pos_b < N && pb->T.A[pos_b] != '\0') ? (unsigned char)pb->T.A[pos_b] : 0;
            if (ca != cb) return (ca < cb) ? -1 : 1;
            // Если один блок закончился, двигаемся дальше
            if (pa->T.A[pos_a] == '\0') { pa = pa->next; pos_a = 0; }
            if (pb->T.A[pos_b] == '\0') { pb = pb->next; pos_b = 0; }
            continue;
        }
        // Если один из блоков закончился, переходим к следующему
        if (pa->T.A[pos_a] == '\0') { pa = pa->next; pos_a = 0; }
        if (pb->T.A[pos_b] == '\0') { pb = pb->next; pos_b = 0; }
    }
    if (pa == nullptr && pb == nullptr) return 0;
    return (pa == nullptr) ? -1 : 1;
}