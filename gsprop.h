#pragma once

#include <functional>

template<typename T>
class GSProperty {
private:
        T value;
        
        std::function<T(const T&)> setter;
        std::function<T(const T&)> getter;
public:
        explicit GSProperty(
                T value,
                std::function<T(const T&)> s = [](const T& val) { return val; },
                std::function<T(const T&)> g = [](const T& val) { return val; }
        ) : value(value), setter(std::move(s)), getter(std::move(g)) {}
        
        operator T() const {
                return getter(value);
        }
        
        T& operator=(const T& newValue) {
                value = setter(newValue);
                return value;
        }
        
        GSProperty& operator=(const GSProperty& other) {
                if (this != &other) value = setter(static_cast<T>(other));
                return *this;
        }
};