#ifndef EVENT_EMITTER_HPP_
#define EVENT_EMITTER_HPP_

#include <iostream>
#include <bits/stdc++.h>
#include <memory>

using namespace std;

struct ListenerBase {
    ListenerBase(void) = default;
    ~ListenerBase(void) = default;

    unsigned int listenerID;
};

template<typename... Args>
struct Listener : ListenerBase {
    function<void(Args...)> callback;
};

class EventEmitter {
    public:
        EventEmitter(void);
        ~EventEmitter(void);
    
    private:
        static EventEmitter *_instance;
        map<unsigned int, vector<ListenerBase*>> _listeners;

    public:
        static EventEmitter *getInstance(void);
        
        template<typename _Type, typename... Args>
        inline unsigned int on(unsigned int eventID, function<_Type> callback) {
            Listener<Args...> *l = new Listener<Args...>();
            l->callback = callback;

            for(auto i = _listeners.begin(); i != _listeners.end(); i++) {
                if(i->first == eventID) {
                    i->second.push_back(l);
                    l->listenerID = i->second.size() - 1;
                    return l->listenerID;
                }
            }

            l->listenerID = 0;
            _listeners.insert(std::pair<unsigned int, vector<ListenerBase*>>({eventID, {l}}));
            return l->listenerID;
        }

        template<typename... Args>
        inline void emit(unsigned int eventID, Args... args) {
            auto it = _listeners.find(eventID);

            if(it != _listeners.end()) {
                Listener<Args...> *ret = nullptr;
                for(auto const &i : _listeners.find(eventID)->second) {
                    ret = static_cast<Listener<Args...>*>(i);
                    ret->callback(args...);
                }
                delete ret;
            } else {
                cerr << "Event hasn't been register" << endl;
                return;
            }
        }

        void erase_Listener(unsigned int eventID, unsigned int listenerID);
        void erase_Event(unsigned int eventID);
};


#endif //EVENT_EMITTER_HPP_