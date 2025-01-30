# Simple-Calculator
 C program that performs basic arithmetic operations (addition, subtraction, multiplication, division) and advanced mathematical functions (trigonometric, logarithmic, and exponential). Additionally, it stores all operations and results in a file, ensuring that data remains accessible even after the program is closed.
 
 Key Features:
 
1)Basic Arithmetic Operations:
Addition (+), Subtraction (-), Multiplication (*), and Division (/).

2)Advanced Mathematical Functions:
Trigonometric (sin, cos, tan).
Logarithmic and exponential calculations.

3)User Registration & Login:
The program prompts users to register or log in.User credentials are stored in a file for future access.

4)Persistent Data Storage:
Every operation performed by the user, along with inputs and results, is stored in a file.The filename is based on the username, allowing each user to have a separate record.

5)File Handling for Data Storage:
User data and history are stored in text files.When the user logs in, previous calculations can be displayed.

Working of the Project:

1)User Authentication:
New users register by entering a username and password.Existing users log in using stored credentials.

2)Calculator Operations:
The user selects an operation from the menu.Inputs are taken from the user.The result is calculated and displayed.

3)Data Storage:
The username is used as the filename (e.g., user123.txt).Each calculation (inputs, operations, results) is appended to the file.

4)Viewing History:
Users can choose to view past calculations, which are read from their respective files.

5)Technology & Concepts Used:

1)C Programming Language(looping and control statements,array,string)

2)File Handling (fopen, fclose, fprintf, fscanf)

3)String Handling (strcmp, strcpy)

4)User Authentication System

5)Mathematical Functions (math.h)

