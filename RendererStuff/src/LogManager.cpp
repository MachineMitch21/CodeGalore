
#include "LogManager.h"

#include <stdio.h>
#include <string.h>
#include <time.h>

LogManager::LogManager()
{

}

LogManager::~LogManager()
{

}

void LogManager::LogToConsole(const std::string& logStr)
{
    printf("%s -- %s\n", GetAsciiTime(), logStr.c_str());
}

void LogManager::LogToFile(const std::string& file, const std::string& logStr)
{
    FILE* fp;
    fp = fopen(file.c_str(), "w+");

    const char* str = logStr.c_str();

    char* asctime = GetAsciiTime();

    fwrite(asctime, sizeof(char), strlen(asctime), fp);
    fwrite(str, sizeof(char), strlen(str), fp);
    
    char newline[] = { '\n' };
    fwrite(newline, sizeof(char), 1, fp);

    fclose(fp);
}

char* LogManager::GetAsciiTime()
{
    time_t rawtime;
    struct tm* timeinfo;

    time(&rawtime);
    timeinfo = localtime(&rawtime);

    return asctime(timeinfo);
}