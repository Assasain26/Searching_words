#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

typedef unsigned char uchar;
typedef unsigned short ushort;

struct LIST { string word; LIST* next; };

int countWord(string name_file);

void if_exist(string name_file);

LIST* read_list(LIST* lst, string name_file, int size);

void write_list(LIST* lst, string name_file, int size);

int findWord(LIST* lst, string name_file, int size);