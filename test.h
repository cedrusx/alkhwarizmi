#include <iostream>
#include <vector>

class Test {
public:
    static void test(std::vector<int> (*func)(std::vector<int>),
              std::vector<std::vector<int>> testcases)
    {
        for (auto &tc : testcases) {
            std::cout << "\nTestcase: ";
            output(tc);
            auto res = (*func)(tc);
            std::cout << "  Result: ";
            output(res);
        }
    }

private:
    static void output(std::vector<int> &arr)
    {
        std::cout << "[";
        for (auto ele : arr)
            std::cout << ele << ",";
        if (!arr.empty())
            std::cout << "\b";
        std::cout << "]" << std::endl;
    }
};