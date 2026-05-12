#include "deff_v.h"
#include <iostream>
#include <fstream>

using namespace std;

int main() {
    setlocale(LC_ALL, "ru");

    const char* in1f = "C:\\Users\\Анечка\\Documents\\4\\in1.txt";
    const char* in2f = "C:\\Users\\Анечка\\Documents\\4\\in2.txt";
    const char* outf = "C:\\Users\\Анечка\\Documents\\4\\out.txt";
    

    f_v l1, l2, l3;
    l1.h = l1.t = nullptr; l1.L = 0;
    l2.h = l2.t = nullptr; l2.L = 0;
    l3.h = l3.t = nullptr; l3.L = 0;

    inp_f_v(l1, in1f);
    inp_f_v(l2, in2f);

    symmetric_difference(l3, l1, l2);

    ofstream fout(outf);
    if (fout.is_open()) {
        fout << "l1 = R(S1):\n";
        out_f_v(l1, fout);
        fout << "\nl2 = R(S2):\n";
        out_f_v(l2, fout);
        fout << "\nl3 = R(S3):\n";
        out_f_v(l3, fout);
        fout.close();
    }

    free_f_v(l1);
    free_f_v(l2);
    free_f_v(l3);

    return 0;
}