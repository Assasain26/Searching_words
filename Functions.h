#pragma once
#include <string>

using namespace std;

struct LIST { string word; LIST* next; };

int countWord(string name_file);

LIST* read_list(LIST* lst, string name_file, int size);

void write_list(LIST* lst, string name_file, int size);

int findWord(string name_file, LIST* words, int size);