#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
//����, �̸��� ������ ����
vector<pair<int, string>> students;

int main()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int score;
		string name;
		cin >> name >> score;
		students.push_back(pair<int, string>(score, name));
	}

	sort(students.begin(), students.end());
	for (int i = 0; i < N; i++)
		cout << students[i].second << ' ';
}

/*
* pair�� ���°� class���°� ���� ���ɻ� ����
* �׷��� class���°� �ڵ� Ȯ�强, �������� ����
*/

//class Student {
//public:
//    string name;
//    int score;
//    Student(string name, int score) {
//        this->name = name;
//        this->score = score;
//    }
//    // ���� ������ '������ ���� ����'
//    bool operator <(Student &other) {
//        return this->score < other.score; 
//    }
//};
//
//int n;
//vector<Student> v;
//
//int main(void) {
//    // N�� �Է¹ޱ�
//    cin >> n;
//
//    // N���� �л� ������ �Է¹޾� ����Ʈ�� ����
//    for (int i = 0; i < n; i++) {
//        string name;
//        int score;
//        cin >> name >> score;
//        v.push_back(Student(name, score));
//    }
//    
//    sort(v.begin(), v.end());
//
//    // ������ ����� ����� ���
//    for(int i = 0; i < n; i++) {
//        cout << v[i].name << ' ';
//    }
//}