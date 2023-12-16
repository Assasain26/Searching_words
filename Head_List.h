#pragma once
#include <iostream>
#include <fstream>
#include <string>

struct LIST { std::string word; LIST* next; };

int countWord(LIST* lst);

LIST* push_back(LIST* lst, std::string word);

LIST* do_Null_last(LIST* lst);

LIST* read_list(LIST* lst, std::string name_file);

void write_list(LIST* lst, std::string name_file, int size);

std::string findWord(LIST* lst, std::string name_file, int size);