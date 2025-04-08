/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findMissingAndRepeatedValues(int** grid, int gridSize, int* gridColSize, int* returnSize) {
    
    int *seen = (int*)calloc(gridSize*gridColSize[0], sizeof(int));
    int missing = -1;
    int repeated = -1;

    for(int i=0; i<gridSize; i++) {
        for(int j=0; j<gridColSize[i]; j++) {
            int val = grid[i][j];
            seen[val-1]++;
        }
    }

    for(int i=0; i<gridSize*gridColSize[0];i++) {
        if(seen[i]==0) {
            missing = i+1;
            continue;
        }
        if(seen[i]==2) repeated = i+1;
    }

    int *result = (int*)malloc(2*sizeof(int));
    result[0]=repeated;
    result[1]=missing;

    *returnSize=2;
    
    free(seen);

    return result;
}
