//
// Created by mpibbes on 02/05/22.
//
#include "gtest/gtest.h"
#include "../Note.h"

TEST(Note, setBlockedTest){
Note nota("Titolo","Testo");
nota.setBlocked(true);
ASSERT_TRUE(nota.isBlocked());
}

TEST(Note,deleteNoteTest){
Note* nota= new Note("Titolo","Testo");
nota->setBlocked(true);
ASSERT_FALSE(nota->deleteNote());
nota->setBlocked(false);
ASSERT_TRUE(nota->deleteNote());
}

TEST(Note,getTitleTest){
Note nota("Titolo","Testo");
ASSERT_EQ("Titolo",nota.getTitle());
}


TEST(Note, getTextTest){
Note nota("Titolo","Testo");
ASSERT_EQ("Testo",nota.getText());
}

TEST(Note,modifyNoteTest){
Note nota("Titolo","Testo");
Note nota2("Titolo2","Testo2");
nota2.setBlocked(true);
std::string modify="Modifica";
bool isModified= false;
isModified=nota.modifyNote(modify,modify);
ASSERT_TRUE(isModified);
ASSERT_EQ("Modifica",nota.getTitle());
ASSERT_EQ("Modifica",nota.getText());
ASSERT_FALSE(nota2.modifyNote(modify,modify));
}


TEST(Note,setTitleTest){
Note nota("Titolo","Testo");
std::string modify="Modifica";
nota.setTitle(modify);
ASSERT_EQ("Modifica",nota.getTitle());
}



TEST(Note, setTextTest){
Note nota("Titolo","Testo");
std::string modify="Modifica";
nota.setText(modify);
ASSERT_EQ("Modifica",nota.getText());
}

TEST(Note, isBlockedTest){
Note nota("Titolo","Testo");
ASSERT_FALSE(nota.isBlocked());
}


TEST(Note, getIsImportantTest){
Note nota("Titolo","Testo");
ASSERT_FALSE(nota.getIsImportant());
}

TEST(Note, setIsImportantTest){
Note nota("Titolo", "Testo");
nota.setIsImportant(true);
ASSERT_TRUE(nota.getIsImportant());
}