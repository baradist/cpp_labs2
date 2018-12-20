#ifndef LAB9_FUNCTIONS_H
#define LAB9_FUNCTIONS_H

#include <iostream>

using namespace std;

template<typename T>
inline void print_container(const T &cont) {
    cout << "Container is a : " << typeid(cont).name() << endl;
    for (typename T::const_iterator itb = cont.begin(); itb != cont.end(); ++itb) {
        cout << *itb << endl;
    }
    cout << endl;
}

template<typename T>
void print_queue_of_pointers(T q) {
    while (!q.empty()) {
        cout << *q.front() << endl;
        q.pop();
    }
    cout << '\n';
}

template<typename T>
void print_from_top(T q) {
    while (!q.empty()) {
        cout << q.top() << endl;
        q.pop();
    }
    cout << '\n';
}

typedef pair<string, pair<string, string> > T;

template<typename map_key, typename map_val>
void print_map(const map<map_key, map_val> &_map) {
    for (typename map<map_key, map_val>::const_iterator it = _map.begin(); it != _map.end(); ++it) {
        cout << it->first << " => " << it->second << '\n';
    }
}

template<typename map_key, typename map_val>
void print_map(const multimap<map_key, map_val> &_map) {
    for (typename multimap<map_key, map_val>::const_iterator it = _map.begin(); it != _map.end(); ++it) {
        cout << it->first << " => " << it->second << '\n';
    }
}

template<typename map_key, typename map_val>
void print_map_by_key(const multimap<map_key, map_val> &_map, const map_key &key) {
    for (typename multimap<map_key, map_val>::const_iterator it = _map.lower_bound(key);
         it != _map.upper_bound(key); ++it) {
        cout << it->first << " => " << it->second << '\n';
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
ostream &operator<<(ostream &os, const set<T> &set1) {
    copy(set1.begin(), set1.end(), ostream_iterator<T>(os, " "));
    return os;
}

template<typename T>
ostream &operator<<(ostream &os, const multiset<T, greater<T>> &set1) { // TODO how to generalize?
    copy(set1.begin(), set1.end(), ostream_iterator<T>(os, " "));
    return os;
}

#endif //LAB9_FUNCTIONS_H
