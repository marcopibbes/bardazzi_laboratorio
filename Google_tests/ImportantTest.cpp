//
// Created by mpibbes on 02/05/22.
//
#include "gtest/gtest.h"
#include "../Important.h"

TEST(Important,addNoteTest){
Note* note=new Note("Titolo","Testo");
Important* important=Important::getInstance();
important->addNote(note);
ASSERT_TRUE(note->getIsImportant());
}

TEST(Important, removeNoteTest){
Note* note=new Note("Titolo","Testo");
Note* note2=new Note("Titolo2","Testo2");
Important* important=Important::getInstance();
important->addNote(note);
important->addNote(note2);
important->removeNote(1);
ASSERT_FALSE(note->getIsImportant());
ASSERT_TRUE(note2->getIsImportant());
}

TEST(Important, getInstanceTest){
EXPECT_NE(Important::getInstance(), nullptr);
}