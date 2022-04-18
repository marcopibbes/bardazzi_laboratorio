//
// Created by mpibbes on 18/04/22.
//

#ifndef BARDAZZI_LAB_NOTE_H
#define BARDAZZI_LAB_NOTE_H
#include <string>


class Note {
public:
    void toggleImportant ();
    void deleteNote();
    void editNote (std::string &a);
private:
    bool isImportant;
    bool isLocked;
    std::string* text;


};


#endif //BARDAZZI_LAB_NOTE_H
