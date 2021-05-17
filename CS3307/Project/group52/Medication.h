#include <iostream>

#include "Activity.h"

using namespace std;

class Medication : public Activity {

	private:

		//Attributes
		string medName;
		int dosageAmount;
		bool taken;

	public:

		bool setDosage(int dosage);

		bool setMedName(string name);

		bool setTaken(bool status);

		string getMedName();

		int getDosage();

		bool getTaken();
};
