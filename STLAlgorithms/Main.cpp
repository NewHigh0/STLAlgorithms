#include <iostream>
#include <vector>
#include <algorithm>

template<typename Container>
class MinFunctor {
public:
    auto operator()(const Container& vec) {
        return *std::min_element(vec.begin(), vec.end());
    }
};

template<typename Container>
class MaxFunctor {
public:
    auto operator()(const Container& vec) {
        return *std::max_element(vec.begin(), vec.end());
    }
};

template<typename Container>
class SortDescendingFunctor {
public:
    void operator()(Container& vec) {
        std::sort(vec.begin(), vec.end(), std::greater<typename Container::value_type>());
    }
};

template<typename Container>
class SortAscendingFunctor {
public:
    void operator()(Container& vec) {
        std::sort(vec.begin(), vec.end());
    }
};

template<typename Container>
class IncreaseFunctor {
private:
    typename Container::value_type _value;
public:
    IncreaseFunctor(typename Container::value_type value) : _value(value) {}

    void operator()(Container& vec) {
        std::transform(vec.begin(), vec.end(), vec.begin(),
            [this](auto x) { return x + _value; });
    }
};

template<typename Container>
class DecreaseFunctor {
private:
    typename Container::value_type _value;
public:
    DecreaseFunctor(typename Container::value_type value) : _value(value) {}

    void operator()(Container& vec) {
        std::transform(vec.begin(), vec.end(), vec.begin(),
            [this](auto x) { return x - _value; });
    }
};

template<typename Container>
class RemoveFunctor {
private:
    typename Container::value_type _value;
public:
    RemoveFunctor(typename Container::value_type value) : _value(value) {}

    void operator()(Container& vec) {
        vec.erase(
            std::remove(vec.begin(), vec.end(), _value),
            vec.end()
        );
    }
};

template<typename Container>
void printVector(const Container& vec) {
    for (const auto& x : vec) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
}

int main() {
    /*std::vector<int> numbers = { 5, 2, 8, 1, 9, 3, 7, 4, 6 };

    std::cout << "Original vector: ";
    printVector(numbers);

    MinFunctor minFunc;
    std::cout << "Minimum value: " << minFunc(numbers) << std::endl;

    MaxFunctor maxFunc;
    std::cout << "Maximum value: " << maxFunc(numbers) << std::endl;

    SortDescendingFunctor sortDescFunc;
    sortDescFunc(numbers);
    std::cout << "Sorted descending: ";
    printVector(numbers);

    SortAscendingFunctor sortAscFunc;
    sortAscFunc(numbers);
    std::cout << "Sorted ascending: ";
    printVector(numbers);

    IncreaseFunctor increaseFunc(3);
    increaseFunc(numbers);
    std::cout << "Increased by 3: ";
    printVector(numbers);

    DecreaseFunctor decreaseFunc(2);
    decreaseFunc(numbers);
    std::cout << "Decreased by 2: ";
    printVector(numbers);

    RemoveFunctor removeFunc(5);
    removeFunc(numbers);
    std::cout << "After removing 5: ";
    printVector(numbers);*/

    std::vector<int> intNumbers = { 5, 2, 8, 1, 9, 3, 7, 4, 6 };
    std::cout << "Integer Vector Operations:\n";
    printVector(intNumbers);

    MinFunctor<std::vector<int>> minIntFunc;
    std::cout << "Minimum int: " << minIntFunc(intNumbers) << std::endl;

    MaxFunctor<std::vector<int>> maxIntFunc;
    std::cout << "Maximum int: " << maxIntFunc(intNumbers) << std::endl;

    SortDescendingFunctor<std::vector<int>> sortDescIntFunc;
    sortDescIntFunc(intNumbers);
    std::cout << "Sorted int descending: ";
    printVector(intNumbers);

    std::vector<float> floatNumbers = { 5.5f, 2.3f, 8.1f, 1.7f, 9.2f, 3.6f, 7.4f, 4.9f, 6.2f };
    std::cout << "\nFloat Vector Operations:\n";
    printVector(floatNumbers);

    MinFunctor<std::vector<float>> minFloatFunc;
    std::cout << "Minimum float: " << minFloatFunc(floatNumbers) << std::endl;

    MaxFunctor<std::vector<float>> maxFloatFunc;
    std::cout << "Maximum float: " << maxFloatFunc(floatNumbers) << std::endl;

    SortAscendingFunctor<std::vector<float>> sortAscFloatFunc;
    sortAscFloatFunc(floatNumbers);
    std::cout << "Sorted float ascending: ";
    printVector(floatNumbers);

    std::vector<double> doubleNumbers = { 5.55, 2.33, 8.11, 1.77, 9.22, 3.66, 7.44, 4.99, 6.22 };
    std::cout << "\nDouble Vector Operations:\n";
    printVector(doubleNumbers);

    IncreaseFunctor<std::vector<double>> increaseDoubleFunc(0.5);
    increaseDoubleFunc(doubleNumbers);
    std::cout << "Increased double by 0.5: ";
    printVector(doubleNumbers);

    DecreaseFunctor<std::vector<double>> decreaseDoubleFunc(0.3);
    decreaseDoubleFunc(doubleNumbers);
    std::cout << "Decreased double by 0.3: ";
    printVector(doubleNumbers);

    return 0;
}