// Create an array of structures with associations containing information about: 
// student's last name, course, specialty (to represent the specialty, use lists (Enum), and to represent the course - integers) and grades in physics, mathematics;
// If the specialty is "Computer Science", then the third grade in programming;
// If the specialty is "Informatics", then the third assessment is from numerical methods; 
// for all other specialties : "Mathematics and Economics", "Physics and Informatics", "On-the-job training" - the third assessment - from pedagogy.
// 
// Functions that must be implemented:
// [■] For each student, display: last name and average score.
// [■] Calculate the number of students who study "excellently".
// [■] Calculate the percentage of students who study without threes("excellent" and "good").
// [■] Display the names of students who received grades "5" or "4" in physics.
// [■] Calculate the average score for each subject.
// [■] Calculate the number of "excellent" marks for each subject.
//

#include <iostream>
using namespace std;

enum Enum_Speciality
{
	Computer_Science = 0, Informatics, Mathematics_And_Economics, Physics_And_Informatics, Work_Training
};
enum Enum_Menu
{
	E_Print_All_Students = 1, E_Print_All_Average_Score, E_Print_All_Excellently_Study, E_Print_All_Without_Threes_Study, 
	E_Print_Students_Who_Received_Grades_5_Or_4_In_Physics, E_Subject_Average_Score, E_Print_Number_Of_Excellent_Marks_For_Each_Subject
};
enum Enum_Sub_Menu_Average_Score
{
	Back, E_Print_Physics_Average_Score, E_Print_Mathematics_Average_Score, E_Print_Programming_Average_Score, E_Print_Numerical_Methods_Average_Score, E_Printt_Pedagogy_Average_Score
};
enum Enum_Sub_Menu_Number_Of_Excellent_Marks_For_Each_Subject
{
	Back_, E_Physics, E_Mathematics, E_Programming, E_Numerical_Methods, E_Pedagogy
};
struct student
{
	string surname = "0";
	int speciality = 0;
	int course = 0;
	
	int physics = 0;
	int mathematics = 0;
	int thirdsubject = 0;

	void add(string in_surname, int in_course, int in_speciality, int in_physics, int in_mathematics, int in_thirdsubject)
	{
		surname = in_surname;
		course = in_course;
		speciality = in_speciality;
		physics = in_physics;
		mathematics = in_mathematics;
		thirdsubject = in_thirdsubject;
	}
	void Print_Speciality(int speciality)
	{
		if (speciality == Computer_Science)
		{
			cout << "\n\tSpeciality:\tComputer Science";
		}
		else if (speciality == Informatics)
		{
			cout << "\n\tSpeciality:\tInformatics";
		}
		else if (speciality == Mathematics_And_Economics)
		{
			cout << "\n\tSpeciality:\tMathematics And Economics";
		}
		else if (speciality == Physics_And_Informatics)
		{
			cout << "\n\tSpeciality:\tPhysics And Informatics";
		}
		else if (speciality == Work_Training)
		{
			cout << "\n\tSpeciality:\tWork Training";
		}
	}
	void Print_Third_Subject(int speciality)
	{
		if (speciality == Computer_Science)
		{
			cout << "\n\tProgramming:\t" << thirdsubject;
		}
		else if (speciality == Informatics)
		{
			cout << "\n\tNumerical methods:\t" << thirdsubject;
		}
		else if (speciality == Mathematics_And_Economics || speciality == Physics_And_Informatics || speciality == Work_Training)
		{
			cout << "\n\tPedagogy:\t" << thirdsubject;
		}
	}
	void Print_Student()
	{
		cout << "\n\n\tSurname:\t" << surname;
		cout << "\n\tCourse:\t\t" << course;
		Print_Speciality(speciality);
	}
	void print()
	{
		Print_Student();
		
		cout << "\n\tPhysics:\t" << physics;
		cout << "\n\tMathematics:\t" << mathematics;
		Print_Third_Subject(speciality);
	}
	int Average_Score()
	{
		return (physics + mathematics + thirdsubject) / 3;
	}
	//Average_Score
	void Print_Average_Score()
	{
		Print_Student();
		cout << "\n\tAverage Score\t" << Average_Score();
	}
	//excellently
	int Print_Excellently_Study()
	{
		int count = 1;
		if (Average_Score() == 5)
		{
			Print_Student();
			return count;
		}
		return 0;
	}

};

