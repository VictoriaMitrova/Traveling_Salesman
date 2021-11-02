#ifndef PROJECT_72005_RELATION_H
#define PROJECT_72005_RELATION_H
#include <iostream>

class Relation {
public:
    Relation();
    ~Relation();


    std::string& getCity1();
    std::string& getCity2();
    double getCostValue();

    void setCity1(std::string);
    void setCity2(std::string);
    void setCostValue(double);
    void setRelation(std::string, std::string, double);

    void setRelations(std::string, Relation*);
    bool isCity(std::string, int&);

    bool operator<(Relation&);

    void clear();

private:
    std::string city1;
    std::string city2;
    double costValue;
};


#endif //PROJECT_72005_RELATION_H
