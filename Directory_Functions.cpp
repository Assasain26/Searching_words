#include "Head_List.h"
#include "Head_Directory.h"

typedef map<string, WIN32_FIND_DATAA> FilesMap;


LIST* fillFiles(string mDirPath, LIST* mFiles) {
    if (mDirPath.empty() != true) 
    {
        FilesMap::value_type::second_type fmap;
        HANDLE hFind = FindFirstFileA(string(mDirPath + "\\*.txt").c_str(), &fmap);
        if (INVALID_HANDLE_VALUE != hFind)
            mFiles = new LIST;
            LIST* data = mFiles;
            do {
                if (fmap.dwFileAttributes != FILE_ATTRIBUTE_DIRECTORY) {
                     data->word = fmap.cFileName;
                     data->next = new LIST;
                     data = data->next;
                }
            } while (NULL != FindNextFileA(hFind, &fmap));
            data->next = NULL;
            FindClose(hFind);
    }
     return mFiles;
}
