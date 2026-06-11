//
// Created by Karan Nandkar on 23/05/26.
//


#include <cstdio>

class FileHandler
{
private:
    FILE* file;

public:
    FileHandler(const char* path)
    {
        file = fopen(path, "r");
    }

    ~FileHandler()
    {
        if (file)
        {
            fclose(file);
        }
    }
};
