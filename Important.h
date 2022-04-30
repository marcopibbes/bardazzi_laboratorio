//
// Created by mpibbes on 30/04/22.
//

#ifndef BARDAZZI_LAB_IMPORTANT_H
#define BARDAZZI_LAB_IMPORTANT_H

#include <iostream>
#include "Observer.h"
#include "Note.h"
#include "Collection.h"

class Subject;


class Important : public Collection {
public:
    //design patter singleton
    static Important *getInstance();

    //distruttore
    ~Important() override;

    //aggiunge una nota alla collezione
    void addNote(Note *newNote) override;

    //rimuove una nota dalla collezione
    bool removeNote(int n) override;


    //metodi design pattern observer
    void updateDelete(Note &note) override;


private:
    Important();

    std::string name = "Note Importanti";
    std::list<Note *> noteList;
    static Important *instance;

};


#endif //BARDAZZI_LAB_IMPORTANT_H
