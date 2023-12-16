The Search program is launched from the console. Input parameters: Path, input file, Search depth and output file.

The input file consists of words that are separated by a space and the last element too.
Path - the directory in which the search is performed.
The search depth is the value that determines which folder tree will be built.
Output file - File with test results.

After all the parameters have been entered, the program will search for words from the input file, in all folders, in text files.
If at least one word can be found, the program stops searching in this file and writes 
the value 1 - that is, a positive result. Otherwise negative. There are many checks for bad input data.

Features: Uses the <filesystem> library, which is only available with the C++17 language version.
