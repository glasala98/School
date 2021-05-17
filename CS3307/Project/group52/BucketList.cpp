#include "BucketList.h"
#include "Bucket.h"

using namespace std;

    Bucket BucketList::getBucket() {
        return *bucket;
    }
