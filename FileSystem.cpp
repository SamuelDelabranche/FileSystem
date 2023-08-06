#include "FileSystem.h"

using namespace std;
namespace fs = std::filesystem;

FileSystem::FileSystem() {
	this->initVariables();

}

FileSystem::~FileSystem() {
	delete this->m_rootDirectory;
	delete this->m_terminalUI;
}







// private Function
void FileSystem::initVariables() {
	this->m_rootDirectory = new Directory("root");
	this->m_currentPath = fs::current_path();

	this->m_terminalUI = new TerminalUI();
}

void FileSystem::lowerString(string& textToLower) const {
	int i = 0;

	for (char& letter : textToLower) {
		if (letter >= 'A' && letter <= 'Z') { // if letter is UpperCase
			textToLower[i] = letter+32;
		}
		++i;
	}
}


// public function

void FileSystem::showGUI(const bool& error, const std::string& errorMessage) const {
	for (int i = 0; i < this->m_currentPath.string().size(); i++) {
		cout << "-";
	}

	this->m_terminalUI->WelcomeMessage(this->m_systemVersion);
	cout << "Your currentPATH : "; this->showCurrentPath(false); cout << endl;

	for (int i = 0; i < this->m_currentPath.string().size(); i++) {
		cout << "-" ;
	}
	this->m_terminalUI->getChoiceGUI();	
	if (error) {
		m_terminalUI->showErrorMessage(errorMessage);
	}
	cout << "\n\n" << "\t\t Your Choice: ";


}

string FileSystem::checkCommand(string& userCommand) const {
	string tempVar = userCommand.substr(0, userCommand.find_first_of(" "));
	this->lowerString(tempVar);

	return tempVar;
}


// START CD COMMAND

void FileSystem::cd(const string userCommand) {
	if (userCommand != "..") {
		if(userCommand == "."){ this->m_currentPath = fs::current_path(); }
		else {
			fs::path tempPath = this->m_currentPath / userCommand; // CurrentPATH / path

			if (fs::exists(tempPath) && fs::is_directory(tempPath)) {
				this->m_currentPath = tempPath.string();
				this->showCurrentPath(true);
			}
			else {
				this->m_terminalUI->showErrorMessage("PATH");
			}
		}


	}
	else {
		this->m_currentPath = m_currentPath.parent_path();
		this->showCurrentPath(true);
	}
}

// END CD COMMAND

// START LS COMMAND

void FileSystem::ls(string userCommand) {
	vector<string> L_file;
	if (commandLSChecker(userCommand)) {
		if (!(fs::is_empty(userCommand))) {
			cout << "Directory(ies): " << endl;

			for (auto const& element_ : fs::directory_iterator(userCommand)) {
				if (!(fs::is_directory(element_))) { L_file.push_back(element_.path().filename().string()); }
				else {
					cout << "\t" << element_.path().filename().string() << endl;
				}
			}
		}
		else {
			cout << "This file is empty! " << endl;
		}

		if (L_file.size() > 0) {
			cout << "File(s): " << endl;
			for (const string element : L_file) {
				cout << "\t" << element << endl;
			}
		}
	}
	else {
		this->m_terminalUI->showErrorMessage("PATH");
	}
}


bool FileSystem::commandLSChecker(const string userCommand) const {
	return (userCommand == this->m_currentPath.string() || (fs::is_directory(userCommand) && fs::exists(userCommand)));
	// return true if userCommand is current path or other valid directory path

}




void FileSystem::showCurrentPath(const bool& jump) const {
	this->m_terminalUI->showPath(this->m_currentPath, jump);
}

string FileSystem::getCurrentPath() const {
	return this->m_currentPath.string();
}