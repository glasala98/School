#ifndef NOTIFICATIONS_H
#define NOTIFICATIONS_H


#include <stdio.h>
#include "Activity.h"
#include "DateAndTime.h"


class Notification {

  private:

    //Attributes
    int notificationID, status;
    Activity activity;
    DateAndTime delta;
    Notification deliveryMethod;

  public:

    Notification(int ID, Activity theActivity);
    Notification(int ID, Activity theActivity, DateAndTime theDelta, int method);
    int getID();
    int getStatus();
    bool setStatus(int newStatus);
    Activity getActivity();
    DateAndTime getDelta();
    bool setDelta(DateAndTime newDelta);
    string getDeliveryMethod();
    bool setDeliveryMethod(int method);

};

#endif
