#define _CRT_SECURE_NO_WARNINGS

#include "FileHandler.h"
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <ctime>

// Constructor
FileHandler::FileHandler() : filename(""), data("") {}

// Destructor
FileHandler::~FileHandler() {}

// Generates a file name based on the computer ID
std::string FileHandler::generateFileName(int computerID) {
    std::ostringstream oss;
    oss << "Computer_" << computerID << ".txt";
    return oss.str();
}

// Utility function to get the current timestamp
std::string FileHandler::getCurrentTimestamp() {
    time_t now = time(nullptr);
    char buffer[100];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", localtime(&now));
    return std::string(buffer);
}

// Setters
void FileHandler::setFilename(const std::string& filename) {
    this->filename = filename;
}

void FileHandler::setData(const std::string& data) {
    this->data = data;
}

// Getters
std::string FileHandler::getFilename() const {
    return filename;
}

std::string FileHandler::getData() const {
    return data;
}

// Reads data from the file
void FileHandler::readFile() {
    if (filename.empty()) {
        throw std::runtime_error("Filename is not set.");
    }

    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Could not open file: " + filename);
    }

    std::ostringstream buffer;
    buffer << file.rdbuf();
    data = buffer.str();
    file.close();
}

// Writes data to the file
void FileHandler::writeFile() {
    if (filename.empty()) {
        throw std::runtime_error("Filename is not set.");
    }

    std::ofstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Could not open file for writing: " + filename);
    }

    file << data;
    file.close();
}

// Loads data for a specific computer
std::string FileHandler::loadFileData(int computerID) {
    filename = generateFileName(computerID);
    readFile();
    return data;
}

// Saves data for a specific computer
void FileHandler::saveFileData(int computerID, const std::string& data) {
    filename = generateFileName(computerID);
    setData(data);
    writeFile();
}

// Passes data to HMI/SCADA (placeholder function)
void FileHandler::passDataToHMI() {
    if (data.empty()) {
        std::cerr << "No data to pass to HMI/SCADA." << std::endl;
    }
    else {
        std::cout << "Data passed to HMI/SCADA: " << data << std::endl;
    }
}
