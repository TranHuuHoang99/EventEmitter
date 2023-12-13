#ifndef OBJECT_A_HPP_
#define OBJECT_A_HPP_

#include <bits/stdc++.h>
#include "EventEmitter.hpp"
#include "EventID.hpp"

using namespace std;

class ObjectA {
    public:
        ObjectA(void) = default;
        ~ObjectA(void) = default;

    public:
        int obj_value_int = 0;
        const char *obj_value_str = " ";
        void init(void);
        void test_erase_eventID(void);
};


#endif //OBJECT_A_HPP_