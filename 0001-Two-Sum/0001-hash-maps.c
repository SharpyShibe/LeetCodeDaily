#include <stdlib.h>

//solution using a simple hash map

int TABLE_SIZE;

typedef struct HashNode {
    int key;
    int value;
    struct HashNode* next;
} HashNode;

HashNode **hashTable = NULL;

int hash(int key) {
    if (key < 0) key = -key;
    return key % TABLE_SIZE;
}

void insert(int key, int value) {
    int h = hash(key);
    HashNode* node = (HashNode*)malloc(sizeof(HashNode));
    node->key =  key;
    node->value = value;
    node->next = hashTable[h];
    hashTable[h] = node;
}

bool find(int key, int *found_index_rtn) {
    int h = hash(key);
    HashNode* node = hashTable[h];
    *found_index_rtn = 0;

    while (node) {
        if (node->key == key) {
            *found_index_rtn = node->value;
            return 1;
        }
        node = node->next;
    }
    return 0;
}

void clear_table() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        HashNode* node = hashTable[i];
        while (node) {
            HashNode* tmp = node;
            node = node->next;
            free(tmp);
        }
        hashTable[i] = NULL;
    }
}

int next_prime(int n) {
    while (1) {
        int is_prime = 1;
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                is_prime = 0;
                break;
            }
        }
        if (is_prime) return n;
        n++;
    }
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    *returnSize = 2;
    int* result = (int*)malloc(sizeof(int) * 2);

    //Keep hashTable size as small as feasably possible
    TABLE_SIZE = next_prime(numsSize*2);
    hashTable = malloc(sizeof(HashNode*)*TABLE_SIZE);
    memset(hashTable, 0, sizeof(HashNode*)*TABLE_SIZE);
    clear_table();

    int complement = 0;
    int foundIndex = 0;
    for (int i = 0; i < numsSize; i++) {
        complement = target - nums[i];

        if (find(complement, &foundIndex)) {
            result[0] = foundIndex;
            result[1] = i;
            return result;
        }
        insert(nums[i], i);
    }

    *returnSize = 0;
    clear_table();
    free(hashTable);
    return NULL;
}
