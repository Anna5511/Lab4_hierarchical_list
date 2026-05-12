#include "deff_v.h"
#include "defel_v.h"
#include "deff_g.h"

void init_f_v(f_v& lst) {
    lst.h = lst.t = nullptr;
    lst.L = 0;
}

void inp_f_v(f_v& lst, const char* filename) {
    init_f_v(lst);
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "ќшибка открыти€ файла: " << filename << std::endl;
        return;
    }

    while (true) {
        // пропускаем пробелы и табул€ции
        while (file.peek() == ' ' || file.peek() == '\t')
            file.get();

        if (file.eof()) break;

        el_v* node = nullptr;
        inp_el_v(node, file);
        if (!node) break;

        if (!lst.h) lst.h = node;
        else lst.t->next = node;
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

// —имметрическа€ разность двух упор€доченных множеств (вертикальные списки)
void symmetric_difference(f_v& result, const f_v& l1, const f_v& l2) {
    free_f_v(result);
    const el_v* p1 = l1.h;
    const el_v* p2 = l2.h;
    el_v** tail = &result.h;

    while (p1 && p2) {
        int cmp = cmp_f_g(p1->f, p2->f);
        if (cmp < 0) {
            el_v* node = new el_v;
            copy_f_g(node->f, p1->f);
            node->next = nullptr;
            *tail = node;
            tail = &node->next;
            result.L++;
            p1 = p1->next;
        }
        else if (cmp > 0) {
            el_v* node = new el_v;
            copy_f_g(node->f, p2->f);
            node->next = nullptr;
            *tail = node;
            tail = &node->next;
            result.L++;
            p2 = p2->next;
        }
        else { // равны Ц пропускаем оба
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
        result.L++;
        p1 = p1->next;
    }

    while (p2) {
        el_v* node = new el_v;
        copy_f_g(node->f, p2->f);
        node->next = nullptr;
        *tail = node;
        tail = &node->next;
        result.L++;
        p2 = p2->next;
    }

    result.t = (result.h ? *tail : nullptr);
}