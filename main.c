#include <stdio.h>
#include "main.h"

void main(void)
{
    int nums[]= {2,7,11,15};
    int target = 9;
    int size;
    int* ret = twoSum(nums,sizeof(nums)/sizeof(nums[0]),target,&size);

    if(size!=0) {
        printf("%d %d\n",ret[0],ret[1]);
    }

    printf("build time %s,%s\n",__DATE__,__TIME__);
    return;
}