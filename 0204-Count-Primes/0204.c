#define GET_BIT(arr, idx) ((arr[(idx) >> 3] >> ((idx) & 7)) & 1)
#define SET_BIT(arr, idx) (arr[(idx) >> 3] |= (1 << ((idx) & 7)))
#define CLEAR_BIT(arr, idx) (arr[(idx) >> 3] &= ~(1 << ((idx) & 7)))

//Simple implementation using the Sieve of Eratosthenes
//using a bitset for memory optimization which
//seems to be a good choice since this code consistenly 
//beats >98% of other submissions on Leetcode if you 
//trust Leetcode's memory metrics (which you shouldn't).
//As for the runtime, skipping even numbers in the loops places this
//solution in the top 10%.
int countPrimes(int n) {

    if(n==0 || n==1 || n==2) return 0;

    int size = (n >> 3) +1; //>>3 :=: divide by 8 to get bytes

    uint8_t *is_prime = malloc(size);
    if (!is_prime) {
        perror("Memory allocation failed");
        exit(1);
    }

    for (int i = 0; i < size; i++) {
        is_prime[i] = 0xFF;
    }

    CLEAR_BIT(is_prime, 0);
    CLEAR_BIT(is_prime, 1);
    SET_BIT(is_prime, 2);
    for (int i=3; i*i < n; i = i+2) {
        if (GET_BIT(is_prime, i)) {
            for (int j = i*i; j <=n; j += i) {
                CLEAR_BIT(is_prime, j);
            }
        }
    }

    int total = 0;
    for (int i = 3; i < n; i += 2) {
        if (GET_BIT(is_prime, i)) {
            total += 1;
        }
    }

    free(is_prime);
    return total+1;
}
