#include "Task.h"

void Task::getData(string title, string description, string dueDate, string priority)
{
	m_title = title;
	m_description = description;
	m_dueDate = dueDate;
	m_priority = priority;
}

//Task::Task(string title, string description, string dueDate, string priority) :
//	m_title(title), m_description(description), m_dueDate(dueDate), m_priority(priority)
//{
//}

void Task::show()
{
	cout << "Title: " << m_title << '\n'
		 << "Description: " << m_description << '\n'
		 << "Due Date: " << m_dueDate << '\n'
		 << "Priority: " << m_priority << '\n';
}