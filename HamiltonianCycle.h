#ifndef PROJECT_72005_HAMILTONIANCYCLE_H
#define PROJECT_72005_HAMILTONIANCYCLE_H
#include "PathsMatrix.h"



//// USING HAMILTONIAN CYCLE TO CHECK IF PATH EXIST

class HamiltonianCycle {
public:

    static bool backtracking(double**, int);

private:
    static bool isSafe(int, double**, int[], int);
    static bool hamCycleHelp(double**, int[], int, int);
    static bool hamCycle(double**, int);

};


#endif //PROJECT_72005_HAMILTONIANCYCLE_H
