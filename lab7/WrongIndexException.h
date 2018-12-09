
#ifndef LAB7_WRONGINDEXEXCEPTION_H
#define LAB7_WRONGINDEXEXCEPTION_H


#include <ostream>

class WrongIndexException : public std::range_error {
public:
    friend std::ostream &operator<<(std::ostream &os, const WrongIndexException &exception) {
        return os << static_cast<const range_error &>(exception).what();
    }

    WrongIndexException(const char *msg) : range_error(msg) {};
};


#endif //LAB7_WRONGINDEXEXCEPTION_H
