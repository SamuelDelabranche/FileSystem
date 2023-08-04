#pragma once
#ifndef FILE_H
#define FILE_H

#include <string>

class File
{
	public:
		File(std::string name, std::string path = "/");

	private:
		std::string m_name;
		std::string m_path;
};

#endif