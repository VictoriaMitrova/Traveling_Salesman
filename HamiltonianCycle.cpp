#include "HamiltonianCycle.h"


//TODO
// UPGRADE TO ISFOUND
bool HamiltonianCycle::isSafe(int v, double** matrix, int path[], int pos)  {
    if (matrix[path[pos - 1]][v] == 0)
        return false;

    //// IF RELATION IS ALREADY FOUND, DO NO PUT IT AGAIN
    for (int i = 0; i < pos; i++)
        if (path[i] == v)
            return false;
    return true;
}

bool HamiltonianCycle::hamCycleHelp(double** matrix, int path[], int pos, int size){
    if (pos == size){
        //// IF THIS IS LAST STEP, CHECK IF THERE IS PATH FROM FINAL TO START STATE
        if (matrix[path[pos - 1]][path[0]] != 0)
            return true;
        else
            return false;
    }

    //// IF THIS IS NOT THE LAST STEP
    for (int v = 1; v < size; ++v) {
        if (isSafe(v, matrix, path, pos)){
            path[pos] = v;

            //// RECURSION TO FIND IS IT POSSIBLE TO AROUND ALL THE CITIES
            //// AND RETURN BACK TO THE START ONE
            if (hamCycleHelp (matrix, path, pos + 1, size))
                return true;

            //// IF IN THIS STATE THERE IS NO POSSIBLE SOLUTION
            //// REMOVE IT FROM PATH AND CONTINUE
            path[pos] = -1;
        }
    }
    return false;
}

bool HamiltonianCycle::hamCycle(double** matrix, int size)
{
    //// CREATE AND FILL PATH WITH -1, ALREADY NOT FOUND VISITED CITIES
    int *path = new int[size];
    for (int i = 0; i < size; i++)
        path[i] = -1;

    //// ADD THE START STATE TO PATH
    path[0] = 0;
    if (!hamCycleHelp(matrix, path, 1, size)){
        std::cout << "\nSolution does not exist";
        return false;
    }
    std::cout << "Solution Exists \n";
    return true;
}

bool HamiltonianCycle::backtracking(double **matrix, int size) {
    return hamCycle(matrix, size);
}