student* Fill(int& size);
void Print_All_Students(student* students, int& size);
void Print_All_Average_Score(student* students, int& size);
void Print_All_Excellently_Study(student* students, int& size);
void Print_All_Without_Threes_Study(student* students, int& size);
void Print_Students_Who_Received_Grades_5_Or_4_In_Physics(student* students, int& size);

//physics, mathematics, thirdsubject
void Print_Physics_Average_Score(student* students, int& size);
void Print_Mathematics_Average_Score(student* students, int& size);
void Print_Third_Subject_Average_Score(student* students, int& size, int speciality);

//Calculate the number of "excellent" marks for each subject
void Number_Of_Excellent_Marks_Physics(student* students, int& size);
void Number_Of_Excellent_Marks_Mathematics(student* students, int& size);
void Number_Of_Excellent_Marks_Third_Subject(student* students, int& size, int speciality);

void Sub_Menu_Average_Score(student* Students, int& size);
void Sub_Menu_Number_Of_Excellent_Marks_For_Each_Subject(student* Students, int& size);
void Menu(student* Students, int& size);

int main()
{
	int size = 10;
	student* Students = Fill(size);
	do
	{
		Menu(Students, size);
	} while (true);
}
student* Fill(int& size)
{
	student* Students = new student[size];
	
	//Computer_Science, Informatics, Mathematics_And_Economics, Physics_And_Informatics, Work_Training
	//             (surname, course, speciality, physics, mathematics, thirdsubject)
	Students[0].add("student 1", 1, Computer_Science, 5, 5, 5);//5
	Students[1].add("student 2", 2, Computer_Science, 4, 5, 4);//4
	Students[2].add("student 3", 4, Informatics, 3, 4, 4);//3
	Students[3].add("student 4", 1, Informatics, 5, 5, 5);//5
	Students[4].add("student 5", 3, Mathematics_And_Economics, 4, 5, 4);//4
	Students[5].add("student 6", 2, Mathematics_And_Economics, 3, 4, 4);//3
	Students[6].add("student 7", 4, Physics_And_Informatics, 4, 4, 3);//3
	Students[7].add("student 8", 3, Physics_And_Informatics, 5, 5, 4);//4
	Students[8].add("student 9", 2, Work_Training, 4, 5, 3);//3
	Students[9].add("student 10", 1, Work_Training, 5, 4, 4);//4

	return Students;
}
void Print_All_Students(student* students, int& size)// Print all students surname, course, speciality, physics, mathematics, third subject;
{
	for (int i = 0; i < size; i++)
	{
		students[i].print();
	}
}
void Print_All_Average_Score(student* students, int& size)
{
	for (int i = 0; i < size; i++)
	{
		students[i].Print_Average_Score();
	}
}
void Print_All_Excellently_Study(student* students, int& size)//Only 5 
{
	cout << "\n\n\tExcellently Study Students:";
	int count = 0;
	for (int i = 0; i < size; i++)
	{
		count += students[i].Print_Excellently_Study();
	}
	printf("\n\n\t%d Students Study Excellently", count);
}
void Print_All_Without_Threes_Study(student* students, int& size)//Calculate the percentage of students who study without threes("excellent" and "good").
{
	cout << "\n\n\tWithout threes Study Students:";
	double count = 0.0;
	double dsize = (double)size;
	for (int i = 0; i < size; i++)
	{
		if (students[i].mathematics > 3 && students[i].physics > 3 && students[i].thirdsubject > 3)
		{
			count += 1.0;
			students[i].print();
		}
	}
	count = count / dsize * 100.0;
	cout << "\n\n\t" << count << "% students study without threes";
}
void Print_Students_Who_Received_Grades_5_Or_4_In_Physics(student* students, int& size)//Display the names of students who received grades "5" or "4" in physics.
{
	cout << "\n\n\tStudents Who Received Grades 5 Or 4 In Physics:\n";
	for (int i = 0; i < size; i++)
	{
		if (students[i].physics > 3)
		{
			students[i].Print_Student();
		}
	}
}

