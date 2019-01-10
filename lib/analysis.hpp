#include<chrono>

namespace analysis
{

    void print_array(int *a, int N);
    void random_number_array(int *a, int N);

    template<typename func, typename ...Types>
    int measure_time(func *f, Types... args)
    /*
    Measures execution time of a function in nanoseconds
    */
    {
        auto start = std::chrono::system_clock::now();

        f(std::forward<Types>(args)...);

        auto end = std::chrono::system_clock::now();
        auto exect = std::chrono::duration_cast<std::chrono::nanoseconds>(end-start).count();
        return exect;
    }
}