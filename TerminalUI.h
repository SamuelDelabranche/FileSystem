#pragma once
#ifndef TERMINALUI_H
#define TERMINALUI_H

#include <iostream>
#include <string>
#include <filesystem>

class TerminalUI
{
	public:
		TerminalUI();

		void WelcomeMessage(const std::string& systemVersion) const;
		void showPath(const std::filesystem::path& path, const bool tabJump) const; // Show path
		void showErrorMessage(const std::string &errorCode) const;
		void getChoiceGUI() const;

	private:
		std::string m_welcomeMessage = "-#- File system like 'Linux' -#-";

};	

#endif