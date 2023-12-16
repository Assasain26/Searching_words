#include "Head_List.h"

int countWord(LIST* lst)
{
    int size = 0;
    LIST* data = lst;
    while (data->word != "")
    {
        size++;
        data = data->next;
    }
    return size;
}

// Указания ссылки на Null, последнего элемента списка
LIST* do_Null_last(LIST* lst)
{
    LIST* data = lst;
    while (data->word != "")
    {
        data = data->next;
    }
    data->next = NULL;
    return lst;
}

// Сохранение элемента в конец списка.
LIST* push_back(LIST* lst, std::string word)
{
    LIST* data = lst;
    while (data->word != "")
    {
        data = data->next;
    }
    data->word = word;
    data->next = new LIST;
    return lst;
}

// Запись в список из файла, слов, разделённые пробелом и последним.
LIST* read_list(LIST* lst, std::string name_file)
{
    std::ifstream file(name_file);
    if (!file.eof())
    {
        LIST* data = lst;
        std::string words;

        if (file.is_open())
        {
            while (getline(file, words, ' '))
            {
                data = push_back(data, words);
            }
            data = do_Null_last(data);
        }

        else { std::cout << "Файл не смог открыться"; exit(10); }

        file.close();
    }

    else { std::cout << "Файл слов пустой"; exit(1); }

    return lst;
}

// Запись списка в файл, поэлементно, с новой строки.
void write_list(LIST* lst, std::string name_file, int size)
{
    std::fstream file(name_file, std::ios::out);
    if (file.is_open())
    {
        LIST* data = lst;
        for (int i = 0; i < size; i++)
        {
            file << (data->word);
            data = data->next;
            if ((size - 1) != i)
            {
                file << "\n";
                file << "__________________________________________________________\n";
            }
        }
        data = lst;
    }
    file.close();
}

// Функция поиска слов в заданном файле.
std::string findWord(LIST* lst, std::string name_file, int size) {
    std::string result = "";
    std::string line;
    std::ifstream file(name_file);
    if (file.is_open())
    {
        LIST* data = lst, * fol = data->next;

        while (std::getline(file, line)) {
            for (int i = 0; i < size; i++) {
                if ((line).find((data->word)) != std::string::npos)
                {
                    result = result + data->word;
                    break;
                }
                data = data->next;
                if (fol) { fol = fol->next; }
                else { break; };
            }
            data = lst;
            fol = data->next;
            if (result != "") { break; }
        }
    }
    else { std::cout << "Файл исчез во время работы"; exit(15); }
    file.close();
    return result;
}