int canCompleteCircuit(int* gas, int gasSize, int* cost, int costSize) {

    int diffs[gasSize];
    int sum = 0;

    for (int i = 0; i < gasSize; i++) {
        diffs[i] = gas[i]-cost[i];
        sum += diffs[i];
    }

    if (sum < 0) return -1;

    int loopSum = 0;
    int start = 0;

    for (int i = 0; i < gasSize; i++) {
        loopSum += diffs[i];
        if (loopSum < 0) {
            start = i + 1;
            loopSum = 0;
        }
    }

    return start;
}