//physics, mathematics, thirdsubject
void Print_Physics_Average_Score(student* students, int& size)
{
	int score = 0;
	for (int i = 0; i < size; i++)
	{
		score += students[i].physics;
	}
	score = score / size;
	cout << "\n\n\tPhysics average score is: " << score;
}
void Print_Mathematics_Average_Score(student* students, int& size)
{
	int score = 0;
	for (int i = 0; i < size; i++)
	{
		score += students[i].mathematics;
	}
	score = score / size;
	cout << "\n\n\tMathematics average score is: " << score;
}
void Print_Third_Subject_Average_Score(student* students, int& size, int speciality)
{
	//Computer_Science, Informatics, Mathematics_And_Economics, Physics_And_Informatics, Work_Training

	int score = 0;
	int much = 0;
	if (speciality == Computer_Science)
	{
		for (int i = 0; i < size; i++)
		{
			if (students[i].speciality == Computer_Science)
			{
				score += students[i].thirdsubject;
				much++;
			}
		}
		score = score / much;
		cout << "\n\n\tProgramming average score is: " << score;
	}
	else if (speciality == Informatics)
	{
		for (int i = 0; i < size; i++)
		{
			if (students[i].speciality == Informatics)
			{
				score += students[i].thirdsubject;
				much++;
			}
		}
		score = score / much;
		cout << "\n\n\tNumerical methods average score is: " << score;
	}
	else if (speciality == Mathematics_And_Economics || speciality == Physics_And_Informatics || speciality == Work_Training)
	{
		for (int i = 0; i < size; i++)
		{
			if (students[i].speciality == Informatics || students[i].speciality == Physics_And_Informatics || students[i].speciality == Work_Training)
			{
				score += students[i].thirdsubject;
				much++;
			}
		}
		score = score / much;
		cout << "\n\n\tPedagogy average score is: " << score;
	}
}

//Calculate the number of "excellent" marks for each subject
void Number_Of_Excellent_Marks_Physics(student* students, int& size)//Physics
{
	int count = 0;
	for (int i = 0; i < size; i++)
	{
		if (students[i].physics == 5)
		{
			count++;
		}
	}
	cout << "\n\n\tNumber of excellent marks in Physics is: " << count;
}

