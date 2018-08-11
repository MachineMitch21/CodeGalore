
#ifndef LOGMANAGER_H
#define LOGMANAGER_H

#include <string>

class LogManager 
{
public:
    ~LogManager();

    static void LogToConsole(const std::string& logStr);
    static void LogToFile(const std::string& logStr, const std::string& file = "log_file.txt");

protected:
    LogManager();

    static char* GetAsciiTime();
};

#endif // LOGMANAGER_H
