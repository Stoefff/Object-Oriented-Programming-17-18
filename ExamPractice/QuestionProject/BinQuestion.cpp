#include "BinQuestion.h"

BinQuestion::BinQuestion(const char* ques, bool rigthAns)
    :Question(ques){
}

BinQuestion::BinQuestion(const BinQuestion& rhs)
    :Question(rhs){
    this->ans = rhs.ans;
    this->rightAns = rhs.rightAns;
}

BinQuestion& BinQuestion::operator=(const BinQuestion& rhs){
    if (this != &rhs){
        Question::operator=(rhs);
        this->ans = rhs.ans;
        this->rightAns = rhs.rightAns;
    }
    return *this;
}

BinQuestion::~BinQuestion(){
}
