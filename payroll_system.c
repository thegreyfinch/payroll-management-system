#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> //it is necessary for isalpha function
#include <process.h>

FILE *file; // declare file pointer

struct person
{ // child structure definition
	char first[15];
	char sec[15];
	char third[15];
	char fourth[15];
};

struct record
{											// mother structure definition
	char num[11];				// employee number
	struct person name; // child structure declaration
	char status[2];			// employee status
	int hrsWorked;			// employee hours worked
	float deduct;				// employee deductions
};

struct record emp; // mother structure declaration

void writeFile(int x)
{ // this function will write data to the file
	if (x == 1)
	{ // write to file this way if employee has one name
		fprintf(file, "%s %s %s %d %f\n", emp.num, emp.name.first, emp.status, emp.hrsWorked, emp.deduct);
	}
	else if (x == 2)
	{ // write to file this way if employee has two names
		fprintf(file, "%s %s %s %s %d %f\n", emp.num, emp.name.first, emp.name.sec, emp.status, emp.hrsWorked, emp.deduct);
	}
	else if (x == 3)
	{ // write to file this way if employee has three names
		fprintf(file, "%s %s %s %s %s %d %f\n", emp.num, emp.name.first, emp.name.sec, emp.name.third, emp.status, emp.hrsWorked, emp.deduct);
	}
	else if (x == 4)
	{ // write to file this way if employee has four names
		fprintf(file, "%s %s %s %s %s %s %d %f\n", emp.num, emp.name.first, emp.name.sec, emp.name.third, emp.name.fourth, emp.status, emp.hrsWorked, emp.deduct);
	}
	else
	{
		printf("Invalid number of names!");
		exit(1);
	}
}
// this function will display the final output
void printOutput(int x, char num[10], char first[15], char sec[15], char third[15], char fourth[15], char status[7], float basic_salary, float ot_pay, float deduct, float net_pay)
{
	char stats[7];
	// change the status label of R to Regular and C to Casual
	if (strcmp(status, "R") == 0) // use strcmp to compare whether two strings are equal, it is case-sensitive
		strcpy(stats, "Regular");
	else if (strcmp(status, "C") == 0) // use strcmp to compare whether two strings are equal, it is case-sensitive
		strcpy(stats, "Casual");
	else
		printf("\nInvalid Status!");
	// DISPLAY THE FINAL OUTPUT
	if (x == 1)
	{ // if employee has one name, this will be printed as the final output
		printf("\t%-10s\t\t%-15s \t%-7s   \t%-15.2f  \t%-15.2f  \t%-15.2f  \t%-12.2f\n",
					 num, first, stats, basic_salary, ot_pay, deduct, net_pay);
	}

	else if (x == 2)
	{ // if employee has two names, this will be printed as the final output
		printf("\t%-10s\t\t%-s %-s \t\t%-7s\t   \t%-15.2f  \t%-15.2f  \t%-15.2f  \t%-12.2f\n",
					 num, first, sec, stats, basic_salary, ot_pay, deduct, net_pay);
	}

	else if (x == 3)
	{ // if employee has three names, this will be printed as the final output
		printf("\t%-10s\t\t%-s %-s %-s\t\t%-7s\t   \t%-15.2f  \t%-15.2f  \t%-15.2f  \t%-12.2f\n",
					 num, first, sec, third, stats, basic_salary, ot_pay, deduct, net_pay);
	}
	else if (x == 4)
	{  // if employee has three names, this will be printed as the final output
		printf("\t%-10s\t\t%-s %-s %-s %-s\t\t%-7s\t   \t%-15.2f  \t%-15.2f  \t%-15.2f  \t%-12.2f\n",
					 num, first, sec, third, fourth, stats, basic_salary, ot_pay, deduct, net_pay);		
	}
	else
	{
		printf("\nInvalid Data!");
		exit(1);
	}
}

int j;

