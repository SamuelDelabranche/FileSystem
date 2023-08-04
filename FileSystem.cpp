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
	this->m_terminalUI->WelcomeMessage(this->m_systemVersion);
	cout << "Your currentPATH : "; this->getCurrentPath(false); cout << endl;

	for (int i = 0; i < this->m_currentPath.string().size(); i++) {
		cout << "-" ;
	}
	this->m_terminalUI->getChoiceGUI();	
	if (error) {
		m_terminalUI->showErrorMessage(errorMessage);
	}
	cout << "\n\n" << "\t\t Your Choice (number): ";


}



void FileSystem::cd(const std::string userCommand) {
	if (userCommand != "..") {
		if(userCommand == "."){ this->m_currentPath = fs::current_path(); }
		else {
			fs::path tempPath = this->m_currentPath / userCommand; // CurrentPATH / path

			if (fs::exists(tempPath) && fs::is_directory(tempPath)) {
				this->m_currentPath = tempPath.string();
				this->getCurrentPath(true);
			}
			else {
				this->m_terminalUI->showErrorMessage("PATH");
			}
		}


	}
	else {
		this->m_currentPath = m_currentPath.parent_path();
		this->getCurrentPath(true);
	}
}

string FileSystem::checkCommand(string& userCommand) const{
	string tempVar = userCommand.substr(0, userCommand.find_first_of(" "));
	this->lowerString(tempVar);

	return tempVar;
}

void FileSystem::getCurrentPath(const bool& jump) const {
	this->m_terminalUI->showPath(this->m_currentPath, jump);
}