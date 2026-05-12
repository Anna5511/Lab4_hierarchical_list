#include "deff_v.h"
#include <iostream>
#include <fstream>
#include <locale>

using namespace std;

int main() {
    setlocale(LC_ALL, "ru");

    // Используем относительные пути (файлы должны лежать в папке с программой)
    const char* in1f = "C:\\Users\\Анечка\\Documents\\4\\in1.txt";
    const char* in2f = "C:\\Users\\Анечка\\Documents\\4\\in2.txt";
    const char* outf = "C:\\Users\\Анечка\\Documents\\4\\out.txt";

    f_v l1, l2, l3;
    init_f_v(l1);
    init_f_v(l2);
    init_f_v(l3);

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
        cout << "Результат записан в " << outf << endl;
    }
    else {
        cerr << "Ошибка: не удалось открыть output.txt" << endl;
    }

    free_f_v(l1);
    free_f_v(l2);
    free_f_v(l3);

    return 0;
}