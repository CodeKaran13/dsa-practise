//
// Created by Karan Nandkar on 23/05/26.
//


#include <cstddef>

class Buffer
{
private:
    int* data;
    std::size_t size;

public:
    Buffer(std::size_t s)
    {
        size = s;
        data = new int[size];
    }

    ~Buffer()
    {
        delete[] data;
    }

    // Move constructor
    Buffer(Buffer& other) noexcept
    {
        data = other.data;
        size = other.size;

        other.data = nullptr;
        size = 0;
    }
};
