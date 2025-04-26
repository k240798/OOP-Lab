#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdio>

class Logger {
private:
    std::string logFile;
    size_t maxLogSize;

    bool fileTooLarge() {
        std::ifstream file(logFile, std::ios::binary | std::ios::ate);
        return file.tellg() >= maxLogSize;
    }

    void rotateLogs() {
        int logVersion = 1;
        while (std::ifstream(logFile + std::to_string(logVersion) + ".txt")) {
            logVersion++;
        }
        std::rename(logFile.c_str(), (logFile + std::to_string(logVersion) + ".txt").c_str());
    }

public:
    Logger(std::string file, size_t maxSize = 1048576) : logFile(file), maxLogSize(maxSize) {}

    void logMessage(const std::string& message) {
        if (fileTooLarge()) {
            rotateLogs();
        }

        std::ofstream log(logFile, std::ios::app);
        if (log.is_open()) {
            std::time_t currentTime = std::time(nullptr);
            char timestamp[100];
            std::strftime(timestamp, sizeof(timestamp), "[%Y-%m-%d %H:%M:%S]", std::localtime(&currentTime));
            
            log << timestamp << " " << message << std::endl;
            log.close();
        } else {
            std::cerr << "Failed to open log file!" << std::endl;
        }
    }
};

int main() {
    Logger logger("log.txt");
    logger.logMessage("This is a test log message.");
    logger.logMessage("Another log message.");
    for (int i = 0; i < 1000; ++i) {
        logger.logMessage("Log message number: " + std::to_string(i));
    }

    return 0;
}
