#include "TextNotification.h"
#include "Activity.h"

bool TextNotification::pushTextMessage() {
	string command = "curl -X POST \ -H \"Authorization: Bearer c64aaa531c39443c905977b0cba78158\" \ -H \"Content-Type: application/json\" -d ' { \"from\": \"14243696086\", \"to\": [ \""+phonenumber+"\" ], \"body\": \""+activity.message+"\"}' \ \"https://sms.api.sinch.com/xms/v1/cac10fb6f24d4674899bbd0276dfed18/batches\"";
	system(command.c_str());
	return true;
}

bool TextNotification::setActivity(Activity new_activity) {
	activity = new_activity;
	return true;
}

bool TextNotification::setNumber(string new_number) {
	phonenumber = new_number;
	return true;
}

string TextNotification::getNumber() {
	return phonenumber;
}

Activity TextNotification::getActivity() {
	return activity;
}
