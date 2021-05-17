#ifndef NOTIFICATIONDELIVERY_H
#define NOTIFICATIONDELIVERY_H


#include <iostream>

class Activity;
class DateAndTime;


class NotificationDelivery {

  private:

    //Attributes
    int notificationID, method;
    Activity *activity;
    DateAndTime *pushTime;

  public:

    NotificationDelivery();
    NotificationDelivery(DateAndTime time, int method, Activity theActivity);
    int getID();
    Activity getActivity();
    DateAndTime getPushTime();
    bool setPushTime(DateAndTime newTime);
    int getDeliveryMethod();
    bool setDeliveryMethod(int newMethod);

};

#endif