#pragma once
#ifndef FILESYSTEM_H
#define FILESYSTEM_H

#include "TerminalUI.h"
#include "Directory.h"
#include "File.h"

#include <filesystem>


class FileSystem
{
	public:
		FileSystem();
		~FileSystem();

		void cd(const std::string userCommand); // Change path
		std::string checkCommand(std::string& userCommand) const;

		void getCurrentPath(const bool& jump) const; // Show the current path

		void showGUI(const bool& error = false, const std::string& errorMessage = "None") const;


	private:
		Directory* m_rootDirectory; // create an root directory
		TerminalUI* m_terminalUI;

		std::filesystem::path m_currentPath; // currentPath (Path of the file)

		//Text
		std::string m_systemVersion = "v0.1";


		void initVariables(); // Initialize all the class variables
		void lowerString(std::string &textToLower) const;

};

#endif