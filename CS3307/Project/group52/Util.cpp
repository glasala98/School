#include "Util.h"
#include "UserList.h"
#include "User.h"

using namespace std;

    int Util::userInput(string initString, vector <string> selections) {

        int size = selections.size();
        int selection = 0;

        cout << initString;
        cout << "\n\n";

        while(selection == 0) {

            for(int i = 0; i < size; i++) {
                cout << selections[i];
                cout << "\n";
            }

            cout << "\nSelection: ";
            cin >> selection;

            if(selection < 1 || selection > size) {
                cout << "\n\nError: Please choose from the available selections";
                selection == 0;
            }
        }

        return selection;

    }

    bool Util::exit() {

        //Code to save the objects in memory to data files
        return true; //temp

    }

    UserList Util::initializeSystem(string filepath) {

        //Code to initialize from UserList
        return UserList(); //temp

    }

    bool Util::signIn(User theUser, UserList theList) {

        string username, password;
        int selection;

        while (true) {

            cout << "\nUsername: ";
            cin >> username;

            for(int i = 0; i < theList.getSize(); i++) {

                User currentUser = theList.get(i);

                if (username == currentUser.getUsername()) {
                    theUser = currentUser;
                    break;
                }

            }

            vector <string> selections;

            selections[1] = "1: Try Again";
            selections[2] = "2: Exit";

            selection = Util::userInput("\n\nError: No User with this username exists", selections);

            if (selection == 2) {
                Util::exit();
                return 0; 
            }
        }

        selection = 0;
        
        while (true) {

            cout << "\nPassword: ";
            cin >> password;

            if (theUser.authenticate(password)) { return true; }

            vector <string> selections;

            selections[1] = "1: Try Again";
            selections[2] = "2: Exit";

            selection = Util::userInput("Error: The password is incorrect", selections);

            if (selection == 2) { return false; }

        }
    }
