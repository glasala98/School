#ifndef BUCKETLIST_H
#define BUCKETLIST_H

#include <iostream>
#include <vector>

#include "ActivityList.h"
class Bucket;


class BucketList : public ActivityList {

  private:

    //Attributes
    Bucket *bucket;
    
  public:

    Bucket getBucket();

};

#endif

