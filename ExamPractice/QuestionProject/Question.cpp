#include "Question.h"
#include <cstring>
#include <iostream>

using std::cerr;
using std::endl;

Question::Question(const char* ques)
    :ques(nullptr){
    try{
        this->ques = new char[strlen(ques) + 1];
        strcpy(this->ques, ques);
    } catch (std::bad_alloc& e){
        std::cerr << "Bad allocation" << endl;
        throw;
    }
}

Question::Question(const Question& rhs){
        copy(rhs);
}

Question& Question::operator=(const Question& rhs){
    if(this != &rhs){
        free();
        copy(rhs);
    }
    return *this;
}

Question::~Question(){
    free();
}

void Question::free(){
    delete[] ques;
    ques = nullptr;
}

void Question::copy(const Question& rhs){
    try{
        this->ques = new char[strlen(rhs.ques) + 1];
        strcpy(this->ques, rhs.ques);
    } catch (std::bad_alloc& e){
        cerr << "Bad allocation" << endl;
        throw;
    }
}
