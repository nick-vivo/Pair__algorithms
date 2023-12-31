#ifndef ___PAIR_H__
#define __PAIR_H__
#include <memory>

//Для работы данного класса должны быть перегружены операторы: суммы, сравнения, swap в std::swap, присваивание
template<class T_key, class T_value>
class pair
{
    std::shared_ptr<T_key> _key;
    std::shared_ptr<T_value> _value;

public:

    pair(): _key( std::make_shared<T_key>( T_key() ) ), _value( std::make_shared<T_value>( T_value() ) ) {}

    pair(T_key key, T_value value): _key( std::make_shared<T_key>( key ) ), _value( std::make_shared<T_value>( value ) ) {}

    pair(const pair& other): _key( std::make_shared<T_key>( other._key.operator*() ) ), _value( std::make_shared<T_value>( other._value.operator*() ) ) {}

    ~pair() {}

    pair& operator=(const pair& other)
    {
        this->_key.operator*() = other._key.operator*();
        this->_value.operator*() = other._value.operator*();
        return *this;
    }

    pair operator+(const pair& other)
    {
        pair<T_key, T_value> sum;
        sum._key.operator*() = this->_key.operator*() + other._key.operator*();
        sum._value.operator*() = this->_value.operator*() + other._value.operator*();
        return sum;
    }

    pair& operator+=( const pair& other )
    {
        this->_key.operator*() = this->_key.operator*() + other._key.operator*();
        this->_value.operator*() = this->_value.operator*() + other._value.operator*();
        return *this;
    }

    bool operator==(const pair& other)
    {
        if (this->_key.operator*() == other._key.operator*() && this->_value.operator*() == other._value.operator*() )
            return true;
        return false;
    }

    T_key& key() noexcept
    {
        return this->_key.operator*();
    }

    T_value& value() noexcept
    {
        return this->_value.operator*();
    }

    T_key ckey() const noexcept
    {
        return this->_key.operator*();
    }

    T_value cvalue() const noexcept
    {
        return this->_value.operator*();
    }

    static void swap(pair<T_key, T_value> first, pair<T_key, T_value> second)
    {
        std::swap(first.key(), second.key());
        std::swap(first.value(), second.value());
    }

};


#endif