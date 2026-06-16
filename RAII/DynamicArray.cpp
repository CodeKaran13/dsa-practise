//
// Created by Karan Nandkar on 31/05/26.
//


/**
 * Implement rule of 5
 */

#include <vector>

class DynamicArray
{
private:
    int* data;
    size_t size;

public:
    // Default constructor
    DynamicArray() : data(nullptr), size(0) {}

    // Constructor with size
    DynamicArray(size_t newSize)
        : data(new int[newSize]{}), size(newSize)
    {}

    // Destructor
    ~DynamicArray()
    {
        delete[] data;
    }

    // Copy constructor - deep copy
    DynamicArray(const DynamicArray& other)
        : data(nullptr), size(other.size)
    {
        if (size > 0)
        {
            data = new int[size];
            std::copy(other.data, other.data + size, data);
        }
    }

    // Copy assignment operator - deep copy
    DynamicArray& operator=(const DynamicArray& other)
    {
        if (this == &other)
            return *this;

        int* newData = nullptr;

        if (other.size > 0)
        {
            newData = new int[other.size];
            std::copy(other.data, other.data + other.size, newData);
        }

        delete[] data;

        data = newData;
        size = other.size;

        return *this;
    }

    // Move constructor
    DynamicArray(DynamicArray&& other) noexcept
        : data(other.data), size(other.size)
    {
        other.data = nullptr;
        other.size = 0;
    }

    // Move assignment operator
    DynamicArray& operator=(DynamicArray&& other) noexcept
    {
        if (this == &other)
            return *this;

        delete[] data;

        data = other.data;
        size = other.size;

        other.data = nullptr;
        other.size = 0;

        return *this;
    }

    size_t Size() const
    {
        return size;
    }

    int& operator[](size_t index)
    {
        return data[index];
    }

    const int& operator[](size_t index) const
    {
        return data[index];
    }
};
