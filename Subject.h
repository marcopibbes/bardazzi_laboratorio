//
// Created by mpibbes on 30/04/22.
//

#ifndef BARDAZZI_LAB_SUBJECT_H
#define BARDAZZI_LAB_SUBJECT_H

#include "Observer.h"


class Subject {
public:
    virtual ~Subject()=default;
    virtual void notify()=0;

    virtual void subscribe(Observer *o)=0;
    virtual void unsubscribe(Observer* o)=0;


};

#endif //BARDAZZI_LAB_SUBJECT_H
