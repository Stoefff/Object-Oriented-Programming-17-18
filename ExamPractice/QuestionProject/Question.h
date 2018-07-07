#ifndef __QUESTION__HEADER
#define __QUESTION__HEADER

class Question {
public:
    Question(const char* ques);
    Question(const Question& rhs);
    Question& operator=(const Question& rhs);
    virtual ~Question();

    virtual void ask() = 0;
    virtual void grade(char* ans) = 0;

private:
    void free();
    void copy(const Question& rhs);

protected:
    char* ques;
    int gradedPoints;
};

#endif
