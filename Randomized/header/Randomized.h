#ifndef RANDOM_HPP
#define RANDOM_HPP

#include <random>
#include <stdexcept>
#include <type_traits>
#include <memory>

class Random {
    std::mt19937 engine;
public:
    Random() : engine(std::random_device{}()) {}

    template <typename T>
    typename std::enable_if<std::is_integral<T>::value, T>::type
    operator()(T min, T max) {
        if (min > max) throw std::invalid_argument("Random: min > max");
        std::uniform_int_distribution<T> dist(min, max);
        return dist(engine);
    }

    template <typename T>
    typename std::enable_if<std::is_floating_point<T>::value, T>::type
    operator()(T min, T max) {
        if (min > max) throw std::invalid_argument("Random: min > max");
        std::uniform_real_distribution<T> dist(min, max);
        return dist(engine);
    }
};

#endif
