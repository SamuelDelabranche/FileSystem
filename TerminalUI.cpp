#include "TerminalUI.h"

using namespace std;

TerminalUI::TerminalUI() {}

// GUI
void TerminalUI::WelcomeMessage(const string& systemVersion) const {
	cout << "\t\t" << systemVersion << this->m_welcomeMessage << endl << endl;

}


void TerminalUI::getChoiceGUI() const {
	cout << "\n\n";
	cout << "\t\t- QuitProg {Command to quit the program}" << endl;
	cout << "\t\t- help {Help -command // It show the helper text of the command}" << endl;
	cout << "\t\t- Cd {Command for changing current PATH}" << endl;
}




void TerminalUI::showPath(const std::filesystem::path& path, const bool tabJump) const {
	if (tabJump) {
		cout << path << endl;
	}
	else {
		cout << path;
	}
}

void TerminalUI::showErrorMessage(const string& errorCode) const {
	if (errorCode == "PATH") {
		cout << " Error::PATH::This isn't a PATH!";
	}
	else if (errorCode == "COMMAND") {
		cout << " Error::COMMANDS::This command isn't impleted yet!";
	}
}