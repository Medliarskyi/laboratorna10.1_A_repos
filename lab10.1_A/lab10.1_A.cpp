#include <iostream>
#include <iomanip>
#include <string>
#include <windows.h>

using namespace std;

enum Speciality { ITIS, RE, KN, KI, PZ };
string speciality_str[] = { "Інформатика ",
                            "Радіоелектроніка", "Комп'ютерні науки",
                            "Комп'ютерна інженерія", "Програмне забезпечення" };

struct Students
{
    string surname;
    int course;
    Speciality speciality;
    int grade_physics;
    int grade_math;
    int grade_info;
};

void Create(Students* S, const int N);
void Print(Students* S, const int N);
void CalculateAverages(Students* S, const int N, double& avg_physics, double& avg_math, double& avg_info);
int CountHighPhysicsGrades(Students* S, const int N);

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int N;
    cout << "Введіть кількість студентів: ";
    cin >> N;

    Students* S = new Students[N];

    Create(S, N);
    Print(S, N);

    double avg_physics, avg_math, avg_info;
    CalculateAverages(S, N, avg_physics, avg_math, avg_info);

    cout << "Середній бал з фізики: " << setprecision(2) << avg_physics << endl;
    cout << "Середній бал з математики: " << setprecision(2) << avg_math << endl;
    cout << "Середній бал з інформатики: " << setprecision(2) << avg_info << endl;

    int count_physics_high = CountHighPhysicsGrades(S, N);
    cout << "Кількість студентів, які отримали 4 або 5 з фізики: " << count_physics_high << endl;

    delete[] S;

    return 0;
}

void Create(Students* S, const int N)
{
    for (int i = 0; i < N; i++)
    {
        int speciality;
        cout << "Номер студента: " << i + 1 << endl;
        cin.get();
        cin.sync();
        cout << "Прізвище: "; getline(cin, S[i].surname); cout << endl;
        cout << "Курс: "; cin >> S[i].course; cout << endl;
        cout << "Спеціальність (0 - Інформатика, 1 - Радіоелектроніка, 2 - Комп'ютерні науки,"
            << "\n3 - Комп'ютерна інженерія, 4 - Програмне забезпечення): ";
        cin >> speciality;
        S[i].speciality = (Speciality)speciality;
        cout << "Оцінка з фізики: "; cin >> S[i].grade_physics; cout << endl;
        cout << "Оцінка з математики: "; cin >> S[i].grade_math; cout << endl;
        cout << "Оцінка з інформатики: "; cin >> S[i].grade_info; cout << endl;
        cout << endl;
    }
}

void Print(Students* S, const int N)
{
    cout << "=================================================================================================" << endl;
    cout << "|  №  |   Прізвище   |  Курс  |     Спеціальність     |  Фізика  |  Математика  |  Інформатика  |" << endl;
    cout << "-------------------------------------------------------------------------------------------------" << endl;

    for (int i = 0; i < N; i++)
    {
        cout << "|" << setw(4) << left << i + 1 << " ";
        cout << "|" << setw(14) << left << S[i].surname;
        cout << "|" << setw(8) << left << S[i].course;
        cout << "|" << setw(23) << left << speciality_str[S[i].speciality];
        cout << "|" << setw(10) << left << S[i].grade_physics;
        cout << "|" << setw(14) << left << S[i].grade_math;
        cout << "|" << setw(15) << left << S[i].grade_info << "|" << endl;
    }
    cout << "=================================================================================================" << endl << endl;
}

void CalculateAverages(Students* S, const int N, double& avg_physics, double& avg_math, double& avg_info)
{
    int sum_physics = 0, sum_math = 0, sum_info = 0;

    for (int i = 0; i < N; i++) {
        sum_physics += S[i].grade_physics;
        sum_math += S[i].grade_math;
        sum_info += S[i].grade_info;
    }

    avg_physics = static_cast<double>(sum_physics) / N;
    avg_math = static_cast<double>(sum_math) / N;
    avg_info = static_cast<double>(sum_info) / N;
}

int CountHighPhysicsGrades(Students* S, const int N)
{
    int count = 0;

    for (int i = 0; i < N; i++) {
        if (S[i].grade_physics == 5 || S[i].grade_physics == 4) {
            count++;
        }
    }

    return count;
}
