#include <iostream>
#include <fstream>
#include <locale>
#include "Functions.h"

int main()
{
    setlocale(LC_ALL, "Russian");
    /* Тестовые данные */
    LIST* lst1 = NULL;
    int size_lst1 = countWord("11.txt");
    lst1 = read_list(lst1, "11.txt", size_lst1);
    int otvet = findWord("22.txt", lst1, size_lst1);
    cout << otvet;
    /* Тестовые данные */
    return 0;
}
