#pragma once
#include <iostream>
#include <fstream>
#include <string>

struct LIST { std::string word; LIST* next; };

int countWord(LIST* lst);

void if_exist(std::string name_file);

LIST* push_back(LIST* lst, std::string word);

LIST* do_Null_last(LIST* lst);

LIST* read_list(LIST* lst, std::string name_file);

void write_list(LIST* lst, std::string name_file, int size);

int findWord(LIST* lst, std::string name_file, int size);