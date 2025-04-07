#include <stdio.h>

int main()
{
    const int NUM_SUBJECTS = 3;
    const int NUM_TESTS = 4;
    char *subjects[] = {"Physics", "Chemistry", "Math"};
    

    float marks[NUM_SUBJECTS][NUM_TESTS];
    float subjectAverage[NUM_SUBJECTS];
    float overallAverage = 0.0;

    for (int i = 0; i < NUM_SUBJECTS; i++)
    {
        float sum = 0.0;

        printf("Enter marks for %s:\n,subjects[i]");

        for (int j = 0; j < NUM_TESTS; j++)
        {
            do
            {
                switch (j)
                {
                case (0):
                    printf("Assignment(0-100):");
                    break;
                case (1):
                    printf("Course work(0-100):");
                    break;
                case (2):
                    printf("Mid-Term(0-100):");
                    break;
                case (3):
                    printf("End of term(0-100):");
                    break;
                }

                scanf("%f", &marks[i][j]);

                // Validate input
                if (marks[i][j] < 0 || marks[i][j] > 100)
                {
                    printf("Invalid input! Marks Should be between 0 and 100.\n");
                }

            } while (marks[i][j] < 0 || marks[i][j] > 100);
            sum += marks[i][j];
        }

        subjectAverage[i] = sum / NUM_TESTS;
        overallAverage += subjectAverage[i];
        printf("Average for %s: %.2f\n\n", subjects[i], subjectAverage[i]);
    }

    overallAverage /= NUM_SUBJECTS;
    printf("Overall average marks:%.2f\n", overallAverage);

    return 0;
}