void Number_Of_Excellent_Marks_Mathematics(student* students, int& size)//Mathematics
{
	int count = 0;
	for (int i = 0; i < size; i++)
	{
		if (students[i].mathematics == 5)
		{
			count++;
		}
	}
	cout << "\n\n\tNumber of excellent marks in Mathematics is: " << count;
}
void Number_Of_Excellent_Marks_Third_Subject(student* students, int& size, int speciality)
{
	//Computer_Science, Informatics, Mathematics_And_Economics, Physics_And_Informatics, Work_Training
	int count = 0;
	if (speciality == Computer_Science)//Programming
	{
		for (int i = 0; i < size; i++)
		{
			if (students[i].speciality == Computer_Science && students[i].thirdsubject == 5)
			{
				count++;
			}
		}
		cout << "\n\n\tNumber of excellent marks in Programming is: " << count;
	}
	else if (speciality == Informatics)//Numerical methods
	{
		for (int i = 0; i < size; i++)
		{
			if (students[i].speciality == Informatics && students[i].thirdsubject == 5)
			{
				count++;
			}
		}
		cout << "\n\n\tNumber of excellent marks in Numerical methods is: " << count;
	}
	else if (speciality == Mathematics_And_Economics || speciality == Physics_And_Informatics || speciality == Work_Training)//Pedagogy
	{
		for (int i = 0; i < size; i++)
		{
			if ((students[i].speciality == Informatics || students[i].speciality == Physics_And_Informatics || students[i].speciality == Work_Training) && students[i].thirdsubject == 5)
			{
				count++;
			}
		}
		cout << "\n\n\tNumber of excellent marks in Pedagogy is: " << count;
	}
}
void Menu(student* Students, int& size)
{
	int choice = 0;
	printf("\n\n\t1 -- Print all students list\n\t2 -- Print all students average score\n\t3 -- Print all excellently study students");
	printf("\n\t4 -- Print all students who study without threes\n\t5 -- Print Students Who Received Grades 5 Or 4 In Physics\n\t6 -- Subject average score");
	printf("\n\t7 -- Print number of excellent marks for each subject\n\t");
	cin >> choice;

	switch ((Enum_Menu)choice)
	{
	case E_Print_All_Students:
		Print_All_Students(Students, size);
		break;
	case E_Print_All_Average_Score:
		Print_All_Average_Score(Students, size);
		break;
	case E_Print_All_Excellently_Study:
		Print_All_Excellently_Study(Students, size);
		break;
	case E_Print_All_Without_Threes_Study:
		Print_All_Without_Threes_Study(Students, size);
		break;
	case E_Print_Students_Who_Received_Grades_5_Or_4_In_Physics:
		Print_Students_Who_Received_Grades_5_Or_4_In_Physics(Students, size);
		break;
	case E_Subject_Average_Score:
		Sub_Menu_Average_Score(Students, size);
		break;
	case E_Print_Number_Of_Excellent_Marks_For_Each_Subject:
		Sub_Menu_Number_Of_Excellent_Marks_For_Each_Subject(Students, size);
		break;
	default:
		break;
	}
}
void Sub_Menu_Average_Score(student* Students, int& size)
{
	int choice = 0;
	printf("\n\t0 -- Back\n\t1 -- Print Number of excellent marks in physics\n\t2 -- Print Number of excellent marks in mathematics\n\t3 -- Print Number of excellent marks in programming");
	printf("\n\t4 -- Print Number of excellent marks in numerical methods\n\t5 -- Print Number of excellent marks in pedagogy\n\t");
	cin >> choice;

	switch ((Enum_Sub_Menu_Average_Score)choice)
	{
	case Back:
		break;
	case E_Print_Physics_Average_Score:
		Print_Physics_Average_Score(Students, size);
		break;
	case E_Print_Mathematics_Average_Score:
		Print_Mathematics_Average_Score(Students, size);
		break;
	case E_Print_Programming_Average_Score:
		Print_Third_Subject_Average_Score(Students, size, Computer_Science);
		break;
	case E_Print_Numerical_Methods_Average_Score:
		Print_Third_Subject_Average_Score(Students, size, Informatics);
		break;
	case E_Printt_Pedagogy_Average_Score:
		Print_Third_Subject_Average_Score(Students, size, Mathematics_And_Economics);
		break;
	default:
		break;
	}
}
void Sub_Menu_Number_Of_Excellent_Marks_For_Each_Subject(student* Students, int& size)
{
	int choice = 0;
	printf("\n\t0 -- Back\n\t1 -- Print physics average score\n\t2 -- Print mathematics average score\n\t3 -- Print programming average score");
	printf("\n\t4 -- Print numerical methods average score\n\t5 -- Printt pedagogy average score\n\t");
	cin >> choice;

	switch ((Enum_Sub_Menu_Number_Of_Excellent_Marks_For_Each_Subject)choice)
	{
	case Back_:
		break;
	case E_Physics:
		Number_Of_Excellent_Marks_Physics(Students, size);
		break;
	case E_Mathematics:
		Number_Of_Excellent_Marks_Mathematics(Students, size);
		break;
	case E_Programming:
		Number_Of_Excellent_Marks_Third_Subject(Students, size, Computer_Science);
		break;
	case E_Numerical_Methods:
		Number_Of_Excellent_Marks_Third_Subject(Students, size, Informatics);
		break;
	case E_Pedagogy:
		Number_Of_Excellent_Marks_Third_Subject(Students, size, Mathematics_And_Economics);
		break;
	default:
		break;
	}
}