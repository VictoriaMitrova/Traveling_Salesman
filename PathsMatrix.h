#ifndef PROJECT_72005_PATHSMATRIX_H
#define PROJECT_72005_PATHSMATRIX_H
#include "City.h"
#include "Relation.h"
#include "fstream"
#include <fstream>

const int MAX_SIZE = 100;

class PathsMatrix{
public:

    PathsMatrix(std::string);
    ~PathsMatrix();

    int getSize() const;
    std::string getFileContent();
    City* getCities() const;
    City getCity(int) const;
    Relation* getRelations();
    Relation getRelation(int);
    double** getMatrix();
    double* getElement(int) const;
    double getCostValue(int, int) const;


    void printMatrix();
    void printCities();
    void printRelations();

    void clear();

private:

    double** matrix;
    City *cities;
    Relation *relations;
    int size;
    std::string fileContent;

    void setFileContent(std::string);
    void setSize();
    void setDotFile();
    void setMatrix();
    void setCities();
    void setRelations();

    void allocateMatrix();
    void allocateCities();
    void allocateRelations();

    void deleteMatrix();
    void deleteCities();
    void deleteRelations();

};


#endif //PROJECT_72005_PATHSMATRIX_H
