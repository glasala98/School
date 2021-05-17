#ifndef EMAILNOTIFICATION_H
#define EMAILNOTIFICATION_H

#include "Notification.h"

#include <string>

#include "Activity.h"

class EmailNotification : public Notification {

	private:

		//Attributes
		std::string email;

	public:

		bool pushEmail();
		Activity getActivity();
		bool setActivity(Activity new_activity);
		std::string getEmail();
		bool setEmail(std::string new_email);

};

#endif
