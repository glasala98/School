#include "ListOfBuckets.h"
#include "Bucket.h"

using namespace std;

/** 
 * Constructor for ListOfBuckets
 */
ListOfBuckets::ListOfBuckets() {
    size = 0;
}

/** 
 * Get the list that contains the users buckets(quizzes, meetings, appointements)
 * @return a list of Buckets
 */
Bucket ListOfBuckets::get(int i) {
    return (*theList)[i];
}

/** 
 * Adds a new Bucket to the ListOfBuckets
 * @param bucket is a new bucket such as 'quizzes' that can be added to the list of buckets a user can set activities without
 * @return bool false if bucket is already in list indiciating bucket was not added
 * @return bool true if bucket was not in list and was added 
 */
bool ListOfBuckets::add(Bucket bucket) {

    for(int i = 0; i < size; i++) {
        if((*theList)[i].getID() == bucket.getID()) {
            return false;
        }
    }

    theList->push_back(bucket);
    size++;
    return true; 

}

/** 
 * Remove a bucket from the list of buckets
 * @param the bucket to be removed
 * @return bool true if bucket was found and removed
 * @return bool false if bucket was not found or removed 
 */
bool ListOfBuckets::remove(Bucket bucket) {

    for(int i = 0; i < size; i++) {
        if((*theList)[i].getID() == bucket.getID()) {
            theList->erase(theList->begin()+i);
            size--;
            return true;
        }
    }

    return false; 
}

/** 
 * Gets the size of the list of buckets
 * @return the size of the list
 */
int ListOfBuckets::getSize() {
    return size;
}

/** 
 * Gets the list that stores all the buckets a user can select
 * @return a list of all buckets available to the users
 */
vector <Bucket> ListOfBuckets::getList() {
    return *theList;
}

