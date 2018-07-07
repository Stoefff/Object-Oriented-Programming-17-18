#ifndef __BIN__QUESTION__HEADER
#define __BIN__QUESTION__HEADER

#include "Question.h"

class BinQuestion : public Question{
    BinQuestion(const char* ques, bool rightAns);
    BinQuestion(const BinQuestion& rhs);
    BinQuestion& operator=(const BinQuestion& rhs);
    virtual ~BinQuestion() override;

    virtual void ask() override;
    virtual void grade() override;

private:
    bool ans;
    bool rightAns;
};

#endif
