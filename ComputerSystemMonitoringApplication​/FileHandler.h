#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <iostream>
#include <string>

class FileHandler {
private:
    std::string filename;
    std::string data;

    // Generates a file name based on the computer ID
    std::string generateFileName(int computerID);



public:

    // Utility function to get the current timestamp
    std::string getCurrentTimestamp();

    FileHandler();
    ~FileHandler();

    // Setters
    void setFilename(const std::string& filename);
    void setData(const std::string& data);

    // Getters
    std::string getFilename() const;
    std::string getData() const;

    // Reads data from the file
    void readFile();

    // Writes data to the file
    void writeFile();

    // Loads data for a specific computer
    std::string loadFileData(int computerID);

    // Saves data for a specific computer
    void saveFileData(int computerID, const std::string& data);

    // Passes data to HMI/SCADA (placeholder function)
    void passDataToHMI();
};

#endif // FILEHANDLER_H
