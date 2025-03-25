
int findLucky(int* arr, int arrSize) {
    //Offset by one since smallest int possible in arr is 1
    //So count[0] hold count for 1, count[1] for 2, ...
    int count[500] = {0};

    for(int i=0; i<arrSize; i++)
        count[arr[i]-1] += 1;

    int maxLucky = -1;
    for(int i=0; i<500; i++) 
        if(i+1 == count[i]) maxLucky = i+1;
    
    return maxLucky;
}
