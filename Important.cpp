//
// Created by mpibbes on 30/04/22.
//

#include "Important.h"

Important *Important::instance = nullptr;

Important::Important() {}

Important *Important::getInstance() {
    if (instance == nullptr)
        instance = new Important;
    return instance;
}

Important::~Important() = default;


void Important::addNote(Note *newNote) {
    noteList.push_back(newNote);
    newNote->setIsImportant(true);
    newNote->subscribe(this);
}


bool Important::removeNote(int n) {
    int i = 0;
    for (auto itr = noteList.begin(); itr != noteList.end(); itr++) {
        i++;
        if (i == n) {
            (*itr)->unsubscribe(this);
            (*itr)->setIsImportant(false);
            noteList.erase(itr);
            return true;
        }
    }
    return false;
}


void Important::updateDelete(Note &note) {
    noteList.remove(&note);
}
