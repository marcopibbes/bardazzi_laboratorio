//
// Created by mpibbes on 02/05/22.
//
#include "gtest/gtest.h"
#include "../Collection.h"


TEST(Collection,getNameTest){
    Collection collection("NomeCollezione");
    ASSERT_EQ("NomeCollezione",collection.getName());
}

TEST(Collection,setNameTest){
    Collection collection("NomeCollezione");
    std::string modify="Modifica";
    collection.setName(modify);
    ASSERT_EQ("Modifica",collection.getName());
}

TEST(Collection,addNoteTest){
    int collectionSize;
    Note* note=new Note("Titolo","Testo");
    Collection collection("NomeCollezione");
    collectionSize=collection.getNoteList().size();
    collection.addNote(note);
    bool isTrue=false;
    for(auto & itr : collection.getNoteList()){
        if(itr==note)
            isTrue=true;
    }
    ASSERT_TRUE(isTrue);
    ASSERT_EQ(collectionSize+1,collection.getNoteList().size());
}

TEST(Collection,modifyNoteTest){
    bool isModified=false;
    Note* note=new Note("Titolo","Testo");
    Note* note2=new Note("Titolo2","Testo2");
    note2->setBlocked(true);
    Collection collection("NomeCollezione");
    collection.addNote(note);
    collection.addNote(note2);
    std::string modify="Modifica";
    isModified=collection.modifyNote(1, modify, modify);
    ASSERT_EQ("Modifica",note->getTitle());
    ASSERT_EQ("Modifica",note->getText());
    ASSERT_TRUE(isModified);
    isModified=collection.modifyNote(2, modify, modify);
    ASSERT_EQ("Titolo2",note2->getTitle());
    ASSERT_EQ("Testo2", note2->getText());
    ASSERT_FALSE(isModified);
    isModified=true;
    isModified=collection.modifyNote(3, modify, modify);
    ASSERT_FALSE(isModified);
}

TEST(Collection, searchNoteTest){
    Note* note=new Note("Titolo","Testo");
    Note* note2=new Note("Titolo2","Testo2");
    Note* note3=new Note("Titolo3","Testo3");
    Collection collection("NomeCollezione");
    collection.addNote(note);
    collection.addNote(note3);
    ASSERT_TRUE(collection.searchNote(*note));
    ASSERT_TRUE(collection.searchNote(*note3));
    ASSERT_FALSE(collection.searchNote(*note2));
}

TEST(Collection, removeNoteTest){
    bool isRemoved;
    Note* note=new Note("Titolo","Testo");
    Note* note2=new Note("Titolo2","Testo2");
    Collection collection("Nome Collezione");
    collection.addNote(note);
    collection.addNote(note2);
    isRemoved=collection.removeNote(1);
    ASSERT_TRUE(isRemoved);
    ASSERT_FALSE(collection.searchNote(*note));
    isRemoved=collection.removeNote(3);
    ASSERT_FALSE(isRemoved);
}