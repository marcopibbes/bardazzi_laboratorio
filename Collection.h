//
// Created by mpibbes on 18/04/22.
//

#ifndef BARDAZZI_LAB_COLLECTION_H
#define BARDAZZI_LAB_COLLECTION_H

#include <iostream>
#include <list>
#include <memory>
#include "Observer.h"
#include "Note.h"

class Subject;


class Collection : public Observer {
public:
    //costruttore
    explicit Collection(std::string n);

    Collection();

    //distruttore
    ~Collection() override;

    //aggiunge una nota alla collezione
    virtual void addNote(Note *newNote);

    //rimuove una nota dalla collezione
    virtual bool removeNote(int n);

    //modifica una nota della collezione indicandone il numero (se non è bloccata)
    virtual bool modifyNote(int n, std::string &title, std::string &text);

    //restituisce true se la nota è presente nella collezione, false altrimenti
    bool searchNote(Note &note);

    //metodi getter e setter
    std::string getName() const;

    void setName(std::string &n);

    std::list<Note *> getNoteList() const;

    //metodi design pattern observer
    void updateDelete(Note &note) override;


private:
    std::string name;
    std::list<Note *> noteList;
};

#endif //BARDAZZI_LAB_COLLECTION_H
