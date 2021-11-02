#ifndef PROJECT_72005_CITY_H
#define PROJECT_72005_CITY_H
#include <iostream>
#include <string>

class City {

public:

    City();
    ~City();


    std::string& getName();
    int getIndex();

    void setName(std::string&);
    void setIndex(int);


    bool isCity(std::string, int&);
    void setCity(std::string, City*);

private:
    std::string name;
    int index;

};


#endif //PROJECT_72005_CITY_H
