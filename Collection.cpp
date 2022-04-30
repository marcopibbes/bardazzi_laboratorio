//
// Created by mpibbes on 18/04/22.
//

#include "Collection.h"

Collection::Collection(std::string n) : name(n) {
    std::list<Note *> nl;
    noteList = nl;
}

Collection::Collection() {
    name = "Senza nome";
}

Collection::~Collection() = default;

void Collection::addNote(Note *newNote) {
    noteList.push_back(newNote);
    newNote->subscribe(this);
}


bool Collection::removeNote(int n) {
    int i = 0;
    for (auto itr = noteList.begin(); itr != noteList.end(); itr++) {
        i++;
        if (i == n) {
            (*itr)->unsubscribe(this);
            noteList.erase(itr);
            return true;
        }
    }
    return false;
}

bool Collection::modifyNote(int n, std::string &title, std::string &text) {
    int i = 0;
    bool b = false;
    for (auto &itr: noteList) {
        i++;
        if (i == n)
            b = itr->modifyNote(title, text);
    }
    return b;
}

bool Collection::searchNote(Note &note) {
    for (auto &itr: noteList) {
        if (&note == itr)
            return true;
    }
    return false;
}

std::string Collection::getName() const { return name; }

void Collection::setName(std::string &n) { name = n; }


std::list<Note *> Collection::getNoteList() const { return noteList; }

void Collection::updateDelete(Note &note) {
    noteList.remove(&note);
}
