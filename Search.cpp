#include <locale>
#include "Functions.h"

int main()
{
    setlocale(LC_ALL, "Russian");


    string path_search;
    cout << "Введите путь поиска: ";
    cin >> path_search;
    

    short depth = 0;
    while ((depth <= 0) || (depth > 5))
    {
        cout << "Введите глубину поиска (0 < x < 6): ";
        cin >> depth;
        if (depth <= 0)
        {
            cout << "Глубина должна быть больше 0!\n\n";
        }
        if (depth > 5)
        {
            cout << "Глубина должна быть меньше 5!\n\n";
        }
    }


    string file_words;
    cout << "Введите файл слов: ";
    cin >> file_words; // 11.txt
    if_exist(file_words);

    

    /* Тестовые данные */
    LIST* lst1 = NULL;
    int size_lst1 = countWord(file_words);
    lst1 = read_list(lst1, file_words, size_lst1);
    int otvet = findWord(lst1, "22.txt", size_lst1);
    cout << otvet;
    /* Тестовые данные */


    string file_output;
    cout << "Введите файл вывода: ";
    cin >> file_output; // 33.txt
    write_list(lst1, file_output, size_lst1);

    return 0;
}
