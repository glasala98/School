#ifndef LISTOFBUCKETS_H
#define LISTOFBUCKETS_H

#include <iostream>
#include <vector>

class Bucket;

class ListOfBuckets {

  private:

    //Attributes
    std::vector <Bucket>* theList;
    int size;

  public:

    ListOfBuckets();
    ~ListOfBuckets();
    Bucket get(int i);
    bool add(Bucket bucket);
    bool remove(Bucket bucket);
    int getSize();
    std::vector <Bucket> getList();
      
};

#endif
