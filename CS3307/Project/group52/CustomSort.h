#ifndef CUSTUMSORT_H
#define CUSTOMSORT_H

class Activity;
class ActivityList;

namespace CustomSort {

    bool compare(int parameter, int direction, Activity oldActivity, Activity newActivity);
    ActivityList shortest(ActivityList theList);
    ActivityList longest(ActivityList theList);
    ActivityList highestPriority(ActivityList theList);
    ActivityList lowestPriority(ActivityList theList);
    ActivityList whatCanIDo(ActivityList theList, int time);
    ActivityList whatShouldIDo(ActivityList theList, int time);

};

#endif
