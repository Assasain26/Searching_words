#include <iostream>
#include <string>
#include <fstream>

using namespace std;
int countWord(string name) {
    int size = 0;
    ifstream file(name);
    while (!file.eof()) {
        string word;
        getline(file, word, ' ');
        size++;
    }
    file.close();
    return size;
}

string saveDataFile(string name, string* words, int sizeArr) {
    ifstream file(name);
    for (int i = 0; i < sizeArr; i++) {
        getline(file, words[i], ' ');
    }
    file.close();
    return *words;
}

int findWord(string name, string* words, int n) {
    int result = 0;
    string line;
    ifstream file(name);
    while (getline(file, line)) {
        for (int i = 0; i < n; i++) {
            if ((line).find((words[i])) != string::npos)
            {
                result = 1;
                break;
            }
        }
    }
    file.close();
    return result;
}

int main()
{
    string name, words[50];
    cin >> name;
    const int sizeArr = countWord(name);
    *words = saveDataFile(name, words, sizeArr);
    for (int i = 0; i < sizeArr; i++) {
        cout << words[i] << " ";
    }
    cout << "\n\n file.txt = " << findWord("file.txt", *&words, sizeArr);
    cout << "\n\n file02.txt = " << findWord("file02.txt", *&words, sizeArr);
    return 0;
}
