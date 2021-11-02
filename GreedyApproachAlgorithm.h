#ifndef PROJECT_72005_GREEDYAPPROACHALGORITHM_H
#define PROJECT_72005_GREEDYAPPROACHALGORITHM_H
#include "HamiltonianCycle.h"



class GreedyApproachAlgorithm {
private:

public:

    static int GreedyAlgorithm(PathsMatrix&);

private:

    static int minRelation(int, int*, bool*);
    static int findCost(int, double**);
};


#endif //PROJECT_72005_GREEDYAPPROACHALGORITHM_H
