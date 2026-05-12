#include "defstr.h"
#include <cstring>   // <-- важно

void inp_str(str& s, std::istream& in) {
    int i = 0;
    char c;
    while (i < N - 1 && in.peek() != EOF && in.peek() != ' ' &&
        in.peek() != '\t' && in.peek() != '\n' && in.peek() != '\r') {
        in.get(c);
        s.A[i++] = c;
    }
    s.A[i] = '\0';
}

void out_str(const str& s, std::ostream& out) {
    for (int i = 0; i < N && s.A[i] != '\0'; ++i) {
        out << s.A[i];
    }
}

int cmp_str(const str& a, const str& b) {
    return std::strcmp(a.A, b.A);
}