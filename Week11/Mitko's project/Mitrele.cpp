#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

const int maxAthletesCount = 15;

class Athlete{
public:
    Athlete();
    Athlete(int, const char*, const char*, int[5]);
    Athlete(const Athlete&); // Copy constructor
    Athlete& operator=(const Athlete&); // Operator =
    ~Athlete();

    void setName(const char*);
    char* getName();

    void setTeam(char*);
    char* getTeam();

    int getNumber();
    int* getResult();
    int getResultSum();

private:
    void free();
    void copy(const Athlete&);

private:
    int number;
    char* name;
    char* team;
    int results [5];

};

Athlete::Athlete(){
    this->number = 0;
    this->name = nullptr;
    this->team = nullptr;
    for(int i = 0; i < 5; i++){
        results[i] = 0;
    }
}

Athlete::Athlete(int number, const char* name,const char* team, int results[5]){
    this->number = number;
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
    this->team = new char[strlen(team) + 1];
    strcpy(this->team, team);
    for(int i = 0; i<5;i++){
        this->results[i] = results[i];
    }
}

Athlete::Athlete(const Athlete& rhs){
    copy(rhs);
}

Athlete& Athlete::operator=(const Athlete& rhs){
    if (this != &rhs){
        free();
        copy(rhs);
    }
    return *this;
}


Athlete::~Athlete(){
    free();
}

void Athlete::free(){
    delete[] name;
    name = nullptr;
    delete[] team;
    team = nullptr;
}

void Athlete::copy(const Athlete& rhs){
    this->number = rhs.number;
    this->name = new char[strlen(rhs.name) + 1];
    strcpy(this->name, rhs.name);
    this->team = new char[strlen(rhs.team) + 1];
    strcpy(this->team, rhs.team);
    for(int i = 0; i<5;i++){
        this->results[i] = rhs.results[i];
    }
}

void Athlete::setName(const char* newName){
    this->name = new char[strlen(newName)+1];
    strcpy(this->name, newName);
}

char* Athlete::getName(){
    return this->name;
}

void Athlete::setTeam(char* newTeam){
    this->team = new char[strlen(newTeam)+1];
    strcpy(this->team, newTeam);
}

char* Athlete::getTeam(){
    return this->team;
}
int Athlete::getNumber(){
    return this->number;
}

int* Athlete::getResult(){
    return this->results;
}

int Athlete::getResultSum(){
    int sum = 0;
    for (int i = 0; i < 5; i++){
        sum += this->results[i];
    }
    return sum;
}

class FileSystem{
public:
    FileSystem(const char* fileName);
    ~FileSystem();

    void registerAthlete(Athlete a);
    void changeAthlete(Athlete a);
    void deleteAthlete(Athlete a);
    void printAthletes();
    void printSortedByResult();

private:
    void getAthletes(ifstream&);
    void saveAthletes(ofstream&);
    void sortByResult();

private:
    char* filename;
    size_t countAthletes;
    Athlete* athletes[maxAthletesCount];
};

FileSystem::FileSystem(const char* fileName){
    this->filename = new char[strlen(fileName) + 1];
    strcpy(this->filename, fileName);
    ifstream file (this->filename, ios::in);
    if(!file.good()){
        cerr << "Input file stream failed" << endl;
    }
    getAthletes(file);
    file.close();
    cout << "Loading athletes complete" << endl;
}

FileSystem::~FileSystem(){
    ofstream file (this->filename, ios::out | ios::trunc);
    if(!file.good()){
        cerr << "Output file stream failed" << endl;
    }
    saveAthletes(file);
    file.close();
    delete[] filename;
    filename = nullptr;
    //athletes pointer is static, so when it start destructing
    //it will call all destrcutors of its elements, which calls
    // the destructor of each Athlete
}

void FileSystem::getAthletes(ifstream& file){
    file >> this->countAthletes;
    for(int i = 0; i < countAthletes; i++){
        int number;
        char name[41];
        char team[128];
        int results [5];
        file >> number >> name >> team;
        for(int j = 0; j < 5; j++){
            file >> results[j];
        }
        Athlete* a = new Athlete(number, name, team, results);
        athletes[i] = a;
    }
}

void FileSystem::saveAthletes(ofstream& file){
    file << this->countAthletes;
    for(int i = 0; i < this->countAthletes; i++){
        file << athletes[i]->getNumber() << athletes[i]->getName()
            << athletes[i]->getTeam();
        int* buffer = athletes[i]->getResult();
        for(int j = 0; j < 5; j++){
            file << buffer[j];
        }
    }
}

void FileSystem::sortByResult(){ //Insertion sort
    Athlete temp;
	for(size_t i = 1 ; i < countAthletes ; i++){
		for (size_t j = i ; j > 0 && athletes[j]->getResult() > athletes[j-1]->getResult(); j--) {
			temp = *athletes[j-1];
			*athletes[j-1] = *athletes[j];
			*athletes[j] = temp;
		}
    }
}

void FileSystem::registerAthlete(Athlete a){
    if(countAthletes >= 15){
        cout << "No more athletes allowed" << endl;
        return;
    } else {
        athletes[countAthletes] = new Athlete(a);
        countAthletes++;
    }
}

void FileSystem::changeAthlete(Athlete a){
    for (int i = 0; i < this->countAthletes; i++){
        if(!strcmp(athletes[i]->getName(), a.getName())){
            *athletes[i] = a;
            return;
        }
    }
    cout << "No such athlete found" << endl;
}

void FileSystem::deleteAthlete(Athlete a){
    for (int i = 0; i < this->countAthletes; i++){
        if(!strcmp(athletes[i]->getName(), a.getName())){
            for(int j = i; j < this->countAthletes - 1; j++){
                *athletes[j] = *athletes[j + 1];
            }
            countAthletes--;
            return;
        }
    }
    cout << "No such athlete found" << endl;
}

void FileSystem::printAthletes(){
    for(int i = 0; i < this->countAthletes; i++){
        cout << athletes[i]->getNumber() << athletes[i]->getName()
            << athletes[i]->getTeam();
        int* buffer = athletes[i]->getResult();
        for(int j = 0; j < 5; j++){
            cout << buffer[j];
        }
        cout << endl;
    }
}

void FileSystem::printSortedByResult(){
    sortByResult();
    cout << "The students are printed from the best to worst" << endl;
    printAthletes();
}

int main(){
    return 0;
}
