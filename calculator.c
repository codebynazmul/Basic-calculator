#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <windows.h>   // For Sleep() & color on Windows

#define MAX_HISTORY 100

char history[MAX_HISTORY][200];
int historyCount = 0;

// ===================== FUNCTION DECLARATIONS =====================
void clearScreen();
void typeBlue(const char *text, int delay);
void showIntro();
void addHistory(const char *entry);
void showHistory();
void basicCalculator();
void advancedCalculator();
long long factorial(int n);

// ===================== MAIN FUNCTION =====================
int main() {
    int choice;

    showIntro();   // Show blue ASCII animation at start

    do {
        clearScreen();
        printf("============================\n");
        printf("       SIMPLE CALCULATOR     \n");
        printf("============================\n");
        printf("1. Basic Operations (+, -, *, /)\n");
        printf("2. Advanced Operations (Scientific)\n");
        printf("3. View History\n");
        printf("4. Exit\n");
        printf("----------------------------\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n');
            choice = 0;
        }

        switch (choice) {
            case 1: basicCalculator(); break;
            case 2: advancedCalculator(); break;
            case 3: showHistory(); break;
            case 4:
                clearScreen();
                printf("\n====================================\n");
                printf("   Developed by: MD NAZMUL HASAN   \n");
                printf("====================================\n\n");
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }

        printf("\nPress Enter to continue...");
        getchar();
        getchar();

    } while (choice != 4);

    return 0;
}

// ====================== CLEAR SCREEN ======================
void clearScreen() {
    system("cls");
}

// ====================== TYPING BLUE TEXT ======================
void typeBlue(const char *text, int delay) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1); // BLUE

    for (int i = 0; text[i] != '\0'; i++) {
        printf("%c", text[i]);
        fflush(stdout);
        Sleep(delay);
    }

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); // RESET
}

// ====================== ASCII INTRO ======================
void showIntro() {
    clearScreen();
    const char *ascii =
"  _________        .__               .__          __                \n"
"  \\_   ___ \\_____  |  |   ____  __ __|  | _____ _/  |_  ___________ \n"
"  /    \\  \\/\\__  \\ |  | _/ ___\\|  |  \\  | \\__  \\\\   __\\/  _ \\_  __ \\\n"
"  \\     \\____/ __ \\|  |_\\  \\___|  |  /  |__/ __ \\|  | (  <_> )  | \\/\n"
"   \\______  (____  /____/\\___  >____/|____(____  /__|  \\____/|__|   \n"
"          \\/     \\/          \\/                \\/                    \n";

    typeBlue(ascii, 1);
    Sleep(700);
}

// ====================== HISTORY ======================
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

// ====================== BASIC CALCULATOR ======================
void basicCalculator() {
    float a, b, result;
    char op;

    clearScreen();
    printf("--- Basic Calculator ---\n");
    printf("Enter expression (a [+ - * /] b): ");

    if (scanf("%f %c %f", &a, &op, &b) != 3) {
        printf("Invalid input.\n");
        while (getchar() != '\n');
        return;
    }

    char entry[200];

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

// ====================== ADVANCED CALCULATOR ======================
void advancedCalculator() {
    int choice;

    do {
        clearScreen();
        printf("--- Advanced Calculator ---\n");
        printf("1. Square Root\n");
        printf("2. Power\n");
        printf("3. Factorial\n");
        printf("4. Sin(x)\n");
        printf("5. Cos(x)\n");
        printf("6. Tan(x)\n");
        printf("7. Exit to Main Menu\n");
        printf("Choose: ");

        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n');
            choice = 0;
        }

        char entry[200];
        double num, base, exp;
        int n;

        switch (choice) {
            case 1:
                printf("Enter number: ");
                scanf("%lf", &num);
                if (num < 0) printf("Error! Negative number.\n");
                else {
                    double res = sqrt(num);
                    printf("Result: %.2lf\n", res);
                    sprintf(entry, "sqrt(%.2lf) = %.2lf", num, res);
                    addHistory(entry);
                }
                break;

            case 2:
                printf("Enter base: ");
                scanf("%lf", &base);
                printf("Enter exponent: ");
                scanf("%lf", &exp);
                double result;
                result = pow(base, exp);
                printf("Result: %.2lf\n", result);
                sprintf(entry, "%.2lf ^ %.2lf = %.2lf", base, exp, result);
                addHistory(entry);
                break;

            case 3:
                printf("Enter integer: ");
                scanf("%d", &n);
                if (n < 0) printf("Error! Negative number.\n");
                else {
                    long long fact = factorial(n);
                    printf("Result: %lld\n", fact);
                    sprintf(entry, "%d! = %lld", n, fact);
                    addHistory(entry);
                }
                break;

            case 4:
                printf("Enter angle (in degrees): ");
                scanf("%lf", &num);
                double s = sin(num * M_PI / 180);
                printf("sin(%.2lf) = %.4lf\n", num, s);
                sprintf(entry, "sin(%.2lf°) = %.4lf", num, s);
                addHistory(entry);
                break;

            case 5:
                printf("Enter angle (in degrees): ");
                scanf("%lf", &num);
                double c = cos(num * M_PI / 180);
                printf("cos(%.2lf) = %.4lf\n", num, c);
                sprintf(entry, "cos(%.2lf°) = %.4lf", num, c);
                addHistory(entry);
                break;

            case 6:
                printf("Enter angle (in degrees): ");
                scanf("%lf", &num);
                double t = tan(num * M_PI / 180);
                printf("tan(%.2lf) = %.4lf\n", num, t);
                sprintf(entry, "tan(%.2lf°) = %.4lf", num, t);
                addHistory(entry);
                break;

            case 7:
                return; // Exit advanced menu

            default:
                printf("Invalid choice!\n");
        }

        printf("\nPress Enter...");
        getchar();
        getchar();

    } while (choice != 7);
}

// ====================== FACTORIAL ======================
long long factorial(int n) {
    return (n <= 1) ? 1 : n * factorial(n - 1);
}
