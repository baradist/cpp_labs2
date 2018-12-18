#ifndef LAB9_FUNCTIONS_H
#define LAB9_FUNCTIONS_H

#include <iostream>

using namespace std;

template<typename T>
inline void printContainer(const T &cont) {
    std::cout << "Container is a : " << typeid(cont).name() << std::endl;
    for (typename T::const_iterator itb = cont.begin(); itb != cont.end(); ++itb) {
        std::cout << *itb << std::endl;
    }
    std::cout << std::endl;
}

template<typename T>
void
print_queue(T q) {
    while (!q.empty()) {
        cout << q.top() << " ";
        q.pop();
    }
    std::cout << '\n';
}

typedef std::pair<string, std::pair<string, string> > T;

template<typename map_key, typename map_val>
void print_map(const std::map<map_key, map_val> &_map) {
    for (typename std::map<map_key, map_val>::const_iterator it = _map.begin(); it != _map.end(); ++it) {
        std::cout << it->first << " => " << it->second << '\n';
    }
}

// // ambiguous-function
//template<typename FROM, typename TO>
//void copy(FROM first, FROM last, TO to) {
//    for ( ; first != last; ++first, ++to) {
//        *to = *first;
//    }
//};

template<typename T>
std::ostream &operator<<(std::ostream &os, const std::set<T> &set1) {
    copy(set1.begin(), set1.end(), ostream_iterator<T>(os, " "));
    return os;
}

template<typename T>
std::ostream &operator<<(std::ostream &os, const std::multiset<T> &set1) {
    copy(set1.begin(), set1.end(), ostream_iterator<T>(os, " "));
    return os;
}

#endif //LAB9_FUNCTIONS_H
