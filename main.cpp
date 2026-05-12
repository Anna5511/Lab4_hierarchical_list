#include "deff_v.h"
#include <fstream>
#include <iostream>

int main() {
    setlocale(LC_ALL, "ru");

    f_v l1, l2, l3;
    inp_f_v(l1, "C:\\Users\\Анечка\\Documents\\4\\in1.txt");
    inp_f_v(l2, "C:\\Users\\Анечка\\Documents\\4\\in2.txt");

    symmetric_difference_f_v(l1, l2, l3);

    std::ofstream fout("C:\\Users\\Анечка\\Documents\\4\\out.txt");
    if (!fout) {
        std::cerr << "Ошибка открытия входного файла\n";
        free_f_v(l1);
        free_f_v(l2);
        free_f_v(l3);
        return 1;
    }

    fout << "Исходный список 1 (S1):\n";
    out_f_v(l1, fout);
    fout << "\nИсходный список 2 (S2):\n";
    out_f_v(l2, fout);
    fout << "\nСимметрическая разность S3:\n";
    out_f_v(l3, fout);

    free_f_v(l1);
    free_f_v(l2);
    free_f_v(l3);
    return 0;
}