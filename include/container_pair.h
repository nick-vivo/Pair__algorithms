#include <pair.h>

#include <string>
#include <iostream>
#include <list.h>
#include <exception.h>

template<class T_key, class T_value>
class Container_Pair
{

using t_size = int;

List< pair<T_key, T_value> > _data;

public:
    Container_Pair(): _data() {}
    Container_Pair(const Container_Pair& other) = delete;
    ~Container_Pair() {}
    
    Container_Pair& operator=(const Container_Pair& other) = delete;

    t_size size()
    {
        return _data.size();
    }

    T_value& operator[](const T_key& search)
    {
        for(t_size i = 0; i < _data.size(); ++i)
        {
            if ( _data[i].key() == search )
                return _data[i].value();
        }
        throw mstd::exception("Don't search your value");
    }

    void add(const pair<T_key, T_value>& for_add)
    {
        if ( !verification(for_add) )
            throw std::runtime_error("Pointed key been");
        _data.push_back(for_add);
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

    std::ostream& print(std::ostream& stream)
    {
        for(t_size i = 0; i < _data.size(); ++i)
        {
            stream << "\nindex: " << i << "\tkey: " << _data[i].ckey() << "\tvalue: " << _data[i].cvalue();
        }
        return stream;
    }
    
};