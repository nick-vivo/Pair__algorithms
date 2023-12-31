#ifndef __ARRAY_H__
#define __ARRAY_H__


#include <stdexcept>
using t_size = int;

template<class T_data>
class Array
{
    t_size _size;
    T_data* _data;
public:
    Array(): _data(nullptr), _size(0) {}

    Array(const Array& other): _size( other._size ), _data( new T_data[ _size ] ) 
    {
        for ( t_size i = 0; i < this->_size; ++i )
        {
            this->_data[i] = other._data[i]; 
        }
    } 

    Array(t_size size): _size(size), _data( new T_data[ _size ] ) {}

    virtual ~Array()
    {
        delete[] _data;
    }

    Array& operator=(const Array& other)
    {
        if (this->_data)
            delete[] _data;
        this->_size = other._size;

        this->_data = new T_data[this->_size];
        
        for ( t_size i = 0; i < this->_size; ++i )
        {
            this->_data[i] = other._data[i]; 
        }
    }

    inline T_data& operator[](t_size index)
    {
        if (index >= this->_size || index < 0)
        {
            throw std::runtime_error("Index of array is fail");
        }
        return *(_data + index);
    }
    
    inline t_size size() const noexcept
    {
        return this->_size;
    }
};

#endif