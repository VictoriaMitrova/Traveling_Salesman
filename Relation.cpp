#include "Relation.h"

Relation::Relation() {
    this->costValue = 0;
}

Relation::~Relation() {
    this->clear();
}

std::string& Relation::getCity1() {
    return this->city1;
}

std::string& Relation::getCity2() {
    return this->city2;
}

double Relation::getCostValue() {
    return this->costValue;
}

void Relation::setCity1(std::string newCity1) {
    this->city1 = newCity1;
}

void Relation::setCity2(std::string newCity2) {
    this->city2 = newCity2;
}

void Relation::setCostValue(double newValue) {
    this->costValue = newValue;
}

void Relation::setRelation(std::string newCity1, std::string newCity2, double newValue) {
    this->setCity1(newCity1);
    this->setCity2(newCity2);
    this->setCostValue(newValue);
}

bool Relation::isCity(std::string content, int& current){
    int counter = current;

    while((content[counter] != ';' && content[counter] != '-') && content[counter + 1] != '\0'){
        if ((content[counter + 1] == '-' && content[counter + 2] == '>') || content[counter + 1] == '\0')
            return false;
        ++counter;
    }
    return true;
}

bool Relation::operator<(Relation & other) {
    if(this->costValue < other.costValue)
        return true;
    return false;
}

void Relation::setRelations(std::string content, Relation* relations){
    int counter2 = 0;
    for(int i = 0; content[i] != '\0'; ++i){
        if(!isCity(content, i)){
            std::string temp;
            while(content[i] != ';' && content[i] != '\0'){
                temp += content[i];
                ++i;
            }
            //--i;
            int j = 0;
            while((temp[j] >= 'a' && temp[j] <= 'z') || (temp[j] >= 'A' && temp[j] <= 'Z')){
                relations[counter2].city1 += temp[j];
                ++j;
            }
            j += 2;
            while((temp[j] >= 'a' && temp[j] <= 'z') || (temp[j] >= 'A' && temp[j] <= 'Z')){
                relations[counter2].city2 += temp[j];
                ++j;
            }
            while(!(temp[j] >= '0' && temp[j] <= '9') && temp[j] != '-' && temp[j] != '.')
                ++j;
            std::string cost;
            while((temp[j] >= '0' && temp[j] <= '9') || temp[j] == '.' || temp[j] =='-') {
                cost += temp[j];
                ++j;
            }
            relations[counter2].costValue = std::stod(cost);
            --i;
            ++counter2;
            temp.clear();
        }
    }
}

void Relation::clear() {
    this->city1.clear();
    this->city2.clear();
    this->costValue = 0;
}

