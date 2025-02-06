#include <iostream>
#include <vector>
#include <algorithm>

class MinFunctor {
public:
    int operator()(const std::vector<int>& vec) {
        return *std::min_element(vec.begin(), vec.end());
    }
};

class MaxFunctor {
public:
    int operator()(const std::vector<int>& vec) {
        return *std::max_element(vec.begin(), vec.end());
    }
};

class SortDescendingFunctor {
public:
    void operator()(std::vector<int>& vec) {
        std::sort(vec.begin(), vec.end(), std::greater<int>());
    }
};

class SortAscendingFunctor {
public:
    void operator()(std::vector<int>& vec) {
        std::sort(vec.begin(), vec.end());
    }
};

class IncreaseFunctor {
private:
    int _value;
public:
    IncreaseFunctor(int value) : _value(value) {}

    void operator()(std::vector<int>& vec) {
        std::transform(vec.begin(), vec.end(), vec.begin(),
            [this](int x) { return x + _value; });
    }
};

class DecreaseFunctor {
private:
    int _value;
public:
    DecreaseFunctor(int value) : _value(value) {}

    void operator()(std::vector<int>& vec) {
        std::transform(vec.begin(), vec.end(), vec.begin(),
            [this](int x) { return x - _value; });
    }
};

class RemoveFunctor {
private:
    int _value;
public:
    RemoveFunctor(int value) : _value(value) {}

    void operator()(std::vector<int>& vec) {
        vec.erase(
            std::remove(vec.begin(), vec.end(), _value),
            vec.end()
        );
    }
};

void printVector(const std::vector<int>& vec) {
    for (int x : vec) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> numbers = { 5, 2, 8, 1, 9, 3, 7, 4, 6 };

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
    printVector(numbers);

    return 0;
}