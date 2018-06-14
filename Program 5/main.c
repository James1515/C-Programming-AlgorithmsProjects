/* 
 * 
 * Purpose: The purpose of the program is to keep and perform 
 * statistical analysis for a class of students. The program will 
 * display 6 columns in table form: the first column will 
 * display the id information of each student, and the other 5 columns 
 * will include the values of 5 quizzes separated into columns. 
 * The program will also display the hi-score, the lo-score, and 
 * the average score of each quiz column.
 * 
 *     Author: James Ortiz
 *     Modified: 4/2/2016
 */

#include <stdio.h>  //Pre-processor to recieve input/output

//Constants to hold the quantities of the arrays used in the program.
#define MAXIMUM_AMT_STUDENTS 40 //Maximum amount of Rows
#define MAXIMUM_AMT_QUIZZES  5  //Maximum amount of columns


//=============Function Declarations===============//

//Function getData:
void getData(int studnt_ID[], int stdntScores[][MAXIMUM_AMT_QUIZZES],
        int* numStudts);

//Function calculate:
void calculate(int stdntScores[][MAXIMUM_AMT_QUIZZES], 
        int numStudts, int quiz_cnt, int hi_score[], int lo_score[],
        double average[]);

//Function calcLoScore:
int calcLoScore(int stdntScores[][MAXIMUM_AMT_QUIZZES], int quiz_cnt,
                int numStudts);

//Function calcHiScore:
int calcHiScore(int stdntScores[][MAXIMUM_AMT_QUIZZES], int quiz_cnt,
                int numStudts);

//Function calcAverage:
double calcAverage(int stdntScores[][MAXIMUM_AMT_QUIZZES], int quiz_cnt,
                   int numStudnts);

//Function printResults:
void printResults(int stdnt_ID[], int stdntScores[][MAXIMUM_AMT_QUIZZES], 
        int quiz_cnt, int numStudnts, int hi_score[], int lo_score[], 
        double average[]);


int main(void) // "main" header
{   
    
    //Variable Declarations:
    /*
     Variables of type "Int":
     The array student_ID is intended to store the 
     identifications of all of the students inputted. The
     array "studentScores" is a two-dimensional array that holds
     the values of the quizzes, and of the the student identifications.
     
     The arrays "high_score" and "low_score" holds the highest and
     lowest scores for each of the quizzes. 
     The variable "quiz_count" keeps track of the quiz_values used in the 
     functions when they are called.
     * 
     
     Variables of type "Double":
     *
     The array average is of type "double", and stores the average for each
     quiz.
     *
     
     */
    int student_ID[MAXIMUM_AMT_STUDENTS];
    int studentScores[MAXIMUM_AMT_STUDENTS][MAXIMUM_AMT_QUIZZES];
    int high_score[MAXIMUM_AMT_QUIZZES];
    int low_score[MAXIMUM_AMT_QUIZZES];
    double Average[MAXIMUM_AMT_QUIZZES];
    int quiz_count = 0;
    int number_of_students = 0;
    
    //Function Calls: getData, calculate, and printResults
    
    getData(student_ID, studentScores, &number_of_students);

    calculate(studentScores, number_of_students, quiz_count, high_score,
            low_score, Average);
    printResults(student_ID, studentScores, quiz_count, number_of_students,
            high_score, low_score, Average);
    
    


    return 0; //Terminates program
    
    
} //Ends main

//==============Function Definitions===========//

/*
 ****************getData Function***********************
 Allows a pointer to be used to gain access to a data
 file called myfile.dat. Reads information until the 
 end of the file is reached.
 *******************************************************
 */

void getData(int studnt_ID[], int stdntScores[][MAXIMUM_AMT_QUIZZES],
        int* numStudts) 
{

    //Enables a pointer 
    FILE* spIn; 
    //Pointer is used to gain access to "myfile.dat"
    //File is then read through the fopen function
    spIn = fopen ("myfile.dat", "r");
    
    //Student count is assigned to "0"
    //quiz_count is initialized
    
    int student_count = 0;
    int quiz_count;
    
    //While-loop: 
    //Goes through the data file and iterates until it reaches the end of 
    //the file
    while (fscanf(spIn, "%d", &studnt_ID[student_count]) != EOF)
    {
        //For-loop: Keeps track of the student scores, and uses "fscan" to
        //take in values from the data file.
        for(quiz_count = 0; quiz_count < MAXIMUM_AMT_QUIZZES; quiz_count++)
        {
           
            fscanf(spIn, "%d", &stdntScores[student_count][quiz_count]);
        }
        
        //student_count is incremented
        student_count = student_count + 1;
    }
    
    //The address of numStudts is assigned to the value of 
    *numStudts = student_count;
    
    

    return; //Returns control to main
} //getData
/*
 ****************calculate Function***********************
 Assigns hi_score[], lo_score[], and average[], to the 
 functions calcLoScore, calcHiScore, and calcAverage. These 
 assigned arrays are returned back to main.
 *********************************************************
*/
void calculate(int stdntScores[][MAXIMUM_AMT_QUIZZES], 
        int numStudts, int quiz_cnt, int hi_score[], int lo_score[],
        double average[])
{
    //The array hi_score is assigned to the returned value of 
    //the function "calcHiScore".
    hi_score[MAXIMUM_AMT_QUIZZES] = calcHiScore(stdntScores,
            quiz_cnt, numStudts);
    
    //The array "lo_score" is assigned to the returned value of 
    //the function "calcLoScore".
    lo_score[MAXIMUM_AMT_QUIZZES] = calcLoScore(stdntScores,
            quiz_cnt, numStudts);
    
    //The array "average" is assigned to the returned value of
    //the function "calcAverage".
    
    average[MAXIMUM_AMT_QUIZZES] = calcAverage(stdntScores,
            quiz_cnt, numStudts);
    
    return; //Returns control to main
    
} //calculate
/*
 ****************calcLoScore Function***********************
 Calculates the lowest score of each of the quizzes for 
 each student.
 ***********************************************************
*/
int calcLoScore(int stdntScores[][MAXIMUM_AMT_QUIZZES], int quiz_cnt,
                int numStudts)
{
    //Assigns the variable result to zero
    int result = 0;
    
    //Declares the variable student_count
    int student_count;
    
    //result is assigned to the value of the array stdntScores[][]
    
    result = stdntScores[0][quiz_cnt];
    //For-loop: Repeats until student_count has the numerical value
    //of numStudts
    for(student_count = 0; student_count < numStudts; student_count++)
    {
        //If-Statement: Goes through the quiz rows, and assigns 
        //the lowest score to result.
        if(stdntScores[student_count][quiz_cnt] < result)
        {
            result = stdntScores[student_count][quiz_cnt];
        }
    }
    
    //Returns the value of result to the function "calculate"
    return result;
    
} //calcLoScore


