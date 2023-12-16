#include <locale>
#include "Head_List.h" // Функции со списком
#include "Head_Directory.h" // Функции работа с директориями

// Процедура проверки существования файла
void if_exist(std::string name_file)
{
    std::ifstream file(name_file);
    if (!file.is_open())
    {
        std::cout << "Файл отсутствует";
        exit(1);
    }
    file.close();
}

int main()
{
    setlocale(LC_ALL, "Russian");


    std::string path_search;
    std::cout << "Введите путь поиска: "; 
    std::cin >> path_search; // A:\tests_1
    

    short depth = 0;
    while ((depth <= 0) || (depth > 5))
    {
        std::cout << "Введите глубину поиска (0 < x < 6): ";
        std::cin >> depth;
        if (depth <= 0)
        {
            std::cout << "Глубина должна быть больше 0!\n\n";
        }
        if (depth > 5)
        {
            std::cout << "Глубина должна быть меньше 5!\n\n";
        }
    }
    depth = depth - 1; // 0, 1, 2, ..., n


    std::string name_file_words;
    std::cout << "Введите файл слов: ";
    std::cin >> name_file_words; // A://tests_1/words.txt
    if_exist(name_file_words);


    // Чтение слов из файла, в котором слова отделены пробелом и последнее тоже.
    LIST* lst_words = NULL;
    lst_words = new LIST;
    lst_words = read_list(lst_words , name_file_words);
    int size_lst_words = countWord(lst_words);


    // Запись в список всех txt файлов, с заданной глубиной
    LIST* list_dirs = NULL;
    list_dirs = new LIST;
    list_dirs = fillFiles(path_search, list_dirs, depth); 
    int size_lst_dirs = countWord(list_dirs);


    // Результат проверки совпадений слов в txt файлов.
    LIST* dirs = list_dirs;
    while (dirs->word != "")
    {
        std::string otvet = findWord(lst_words, dirs->word, size_lst_words);
        if (otvet != "")
        {
            dirs->word = dirs->word + " - ИМЕЕТ слово: " + otvet;
        }
        else
        {
            dirs->word = dirs->word + " - НЕ ИМЕЕТ искомые слова";
        }
        dirs = dirs->next;
    }

    
    // Вывод в файл.
    std::string file_output;
    std::cout << "Введите файл вывода: ";
    std::cin >> file_output; // test.txt
    write_list(list_dirs, file_output, size_lst_dirs);

    std::cout << "\nФайл был успешно записан!\n";

    return 0;
}
