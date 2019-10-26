#include <iostream>
#include <string.h>
using namespace std;
template <typename T>
class Device
{
protected:
    char* marka;
    T* apps;
    int caps;
    int size;
    void copy(const char*);
    void remove();
    void resize();
public:
    Device(const char* = " ");
    Device(const Device&);
    Device& operator=(const Device&);
    virtual ~Device();
    void addApp(T);
    virtual void print() const = 0;
    virtual Device* clone() const = 0;
};
template <typename T>
void Device<T>::print() const
{
    cout << marka << endl;
    for (int i = 0; i < size; i++)
    {
        cout << apps[i] << endl;
    }
}
template <typename T>
Device<T>::Device(const char* marka)
{
    copy(marka);
}
template <typename T>
Device<T>::Device(const Device<T>& other)
{
    copy(other.marka);
}
template <typename T>
Device<T>& Device<T>::operator=(const Device<T>& other)
{
    if (this != &other)
    {
        remove();
        copy(other.marka);
    }
    return *this;
}
template <typename T>
Device<T>::~Device()
{
    remove();
}
template <typename T>
void Device<T>::remove()
{
    delete[] marka;
    delete[] apps;
}
template <typename T>
void Device<T>::copy(const char* marka)
{
    this->marka = new char[strlen(marka) + 1];
    strcpy(this->marka, marka);
    this->caps = 2;
    this->size = 0;
    apps = new T[caps];
    for (int i = 0; i < size; i++)
    {
        this->apps[i] = apps[i];
    }
}
template <typename T>
void Device<T>::addApp(T new_app)
{
    if (size == caps)
    {
        resize();
    }
    apps[size++] = new_app;
}
template <typename T>
void Device<T>::resize()
{
    T* temp = new T[caps * 2];
    for (int i = 0; i < size; i++)
    {
        temp[i] = apps[i];
    }
    delete[] apps;
    caps *= 2;
    apps = temp;
}
template <typename T>
class Phone : public Device<T>
{
private:
    double price;
public:
    Phone(const char* = " ", double = 1199.99);
    Phone(const Phone<T>&);
    Phone<T>& operator=(const Phone<T>&);
    void print() const override;
    Device<T>* clone() const override;
    //bool compareWith(const Phone&) const;
    //friend bool operator>(const Phone&, const Phone&);
};
template <typename T>
void Phone<T>::print() const
{
    print();
}
template <typename T>
Phone<T>::Phone(const char* marka, double price) : Device<T>(marka)
{
    this->price = price;
}
template <typename T>
Phone<T>::Phone(const Phone<T>& other) : Device<T>(other)
{
    price = other.price;
}
template <typename T>
Phone<T>& Phone<T>::operator=(const Phone<T>& other)
{
    if (this != &other)
    {
        Device<T>::operator=(other);
        price = other.price;
    }
    return *this;
}

template <typename T>
Device<T>* Phone<T>::clone() const{
    return new Phone(*this);
}
/*
template <typename T>
bool Phone<T>::compareWith(const Phone& other) const
{
    return price > other.price && size > other.size;
}
template <typename T>
bool operator>(const Phone& lhs,const Phone& rhs)
{
    return (lhs.size > rhs.size && lhs.price > lhs.price);
}
*/
template <typename T>
class Catalog
{
private:
    Device<T>** phones;
    int _cap;
    int _size;
    void _copy(const Catalog&);
    void _remove();
    void _resize();
public:
    Catalog();
    Catalog(const Catalog&);
    Catalog& operator=(const Catalog&);
    ~Catalog();
    void addElement(const Device<T>&);
};
template <typename T>
void Catalog<T>::_copy(const Catalog<T>& other)
{
    this->_cap = other._cap;
    this->_size = other._size;
    phones = new Device<T> * [_cap];
    for (int i = 0; i < _size; i++)
    {
        this->phones[i] = other.phones[i]->clone();
    }
}
template <typename T>
void Catalog<T>::_remove()
{
    for (int i = 0; i < _size; i++)
    {
        delete[] phones[i];
    }
    delete[] phones;
}
template <typename T>
void Catalog<T>::_resize()
{
    Device<T>** temp = new Device<T>*[_cap*2];
    for(int i = 0;i < _size;i++)
    {
        temp[i] = phones[i];
    }
    _cap *= 2;
    delete[] phones;
    phones = temp;
}
template <typename T>
Catalog<T>::Catalog() : _cap(2), _size(0)
{
    phones = new Device<T> * [_cap];
}
template <typename T>
Catalog<T>::Catalog(const Catalog<T>& other)
{
    _copy(other);
}
template <typename T>
Catalog<T>& Catalog<T>::operator=(const Catalog<T>& other)
{
    if (this != &other)
    {
        _remove();
        _copy(other);
    }
    return *this;
}
template <typename T>
Catalog<T>::~Catalog()
{
    _remove();
}
template <typename T>
void Catalog<T>::addElement(const Device<T>& new_phone)
{
    if(_cap == _size)
    {
        _resize();
    }

    phones[_size++] = new_phone.clone();
}
int main()
{
    Phone<int> a("Samsung");
    a.addApp(1);
    a.addApp(2);
    a.addApp(3);
    a.print();
    Catalog<int> catalog;
    catalog.addElement(a);
    return 0;
}