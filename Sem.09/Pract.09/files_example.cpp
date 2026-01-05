#pragma warning (disable: 4996)
#include <iostream>
#include <fstream>

const size_t BUFFER_SIZE = 1024;
const char* STUDENTS_FILE_NAME = "students.txt";

struct Student {
	char* name;
	int age;
};

void freeStudents(Student* students, size_t count) {
	for (size_t i = 0; i < count; i++)
	{
		delete[] students[i].name;
	}

	delete[] students;
}

Student* readStudents(std::istream& is, size_t& count) {
	is >> count;

	Student* students = new Student[count];

	for (size_t i = 0; i < count; i++)
	{
		char buffer[BUFFER_SIZE];
		is >> buffer;

		students[i].name = new char[strlen(buffer) + 1];
		strcpy(students[i].name, buffer);

		is >> students[i].age;
	}

	return students;
}

Student* readStudentsFromFile(const char* fileName, size_t& count) {
	if (!fileName)
		return nullptr;

	std::ifstream ifs(fileName);

	if (!ifs.is_open())
		return nullptr;

	Student* students = readStudents(ifs, count);
	ifs.close();
	return students;
}

void writeStudents(std::ostream& os, Student* students, size_t count) {
	os << count << std::endl;

	for (size_t i = 0; i < count; i++)
	{
		os << students[i].name << " " << students[i].age << std::endl;
	}
}

void writeStudentsToFile(const char* fileName, Student* students, size_t count) {
	if (!fileName)
		return;

	std::ofstream ofs(fileName);

	if (!ofs.is_open())
		return;

	writeStudents(ofs, students, count);
	ofs.close();
}


int main()
{
	/*size_t count;
	Student* students = readStudents(std::cin, count);

	writeStudentsToFile(STUDENTS_FILE_NAME, students, count);*/

	size_t count;
	Student* students = readStudentsFromFile(STUDENTS_FILE_NAME, count);

	writeStudents(std::cout, students, count);
}
