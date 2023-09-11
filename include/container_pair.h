#include <pair.h>
#include <array.h>

#include <string>
#include <iostream>

template<class T_key, class T_value>
class Container_Pair
{

Array< pair<T_key, T_value> > _data;
t_size _count_size;
public:
    Container_Pair() = delete;
    Container_Pair(const Container_Pair& other) = delete;
    Container_Pair(t_size size): _count_size(0), _data(size) {}
    ~Container_Pair() {}
    
    Container_Pair& operator=(const Container_Pair& other) = delete;

    t_size count_size()
    {
        return this->_count_size;
    }
    
    t_size max_size()
    {
        return this->_data.size();
    }

    T_value& operator[](const T_key& search)
    {
        for(t_size i = 0; i < _data.size(); ++i)
        {
            if ( _data[i].key() == search )
                return _data[i].value();
        }
        throw std::runtime_error("Don't search your value");
    }

    void add(const pair<T_key, T_value>& for_add)
    {
        if (_count_size + 1 > _data.size())
            throw std::runtime_error("Your size is over");
        if ( !verification(for_add) )
            throw std::runtime_error("Pointed key been");
        _data[_count_size] = for_add;
        ++_count_size;
    }

private:

    bool verification(pair<T_key, T_value> pai)
    {
        for(t_size i = 0; i < _data.size(); ++i)
        {
            if ( _data[i].key() == pai.key() )
                return false;
        }
        return true;
    }

public:
    void rm(const T_key& search)
    {
        t_size save_index = -1;
        for(t_size i = 0; i < _data.size(); ++i)
        {
            if ( _data[i].key() == search )
            {
                save_index = i;
                break;
            }
        }
        if (save_index == -1)
            throw std::runtime_error("Your key is fail");
        
        for(t_size i = save_index; i < this->_count_work - 1; ++i)
            swap(this->_data[i], this->_data[i + 1]);
        --_count_size;
    }

    std::ostream& print(std::ostream& stream)
    {
        for(t_size i = 0; i < _data.size(); ++i)
        {
            stream << "\nindex: " << i << "\tkey: " << _data[i].ckey() << "\tvalue: " << _data[i].cvalue();
        }
        return stream;
    }
    
};