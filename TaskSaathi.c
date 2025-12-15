#include <stdio.h>

#define MAX_TASKS 10
#define TASK_LEN 50

int main() {

    char tasks[MAX_TASKS][TASK_LEN];   // Task names (single word)
    int status[MAX_TASKS];             // 0 = pending, 1 = completed
    int taskCount = 0;
    int choice;

    // Initialize task status
    for (int i = 0; i < MAX_TASKS; i++) {
        status[i] = 0;
    }

    while (1) {

         printf("\n");
         printf("====================================================\n");
         printf("||                                                ||\n");
         printf("||               W  E  L  C  O  M  E              ||\n");
         printf("||                      T O                       ||\n");
         printf("||               T A S K S A A T H I              ||\n");
         printf("||                                                ||\n");
         printf("====================================================\n\n");
 
        printf("   [1]  Add Task\n");
        printf("   [2]  View Tasks\n");
        printf("   [3]  Mark Task Completed\n");
        printf("   [4]  End Day & Reflection\n");
        printf("   [5]  Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        /* ADD TASK */
       if (choice == 1) {

    int n;
    printf("How many tasks do you want to add? ");
    scanf("%d", &n);

    if (taskCount + n > MAX_TASKS) {
        printf("Cannot add that many tasks. Limit exceeded.\n");
    } 
    else {
        for (int i = 0; i < n; i++) {
            printf("Enter task %d: ", taskCount + 1);
            scanf(" %[^\n]", tasks[taskCount]);  // allows spaces
            status[taskCount] = 0;
            taskCount++;
        }
        printf(" %d task(s) added successfully.\n", n);
        printf("Close the program and do your work.\n");
        printf("Come back later to mark completion.\n");
 
    }
}


        /* VIEW TASKS */
        else if (choice == 2) {

            if (taskCount == 0) {
                printf("No tasks available.\n");
            } else {
                printf("\nYour Tasks:\n");
                for (int i = 0; i < taskCount; i++) {
                    if (status[i] == 1)
                        printf("[X] %d. %s\n", i + 1, tasks[i]);
                    else
                        printf("[ ] %d. %s\n", i + 1, tasks[i]);
                }
            }
        }

        /* MARK TASK COMPLETED */
       else if (choice == 3) {

    int num;

    printf("Enter task numbers to mark completed (0 to stop):\n");

    while (1) {
        scanf("%d", &num);

        if (num == 0) {
            break;   // stop input
        }

        if (num < 1 || num > taskCount) {
            printf("Invalid task number.\n");
        } 
        else if (status[num - 1] == 1) {
            printf("Task %d already completed.\n", num);
        }
        else {
            status[num - 1] = 1;
        }
    }

    printf("Selected tasks marked as completed.\n");
}


        /* DAILY REFLECTION */
        else if (choice == 4) {

            int completedTasks = 0;

            for (int i = 0; i < taskCount; i++) {
                if (status[i] == 1)
                    completedTasks++;
            }

            printf("\n----- DAILY REFLECTION -----\n");

            if (taskCount == 0) {
                printf("No tasks were planned today.\n");
                printf("A calm day. Planning helps tomorrow.\n");
            }
            else if (completedTasks == taskCount) {
                printf("All tasks completed.\n");
                printf("You showed Strong focus and discipline today.\n");
            }
            else if (completedTasks > taskCount / 2) {
                printf("Most of the tasks completed.\n");
                printf("Good progress. Stay consistent.\n");
            }
            else if (completedTasks > 0) {
                printf("Some tasks completed.\n");
                printf("Efforts were made. Improve gradually.\n");
            }
            else {
                printf("No tasks completed today.\n");
                printf("Reset and be better tomorrow.\n");
            }
        }

        /* EXIT */
        else if (choice == 5) {
            printf("Comeback again for managing your DinCharya.\n");
            break;
        }
        else {
            printf("Invalid choice.\n");
        }
    }

    return 0;
}
