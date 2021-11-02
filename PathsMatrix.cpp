#include "PathsMatrix.h"

//// NOT POSSIBLE TO CREATE MATRIX WITHOUT FILE
PathsMatrix::PathsMatrix(std::string fileName) {

    this->allocateCities();
    this->allocateRelations();
    this->size = 0;

    this->setFileContent(fileName);

    this->setCities();
    this->setRelations();

    this->setSize();

    this->allocateMatrix();
    this->setMatrix();

    this->setDotFile();
}

PathsMatrix::~PathsMatrix() {
    this->clear();
}



int PathsMatrix::getSize() const {
    return this->size;
}

std::string PathsMatrix::getFileContent() {
    return this->fileContent;
}

City* PathsMatrix::getCities() const {
    return this->cities;
}

City PathsMatrix::getCity(int index) const {
    return this->cities[index];
}

Relation* PathsMatrix::getRelations() {
    return this->relations;
}

Relation PathsMatrix::getRelation(int index) {
    return this->relations[index];
}

double PathsMatrix::getCostValue(int index, int index2) const {
    return this->getElement(index)[index2];
}

double* PathsMatrix::getElement(int index) const {
    return this->matrix[index];
}

double** PathsMatrix::getMatrix() {
    return this->matrix;
}



void PathsMatrix::printMatrix() {
    for(int i = 0; i < this->size; ++i){
        for(int j = 0; j < this->size; ++j) {
            std::cout << this->matrix[i][j] << "   ";
        }
        std::cout << std::endl;
    }
}

void PathsMatrix::printCities() {
    for(int i = 0; i < this->size; ++i){
        std::cout << this->cities[i].getName() << std::endl;
    }
}

void PathsMatrix::printRelations() {
    for(int i = 0; !relations[i].getCity1().empty(); ++i){
        std::cout << "From " << this->relations[i].getCity1() << " to " <<
                  this->relations[i].getCity2() << " is " <<
                  this->relations[i].getCostValue() << std::endl;
    }
}

void PathsMatrix::clear() {
    this->deleteMatrix();
    this->deleteCities();
    this->deleteRelations();
}



void PathsMatrix::setFileContent(std::string fileName) {
    this->fileContent.clear();
    std::string temp;
    std::ifstream in(fileName);

    if(!in.is_open()){
        std::cout << "File is not opened!" << std::endl;
        exit(-1);
    }
    while(!in.eof()){
        in >> temp;
        this->fileContent += temp;
    }
    in.close();
}

void PathsMatrix::setSize() {
    while(!this->cities[this->size].getName().empty())
        ++this->size;
}

//// LAST STEP
void PathsMatrix::setDotFile() {
    std::ofstream out("TownsConnections.dot");
    if(out.is_open())
        std::cout << "\nINFO SAVED IN .dot FILE\n";

    // PUSH IN 7TH POSITION SPACE SO FROM THE DOT FILE CAN CREATE IMAGE
    this->fileContent.insert(7, " ");
    out << this->fileContent;

    out.close();
}

//// CREATE DYNAMIC MATRIX AND FILL ALL CELLS WITH 0
void PathsMatrix::allocateMatrix() {
    this->matrix = new double*[this->size];
    for (int i = 0; i < this->size; ++i)
        this->matrix[i] = new double[this->size];


    for(int i = 0; i < this->size; ++i)
        for(int j = 0; j < this->size; ++j)
            this->matrix[i][j] = 0;
}

void PathsMatrix::allocateCities() {
    this->cities = new (std::nothrow) City[MAX_SIZE];
}

void PathsMatrix::allocateRelations() {
    this->relations = new (std::nothrow) Relation[MAX_SIZE];
}

void PathsMatrix::deleteMatrix() {
    for (int i = 0; i < size; ++i)
        delete [] matrix[i];
    delete [] matrix;
}

void PathsMatrix::deleteCities() {
    delete[] this->cities;
}

void PathsMatrix::deleteRelations() {
    delete[] this->relations;
}

//// SETS ALL RELATIONS BETWEEN CITIES
void PathsMatrix::setMatrix() {
    for(int i = 0; !this->relations[i].getCity1().empty(); ++i){
        int row = 0;
        int columb = 0;
        for(int j = 0; j < this->size; ++j){
            if(this->cities[j].getName() == this->relations[i].getCity1())
                row = j;
            if(this->cities[j].getName() == this->relations[i].getCity2())
                columb = j;
        }
        this->matrix[columb][row] = relations[i].getCostValue();
        this->matrix[row][columb] = relations[i].getCostValue();
    }
}

void PathsMatrix::setCities(){
    this->cities->setCity(this->fileContent, this->cities);
}

void PathsMatrix::setRelations() {
    this->relations->setRelations(this->fileContent, this->relations);
}
