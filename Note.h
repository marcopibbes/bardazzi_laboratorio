//
// Created by mpibbes on 18/04/22.
//

#ifndef BARDAZZI_LAB_NOTE_H
#define BARDAZZI_LAB_NOTE_H
#include <string>
#include <iostream>

class Note {
public:
    Note(std::string name, std::string text);
    ~Note() {
        std::cout<<name<< " deleted."<<std::endl;
    };

    bool getImportant ()
    {
        return isImportant;
    }
    void toggleImportant ()
    {
        if(isImportant){
            isImportant=false;
            std::cout<< name<< " set as not important"<<std::endl;}
        else
        {
            std::cout<< name<<" set as important"<<std::endl;
            isImportant=true;}

    }

    void toggleLocked()
    {
        if (isLocked)
        {
            std::cout<<name<<" unlocked."<<std::endl;
            isLocked=false;
        }
        else
        {
            std::cout<<name<<" locked."<<std::endl;
            isLocked=true;
        }
    }


    void editNote (std::string a, std::string b)
    {
        if (isLocked)
            std::cout<<"Note is locked! Cannot modify it."<<std::endl;
        else {
            name = a;
            text = b;
            std::cout<<"Successfully edited."<<std::endl;
        }
    }

    void deleteNote()
    {
        if(isLocked)
            std::cout<<"Note is locked! Cannot delete it."<<std::endl;
        else
        {
            delete this;
        }
    }

    std::string getName()
    {
        return name;
    }

    std::string getText()
    {
        return text;
    }

private:
    bool isImportant=false;
    bool isLocked=false;
    std::string text;
    std::string name;
};


#endif //BARDAZZI_LAB_NOTE_H
