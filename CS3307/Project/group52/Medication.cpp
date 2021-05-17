#include <iostream>
#include <stdio.h>
#include "Medication.h"

using namespace std;

bool Medication::setDosage(int dosage) {

			dosageAmount = dosage;
			return true;

		}

bool Medication::setMedName(string name) {

			medName = name;
			return true;

		}

bool Medication::setTaken(bool status) {

			taken = status;
			return true;

		}

string Medication::getMedName() {

			return medName;

		}

int Medication::getDosage() {

			return dosageAmount;

		}

bool Medication::getTaken() {

			return taken;

		}






