
#ifndef LAB8_FUNCTIONS_H
#define LAB8_FUNCTIONS_H

#include <vector>

template<typename T>
void printVectorParameters(std::ostream &os, std::vector<T> vector) {
    os << "size(): " << vector.size()
       << ", capacity(): " << vector.capacity()
       << ", max_size(): " << vector.max_size() << std::endl;
    for (int i = 0; i < vector.size(); ++i) {
        os << "vector[" << i << "]: " << vector[i] << std::endl;
    }
    os << std::endl;
}

template<typename T>
void removeDuplicates(std::vector<T> &v) {
    for (typename std::vector<T>::iterator itb = v.begin(); itb != v.end() && (itb + 1) != v.end(); ++itb) {
        for (typename std::vector<T>::iterator internal = itb + 1; internal != v.end();) {
            if (*itb == *internal) {
                internal = v.erase(internal);
            } else {
                ++internal;
            }
        }
    }
}

void insertFirstIfDoesntContain(std::vector<char> &v, char c) {
    auto itb = v.begin();
    for (; itb != v.end(); ++itb) {
        if (*itb == c) {
            return;
        }
    }
    v.insert(v.begin(), c);
}

template<typename T>
inline void printContainer(const T &cont) {
    std::cout << "Container is a : " << typeid(cont).name() << std::endl;
    for (typename T::const_iterator itb = cont.begin(); itb != cont.end(); ++itb) {
        std::cout << *itb << std::endl;
    }
    std::cout << std::endl;
}

#endif //LAB8_FUNCTIONS_H
