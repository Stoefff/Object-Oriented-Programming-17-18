#ifndef __SENSOR__HEADER__INCLUDED
#define __SENSOR__HEADER__INCLUDED

typedef unsigned int uint;

class Sensor{
public:
    Sensor();
    Sensor(char*);
    Sensor(const Sensor&);
    Sensor& operator=(const Sensor&);
    ~Sensor();

    const float getTemp() const;
    char* getDescription() const;
    const uint getID() const;

private:
    float temp;
    char* description;
    uint ID;

    float generateTemp();
    uint generateID();
};

#endif
