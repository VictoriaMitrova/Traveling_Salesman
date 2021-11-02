#include "City.h"


City::City() {
    this->index = 0;
}

City::~City(){
    this->name.clear();
    this->index = 0;
}

std::string& City::getName() {
    return this->name;
}

int City::getIndex() {
    return this->index;
}

void City::setName(std::string& newName) {
    this->name.clear();
    this->name = newName;
}

void City::setIndex(int newIndex) {
    this->name = newIndex;
}

bool City::isCity(std::string content, int& current){

    int counter = current;

    while((content[counter] != ';' && content[counter] != '-') && content[counter + 1] != '\0'){
        if ((content[counter + 1] == '-' && content[counter + 2] == '>') || content[counter + 1] == '\0') {
            return false;
        }
        ++counter;
    }
    return true;
}

void City::setCity(std::string content, City* citiesNames){

    int counter = 0;
    for(int i = 0; content[i] != '\0'; ++i){
        if(content[i] == '{'){
            ////REMOVE '{'
            ++i;
            if(isCity(content, i)){
                while(content[i] != ';' && content[i] !='\0'){
                    citiesNames[counter].name += content[i];
                    ++i;
                }
                //// GO BACK TO content[i] = ';', CHECKING FOR THE NEXT ELEMENT PROPERLY
                --i;
                citiesNames[counter].index = counter;
                ++counter;
            }
        } else if(content[i] == ';'){
            //// REMOVE ';'
            ++i;
            if(isCity(content, i) && content[i] !='}') {
                while (content[i] != ';' && content[i] !='\0') {
                    citiesNames[counter].name += content[i];
                    ++i;
                }
                //// GO BACK TO content[i] = ';', CHECKING FOR THE NEXT ELEMENT PROPERLY
                --i;
                citiesNames[counter].index = counter;
                ++counter;
            }
        }
    }
}

