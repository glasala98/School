#include "EmailNotification.h"

#include <iostream>
#include <fstream>

#include "Activity.h"


using namespace std;

bool EmailNotification::pushEmail() {

	ofstream MyFile("email.txt");
	MyFile << "To: \"User, G52\" <"+email+">\n";
	MyFile << "From: \"System, G52\" <g52mailnotification@gmail.com>\n";
	MyFile << "Subject: "+activity->getMessage()+"\n";
	MyFile << "\n";
	MyFile << activity->getDescription()+"\n";
	string command = "curl --ssl-reqd smtp.gmail.com:587 --mail-from g52mailnotification@gmail.com --mail-rcpt "+email+" --upload-file email.txt --user 'g52mailnotification@gmail.com:G52groupassignment'";
	system(command.c_str());
	remove("email.txt");
	return true;
}

bool EmailNotification::setActivity(Activity new_activity) {
	*activity = new_activity;
	return true;
}

bool EmailNotification::setEmail(string new_email) {
	email = new_email;
	return true;
}

Activity EmailNotification::getActivity() {
	return *activity;
}

string EmailNotification::getEmail() {
	return email;
}
