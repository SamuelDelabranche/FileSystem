#pragma once
#ifndef DIRECTORY_H
#define DIRECTORY_H

#include <vector>
#include <string>

#include "File.h"


class Directory
{
	public:
		Directory(const std::string &name, const std::string &path = "/");


	private:
		// Files and Directories that the Directory have.
		std::vector<File> l_files; 
		std::vector<Directory> l_directories;

		// His name / path
		std::string m_name;
		std::string m_path;


};

#endif