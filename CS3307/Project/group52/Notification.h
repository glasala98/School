#ifndef NOTIFICATION_H
#define NOTIFICATION_H


#include <iostream>

class Activity;
class DateAndTime;
class NotificationDelivery;


class Notification {

  protected:

    //Attributes
    int notificationID, status, method;
    Activity *activity;
    DateAndTime *delta;
    NotificationDelivery *deliveryMethod;

  public:

    Notification();
    Notification(int ID, Activity theActivity);
    Notification(DateAndTime theDelta, int theMethod);
    Notification(int ID, Activity theActivity, DateAndTime theDelta, int theMethod);
    bool notificationTemplate();
    int getID();
    int getStatus();
    bool setStatus(int newStatus);
    Activity getActivity();
    DateAndTime getDelta();
    bool setDelta(DateAndTime newDelta);
    int getDeliveryMethod();
    bool setDeliveryMethod(int theMethod);

};

#endif
