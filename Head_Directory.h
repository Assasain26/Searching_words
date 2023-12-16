#pragma once
#include "Head_List.h"
#include <filesystem>

LIST* fillFiles(const std::string& DirPath, LIST* Files, short depth);