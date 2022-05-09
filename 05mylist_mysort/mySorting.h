#include <iterator>
#include <array>
#include <vector>
#include <algorithm> 

template<typename Container>
void mySort(Container& values) {

    auto begin = std::begin(values);
    auto end = std::end(values);

    std::sort(begin, end);
}
