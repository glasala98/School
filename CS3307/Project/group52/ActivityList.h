#ifndef ACTIVITYLIST_H
#define ACTIVITYLIST_H

#include <iostream>
#include <vector>

class Activity;

class ActivityList {

  private:

    //Attributes
    std::vector <Activity>* theList;
    int size;
            
  public:

    ActivityList();
    ~ActivityList();
    Activity get(int i);
    bool add(Activity activity);
    bool remove(Activity activity);
    bool concat(ActivityList newList);
    int getSize();
    std::vector <Activity> getList();
};

#endif
