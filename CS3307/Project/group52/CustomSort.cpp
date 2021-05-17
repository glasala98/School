#include "CustomSort.h"

#include <algorithm>
#include <iostream>
#include <vector>

#include "ActivityList.h"
#include "Activity.h"
#include "DateAndTime.h"

using namespace std;

    bool CustomSort::compare(int parameter, int direction, Activity oldActivity, Activity newActivity) {
        
        if(parameter == 1) {//Time

            if(direction == 1) { return(newActivity.getEstimation().getTime() < oldActivity.getEstimation().getTime()); } 

            else if(direction == 2 ) { return(newActivity.getEstimation().getTime() > oldActivity.getEstimation().getTime()); }
            
            else { 
                cout << "Improper direction passed to custom sort";
                return false;
            }

        }

        else if(parameter == 2) {//Priority

            if(direction == 1) { return(newActivity.getPriority() < oldActivity.getPriority()); } 

            else if(direction == 2 ) { return(newActivity.getPriority() > oldActivity.getPriority()); }
            
            else { 
                cout << "Improper direction passed to custom sort";
                return false;
            }

        }

        else if(parameter == 3) { //Priority and Time
            return false;
        }

        else {
            cout <<"Improper parameter passed to custom sort";
            return false;
        }

    }

    ActivityList CustomSort::shortest(ActivityList theList) {

        int parameter = 1; //Time Rquired
        int direction = 1; //Smallest to Largest

        vector <Activity> tempList = theList.getList();

        sort(tempList.begin(), tempList.end(), [&parameter = parameter, &direction = direction](Activity oldActivity, Activity newActivity) { return compare(parameter, direction, oldActivity, newActivity); } );

        ActivityList sortedList;

        for(int i = 0; i < tempList.size(); i++) {
            sortedList.add(tempList[i]);
        }

        return sortedList;

    }

    ActivityList CustomSort::longest(ActivityList theList) {

        int parameter = 1; //Time Rquired
        int direction = 2; //Largest to Smallest

        vector <Activity> tempList = theList.getList();

        sort(tempList.begin(), tempList.end(), [&parameter = parameter, &direction = direction](Activity oldActivity, Activity newActivity) { return compare(parameter, direction, oldActivity, newActivity); } );

        ActivityList sortedList;

        for(int i = 0; i < tempList.size(); i++) {
            sortedList.add(tempList[i]);
        }

        return sortedList;

    }

    ActivityList CustomSort::highestPriority(ActivityList theList) {

        int parameter = 2; //Priority
        int direction = 2; //Largest to Smallest

        vector <Activity> tempList = theList.getList();

        sort(tempList.begin(), tempList.end(), [&parameter = parameter, &direction = direction](Activity oldActivity, Activity newActivity) { return compare(parameter, direction, oldActivity, newActivity); } );

        ActivityList sortedList;

        for(int i = 0; i < tempList.size(); i++) {
            sortedList.add(tempList[i]);
        }

        return sortedList;

    }

    ActivityList CustomSort::lowestPriority(ActivityList theList) {

        int parameter = 2; //Priority
        int direction = 1; //Smallest to Largest

        vector <Activity> tempList = theList.getList();

        sort(tempList.begin(), tempList.end(), [&parameter = parameter, &direction = direction](Activity oldActivity, Activity newActivity) { return compare(parameter, direction, oldActivity, newActivity); } );

        ActivityList sortedList;

        for(int i = 0; i < tempList.size(); i++) {
            sortedList.add(tempList[i]);
        }

        return sortedList;

    }

    /*ActivityList CustomSort::whatCanIDo(ActivityList theList, int time) {

    }

    ActivityList CustomSort::whatShouldIDo(ActivityList theList, int time) {

    }*/

