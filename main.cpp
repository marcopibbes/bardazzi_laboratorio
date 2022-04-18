#include <iostream>
#include <string>
#include"Note.h"
#include "Collection.h"
int main() {
    Note nota1 ("Titolo1", "Testo1");
    Note nota2 ("Titolo2", "Testo2");

    nota1.toggleImportant();
    nota2.toggleLocked();


    nota1.editNote("Titolo11", "Testo11");
    nota2.editNote("Titolo21", "Testo21");



    std::cout<<nota1.getName()<<"\n"<<nota1.getText()<<std::endl;
    std::cout<<nota2.getName()<<"\n"<<nota2.getText()<<std::endl;



}
