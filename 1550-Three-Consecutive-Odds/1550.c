bool threeConsecutiveOdds(int* arr, int arrSize) {

    char foundConsec = 0;
    
    for(ushort i=0; i<arrSize; i++) {
        if(arr[i] % 2 == 1) foundConsec++;
        else foundConsec = 0;

        if(foundConsec==3) return true;
    }

    return false;
}
