#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Maximum length for username and password
#define MAX_LENGTH 50

// Function prototypes
void registerUser();
int loginUser();
void performCalculations(char *username);
void writeToFile(char *filename, const char *content);

int main()
{
    int choice;
    printf("Welcome to the Calculator with Login System\n");
    printf("1. Register\n2. Login\n3. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
     {
        case 1:
            registerUser();
            break;
        case 2:
            if (loginUser())
            {
                printf("\nLogin successful!\n");
            }
            break;
        case 3:
            printf("Exiting the program. Goodbye!\n");
            exit(0);
        default:
            printf("Invalid choice. Exiting.\n");
    }
    return 0;
}

// Function to register a new user
void registerUser()
{
    char username[MAX_LENGTH], password[MAX_LENGTH];
    FILE *file;

    printf("\nEnter a username: ");
    scanf("%s", username);
    printf("Enter a password: ");
    scanf("%s", password);

    // Open the "users.txt" file to store the username and password
    file = fopen("users.txt", "a");
    if (file == NULL)
    {
        printf("Error opening file.\n");
        return;
    }

    fprintf(file, "%s %s\n", username, password);
    fclose(file);
    printf("Registration successful. You can now log in.\n");
}

// Function to log in a user
int loginUser()
 {
    char username[MAX_LENGTH], password[MAX_LENGTH];
    char storedUser[MAX_LENGTH], storedPass[MAX_LENGTH];
    FILE *file;

    printf("\nEnter your username: ");
    scanf("%s", username);
    printf("Enter your password: ");
    scanf("%s", password);

    // Open the "users.txt" file to verify login details
    file = fopen("users.txt", "r");
    if (file == NULL)
    {
        printf("Error opening file. Please register first.\n");
        return 0;
    }

    while (fscanf(file, "%s %s", storedUser, storedPass) != EOF)
        {
        if (strcmp(username, storedUser) == 0 && strcmp(password, storedPass) == 0)
         {
            fclose(file);
            performCalculations(username);
            return 1;
        }
    }

    fclose(file);
    printf("Invalid username or password. Try again.\n");
    return 0;
}

// Function to perform calculations
void performCalculations(char *username)
{
    int choice, operation;
    double num1, num2, result;
    char filename[MAX_LENGTH];
    char buffer[256];
    snprintf(filename, MAX_LENGTH, "%s.txt", username);

    while (1)
    {
        printf("\nSelect a Calculation:\n");
        printf("1. Arithmetic (Add, Subtract, Multiply, Divide)\n");
        printf("2. Trigonometric (sin, cos, tan)\n");
        printf("3. Logarithmic (log10, natural log)\n");
        printf("4. Exponential (e^x, x^y)\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
         {
            case 1:
                printf("Enter two numbers: ");
                scanf("%lf %lf", &num1, &num2);
                printf("1. Add\n2. Subtract\n3. Multiply\n4. Divide\n");
                printf("Choose operation: ");
                scanf("%d", &operation);

                if (operation == 1)
                {
                    result = num1 + num2;
                    snprintf(buffer, sizeof(buffer), "Add: %.2lf + %.2lf = %.2lf\n", num1, num2, result);
                }
                 else if (operation == 2)
                {
                    result = num1 - num2;
                    snprintf(buffer, sizeof(buffer), "Subtract: %.2lf - %.2lf = %.2lf\n", num1, num2, result);
                }
                else if (operation == 3)
                {
                    result = num1 * num2;
                    snprintf(buffer, sizeof(buffer), "Multiply: %.2lf * %.2lf = %.2lf\n", num1, num2, result);
                }
                else if (operation == 4)
                {
                    if (num2 != 0)
                    {
                        result = num1 / num2;
                        snprintf(buffer, sizeof(buffer), "Divide: %.2lf / %.2lf = %.2lf\n", num1, num2, result);
                    }
                else

                    {
                        snprintf(buffer, sizeof(buffer), "Error: Division by zero.\n");
                    }
                }
                writeToFile(filename, buffer);
                printf("%s", buffer);
                break;

            case 2:
                printf("Enter a number (in radians): ");
                scanf("%lf", &num1);
                printf("1. sin\n2. cos\n3. tan\n");
                printf("Choose operation: ");
                scanf("%d", &operation);

                if (operation == 1)
                {
                    result = sin(num1);
                    snprintf(buffer, sizeof(buffer), "sin(%.2lf) = %.2lf\n", num1, result);
                }
                else if (operation == 2)
                {
                    result = cos(num1);
                    snprintf(buffer, sizeof(buffer), "cos(%.2lf) = %.2lf\n", num1, result);
                }
                else if (operation == 3)
                {
                    result = tan(num1);
                    snprintf(buffer, sizeof(buffer), "tan(%.2lf) = %.2lf\n", num1, result);
                }
                writeToFile(filename, buffer);
                printf("%s", buffer);
                break;

            case 3:
                printf("Enter a number: ");
                scanf("%lf", &num1);
                printf("1. log10 (Base 10)\n2. ln (Natural Logarithm)\n");
                printf("Choose operation: ");
                scanf("%d", &operation);

                if (num1 > 0)
                {
                    if (operation == 1)
                    {
                        result = log10(num1);
                        snprintf(buffer, sizeof(buffer), "log10(%.2lf) = %.2lf\n", num1, result);
                    }
                else if (operation == 2)
                    {
                        result = log(num1);
                        snprintf(buffer, sizeof(buffer), "ln(%.2lf) = %.2lf\n", num1, result);
                    }
                }
                else
                {
                    snprintf(buffer, sizeof(buffer), "Error: Logarithms undefined for non-positive numbers.\n");
                }
                writeToFile(filename, buffer);
                printf("%s", buffer);
                break;

            case 4:
                printf("1. e^x (Exponential)\n2. x^y (Power)\n");
                printf("Choose operation: ");
                scanf("%d", &operation);

                if (operation == 1)
                {
                    printf("Enter the value of x: ");
                    scanf("%lf", &num1);
                    result = exp(num1);
                    snprintf(buffer, sizeof(buffer), "e^%.2lf = %.2lf\n", num1, result);
                }
                else if (operation == 2)
                {
                    printf("Enter the base (x) and exponent (y): ");
                    scanf("%lf %lf", &num1, &num2);
                    result = pow(num1, num2);
                    snprintf(buffer, sizeof(buffer), "%.2lf^%.2lf = %.2lf\n", num1, num2, result);
                }
                writeToFile(filename, buffer);
                printf("%s", buffer);
                break;

            case 5:
                printf("Exiting calculations. Goodbye!\n");
                return;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

// Function to write results to a file
void writeToFile(char *filename, const char *content)
{
    FILE *file = fopen(filename, "a");
    if (file == NULL)
    {
        printf("Error opening file: %s\n", filename);
        return;
    }
    fprintf(file, "%s", content);
    fclose(file);
}
