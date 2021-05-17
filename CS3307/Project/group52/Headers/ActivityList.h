#ifndef ACTIVITYLIST_H
#define ACTIVITYLIST_H

#include <stdio.h>
#include <vector>

class ActivityList {

  private:

    //Attributes
    vector <Activity> list;
    int size;
            
  public:

    ActivityList();
    bool add(Activity activity);
    bool remove(Activity activity);
    bool concat(vector <Activity> newList);
    int getSize();
    vector <Activity> getList();
};

#endif
