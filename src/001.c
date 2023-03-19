#include "uthash.h"

struct hashTable {
    int key;
    int val;
    UT_hash_handle hh;
};

struct hashTable* hashtable;

struct hashTable* find(int key) 
{
    struct hashTable* tmp;
    HASH_FIND_INT(hashtable,&key,tmp);
    return tmp;  
}

void insert(int key, int val)
{
    struct hashTable* it = find(key);
    if(it == NULL) {
        struct hashTable* tmp=malloc(sizeof(struct hashTable));
        tmp->key=key;
        tmp->val=val;
        HASH_ADD_INT(hashtable,key,tmp);
    } else {
        it->val=val;
    }   
}

int *twoSum(int* nums, int numsSizes, int target, int* returnSize)
{
    hashtable = NULL;
    for(int i=0; i<numsSizes; i++) {
        struct hashTable* it = find(target-nums[i]);
        if(it != NULL) {
            int* ret =malloc(sizeof(int)*2);
            ret[0] = it->val, ret[1] = i;
            *returnSize = 2;
            return ret;
        }
        insert(nums[i],i);
    }
    *returnSize = 0;
    return NULL;
}