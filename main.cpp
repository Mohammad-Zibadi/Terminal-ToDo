#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <windows.h>
#include "include/Task.h"

using std::vector;
using std::string;
using std::cout;
using std::cin;
using std::ws;


string toLower(string str)
{
	transform(str.begin(), str.end(), str.begin(), ::tolower);
	return str;
}

Task createNewTask ()
{
	string title, description, dueDate, priority;

	cout << "Task Title: ";
	getline(cin >> ws, title);
	cout << "Task Description: ";
	getline(cin >> ws, description);
	
	//ToDo show a calendar
	
	cout << "Task Due Date Like (2022/07/05 17:00): ";
	getline(cin >> ws, dueDate);
	cout << "Task Priority (low, medium, high): ";
	getline(cin >> ws, priority);
	

	Task task;
	task.getData(title, description, dueDate, priority);
	return task;
	
//	if(priority != "low" || priority != "medium" || priority != "high")
//		cout << "Please Enter One Of Thease Options: (low, medium, high)";
	
}

void space(int numberOfSpaces){
    for(int i = 0; i < numberOfSpaces; i++)
        cout << " ";
}

int main(int argc, char** argv) {
	
	vector<Task> tasks;
	
	while(true){
	
		string entry_point_command;
		cout << "\nPlease Enter One Of Thease Options: (tasks, calendar)\n";
		cin >> entry_point_command;
		
		if(entry_point_command == "calendar"){
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			
			int firstDay = 6;
			int daysOfMonth = 31;
			int lineLenght = 1;
			
			cout << "      2022/07\n";
			cout << "Sa Su Mo Tu We Th Fr\n ";
			
			space(firstDay * 3);
			
			vector<int> taskDays;
			for(Task task : tasks){
				string dueDate = task.getDueDate();
				int day;
				
				if(dueDate[8] == 0){
					string temp = "";
					temp += dueDate[9];
					day = std::stoi(temp);
				}else{
					string temp = "";
					temp += dueDate[8];
					temp += dueDate[9];
					day = std::stoi(temp);
				}
				
				taskDays.push_back(day);
			}                        
			
			lineLenght += firstDay * 3;
			
			for(int i = 1; i <= daysOfMonth; i++){
				
				bool isInTaskDays = false;
				for(int taskDay : taskDays)
					if(i == taskDay)
						isInTaskDays = true;
				
				if(isInTaskDays)
					SetConsoleTextAttribute(hConsole, 10);
				else
					SetConsoleTextAttribute(hConsole, 15);
					
		        cout << i;
		        lineLenght++;
		        if(lineLenght >= 20 && i != daysOfMonth){
		            if(i < 9) 
						cout << "\n ";
		            else 
						cout << '\n';
		            lineLenght = 1;
		        }
		        else if(i < 9){
		            space(2);
		            lineLenght += 2;
		        }
		        else if(i >= 9 && i < daysOfMonth){
		            space(1);
		            lineLenght += 2;
		        }
		        
		        if(i == daysOfMonth && lineLenght < 20)
					space(2);
		    }
			
		}else if(entry_point_command == "tasks"){
			while(true){
				
				cout << "Your Tasks Are:\n";
				int i = 0;
				
				for(Task task : tasks){
					cout << "Task Number: " << ++i << '\n';
					task.show();
					cout << '\n';
				}
			
				string command;
				cout << "Options Are: (A, D, E, F, Q)\n";
				
				cin >> command;
				command = toLower(command);
				
				if(command == "a"){
					Task task = createNewTask();
					string save_or_exit;
					cout << "Enter S Key To Save The Task, Otherwise Enter Q Key To Exit!\n";
					cin >> save_or_exit;
					save_or_exit = toLower(save_or_exit);
						if(save_or_exit == "s"){
							tasks.push_back(task);
							cout << "Done!\n\n";
							continue;
						}else if(save_or_exit == "q")
							continue;
				}else if(command == "d"){
					int task_number;
					cout << "To Delete A Task, Enter Its Number.\n";
					cin >> task_number;
					task_number--;
					tasks.erase(tasks.begin() + task_number);
					cout << "Done!\n\n";
				}else if(command == "e"){
					int task_number;
					cout << "To Edit A Task, Enter Its Number.\n";
					cin >> task_number;
					
					string title, description, dueDate, priority;
	
					cout << "New Task Title: ";
					getline(cin >> ws, title);
					cout << "New Task Description: ";
					getline(cin >> ws, description);
					
					//ToDo show a calendar
					
					cout << "New Task Due Date Like (year/month/day hh:mm): ";
					getline(cin >> ws, dueDate);
					cout << "New Task Priority (low, medium, high): ";
					getline(cin >> ws, priority);
					task_number--;
					tasks.at(task_number).setTitle(title);
					tasks.at(task_number).setDescription(description);
					tasks.at(task_number).setDueDate(dueDate);
					tasks.at(task_number).setPriority(priority);
					cout << "Done!\n\n";
					continue;
				}else if(command == "f"){
					int task_number;
					
					cout << "To Done Or Undone A Task, Enter Its Number.\n";
					cin >> task_number;
					task_number--;
					string title = tasks.at(task_number).getTitle();
					if(title[0] != '*')
						tasks.at(task_number).setTitle("*" + title);
					else{
						int i = 0;
						for(auto ch : title){
							if(i != 0)
								title[i-1] = ch;
							title[i] = '\0';
							++i;
						}
						
						tasks.at(task_number).setTitle(title);
					}
						
					cout << "Done!\n\n";
				}else if(command == "q")
					break;
			}
		}
	
	}

	return 0;
}