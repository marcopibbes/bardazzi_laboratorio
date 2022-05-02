#include <iostream>
#include <string>
#include"Note.h"
#include "Collection.h"
#include "Important.h"

int main() {
    std::cout << "Creazione di 3 note e 1 collezione" << std::endl;
    Note *appuntamenti1 = new Note("Appuntamenti 16/02", "Dentista, Riunione");
    Note *lista = new Note("Lista Spesa", "Mele, Banane");
    Note *appuntamenti2 = new Note("Appuntamenti 17/02", "Dottore");
    Collection task("task");
    std::cout << "\n\n";
    std::cout << "Aggiungo le note 'appuntamenti' alla collezione task" << std::endl;
    task.addNote(appuntamenti1);
    task.addNote(appuntamenti2);
    std::cout << "\n\n";
    std::cout << "Rimuovo la nota appuntamenti2 dalla collezione" << std::endl;
    task.removeNote(2);
    std::cout << "\n\n";
    std::cout << "Provo a modificare la nota 'lista', che non verra' modificata poiche' e' bloccata" << std::endl;
    lista->setBlocked(true);
    std::string w = "Modifica";
    lista->modifyNote(w, w);
    std::cout << "\n\n";
    std::cout << "Creazione della collezione 'Note Importanti'" << std::endl;
    Important *noteimportanti;
    noteimportanti = Important::getInstance();
    noteimportanti->addNote(appuntamenti1);
    noteimportanti->addNote(lista);
    std::cout << "\n\n";
    //Grazie al design pattern Observer se elimino una nota, questa viene eliminata anche nella collezione
    std::cout << "Elimino la nota 'appuntamenti1'" << std::endl;
    appuntamenti1->deleteNote();
    return 0;

}
