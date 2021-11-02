#include "GreedyApproachAlgorithm.h"

int GreedyApproachAlgorithm::minRelation(int size, int* costValues, bool* foundCities) {
    int min = INT_MAX;
    int minIndex;

    //// FIND THE RELATION WITH THE MINIMUM COST VALUE
    for (int i = 0; i < size; i++) {
        if (!foundCities[i] && costValues[i] < min) {
            min = costValues[i];
            minIndex = i;
        }
    }
    return minIndex;
}

int GreedyApproachAlgorithm::findCost(int size, double** matrix) {

    //// CHECK IF THERE IS POSSIBLE PATH BETWEEN ALL THE CITIES AND RETURN
    //// BACK TO THE START ONE WITHOUT VISITING AGAIN ALL CITIES
    if(!HamiltonianCycle::backtracking(matrix, size))
        return 0;

    int* parent = new int[size];
    int* costValues = new int[size];
    bool* foundCities = new bool[size];

    int t = 0;

    //// SET ALL PARENT AND FOUND CITIES TO MAX/FALSE
    for (int i = 0; i < size; i++) {
        costValues[i] = INT_MAX;
        foundCities[i] = false;
    }

    //// PUSH THE START CITY
    parent[0] = -1;
    costValues[0] = 0;

    for (int i = 0; i < size - 1; i++) {

        int minRelationIndex = GreedyApproachAlgorithm::minRelation(size, costValues, foundCities);

        //// SET THE FOUND CITY
        foundCities[minRelationIndex] = true;

        //// SET COST VALUE BETWEEN THE TWO CITIES
        for (int j = 0; j < size; j++) {
            if (matrix[minRelationIndex][j] && !foundCities[j] && matrix[minRelationIndex][j] < costValues[j]) {
                costValues[j] = matrix[minRelationIndex][j];
                parent[j] = minRelationIndex;
                //// SAVE THE LAST VISITED CITY
                t = j - 1;
            }
        }
    }


    //// ADD TO COST CUM THE COST VALUE BETWEEN START CITY AND FINAL CITY
    int costSum = matrix[t][0];

    for (int i = 1; i < size; i++)
        costSum += matrix[parent[i]][i];

    delete [] parent;
    delete [] costValues;
    delete [] foundCities;

    return costSum;
}

int GreedyApproachAlgorithm::GreedyAlgorithm(PathsMatrix& matrix){
    return GreedyApproachAlgorithm::findCost(matrix.getSize(), matrix.getMatrix());
}


