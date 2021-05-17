#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "Activity.h"
#include "ActivityList.h"
#include "Bucket.h"
#include "BucketList.h"
#include "configRead.h"
#include "configWrite.h"
#include "CustomSort.h"
#include "DateAndTime.h"
#include "EmailNotification.h"
#include "ListOfBuckets.h"
#include "Medication.h"
#include "Notification.h"
#include "NotificationDelivery.h"
#include "NotificationStructure.h"
#include "TextNotification.h"
#include "User.h"
#include "UserList.h"
#include "Util.h"

using namespace std;

int main() {

    UserList theList = Util::initializeSystem("FILENAME");

    if (theList.getSize() == 0) {

        cout << "\n\nWelcome! Create the first user";
        User newUser = User(theList);

    }

    vector <string> selections;

    selections[1] = "1: Sign In";
    selections[2] = "2: Create a New User";
    selections[3] = "3: Exit";

    int selection = Util::userInput("Welcome! Choose from the following options", selections);

    if (selection == 3) {
        Util::exit();
        return 0;
    }

    User theUser;

    if(selection == 2) { User(theList); } //Creates a new User

    else if(selection == 1) {  //Attempts to sign the user in
        
        if(!Util::signIn(theUser, theList)) {
            Util::exit();
            return 0;
        }  
    }

    if (theUser.initialize()) { cout << "\n\n\nError! User could not be initialized\n\n\n"; } //Initializes the Users objects from storage to memory

    selection = 0;

    while(true) { //Core interaction loop

            selections = vector <string>();

            selections[1] = "1: Add an Activity";
            selections[2] = "2: Add a Bucket";
            selections[3] = "3: View My Calendar";
            selections[4] = "4: View My To-Do List";
            selections[5] = "5: Custom Sort";
            selections[6] = "6: Exit";

            selection = Util::userInput("\n\nError: No User with this username exists", selections);

        if (selection == 6) { //Exit
            Util::exit();
            return 0;
        }

        else if(selection == 1) { Activity newActivity = Activity(theUser); } //Add an Activity

        else if (selection == 2) { //Add a bucket

            int bucketID = theUser.getNextBucketID();
            if (!theUser.bumpNextBucketID()) { "\n\n\nERROR!\n\n\n"; }
            Bucket newBucket = Bucket(bucketID);
            theUser.getListOfBuckets().add(newBucket);

        }

        else if (selection == 3) { //Display Calendar
	
        }

        else if (selection == 4) { //Display To-Do List

        }

        else if (selection == 5) { //Custom Sort
             
        }

    }

}
