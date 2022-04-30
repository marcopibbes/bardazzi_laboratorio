//
// Created by mpibbes on 18/04/22.
//

#include "Note.h"

Note::Note(std::string t, std::string tx) : title(t), text(tx) {
}

Note::Note(Note &orig) {
    title = orig.title;
    text = orig.text;
    blocked = orig.blocked;
}

bool Note::deleteNote() {
    if (!this->isBlocked()) {
        notify();
        delete this;
        return true;
    } else
        return false;
}


bool Note::modifyNote(std::string &t, std::string &tx) {
    if (!this->blocked) {
        this->setTitle(t);
        this->setText(tx);

        return true;
    } else
        return false;
}

std::string Note::getTitle() const { return title; }

void Note::setTitle(std::string &t) { title = t; }

std::string Note::getText() const { return text; }

void Note::setText(std::string &t) { text = t; }

bool Note::isBlocked() const { return blocked; }

void Note::setBlocked(bool b) { blocked = b; }

bool Note::getIsImportant() const { return isImportant; }

void Note::setIsImportant(bool i) { isImportant = i; }

void Note::notify() {
    for (auto &itr: observersList) {
        itr->updateDelete(*this);
    }
}

void Note::subscribe(Observer *o) {
    observersList.push_back(o);
}

void Note::unsubscribe(Observer *o) {
    observersList.remove(o);
}