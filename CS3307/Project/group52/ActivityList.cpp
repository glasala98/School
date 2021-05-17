#include "ActivityList.h"
#include "Activity.h"

/**  
 * Creates a list that can store instances of Activity  
 *
 */
using namespace std;

/**
 * default constructor
 * Creates an empty list when called without any param 
 */
ActivityList::ActivityList() {
    size = 0;
}

/**
 * A destructor for ActivityList class
 */
//~ActivityList::ActivityList() {}

/**
 * Getter for ActivityList
 * @param i size of list to create
 * @return A list of size i
 */
Activity ActivityList::get(int i) {
    return (*theList)[i];
}

/**
 * Adds an Activity to ActivityList
 * @param activity An instance of an event that a user wishes to track such as Doctors appt 
 * @return false if activity already exists in list
 * @return true if activity was not found and was added to list
 */
bool ActivityList::add(Activity activity) {

    for(int i = 0; i < size; i++) {
        if((*theList)[i].getID() == activity.getID()) {
            return false;
        }
    }

    theList->push_back(activity);
    size++;
    return true; 

}

/**
 * Remove an Activity from ActivityList
 * @param activity An instance of an event that a user wishes to track such as Doctors appt
 * @return false if activity was not removed
 * @return true if activity was removed
 */
bool ActivityList::remove(Activity activity) {

    for(int i = 0; i < size; i++) {
        if((*theList)[i].getID() == activity.getID()) {
            theList->erase(theList->begin()+i);
            size--;
            return true;
        }
    }

    return false; 
}

/**
 * Merges two lists togethers
 * @param newList ActivityList to merge to this ActivityList
 * @return True if lists were merged
 */
bool ActivityList::concat(ActivityList newList) {
    for(int i = 0; i < newList.getSize(); i++) {
        add(newList.get(i));
    }
    return true;
}

/**
 * Getter to return the size of the list
 * @return returns the size of the list
 */
int ActivityList::getSize() {
    return size;
}

/**
 * Getter that returns this list
 * @return list returns the current list
 */
vector <Activity> ActivityList::getList() {
    return *theList;
}

/*
 * PRINT FUNCTION
 */
