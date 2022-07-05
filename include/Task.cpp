#include "Task.h"

void Task::getData(string title, string description, string dueDate, string priority)
{
	m_title = title;
	m_description = description;
	m_dueDate = dueDate;
	m_priority = priority;
}

void Task::setTitle(string title)
{
	m_title = title;
}

void Task::setDescription(string description)
{
	m_description = description;
}

void Task::setDueDate(string dueDate)
{
	m_dueDate = dueDate;
}

void Task::setPriority(string priority)
{
	m_priority = priority;
}

string Task::getTitle()
{
	return m_title;
}

string Task::getDescription()
{
	return m_description;
}

string Task::getDueDate()
{
	return m_dueDate;
}

string Task::getPriority()
{
	return m_priority;
}

void Task::show()
{
	cout << "Title: " << m_title << '\n'
		 << "Description: " << m_description << '\n'
		 << "Due Date: " << m_dueDate << '\n'
		 << "Priority: " << m_priority << '\n';
}