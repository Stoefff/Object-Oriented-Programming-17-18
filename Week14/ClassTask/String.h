#ifndef __STRING__HEADER
#define __STRING__HEADER

class String {
public:
    String(const size_t size);
    String(const String& rhs);
    String& operator(const String& rhs);

    String& operator+=(const String& rhs);
    String& operator-=(const String& rhs);
    String& operator*=(cosnt int k);

friend bool operator==(const String& str1, const String& str2);

friend bool operator!=(const String& str1, const String& str2);



private:
    void free();
    void copy();
private:
    char* str;
    size_t size;
};
