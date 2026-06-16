//
// Created by Karan Nandkar on 23/05/26.
//


#include <cstdio>
#include <stdexcept>
#include <string>

class FileHandler
{
private:
    FILE* file = nullptr;

public:
    FileHandler(const char* path, const char* mode)
    {
        file = std::fopen(path, mode);
        if (!file)
        {
            throw std::runtime_error("Failed to open file");
        }
    }

    ~FileHandler()
    {
        if (file)
        {
            std::fclose(file);
        }
    }

    // prevent copying
    FileHandler(const FileHandler&) = delete;
    FileHandler& operator=(const FileHandler&) = delete;

    FileHandler(FileHandler&& other) noexcept
        : file(other.file)
    {
        other.file = nullptr;
    }

    FileHandler& operator=(FileHandler&& other) noexcept
    {
        if (this == &other) return *this;

        if (file)
            std::fclose(file);

        file = other.file;
        other.file = nullptr;

        return *this;
    }

    void Write(const std::string& text)
    {
        std::fputs(text.c_str(), file);
    }

    FILE* Get() const
    {
        return file;
    }
};
