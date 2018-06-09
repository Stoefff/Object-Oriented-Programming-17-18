#ifndef __SENSOR__HEADER
#define __SENSOR__HEADER

// We should write clone function
#include <iostream>
class Sensor{
public:
	Sensor(const char*);
	Sensor(const Sensor&);
	Sensor& operator=(const Sensor&);
	virtual ~Sensor();

	const char* getDescription() const;
	void setDescription(const char*);

	unsigned short getID() const;
	void setNewID();

	virtual float getReadings() const = 0;
    virtual size_t getValue() const = 0;

private:
	void copyFrom(const Sensor&);
	void freeData();
	float randomFloat() const;

private:
	char* description;
	unsigned int id;
};

#endif
