//
// Created by mpibbes on 18/04/22.
//

#ifndef BARDAZZI_LAB_NOTE_H
#define BARDAZZI_LAB_NOTE_H

#include <string>
#include <iostream>
#include<list>
#include "Subject.h"

class Note : public Subject {
public:
//costruttore
    Note(std::string t, std::string tx);

//costruttore di copia
    Note(Note &orig);

//cancella una nota (se non è bloccata)
    bool deleteNote();

//modifica titolo e testo di una nota (se non bloccata)
    bool modifyNote(std::string &t, std::string &tx);

//metodi getter e setter
    std::string getTitle() const;

    void setTitle(std::string &t);

    std::string getText() const;

    void setText(std::string &t);

    bool isBlocked() const;

    void setBlocked(bool b);

    bool getIsImportant() const;

    void setIsImportant(bool i);

//metodi design pattern observer
    void notify() override;

    void subscribe(Observer *o) override;

    void unsubscribe(Observer *o) override;


private:
    std::string title;
    std::string text;
    bool blocked = false;
    bool isImportant = false;
    std::list<Observer *> observersList;
};


#endif //BARDAZZI_LAB_NOTE_H
