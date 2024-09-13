// hw1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

namespace Taeyeon2449010 
{
    struct student
    {
        int id{};
        int score{};
        char grade{};
    };
    
    void printStudent(const student& s)//pass-by-reference 이유:구조체같이 용량이 큰 데이터를 전달할 때 이 방식을 사용하고 복사본을 만들지 않고 실제 인자의 저장위치를 알려주어 저장된 값을 변경할 수 있게 한다.
    {
        std::cout << s.id << ": " << s.score << " (" << s.grade << ")\n";
    }

    char calGrade(int score=0)
    {
        if (score >= 90)
            return 'A';
        else if (score >= 80)
            return 'B';
        else if (score >= 70)
            return 'C';
        else if (score >= 60)
            return 'D';
        else
            return 'F';
    }

    student inputStudent()
    {
        student s{};
        std::cout << "Enter student ID:: ";
        std::cin >> s.id;
        std::cout << "Enter student score: ";
        std::cin >> s.score;
        s.grade = calGrade(s.score);
        return s;
    }
    int studentNumber()
    {
        static int n{ 0 };
        return ++n;
    }

}

int main()
{
    using namespace std;

    using namespace Taeyeon2449010;

    student s1{ inputStudent() };
    cout << "(" << studentNumber() << ") ";
    printStudent(s1);

    student s2{ inputStudent() };
    cout << "(" << studentNumber() << ") ";
    printStudent(s2);

    if (s1.score == s2.score)
        std::cout << "Same score, ";
    else
        std::cout << "different score, ";

    if (calGrade(s1.score) == calGrade(s2.score))
        std::cout << "Same grade\n";
    else
        std::cout << "different grade\n";

    return 0;
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
