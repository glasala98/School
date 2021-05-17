#include <iostream>

#include "Notification.h"

using namespace std;

class TextNotification : public Notification {

	private:
		string phonenumber;

	public:
		bool pushTextMessage();
		Activity getActivity();
		bool setActivity(Activity new_activity);
		string getNumber();
		bool setNumber(string new_number);
};
