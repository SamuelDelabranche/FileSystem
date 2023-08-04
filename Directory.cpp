#include "Directory.h"

#include <string>

using namespace std;

Directory::Directory(const std::string& name, const std::string& path) {
	this->m_name = name;
	this->m_path = path;
}