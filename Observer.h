//
// Created by mpibbes on 30/04/22.
//

#ifndef BARDAZZI_LAB_OBSERVER_H
#define BARDAZZI_LAB_OBSERVER_H

    class Note;
    class Subject;


    class Observer {
    public:
        virtual ~Observer()=default;

        virtual void updateDelete(Note& note)=0;
    };



#endif //BARDAZZI_LAB_OBSERVER_H