int main()
{
	int i, n;		   // i is the counter for outer loop, j is for inner loop, n is the integer version of number of employees
	char no[10];	   // this stores the number of employees, it is string in order to invalidate other data except integer
	char status[50];  // this stores the status of employee, it is string in order to invalidate other data except the characters R and C
	char hours[50];	  // this stores the hours worked of employee, it is string in order to invalidate other data except integers
	char deduc[50];	  // this stores the deductions of employee, it is string in order to invalidate other data except floats
	int isAlphanumeric = 0;  //this will check if employee number is alphanumeric
	int isNumeric = 1;     // this will check if employee number is numeric
	printf("Welcome to ProgCrammers Company!\n\n");
empNum:
	printf("Input number of employees: ");
	scanf("%s", no);
	int num_emp = atoi(no);   //convert 
	if ((num_emp > 1000) || (num_emp < 0)) {
		printf("\nInvalid input! It should be less than 1000!\n");
		printf("Input again!\n\n");
		goto empNum; // input number of employees again
	}

	// number of employees should not accept symbols
	for (i = 0; i < strlen(no); i++)
	{   //not accepted symbols 
		if ((no[i] == '!') || (no[i] == '@') || (no[i] == '#') || (no[i] == '$') || (no[i] == '%') ||
				(no[i] == '^') || (no[i] == '/') || (no[i] == '<') || (no[i] == '>') || (no[i] == '*') ||
				(no[i] == '&') || (no[i] == '(') || (no[i] == ')') || (no[i] == '?') || (no[i] == '.') ||
				(no[i] == ';') || (no[i] == ':') || (no[i] == '_') || (no[i] == '-') || (no[i] == '=') ||
				(no[i] == '+') || (no[i] == '[') || (no[i] == ']') || (no[i] == '{') || (no[i] == '}') ||
				(no[i] == '"') || (no[i] == '\'') || (no[i] == '|') || (no[i] == '`') || (no[i] == '~') || (no[i] == '\\'))
		{
			printf("\nInvalid input! It should be a positive integer!\n");
			printf("Input again!\n\n");
			goto empNum; // input number of employees again
		}
	}
	// number of employees should not accept alphabets
	for (i = 0; i < strlen(no); i++)
	{
		if (isalpha(no[i]))
		{
			printf("\nInvalid input! It should be a positive integer!\n");
			printf("Input again!\n\n");
			goto empNum; // input number of employees again
		}
	}
	// convert number of employees to integer using atoi function
	n = atoi(no);
	// if the number of employees is 0, then end the program
	if (n == 0)
	{
		system("cls");
		printf("END OF PROGRAM!");
		return 0;
	}
	int x[n]; // this array will store the number of names the employee has

	// open file for appending
	file = fopen("record.txt", "w");
	// file validation
	if (file == NULL)
	{
		printf("File cannot be created");
		exit(1);
	}
	char num_name[10]; // this string stores the number of names a certain employee has
	// for loop to input the data of each employee then append to file
	for (i = 0; i < n; i++)
	{
		printf("\nEmployee No. %d\n", i + 1);
	// INPUT EMPLOYEE NUMBER
	inputNum: // input employee number again if the necessary condition is not met
		printf("Input Employee Number: ");
		scanf("%s", emp.num);
		// employee number will accept alphabets
		for (j = 0; j < strlen(emp.num); j++)
		{	// employee number will not accept symbols
			if ((emp.num[j] == '!') || (emp.num[j] == '@') || (emp.num[j] == '#') || (emp.num[j] == '$') || (emp.num[j] == '%') ||
					(emp.num[j] == '^') || (emp.num[j] == '/') || (emp.num[j] == '<') || (emp.num[j] == '>') || (emp.num[j] == '*') ||
					(emp.num[j] == '&') || (emp.num[j] == '(') || (emp.num[j] == ')') || (emp.num[j] == '?') || (emp.num[j] == '.') ||
					(emp.num[j] == ';') || (emp.num[j] == ':') || (emp.num[j] == '_') ||  (emp.num[j] == '=') ||
					(emp.num[j] == '+') || (emp.num[j] == '[') || (emp.num[j] == ']') || (emp.num[j] == '{') || (emp.num[j] == '}') ||
					(emp.num[j] == '"') || (emp.num[j] == '\'') || (emp.num[j] == '|') || (emp.num[j] == '`') || (emp.num[j] == '~') || 
					(emp.num[j] == '\\'))
			{
				printf("\nInvalid Employee Number! Must be positive integers!\n");
				printf("Input again!\n");
				goto inputNum; // input employee number again
			}
		}
		// employee number should not be greater than 10 characters
		if (strlen(emp.num) > 10)
		{
			printf("\nInvalid Employee Number! Must not be greater than 10 characters!");
			printf("\nInput again!\n\n");
			goto inputNum; // input employee number again
		}
	// ask the user if he/she has one, two, or third name:
	inputNumOfName: // input number of names again if necessary condition is not met
		printf("Input 1 if the employee has one name\nInput 2 if two names\nInput 3 if three names\nInput 4 if four names\n");
		printf("\nInput here: ");
		scanf(" %s", num_name);
		x[i] = atoi(num_name);
		if ((x[i] <= 0) || (x[i] > 4))
		{
			printf("\nInvalid number of names! Input again!\n");
			goto inputNumOfName; // input number of names again
		}
	// INPUT EMPLOYEE NAME WHO HAS ONE NAME
	inputNameAgain: // input employee's name again if necessary condition is not met
		printf("\nEmployee No. %d\n", i + 1);
		if (x[i] == 1)
		{ // if employee has one name, input first name
			printf("\nNOTE: After you input the first name, input three dots each separated with space (ex. Juan . . .): \n");
			printf("Input Employee Name (FN): ");
			scanf(" %s %s %s %s", emp.name.first, emp.name.sec, emp.name.third, emp.name.fourth);
			// employee name should not be greater than 15 characters
			if (strlen(emp.name.first) > 15)
			{
				printf("Invalid Input Name! It is greater than 15 characters!\n");
				printf("Input again!\n\n");
				goto inputNameAgain; // input employee's name again
			}
			// employee name should not accept symbols except '.' and '-' and ',' and should not accept float, only alphabet and integer
			for (j = 0; j < strlen(emp.name.first); j++)
			{
				if ((emp.name.first[j] == '!') || (emp.name.first[j] == '@') || (emp.name.first[j] == '#') || (emp.name.first[j] == '$') || (emp.name.first[j] == '%') ||
						(emp.name.first[j] == '^') || (emp.name.first[j] == '/') || (emp.name.first[j] == '<') || (emp.name.first[j] == '>') || (emp.name.first[j] == '*') ||
						(emp.name.first[j] == '&') || (emp.name.first[j] == '(') || (emp.name.first[j] == ')') || (emp.name.first[j] == '?') ||
						(emp.name.first[j] == ';') || (emp.name.first[j] == ':') || (emp.name.first[j] == '_') || (emp.name.first[j] == '=') ||
						(emp.name.first[j] == '+') || (emp.name.first[j] == '[') || (emp.name.first[j] == ']') || (emp.name.first[j] == '{') || (emp.name.first[j] == '}') ||
						(emp.name.first[j] == '"') || (emp.name.first[j] == '\'') || (emp.name.first[j] == '|') || (emp.name.first[j] == '`') || (emp.name.first[j] == '~') || 
						(emp.name.first[j] == '\\'))
				{
					printf("Invalid Input Name!\n");
					printf("It should not contain symbols except '.' and '-' and ','\n");
					printf("It should also not contain decimal values\n");
					printf("Input again!\n\n");
					goto inputNameAgain; // input employee's name again
				}
			}
		}
		// INPUT EMPLOYEE NAME WHO HAS TWO NAMES
		else if (x[i] == 2)
		{ // if employee has two names, input two names
			printf("\nNOTE: After you input the first and second name, input two dots after space (ex. Juan Dela . .): \n");
			printf("Input Employee Name: ");
			scanf(" %s %s %s %s", emp.name.first, emp.name.sec, emp.name.third, emp.name.fourth);
			// employee name should not be greater than 15 characters
			if ((strlen(emp.name.first) + strlen(emp.name.sec)) > 15)
			{
				printf("Invalid Input Name! It is greater than 15 characters!\n");
				printf("Input again!\n\n");
				goto inputNameAgain; // input employee's name again
			}
			// employee first name should not accept symbols except '.' and '-' and ',' and should not accept float, only alphabet and integer
			for (j = 0; j < strlen(emp.name.first); j++)
			{
				if ((emp.name.first[j] == '!') || (emp.name.first[j] == '@') || (emp.name.first[j] == '#') || (emp.name.first[j] == '$') || (emp.name.first[j] == '%') ||
						(emp.name.first[j] == '^') || (emp.name.first[j] == '/') || (emp.name.first[j] == '<') || (emp.name.first[j] == '>') || (emp.name.first[j] == '*') ||
						(emp.name.first[j] == '&') || (emp.name.first[j] == '(') || (emp.name.first[j] == ')') || (emp.name.first[j] == '?') || 
						(emp.name.first[j] == ';') || (emp.name.first[j] == ':') || (emp.name.first[j] == '_') || (emp.name.first[j] == '=') ||
						(emp.name.first[j] == '+') || (emp.name.first[j] == '[') || (emp.name.first[j] == ']') || (emp.name.first[j] == '{') || (emp.name.first[j] == '}') ||
						(emp.name.first[j] == '"') || (emp.name.first[j] == '\'') || (emp.name.first[j] == '|') || (emp.name.first[j] == '`') || (emp.name.first[j] == '~') || 
						(emp.name.first[j] == '\\'))
				{
					printf("Invalid Input Name!\n");
					printf("It should not contain symbols except '.' and '-' and ','\n");
					printf("It should also not contain decimal values!\n");
					printf("Input again!\n\n");
					goto inputNameAgain; // input employee's name again
				}
			}
			// employee second name should not accept symbols except '.' and '-' and ',' and should not accept float, only alphabet and integer
			for (j = 0; j < strlen(emp.name.sec); j++)
			{
				if ((emp.name.sec[j] == '!') || (emp.name.sec[j] == '@') || (emp.name.sec[j] == '#') || (emp.name.sec[j] == '$') || (emp.name.sec[j] == '%') ||
						(emp.name.sec[j] == '^') || (emp.name.sec[j] == '/') || (emp.name.sec[j] == '<') || (emp.name.sec[j] == '>') || (emp.name.sec[j] == '*') ||
						(emp.name.sec[j] == '&') || (emp.name.sec[j] == '(') || (emp.name.sec[j] == ')') || (emp.name.sec[j] == '?') || 
						(emp.name.sec[j] == ';') || (emp.name.sec[j] == ':') || (emp.name.sec[j] == '_') || (emp.name.sec[j] == '=') ||
						(emp.name.sec[j] == '+') || (emp.name.sec[j] == '[') || (emp.name.sec[j] == ']') || (emp.name.sec[j] == '{') || (emp.name.sec[j] == '}') ||
						(emp.name.sec[j] == '"') || (emp.name.sec[j] == '\'') || (emp.name.sec[j] == '|') || (emp.name.sec[j] == '`') || (emp.name.sec[j] == '~') || 
						(emp.name.sec[j] == '\\'))
				{
					printf("Invalid Input Name!\n");
					printf("It should not contain symbols except '.' and '-' and ','\n");
					printf("It should also not contain decimal values!\n");
					printf("Input again!\n\n");
					goto inputNameAgain; // input employee's name again
				}
			}
		}
		// INPUT EMPLOYEE NAME WHO HAS THREE NAMES
		else if (x[i] == 3)
		{ // if employee has three names, input three names
			printf("\nNOTE: After you input the first, second, and third name, input a dot after space (ex. Juan De Cruz . ): \n");
			printf("Input Employee Name (FN MN LN): ");
			scanf(" %s %s %s %s", emp.name.first, emp.name.sec, emp.name.third, emp.name.fourth);
			// employee name should not be greater than 15 characters
			if ((strlen(emp.name.first) + strlen(emp.name.sec) + strlen(emp.name.third)) > 15)
			{
				printf("Invalid Input Name! It is greater than 15 characters!\n");
				printf("Input again!\n\n");
				goto inputNameAgain; // input employee's name again
			}
			// employee first name should not accept symbols except '.' and '-' and ',' and should not accept float, only alphabet and integer
			for (j = 0; j < strlen(emp.name.first); j++)
			{
				if ((emp.name.first[j] == '!') || (emp.name.first[j] == '@') || (emp.name.first[j] == '#') || (emp.name.first[j] == '$') || (emp.name.first[j] == '%') ||
						(emp.name.first[j] == '^') || (emp.name.first[j] == '/') || (emp.name.first[j] == '<') || (emp.name.first[j] == '>') || (emp.name.first[j] == '*') ||
						(emp.name.first[j] == '&') || (emp.name.first[j] == '(') || (emp.name.first[j] == ')') || (emp.name.first[j] == '?') ||
						(emp.name.first[j] == ';') || (emp.name.first[j] == ':') || (emp.name.first[j] == '_') || (emp.name.first[j] == '=') ||
						(emp.name.first[j] == '+') || (emp.name.first[j] == '[') || (emp.name.first[j] == ']') || (emp.name.first[j] == '{') || (emp.name.first[j] == '}') ||
						(emp.name.first[j] == '"') || (emp.name.first[j] == '\'') || (emp.name.first[j] == '|') || (emp.name.first[j] == '\\') || (emp.name.first[j] == '`') || 
						(emp.name.first[j] == '~'))
				{
					printf("Invalid Input Name!\n");
					printf("It should not contain symbols except '.' and '-' and ','\n");
					printf("It should also not contain decimal values!\n");
					printf("Input again!\n\n");
					goto inputNameAgain; // input employee's name again
				}
			}
			// employee second name should not accept symbols except '.' and '-' and ',' and should not accept float, only alphabet and integer
			for (j = 0; j < strlen(emp.name.sec); j++)
			{
				if ((emp.name.sec[j] == '!') || (emp.name.sec[j] == '@') || (emp.name.sec[j] == '#') || (emp.name.sec[j] == '$') || (emp.name.sec[j] == '%') ||
						(emp.name.sec[j] == '^') || (emp.name.sec[j] == '/') || (emp.name.sec[j] == '<') || (emp.name.sec[j] == '>') || (emp.name.sec[j] == '*') ||
						(emp.name.sec[j] == '&') || (emp.name.sec[j] == '(') || (emp.name.sec[j] == ')') || (emp.name.sec[j] == '?') || 
						(emp.name.sec[j] == ';') || (emp.name.sec[j] == ':') || (emp.name.sec[j] == '_') || (emp.name.sec[j] == '=') ||
						(emp.name.sec[j] == '+') || (emp.name.sec[j] == '[') || (emp.name.sec[j] == ']') || (emp.name.sec[j] == '{') || (emp.name.sec[j] == '}') ||
						(emp.name.sec[j] == '"') || (emp.name.sec[j] == '\'') || (emp.name.sec[j] == '|') || (emp.name.sec[j] == '`') || (emp.name.sec[j] == '~') || 
						(emp.name.sec[j] == '\\'))
				{
					printf("Invalid Input Name!\n");
					printf("It should not contain symbols except '.' and '-' and ','\n");
					printf("It should also not contain decimal values!\n");
					printf("Input again!\n\n");
					goto inputNameAgain; // input employee's name again
				}
			}
			// employee third name should not accept symbols except '.' and '-' and ',' and should not accept float, only alphabet and integer
			for (j = 0; j < strlen(emp.name.third); j++)
			{
				if ((emp.name.third[j] == '!') || (emp.name.third[j] == '@') || (emp.name.third[j] == '#') || (emp.name.third[j] == '$') || (emp.name.third[j] == '%') ||
						(emp.name.third[j] == '^') || (emp.name.third[j] == '/') || (emp.name.third[j] == '<') || (emp.name.third[j] == '>') || (emp.name.third[j] == '*') ||
						(emp.name.third[j] == '&') || (emp.name.third[j] == '(') || (emp.name.third[j] == ')') || (emp.name.third[j] == '?') || (emp.name.third[j] == ';') ||
						(emp.name.third[j] == ':') || (emp.name.third[j] == '_') || (emp.name.third[j] == '=') || (emp.name.third[j] == '+') || (emp.name.third[j] == '[') ||
						(emp.name.third[j] == ']') || (emp.name.third[j] == '{') || (emp.name.third[j] == '}') || (emp.name.third[j] == '"') || (emp.name.third[j] == '\'') ||
						(emp.name.third[j] == '\\') || (emp.name.third[j] == '`') || (emp.name.third[j] == '~') || (emp.name.third[j] == '|') || 
						((emp.name.third[j] == '.') && (isdigit(emp.name.third[j + 1]))))
				{
					printf("Invalid Input Name!\n");
					printf("It should not contain symbols except '.' and '-' and ','\n");
					printf("It should also not contain decimal values!\n");
					printf("Input again!\n\n");
					goto inputNameAgain; // input employee's name again
				}
			}
		}
		// INPUT EMPLOYEE NAME WHO HAS FOUR NAMES
		else if (x[i] == 4)
		{ // if employee has three names, input three names
			printf("Input Employee Name (FN MN LN): ");
			scanf(" %s %s %s %s", emp.name.first, emp.name.sec, emp.name.third, emp.name.fourth);
			// employee name should not be greater than 15 characters
			if ((strlen(emp.name.first) + strlen(emp.name.sec) + strlen(emp.name.third) + strlen(emp.name.fourth)) > 15)
			{
				printf("Invalid Input Name! It is greater than 15 characters!\n");
				printf("Input again!\n\n");
				goto inputNameAgain; // input employee's name again
			}
			// employee first name should not accept symbols except '.' and '-' and ',' and should not accept float, only alphabet and integer
			for (j = 0; j < strlen(emp.name.first); j++)
			{
				if ((emp.name.first[j] == '!') || (emp.name.first[j] == '@') || (emp.name.first[j] == '#') || (emp.name.first[j] == '$') || (emp.name.first[j] == '%') ||
						(emp.name.first[j] == '^') || (emp.name.first[j] == '/') || (emp.name.first[j] == '<') || (emp.name.first[j] == '>') || (emp.name.first[j] == '*') ||
						(emp.name.first[j] == '&') || (emp.name.first[j] == '(') || (emp.name.first[j] == ')') || (emp.name.first[j] == '?') || 
						(emp.name.first[j] == ';') || (emp.name.first[j] == ':') || (emp.name.first[j] == '_') || (emp.name.first[j] == '=') ||
						(emp.name.first[j] == '+') || (emp.name.first[j] == '[') || (emp.name.first[j] == ']') || (emp.name.first[j] == '{') || (emp.name.first[j] == '}') ||
						(emp.name.first[j] == '"') || (emp.name.first[j] == '\'') || (emp.name.first[j] == '|') || (emp.name.first[j] == '~') || (emp.name.first[j] == '`') || 
						(emp.name.first[j] == '\\') || ((emp.name.third[j] == '.') && (isdigit(emp.name.third[j + 1]))))
				{
					printf("Invalid Input Name!\n");
					printf("It should not contain symbols except '.' and '-' and ','\n");
					printf("It should also not contain decimal values!\n");
					printf("Input again!\n\n");
					goto inputNameAgain; // input employee's name again
				}
			}
			// employee second name should not accept symbols except '.' and '-' and ',' and should not accept float, only alphabet and integer
			for (j = 0; j < strlen(emp.name.sec); j++)
			{
				if ((emp.name.sec[j] == '!') || (emp.name.sec[j] == '@') || (emp.name.sec[j] == '#') || (emp.name.sec[j] == '$') || (emp.name.sec[j] == '%') ||
						(emp.name.sec[j] == '^') || (emp.name.sec[j] == '/') || (emp.name.sec[j] == '<') || (emp.name.sec[j] == '>') || (emp.name.sec[j] == '*') ||
						(emp.name.sec[j] == '&') || (emp.name.sec[j] == '(') || (emp.name.sec[j] == ')') || (emp.name.sec[j] == '?') || 
						(emp.name.sec[j] == ';') || (emp.name.sec[j] == ':') || (emp.name.sec[j] == '_') || (emp.name.sec[j] == '=') ||
						(emp.name.sec[j] == '+') || (emp.name.sec[j] == '[') || (emp.name.sec[j] == ']') || (emp.name.sec[j] == '{') || (emp.name.sec[j] == '}') ||
						(emp.name.sec[j] == '"') || (emp.name.sec[j] == '\'') || (emp.name.sec[j] == '`') || (emp.name.sec[j] == '~') || (emp.name.sec[j] == '|') || 
						(emp.name.sec[j] == '\\') || ((emp.name.third[j] == '.') && (isdigit(emp.name.third[j + 1]))))
				{
					printf("Invalid Input Name!\n");
					printf("It should not contain symbols except '.' and '-' and ','\n");
					printf("It should also not contain decimal values!\n");
					printf("Input again!\n\n");
					goto inputNameAgain; // input employee's name again
				}
			}
			// employee third name should not accept symbols except '.' and '-' and ',' and should not accept float, only alphabet and integer
			for (j = 0; j < strlen(emp.name.third); j++)
			{
				if ((emp.name.third[j] == '!') || (emp.name.third[j] == '@') || (emp.name.third[j] == '#') || (emp.name.third[j] == '$') || (emp.name.third[j] == '%') ||
						(emp.name.third[j] == '^') || (emp.name.third[j] == '/') || (emp.name.third[j] == '<') || (emp.name.third[j] == '>') || (emp.name.third[j] == '*') ||
						(emp.name.third[j] == '&') || (emp.name.third[j] == '(') || (emp.name.third[j] == ')') || (emp.name.third[j] == '?') || (emp.name.third[j] == ';') ||
						(emp.name.third[j] == ':') || (emp.name.third[j] == '_') || (emp.name.third[j] == '=') || (emp.name.third[j] == '+') || (emp.name.third[j] == '[') ||
						(emp.name.third[j] == ']') || (emp.name.third[j] == '{') || (emp.name.third[j] == '}') || (emp.name.third[j] == '"') || (emp.name.third[j] == '\'') ||
						(emp.name.third[j] == '\\') || (emp.name.third[j] == '|') || (emp.name.third[j] == '~') || (emp.name.third[j] == '`') || 
						((emp.name.third[j] == '.') && (isdigit(emp.name.third[j + 1]))))
				{
					printf("Invalid Input Name!\n");
					printf("It should not contain symbols except '.' and '-' and ','\n");
					printf("It should also not contain decimal values!\n");
					printf("Input again!\n\n");
					goto inputNameAgain; // input employee's name again
				}
			}
			// employee fourth name should not accept symbols except '.' and '-' and ',' and should not accept float, only alphabet and integer
			for (j = 0; j < strlen(emp.name.fourth); j++)
			{
				if ((emp.name.fourth[j] == '!') || (emp.name.fourth[j] == '@') || (emp.name.fourth[j] == '#') || (emp.name.fourth[j] == '$') || (emp.name.fourth[j] == '%') ||
						(emp.name.fourth[j] == '^') || (emp.name.fourth[j] == '/') || (emp.name.fourth[j] == '<') || (emp.name.fourth[j] == '>') || (emp.name.fourth[j] == '*') ||
						(emp.name.fourth[j] == '&') || (emp.name.fourth[j] == '(') || (emp.name.fourth[j] == ')') || (emp.name.fourth[j] == '?') || (emp.name.fourth[j] == ';') ||
						(emp.name.fourth[j] == ':') || (emp.name.fourth[j] == '_') || (emp.name.fourth[j] == '=') || (emp.name.fourth[j] == '+') || (emp.name.fourth[j] == '[') ||
						(emp.name.fourth[j] == ']') || (emp.name.fourth[j] == '{') || (emp.name.fourth[j] == '}') || (emp.name.fourth[j] == '"') || (emp.name.fourth[j] == '\'') ||
						(emp.name.fourth[j] == '\\') || (emp.name.fourth[j] == '|') || (emp.name.fourth[j] == '`') || (emp.name.fourth[j] == '~') || 
						((emp.name.fourth[j] == '.') && (isdigit(emp.name.fourth[j + 1]))))
				{
					printf("Invalid Input Name!\n");
					printf("It should not contain symbols except '.' and '-' and ','\n");
					printf("It should also not contain decimal values!\n");
					printf("Input again!\n\n");
					goto inputNameAgain; // input employee's name again
				}
			}
		}
	// INPUT EMPLOYEE STATUS
	inputStatsAgain: // input status again if necessary condition is not met
		printf("\nInput Employee Status Code (R/C): ");
		scanf(" %s", emp.status);
		strcpy(status, emp.status);
		// employee status should not accept integers and other letters except R and C
		for (j = 0; j < strlen(status); j++)
		{
			// employee status should not accept integers and other letters except R and C
			if (isalnum(status[j]) && ((strcmp(status, "R") != 0) && (strcmp(status, "C") != 0)))
			{ // if status is other letters except R or R
				printf("\nInvalid Input Status Code!\n");
				printf("It should not accept integers/decimals/symbols!\n");
				printf("It should only accept 'R' or 'C'\n");
				printf("Input again!\n\n");
				goto inputStatsAgain; // input status again
			}
			// employee status should not accept any symbols and float
			if ((status[j] == '!') || (status[j] == '@') || (status[j] == '#') || (status[j] == '$') || (status[j] == '%') ||
					(status[j] == '^') || (status[j] == '/') || (status[j] == '<') || (status[j] == '>') || (status[j] == '*') ||
					(status[j] == '&') || (status[j] == '(') || (status[j] == ')') || (status[j] == '?') || (status[j] == ';') ||
					(status[j] == ':') || (status[j] == '_') || (status[j] == '=') || (status[j] == '+') || (status[j] == '[') ||
					(status[j] == ']') || (status[j] == '{') || (status[j] == '}') || (status[j] == '"') || (status[j] == '\'') ||
					(status[j] == '`') || (status[j] == '~') || (status[j] == '\\') || (status[j] == '|') || 
					((status[j] == '.') && (isdigit(status[j + 1]))))
			{
				printf("\nInvalid Input Status Code!\n");
				printf("It should not accept integer/decimals/symbols!\n");
				printf("It should only accept 'R' or 'C'\n");
				printf("Input again!\n\n");
				goto inputStatsAgain; // input status again
			}
		}
	// INPUT EMPLOYEE HOURS WORKED
	inputHrsAgain:
		printf("\nInput Employee Hours Worked: ");
		scanf(" %s", hours);
		emp.hrsWorked = atoi(hours); // convert string hours worked to integer hours worked
		if (emp.hrsWorked < 0)
		{
			printf("\nInvalid Input Hours Worked!\n");
			printf("It should not accept negative numbers!\n");
			printf("It should only accept positive integers\n");
			printf("Input again!\n\n");
			goto inputHrsAgain;
		}
		// employee hours worked should not accept alphabet
		for (j = 0; j < strlen(hours); j++)
		{
			// employee hours worked should not accept alphabet
			if (isalpha(hours[j]))
			{
				printf("\nInvalid Input Hours Worked!\n");
				printf("It should not accept strings!\n");
				printf("It should only accept positive integers\n");
				printf("Input again!\n\n");
				goto inputHrsAgain;
			}
			// employee hours worked should not accept any symbols and float
			if ((hours[j] == '!') || (hours[j] == '@') || (hours[j] == '#') || (hours[j] == '$') || (hours[j] == '%') ||
					(hours[j] == '^') || (hours[j] == '/') || (hours[j] == '<') || (hours[j] == '>') || (hours[j] == '*') ||
					(hours[j] == '&') || (hours[j] == '(') || (hours[j] == ')') || (hours[j] == '?') || (hours[j] == ';') ||
					(hours[j] == ':') || (hours[j] == '_') || (hours[j] == '=') || (hours[j] == '+') || (hours[j] == '[') ||
					(hours[j] == ']') || (hours[j] == '{') || (hours[j] == '}') || (hours[j] == '"') || (hours[j] == '\'') ||
					(hours[j] == '~') || (hours[j] == '`') || 
					(hours[j] == '\\') || (hours[j] == '|') || ((hours[j] == '.') && (isdigit(hours[j + 1]))))
			{
				printf("\nInvalid Input Hours Worked!\n");
				printf("It should not accept integer/decimals/symbols!\n");
				printf("It should only accept 'R' or 'C'\n");
				printf("Input again!\n\n");
				goto inputHrsAgain; // input status again
			}
		}
	// INPUT EMPLOYEE DEDUCTIONS
	inputDeducAgain: // input deductions again if necessary condition is not met
		printf("\nInput Employee Deductions: ");
		scanf(" %s", deduc);
		emp.deduct = atof(deduc); // convert string deductions to float deductions
		for (j = 0; j < strlen(deduc); j++)
		{
			// employee deductions should not accept alphabet
			if (isalpha(deduc[j]))
			{
				printf("\nInvalid Input Deductions!\n");
				printf("It should not accept strings!\n");
				printf("It should only accept positive decimal values\n");
				printf("Input again!\n\n");
				goto inputDeducAgain; // input deductions again
			}
			// employee deductions should not accept symbols
			if ((deduc[j] == '!') || (deduc[j] == '@') || (deduc[j] == '#') || (deduc[j] == '$') || (deduc[j] == '%') ||
					(deduc[j] == '^') || (deduc[j] == '/') || (deduc[j] == '<') || (deduc[j] == '>') || (deduc[j] == '*') ||
					(deduc[j] == '&') || (deduc[j] == '(') || (deduc[j] == ')') || (deduc[j] == '?') || (deduc[j] == ';') ||
					(deduc[j] == ':') || (deduc[j] == '_') || (deduc[j] == '=') || (deduc[j] == '+') || (deduc[j] == '[') ||
					(deduc[j] == ']') || (deduc[j] == '}') || (deduc[j] == '"') || (deduc[j] == '\'') ||
					(deduc[j] == '\\') || (deduc[j] == '|') || (deduc[j] == '-') || (deduc[j] == '`') || (deduc[j] == '~'))
			{
				printf("\nInvalid Input Deductions!\n");
				printf("It should only accept positive decimal values\n");
				printf("Input again!\n\n");
				goto inputDeducAgain; // input deductions again
			}
		}
		// function to write the data to file
		writeFile(x[i]);
	}
	fclose(file);
	printf("\nPress any key to continue...");
	getch();
	// open file to print all the employees data:
	file = fopen("record.txt", "r");
	// for loop will read the data of the employees from the file then it will display all the stored data of the employees
	system("cls");
	printf("ProgCrammers Company Employee Records\n");
	for (i = 0; i < n; i++)
	{
		// read data from file
		// the reading of data depends on the number of names a certain employee has
		if (x[i] == 1)
		{ // read data this way if employee has one name
			fscanf(file, "%s %s %s %d %f\n", emp.num, emp.name.first, emp.status, &emp.hrsWorked, &emp.deduct);
			printf("\nEmployee No. %d\n", i + 1);
			printf("Employee Number: %s\n", emp.num);
			printf("Employee Name: %s\n", emp.name.first);
			printf("Employee Status Code: %s\n", emp.status);
			printf("Employee Hours Worked: %d\n", emp.hrsWorked);
			printf("Employee Deductions: %0.2f\n", emp.deduct);
		}
		else if (x[i] == 2)
		{ // read data this way if employee has two names
			fscanf(file, "%s %s %s %s %d %f\n", emp.num, emp.name.first, emp.name.sec, emp.status, &emp.hrsWorked, &emp.deduct);
			printf("\nEmployee No. %d\n", i + 1);
			printf("Employee Number: %s\n", emp.num);
			printf("Employee Name: %s %s\n", emp.name.first, emp.name.sec);
			printf("Employee Status Code: %s\n", emp.status);
			printf("Employee Hours Worked: %d\n", emp.hrsWorked);
			printf("Employee Deductions: %0.2f\n", emp.deduct);
		}
		else if (x[i] == 3)
		{ // read data this way if employee has three names
			fscanf(file, "%s %s %s %s %s %d %f\n", emp.num, emp.name.first, emp.name.sec, emp.name.third, emp.status, &emp.hrsWorked, &emp.deduct);
			printf("\nEmployee No. %d\n", i + 1);
			printf("Employee Number: %s\n", emp.num);
			printf("Employee Name: %s %s %s\n", emp.name.first, emp.name.sec, emp.name.third);
			printf("Employee Status Code: %s\n", emp.status);
			printf("Employee Hours Worked: %d\n", emp.hrsWorked);
			printf("Employee Deductions: %0.2f\n", emp.deduct);
		}
		else if (x[i] == 4)
		{ // read data this way if employee has four names
			fscanf(file, "%s %s %s %s %s %s %d %f\n", emp.num, emp.name.first, emp.name.sec, emp.name.third, emp.name.fourth, emp.status, &emp.hrsWorked, &emp.deduct);
			printf("\nEmployee No. %d\n", i + 1);
			printf("Employee Number: %s\n", emp.num);
			printf("Employee Name: %s %s %s %s\n", emp.name.first, emp.name.sec, emp.name.third, emp.name.fourth);
			printf("Employee Status Code: %s\n", emp.status);
			printf("Employee Hours Worked: %d\n", emp.hrsWorked);
			printf("Employee Deductions: %0.2f\n", emp.deduct);
		}
	}
	// close file
	fclose(file);

	// open file for reading to solve basic salary, ot pay, net pay
	file = fopen("record.txt", "r");

	if (file == NULL)
	{
		printf("File cannot be created");
		exit(1);
	}
	// get basic salary and overtime pay
	float basic_rate;
	char rate[50]; // string version of basic rate that will later be converted to integer using atoi
	float ot_rate;
	float basic_salary[n];
	char salary[50]; // string version of basic salary that will later be converted to string using atoi function
	float ot_pay[n];
	float net_pay[n];

	// for loop to solve basic salary, ot pay, net pay
	for (i = 0; i < n; i++)
	{
		// read data to file first because emp.hrsWorked and deductions are necessary to solve for basic salary, ot pay and net pay
		if (x[i] == 1)
		{ // read data this way if employee has one name
			fscanf(file, "%s %s %s %d %f\n", emp.num, emp.name.first, emp.status, &emp.hrsWorked, &emp.deduct);
		}
		else if (x[i] == 2)
		{ // read data this way if employee has two names
			fscanf(file, "%s %s %s %s %d %f\n", emp.num, emp.name.first, emp.name.sec, emp.status, &emp.hrsWorked, &emp.deduct);
		}
		else if (x[i] == 3)
		{ // read data this way if employee has three names
			fscanf(file, "%s %s %s %s %s %d %f\n", emp.num, emp.name.first, emp.name.sec, emp.name.third, emp.status, &emp.hrsWorked, &emp.deduct);
		}
		else if (x[i] == 4)
		{
			//read data this way if employee has four names
			fscanf(file, "%s %s %s %s %s %s %d %f\n", emp.num, emp.name.first, emp.name.sec, emp.name.third, emp.name.fourth, emp.status, &emp.hrsWorked, &emp.deduct);
		}
		else
		{
			printf("Invalid number of names!");
			exit(1);
		}
		// display the employee number to make it understandable
		printf("\nEmployee No.%d", i + 1);
		// if regular employee, get basic salary then solve for overtime pay
		if (strcmp(emp.status, "R") == 0)
		{			 // use strcmp to compare whether two strings are equal or not, it is case-sensitive
		basic: // input basic salary again if necessary condition is not met:
			printf("\nInput Basic Salary: ");
			scanf(" %s", salary);
			basic_salary[i] = atof(salary); // convert the string version of basic salary to float value then store to basic salary array
			// input validations:
			for (j = 0; j < strlen(salary); j++)
			{
				// basic salary must not accept letters or alphabets
				if (isalpha(salary[j]))
				{
					printf("\n\nInvalid Input! It must be a decimal value!\nInput Again!\n");
					printf("Press any key to continue...");
					goto basic; // input basic salary again
				}
				// basic salary must not accept any symbols except . that represents float
				if ((salary[j] == '!') || (salary[j] == '@') || (salary[j] == '#') || (salary[j] == '$') || (salary[j] == '%') ||
						(salary[j] == '^') || (salary[j] == '/') || (salary[j] == '<') || (salary[j] == '>') || (salary[j] == '*') ||
						(salary[j] == '&') || (salary[j] == '(') || (salary[j] == ')') || (salary[j] == '?') || (salary[j] == ';') ||
						(salary[j] == ':') || (salary[j] == '_') || (salary[j] == '=') || (salary[j] == '+') || (salary[j] == '[') ||
						(salary[j] == ']') || (salary[j] == '}') || (salary[j] == '"') || (salary[j] == '\'') ||
						(salary[j] == '\\') || (salary[j] == '|') || (salary[j] == '-'))
				{
					printf("\n\nInvalid Input! It must be a decimal value!\nInput Again!\n\n");
					goto basic; // input basic salary again
				}
			}
			// if employee worked for more than 160 hours, solve for overtime pay
			if (emp.hrsWorked > 160)
			{
				basic_rate = basic_salary[i] / 160;
				ot_rate = basic_rate * 1.5;
				ot_pay[i] = (emp.hrsWorked - 160) * ot_rate;
			}
			else
			{
				ot_pay[i] = 0;
			}
		}
		// if casual employee, get basic rate then solve for basic salary and overtime pay
		else if (strcmp(emp.status, "C") == 0)
		{					 // use strcmp to compare whether two strings are equal or not, it is case-sensitive
		rateAgain: // input basic rate again if necessary condition is not met:
			printf("\nInput Basic Rate: ");
			scanf(" %s", rate);
			basic_rate = atof(rate); // convert string rate to float basic_rate using atof
			// input validations:
			for (j = 0; j < strlen(rate); j++)
			{
				// basic rate must not accept alphabets or letter
				if (isalpha(rate[j]))
				{
					printf("\n\nInvalid Input! It must be a decimal value!\nInput Again!\n");
					goto rateAgain; // input basic rate again
				}
				// basic rate must not accept symbols
				if ((rate[j] == '!') || (rate[j] == '@') || (rate[j] == '#') || (rate[j] == '$') || (rate[j] == '%') ||
						(rate[j] == '^') || (rate[j] == '/') || (rate[j] == '<') || (rate[j] == '>') || (rate[j] == '*') ||
						(rate[j] == '&') || (rate[j] == '(') || (rate[j] == ')') || (rate[j] == '?') || (rate[j] == ';') ||
						(rate[j] == ':') || (rate[j] == '_') || (rate[j] == '=') || (rate[j] == '+') || (rate[j] == '[') ||
						(rate[j] == ']') || (rate[j] == '}') || (rate[j] == '"') || (rate[j] == '\'') ||
						(rate[j] == '\\') || (rate[j] == '|') || (rate[j] == '-'))
				{
					printf("\n\nInvalid Input! It must be a decimal value!\nInput Again!\n");
					goto rateAgain; // input basic rate again
				}
			}
			// if employee worked for more than 160 hours, solve for overtime pay
			if (emp.hrsWorked > 160)
			{
				basic_salary[i] = 160 * basic_rate;
				ot_rate = basic_rate * 1.5;
				ot_pay[i] = (emp.hrsWorked - 160) * ot_rate;
			}
			else
			{ // if employee worked for 160 and less hours
				basic_salary[i] = emp.hrsWorked * basic_rate;
				ot_pay[i] = 0;
			}
		}
		else
		{
			printf("\nInvalid input!");
		}
		// solve for net pay
		net_pay[i] = basic_salary[i] + ot_pay[i] - emp.deduct;
		// display basic salary, overtime pay, and deductions for proof of correct computation
		printf("\nBasic Salary = %0.2f\n", basic_salary[i]);
		printf("Overtime Pay = %0.2f\n", ot_pay[i]);
		printf("Deductions: %0.2f\n", emp.deduct);
		printf("Net Pay = %0.2f\n", net_pay[i]);
	}
	fclose(file);
	printf("\nPress any key to display the Output...");
	getch(); // getch should come first before system cls in order to display the output above before the output below
	system("cls");
	//  DISPLAY FINAL OUTPUT
	//  printf("\n");
	for (i = 0; i < 160; i++)
		printf("+");
	printf("\n\t\t\t\t\t\t\t\t      PROGCRAMMERS COMPANY");
	printf("\n\t\t\t\t\t\t\t\t          Quezon City\n\n");
	for (i = 0; i < 160; i++)
		printf("+");
	printf("\n\t\t\t\t\t\t\t\t            Payroll\n\n");
	for (i = 0; i < 160; i++)
		printf("-");
	printf("\n\tEmployee\t\tEmployee\t\t Status\t\t    Basic \t\t  Overtime\t\tDeductions\t\t Net \n");
	printf("\n\tNumber \t\t\tName     \t\t\t\t    Salary \t\t  Pay        \t\t         \t\t Pay \n");
	for (i = 0; i < 160; i++)
		printf("-");
	printf("\n");

	// open file for reading purpose: to print the final output
	file = fopen("record.txt", "r");

	if (file == NULL)
	{
		printf("File cannot be created");
		exit(1);
	}
	// for loop to read data to file in order to print the final output
	printf("\n");
	for (i = 0; i < n; i++)
	{
		// read data to file
		if (x[i] == 1)
		{ // read file this way if employee has one name
			fscanf(file, "%s %s %s %d %f\n", emp.num, emp.name.first, &emp.status, &emp.hrsWorked, &emp.deduct);
		}
		else if (x[i] == 2)
		{ // read data this way if employee has two names
			fscanf(file, "%s %s %s %s %d %f\n", emp.num, emp.name.first, emp.name.sec, &emp.status, &emp.hrsWorked, &emp.deduct);
		}
		else if (x[i] == 3)
		{ // read data this way if employee has three names
			fscanf(file, "%s %s %s %s %s %d %f\n", emp.num, emp.name.first, emp.name.sec, emp.name.third, &emp.status, &emp.hrsWorked, &emp.deduct);
		}
		else if (x[i] == 4)
		{	//read data this way if employee has four names
			fscanf(file, "%s %s %s %s %s %s %d %f\n", emp.num, emp.name.first, emp.name.sec, emp.name.third, emp.name.fourth, emp.status, &emp.hrsWorked, &emp.deduct);
		}
		else
		{
			printf("Invalid number of names!");
			exit(1);
		}
		// function call to print final output
		printOutput(x[i], emp.num, emp.name.first, emp.name.sec, emp.name.third, emp.name.fourth, emp.status, basic_salary[i], ot_pay[i], emp.deduct, net_pay[i]);
	}
	fclose(file);
	return 0;
}



