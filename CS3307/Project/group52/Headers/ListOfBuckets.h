#ifndef LISTOFBUCKETS_H
#define LISTOFBUCKETS_H

#include <stdio.h>

class ListOfBuckets {

  private:

    //Attributes
    vector <Bucket> list;
    int size;

  public:

    ListOfBuckets();
    bool add(Bucket bucket);
    bool remove(Bucket bucket);
    int getSize();
    vector <Bucket> getList();
      
};

#endif
