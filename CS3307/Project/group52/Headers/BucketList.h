#ifndef BUCKETLIST_H
#define BUCKETLIST_H

#include <stdio.h>
#include <vector>
#include "ActivityList.h"
#include "Bucket.h"


class BucketList : public ActivityList {

  private:

    //Attributes
    Bucket bucket;
    
  public:

    bucket getBucket();

};

#endif

