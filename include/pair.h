#ifndef __PAIR_H__
#define __PAIR_H__
#include <memory.h>

//Для работы данного класса должны быть перегружены операторы: суммы, сравнения у ключа и значения
template<class T_key, class T_value>
class pair
{
    mstd::shared_ptr<T_key> _key;
    mstd::shared_ptr<T_value> _value;
public:
    pair(): _key( mstd::make_shared<T_key>( T_key() ) ), _value( mstd::make_shared<T_value>( T_value() ) ) {}

    pair(T_key key, T_value value): _key( mstd::make_shared<T_key>( key ) ), _value( mstd::make_shared<T_key>( value ) ) {}

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