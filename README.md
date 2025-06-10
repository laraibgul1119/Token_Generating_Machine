# Token Generating Machine 🎟️

## Project Description 📝

The Token Generating Machine is a C++ application designed to simulate a token-based queuing system, perfect for service-oriented environments like banks 🏦, hospitals 🏥, or customer service centers 📞. It generates unique tokens for customers, tracks active tokens, and manages the servicing process with flair! The project showcases object-oriented programming principles, including encapsulation, static members, and a custom String class for seamless string manipulation.

## Features ✨
### Token Generation 🎫: 
Creates unique token IDs with details about the number of people ahead in the queue and estimated waiting time ⏳.



### Queue Management 📋: 
Tracks active tokens and limits the number to a predefined maximum (_MAX_LIVE_TOKENS).



### Service Tracking ✅:
Keeps count of serviced persons and updates the queue as customers are serviced.



### Custom String Class 🖌️:
A robust String class with functionalities like concatenation, trimming, case conversion, substring search, and numeric conversions.



### Error Handling 🚨: 
Manages edge cases, such as exceeding the maximum token limit.

# Files 📂





### Source.cpp:
The main driver file that demonstrates the TokenMachine class in action 🚀.



### TokenMachine.h:
Header file defining the TokenMachine class interface.



### TokenMachine.cpp:
Implementation of token generation and queue management logic.



### String.h:
Header file for the custom String class, packed with string manipulation methods.



### String.cpp:
Implementation of the String class for all your string-handling needs 🧵.

# Prerequisites 🛠️





⚫- C++ compiler (e.g., g++, MSVC, or Clang) supporting C++11 or later.



⚫- Standard C++ library for input/output operations 📚.

# Installation ⚙️





### 1- Clone the repository:

git clone https://github.com/laraibgul1119/Token_Generating_Machine.git



### 2- Navigate to the project directory:

cd token-generating-machine



### 3- Compile the project using a C++ compiler:

g++ -o TokenMachine Source.cpp TokenMachine.cpp String.cpp



### 4- Run the executable:

./TokenMachine

#  Usage 🎮





1- Call TokenMachine::getNextToken() to generate a new token, which returns a String object with the token ID, people ahead in the queue, and estimated waiting time ⏰.



2- Use TokenMachine::personIsServiced() to mark a customer as serviced, reducing the active token count.



3- Check the total number of serviced customers with TokenMachine::getCountOfPersonsServiced().



4- Reset the machine with TokenMachine::resetMachine() to start fresh 🔄.



5- Default settings: _MAX_LIVE_TOKENS = 5 and _AVERAGE_PROCESSING_TIME_IN_MINUTES = 3 ⏲️.

# Example Output 📺

Running Source.cpp produces output like:

Token Id: 1
Person before you in Line are: 0
Expected Waiting Time: 0 minutes

Token Id: 2
Person before you in Line are: 1
Expected Waiting Time: 3 minutes

...
We are sorry. There can't be more than 5 tokens in system for service. Please wait for some clients to get serviced 

Count of Persons Serviced: 3 

# Code Structure 🏗️





### String Class 🧵: 
A custom class with methods for string manipulation, including concatenate, makeUpper, makeLower, find, replace, trim, and numeric conversions (convertToInteger, convertToFloat).



### TokenMachine Class 🎰: 
A static class managing token generation and queue operations. Key methods:





### getNextToken():
Generates a new token if below the maximum limit.



### personIsServiced():
Decrements active token count when a customer is serviced.



### getActiveTokensCount():
Returns the current number of active tokens.



### getCountOfPersonsServiced():
Returns the total number of serviced customers.



### resetMachine():
Resets the token machine state.

# Limitations ⚠️





o- The maximum number of live tokens and average processing time are hardcoded in setMaxLiveTokens and setAverageProcessingTime. Update defaults in TokenMachine.h to customize.



o- The String class may exit on invalid indices. Ensure proper input validation in production environments.



o- Extensive dynamic memory allocation is used; manage memory carefully to avoid leaks 🧹.

# Contributing 🤝

We love contributions! To get started:





1- Fork the repository 🍴.



2- Create a new branch (git checkout -b feature-branch).



3- Make your changes and commit (git commit -m "Add feature").



4- Push to the branch (git push origin feature-branch).



5- Open a pull request 🚀.

Please follow the existing code style and include tests for your changes.

# License 📜

This project is licensed under the MIT License. See the LICENSE file for details.

# Contact 📧

Have questions or ideas? Open an issue on the GitHub repository or reach out to the maintainer at laraibgulzar1119@example.com. Let's make this project even better! 🌟
