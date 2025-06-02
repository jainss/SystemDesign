#pragma once
#include "./../Observer/Observer.hpp"
#include <vector>

class Subject {
    public:
       virtual void subscribeList(Observer* user) =0;
       virtual void unSubscribe(Observer* user) =0;
       virtual void notify() =0;
       virtual ~Subject() {}
};

