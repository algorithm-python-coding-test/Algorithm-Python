#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Student
{
public:
	string name;
	int korean;
	int english;
	int math;

	//cpp�� ��ü ������ ����
	Student(string name, int kor, int eng, int math)
	{
		this->name = name;
		this->korean = kor;
		this->english = eng;
		this->math = math;
	}

	//������ �����ε��� ���� sort�Լ� ���
	//this < other�� ��
	//if (same korean score, same english score, same math score) : �̸��� �������� ���� => this->name < other.name�� �� true
	//if (same korean score, same english score) : ���� ������ �������� ���� => this->math > other.math�� �� true
	//if (same korean score) : ���� ������ �������� ���� => this->english < other.english�� �� true
	//���� ������ �������� ���� => this->korean > other.korean�� �� true
	bool operator <(Student& other) {
		if (this->korean == other.korean && this->english == other.english && this->math == other.math) {
			return this->name < other.name;
		}
		if (this->korean == other.korean && this->english == other.english) {
			return this->math > other.math;
		}
		if (this->korean == other.korean) {
			return this->english < other.english;
		}
		return this->korean > other.korean;
	}
};

int N;

vector<Student> students;

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		string name;
		int korean, english, math;
		cin >> name >> korean >> english >> math;

		Student student(name, korean, english, math);
		students.push_back(student);
	}

	sort(students.begin(), students.end());

	for (int i = 0; i < N; i++)
		cout << students[i].name << '\n';
}

/*
������ �����ε� ��ſ�

bool compare(Student& other)
{
if (this->korean == other.korean && this->english == other.english && this->math == other.math) {
		return this->name < other.name;
	}
	if (this->korean == other.korean && this->english == other.english) {
		return this->math> other.math;
	}
	if (this->korean == other.korean) {
		return this->english < other.english;
	}
	return this->korean > other.korean;
}

�� �� main���� sort(students.begin(), students.end(), compare);���� �ص� ������ ��� ���� ��.
*/