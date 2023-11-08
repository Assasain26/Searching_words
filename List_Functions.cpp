#include "Head_List.h"

void if_exist(string name_file)
{
    ifstream file(name_file);
    if (!file.is_open())
    {
        cout << "Файл отсутствует"; 
        exit(1);
    }
    file.close();
}

int countWord(string name_file) 
{
    int size = 0;
    ifstream file(name_file);
    if (file.is_open())
    {
        if (sizeof(file) != 0)
        {
            string words;
            while (getline(file, words, ' '))
            {
                size++;
            }
        }
    }
    else { cout << "Файл отсутствует"; exit(1); }
    file.close();
    return size;
}

LIST* read_list(LIST* lst, string name_file, int size)
{
    if (size != 0)
    {
        LIST* data;
        string words;
        ifstream file(name_file);

        if (file.is_open())
        {
            lst = new LIST;
            data = lst;
            getline(file, words, ' ');
            data->word = words;
            while (getline(file, words, ' '))
            {
                data->next = new LIST;
                data = data->next;
                data->word = words;
            }
            data->next = NULL;
        }

        else { cout << "Файл отсутствует"; exit(1); }

        file.close();

    }

    else { cout << "Файл пустой"; exit(1); }

    return lst;
}

void write_list(LIST* lst, string name_file, int size)
{
    fstream file(name_file, ios::out);
    if (file.is_open())
    {
        LIST* data = lst;
        for (int i = 0; i < size; i++)
        {
            file << (data->word);
            data = data->next;
            if ((size - 1) != i)
            {
                file << " ";
            }
        }
        data = lst;
    }
    else { cout << "Файл отсутствует"; exit(1); }
    file.close();
}

int findWord(LIST* lst, string name_file, int size) {
    int result = 0;
    string line;
    ifstream file(name_file);
    if (file.is_open())
    {
        LIST* data = lst, * fol = data->next;

        while (getline(file, line)) {
            for (int i = 0; i < size; i++) {
                if ((line).find((data->word)) != string::npos)
                {
                    result = 1;
                    break;
                }
                data = data->next;
                if (fol) { fol = fol->next; }
                else { break; };
            }
            data = lst;
            fol = data->next;
            if (result) { break; }
        }
    }
    else { cout << "Файл отсутствует"; exit(1); }
    file.close();
    return result;
}