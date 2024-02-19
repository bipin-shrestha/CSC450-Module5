/*
Name: 				Bipin Shrestha
Project Name: 		CSC450-CT1-Module5
Project Purpose: 	To create a interactive program that takes user input, store in a file, download the file,
					append new text to file without deleting it and create a new reversal file with all the reversed text in it.
Algorithm Used: 	Program has simple function to prompt the user to enter some text, open file "CSC450_CT5_mod5.txt" in append mode and
					write user input into the file and close it. After writing the input, call the 'reversalMethod' function. In
					'reversalMethod', read the content of "CSC450_CT5_mod5.txt", reverse each line and write the reversed line in a new file
					named "CSC450-CT5-mod5-reverse.txt" and close the file.
Program Inputs: 	Program takes the text as user input when prompted.
Program Outputs: 	Program appends the user input to file "CSC450_CT5_mod5txt" and also creas a new file named "CSC450-CT5-mod5-reverse.txt"
					and writes the reversed lines from "CSC450_CT5_mod5.txt" into it.
Program Limitations: Program appends user input to original file, but doesn't handle the case if the file doesn't exist initially.
Program Errors: 	If the file "CSC450_CT5_mod5.txt" cannot open, error message is displayed.

====================================
*/

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

void reversalMethod(){
	std::ifstream file;
	std::ofstream reversalFile;
	std::string line;

	// Open original file to read data
	file.open("CSC450_CT5_mod5.txt");
	// Create reversal file to store data from original file
	reversalFile.open("CSC450-CT5-mod5-reverse.txt", std::ios::app);
	while(std::getline (file, line)){
		std::string reversedLine = line;
		std::reverse(reversedLine.begin(), reversedLine.end());
		reversalFile << reversedLine << std::endl;
	}
	// Close reversal file
	reversalFile.close();
}

int main() {
    std::string userInput;
    // Prompt the user to enter some text
    std::cout << "Enter text: ";
    // Read user input
    std::getline(std::cin, userInput);
    std::ofstream file;

    // Open output file in append mode
    file.open("CSC450_CT5_mod5.txt", std::ios::app);

    // Check if file was opened successfully
    if(file.is_open()){
    	// Append user input data to the file
    	file << userInput<< std::endl;
    	// Close the file
    	file.close();
		// Display message data was appended
		std::cout << "Data Appended";
    }
    else{
    	// Display Error Message
    	std::cout << "Failed to open the file." << std::endl;
    }
    reversalMethod();
    return 0;
}




