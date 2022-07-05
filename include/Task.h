#ifndef TASK_H
#define TASK_H

#include <iostream>
#include <string>
#include <algorithm>

using std::string;
using std::cout;

class Task
{
public:
	void getData(string, string, string, string);
	void show();
	
private:
	string m_title;
	string m_description;
	string m_dueDate;
	string m_priority;
};

#endif