#include <iostream>
#include "EventEmitter.hpp"
#include "ObjectA.hpp"
#include "ObjectB.hpp"

using namespace std;

int main(void) {
    
    ObjectA *_a = new ObjectA();
    _a->init();

    cout << _a->obj_value_int << ", " << _a->obj_value_str << endl;

    ObjectB *_b = new ObjectB();

    _b->init();
    cout << _b->objb_value_int << ", " << _b->objb_value_str << endl;

    _a->test_erase_eventID();

    _b->go();

    cout << _a->obj_value_int << ", " << _a->obj_value_str << endl;
    cout << _b->objb_value_int << ", " << _b->objb_value_str << endl;
    return 0;
}