/*
 ****************calcHiScore Function***********************
 Calculates the highest score of each of the quizzes for each
 student.
 ***********************************************************
*/

int calcHiScore(int stdntScores[][MAXIMUM_AMT_QUIZZES], int quiz_cnt,
                int numStudts)
{
    //result is initialized and assigned to zero
    int result = 0;
    
    //student_count is declared 
    int student_count;
    
    //result is assigned to the array stdntScores[][]
    result = stdntScores[0][quiz_cnt];
    
    //For-loop:
    //Iterates as long as student_count is less than numStudts
    for(student_count = 0; student_count < numStudts; student_count++)
    {
        //If-statement: assigns result to the greatest value of each quiz
        //row.
        if(stdntScores[student_count][quiz_cnt] > result)
        {
            result = stdntScores[student_count][quiz_cnt];
        }
    }
    
    return result; //Returns the value of "result" to "calculate"
    
}  //calcHiScore


/*
 ****************calcAverage Function******************************
 Calculates the average for each of the 5 quizzes of all students.
 ******************************************************************
*/

double calcAverage(int stdntScores[][MAXIMUM_AMT_QUIZZES], int quiz_cnt,
                   int numStudnts)
{

    //Initializes and assigns average to zero
    float average = 0;
    
    //"sum" and "student_count" declarations
    int sum = 0;
    int student_count;
    int result = 0;
    
    //For-loop: Goes through the student quiz scores, 
    //and finds the average for each of the rows.
    for(student_count = 0; student_count < numStudnts; student_count++)
    {
        sum = sum + stdntScores[student_count][quiz_cnt];
    }
    
    //Assigns average to the sum divided by the number of students.
    average = sum /(float)numStudnts;
    
    return average; //Returns the value of "average" to "calculate"

} //calcAverage

/*
 ****************printResults Function***********************
 Displays the results of all of the quizzes, along with the 
 average, the high-score, and the low-score for each of the 5 
 quizzes. 
 ************************************************************
*/

void printResults(int stdnt_ID[], int stdntScores[][MAXIMUM_AMT_QUIZZES], 
        int quiz_cnt, int numStudnts, int hi_score[], int lo_score[], 
        double average[])
{
    
    
    //Declaration for "row" and "column"
    int row;
    int column;
    
    
    printf("Student\t    Quiz 1  Quiz 2  Quiz 3  Quiz 4  Quiz 5\n");
    

    //Displays the grades of the table
    for(row = 0; row < numStudnts; row++)
    {
        //Displays the student id
        printf("   %d", stdnt_ID[row]);
        
        for(column = 0; column < MAXIMUM_AMT_QUIZZES; column++)
        {
            //Displays the student scores
            printf("%8d", stdntScores[row][column]);
        }
        printf("\n");
    }
    
    //High-score section
    printf("High-Score\t");
    
    for(column = 0; column < MAXIMUM_AMT_QUIZZES; column++)
    {
        //Displays the results of the High-Score
        printf("%6d", hi_score[column]);
    }
    printf("\n");
    
    //Low-Score Section
    printf("Low-Score\t");
    
    for(column = 0; column < MAXIMUM_AMT_QUIZZES; column++)
    {
        //Displays the results of the Low-Score
        printf("%6d", lo_score[column]);
        
    } 
    printf("\n");    
    
    //Average Section
    printf("Average\t");
    
    for(column = 0; column < MAXIMUM_AMT_QUIZZES; column++)
    {
        //Displays the results of the  "Average" 
        printf("%8.2f", average[column]);
        
    }
    printf("\n");
    
    //Returns control to "main"
    return;
} //printResults










  






