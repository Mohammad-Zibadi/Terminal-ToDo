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
	// initializing variables from the user console input
	void getData(string, string, string, string);
	void show();
	void setTitle(string);
	void setDescription(string);
	void setDueDate(string);
	void setPriority(string);
	string getTitle();
	string getDescription();
	string getDueDate();
	string getPriority();
	
private:
	string m_title;
	string m_description;
	string m_dueDate;
	string m_priority;
};

#endif