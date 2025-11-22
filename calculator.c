#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX_HISTORY 100


char history[MAX_HISTORY][100];
int historyCount = 0;

void addHistory(const char *entry) {
    if (historyCount < MAX_HISTORY) {
        strcpy(history[historyCount], entry);
        historyCount++;
    }
}

void showHistory() {
    clearScreen();
    printf("========= HISTORY =========\n");

    if (historyCount == 0) {
        printf("No history available.\n");
        return;
    }

    for (int i = 0; i < historyCount; i++) {
        printf("%d. %s\n", i + 1, history[i]);
    }
    printf("===========================\n");
}


void clearScreen();
void basicCalculator();
void advancedCalculator();
long long factorial(int n);


int main() {
    int choice;

    do {
        clearScreen();
        printf("============================\n");
        printf("       SIMPLE CALCULATOR     \n");
        printf("============================\n");
        printf("1. Basic Operations (+, -, *, /)\n");
        printf("2. Advanced Operations (sqrt, power, factorial)\n");
        printf("3. View History\n");
        printf("4. Exit\n");
        printf("----------------------------\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF) {}
            choice = 0;
        }

        switch (choice) {
            case 1:
                basicCalculator();
                break;
            case 2:
                advancedCalculator();
                break;
            case 3:
                showHistory();
                break;
            case 4:
                clearScreen();
                printf("\n====================================\n");
                printf("   Developed by: MD NAZMUL HASAN   \n");
                printf("====================================\n\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }

        printf("\nPress Enter to continue...");
        getchar();
        getchar();

    } while (choice != 4);

    return 0;
}


void clearScreen() {
    fflush(stdout);
    int ret = 0;

#ifdef _WIN32
    ret = system("cls");
#else
    ret = system("clear");
#endif

    if (ret != 0) {
        for (int i = 0; i < 50; i++)
            putchar('\n');
        fflush(stdout);
    }
}


void basicCalculator() {
    float a, b, result;
    char op;

    clearScreen();
    printf("--- Basic Calculator ---\n");
    printf("Enter expression (a [+ - * /] b): ");

    if (scanf("%f %c %f", &a, &op, &b) != 3) {
        printf("Invalid input format.\n");
        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF) {}
        return;
    }

    char entry[100];

    switch (op) {
        case '+':
            result = a + b;
            printf("Result: %.2f\n", result);
            sprintf(entry, "%.2f + %.2f = %.2f", a, b, result);
            addHistory(entry);
            break;

        case '-':
            result = a - b;
            printf("Result: %.2f\n", result);
            sprintf(entry, "%.2f - %.2f = %.2f", a, b, result);
            addHistory(entry);
            break;

        case '*':
            result = a * b;
            printf("Result: %.2f\n", result);
            sprintf(entry, "%.2f * %.2f = %.2f", a, b, result);
            addHistory(entry);
            break;

        case '/':
            if (b == 0) {
                printf("Error! Division by zero.\n");
            } else {
                result = a / b;
                printf("Result: %.2f\n", result);
                sprintf(entry, "%.2f / %.2f = %.2f", a, b, result);
                addHistory(entry);
            }
            break;

        default:
            printf("Invalid operator!\n");
    }
}


void advancedCalculator() {
    int choice;
    double num, base, exp;
    int n;

    clearScreen();
    printf("--- Advanced Calculator ---\n");
    printf("1. Square Root\n");
    printf("2. Power\n");
    printf("3. Factorial\n");
    printf("Enter your choice: ");

    if (scanf("%d", &choice) != 1) {
        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF) {}
        printf("Invalid input.\n");
        return;
    }

    char entry[100];

    switch (choice) {
        case 1:
            printf("Enter a number: ");
            if (scanf("%lf", &num) != 1) { printf("Invalid input.\n"); return; }

            if (num < 0)
                printf("Error! Negative number.\n");
            else {
                double res = sqrt(num);
                printf("Square root of %.2lf = %.2lf\n", num, res);
                sprintf(entry, "sqrt(%.2lf) = %.2lf", num, res);
                addHistory(entry);
            }
            break;

        case 2:
            printf("Enter base: ");
            if (scanf("%lf", &base) != 1) { printf("Invalid input.\n"); return; }

            printf("Enter exponent: ");
            if (scanf("%lf", &exp) != 1) { printf("Invalid input.\n"); return; }

            double result;
            result = pow(base, exp);
            printf("Result: %.2lf\n", result);
            sprintf(entry, "%.2lf ^ %.2lf = %.2lf", base, exp, result);
            addHistory(entry);
            break;

        case 3:
            printf("Enter an integer: ");
            if (scanf("%d", &n) != 1) { printf("Invalid input.\n"); return; }

            if (n < 0)
                printf("Error! Factorial of negative number doesn't exist.\n");
            else {
                long long fact = factorial(n);
                printf("Factorial of %d = %lld\n", n, fact);
                sprintf(entry, "%d! = %lld", n, fact);
                addHistory(entry);
            }
            break;

        default:
            printf("Invalid choice!\n");
    }
}


long long factorial(int n) {
    if (n == 0 || n == 1)
        return 1;
    else
        return n * factorial(n - 1);
}
