#ifndef LAB9_FUNCTIONS_H
#define LAB9_FUNCTIONS_H

#include <iostream>
#include <string>

using namespace std;

template<typename T>
inline void print_container(const T &cont) {
    cout << "Container is a : " << typeid(cont).name() << endl;
    for (typename T::const_iterator itb = cont.begin(); itb != cont.end(); ++itb) {
        cout << *itb << endl;
    }
    cout << endl;
}

template<typename Ad> 
const typename Ad::value_type& Get(const Ad& a) {
	return a.top();
}

template<typename T, typename C>
const T& Get(const queue<T,C>& a) {
	return a.front();
}

template<typename T>
const T& Get(const queue<T*>& a) {
	return *a.front();
}

template<typename T>
void print_adapter(T q) {
    while (!q.empty()) {
        cout << /*q.top()*/ Get(q)<< endl;
        q.pop();
    }
    cout << '\n';
}

template<typename map_key, typename map_val>
void print_map(const map<map_key, map_val> &_map) {
    for (typename map<const map_key, map_val>::const_iterator it = _map.begin(); it != _map.end(); ++it) {
        cout << it->first << " => " << /*it->second <<*/ '\n'; // TODO
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

template<typename T>
ostream &operator<<(ostream &os, const set<T> &set1) {
    copy(set1.begin(), set1.end(), ostream_iterator<T>(os, " "));
    return os;
}
template<typename T>
ostream &operator<<(ostream &os, const multiset<T> &set1) {
	copy(set1.begin(), set1.end(), ostream_iterator<T>(os, " "));
	return os;
}

#endif //LAB9_FUNCTIONS_H
