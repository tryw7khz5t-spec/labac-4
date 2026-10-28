
#include <stdio.h>

#define MAX_STUDENTS 5

struct STUDENT {
    char NAME[50];
    int GROUP;
    int SES[5];
    float AVG;
};

int main() {
    struct STUDENT STUD1[MAX_STUDENTS], temp;
    int i, j, sum, ok, found = 0;


    for (i = 0; i < MAX_STUDENTS; i++) {
        printf("\nStudent %d\n", i + 1);

        printf("Name: ");
        scanf("%49s", STUD1[i].NAME);

        printf("Group: ");
        scanf("%d", &STUD1[i].GROUP);

        sum = 0;

        for (j = 0; j < 5; j++) {
            printf("Grade %d: ", j + 1);
            scanf("%d", &STUD1[i].SES[j]);
            sum += STUD1[i].SES[j];
        }

        STUD1[i].AVG = sum / 5.0;
    }

    
    for (i = 0; i < MAX_STUDENTS; i++) {
        for (j = i + 1; j < MAX_STUDENTS; j++) {
            if (STUD1[i].AVG > STUD1[j].AVG) {
                temp = STUD1[i];
                STUD1[i] = STUD1[j];
                STUD1[j] = temp;
            }
        }
    }


    for (i = 0; i < MAX_STUDENTS; i++) {
        ok = 1;

        for (j = 0; j < 5; j++) {
            if (STUD1[i].SES[j] != 4 &&
                STUD1[i].SES[j] != 5) {
                ok = 0;
            }
        }

        if (ok == 1) {
            printf("%s Group %d\n",
                   STUD1[i].NAME, STUD1[i].GROUP);
            found = 1;
        }
    }

    if (found == 0) {
        printf("No students found\n");
    }

    return 0;
}
