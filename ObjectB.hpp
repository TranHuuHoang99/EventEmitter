#ifndef OBJECT_B_HPP_
#define OBJECT_B_HPP_

#include <bits/stdc++.h>
#include "EventEmitter.hpp"
#include "EventID.hpp"

using namespace std;

class ObjectB {
    public:
        ObjectB(void) = default;
        ~ObjectB(void) =default;

    public:
        int objb_value_int = 0;
        const char *objb_value_str = " ";
        void init(void);
        void go(void);
};


#endif //OBJECT_B_HPP_