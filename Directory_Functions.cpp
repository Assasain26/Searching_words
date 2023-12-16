#include "Head_List.h"
#include "Head_Directory.h"

// Функция записи пути файла в список.
LIST* fillFiles(const std::string& DirPath, LIST* Files, short depth = 0)
{
    if (DirPath.empty() != true)
    {
        for (auto& path : std::filesystem::directory_iterator
            (DirPath, std::filesystem::directory_options::skip_permission_denied))
        {
            std::string path_string = path.path().string();
            if (path.is_directory() && depth)
            {
                Files = fillFiles(path_string, Files, depth - 1);
            }
            else if (path_string.find(".txt") != std::string::npos)
            {
                Files = push_back(Files, path_string);
            }
        }
        Files = do_Null_last(Files);
    }
    return Files;
}
