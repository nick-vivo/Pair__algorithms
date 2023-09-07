#ifndef __PAIR_H__
#define __PAIR_H__
#include <memory.h>

//Для работы данного класса должны быть перегружены операторы: суммы, сравнения
template<typename T_key, typename T_value>
class pair
{
private:
mstd::shared_ptr<T_key> _key;
mstd::shared_ptr<T_value> _value; 

public:
pair() = delete;

pair(T_key key, T_value value): _key( mstd::make_shared(key) ), _value( mstd::make_shared(value) ) {}

~pair() {}

T_key& key()
{
    return this->_key.operator*();
}

T_value& value()
{
    return this->_value.operator*();
}

};

#endif