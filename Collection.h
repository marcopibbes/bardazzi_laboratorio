//
// Created by mpibbes on 18/04/22.
//

#ifndef BARDAZZI_LAB_COLLECTION_H
#define BARDAZZI_LAB_COLLECTION_H
#include<string>
#include <list>
#include "Note.h"
class Collection {
public:
    Collection(std::string &name): name(name){};
    std::string getName()
    {
       return name;
    }
    void setName(std::string &n)
    {
        name=n;
    }

    void addNote(Note a)
    {
        list.push_back(&a);
        std::cout<<"Note successfully added to collection."<<std::endl;
    }

    void removeNote(Note a)
    {
        list.remove(&a);
        std::cout<<"Note successfully removed from collection."<<std::endl;
    }
private:
    std::string name;
    std::list <Note*> list;
};


#endif //BARDAZZI_LAB_COLLECTION_H
