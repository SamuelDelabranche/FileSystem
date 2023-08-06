#include "FileSystem.h"

#include <iostream>
#include <string>

using namespace std;


int main() {
	bool endProg = false;

	FileSystem filesystem;
	std::string userCommand;
	system("cls");

	filesystem.showGUI();
	while (!endProg) {

		getline(cin, userCommand);
		
		// Remove space before the commands
		userCommand.erase(0, userCommand.find_first_not_of(" "));
		// Remove space after the commands
		userCommand.erase(0, userCommand.find_first_not_of(" "));

		
		if ( filesystem.checkCommand(userCommand) == "quitprog" ) { endProg = true; }

		else if ( filesystem.checkCommand(userCommand) == "cd") {
			if (userCommand.size() <= 3) { filesystem.showGUI(true, "NUMARGS"); }
			else {
				// Send to the public method of fileSystem class all the characters after the "cd"
				filesystem.cd(userCommand.substr(3)); // 3 chars "c","d"," "
				filesystem.showGUI();
			}
		} 
		
		else if (filesystem.checkCommand(userCommand) == "ls") {
			if (userCommand.size() <= 3) { filesystem.ls(filesystem.getCurrentPath()); } // if just 'ls', it send to ls command the current path
			else { 
				filesystem.ls(userCommand.erase(0, 3)); // delete 'ls' and the space after 's');
			}

			filesystem.showGUI();

		}
		
		else if (filesystem.checkCommand(userCommand) == "clear") { 
			system("cls");
			filesystem.showGUI();
		}
		
		
		else { filesystem.showGUI(true, "COMMAND"); }

	}

	return 0;
}