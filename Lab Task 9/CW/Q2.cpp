#include <iostream>
#include <vector>
#include <string>

using namespace std;

enum class LogSeverity {
    INFO,
    WARNING,
    ERROR
};

class Logger {
private:
    struct LogEntry {
        string message;
        LogSeverity severity;
        string module;
    };

    vector<LogEntry> logs;
    const size_t MAX_LOG_ENTRIES = 1000;
    string auditorPassword;

    void addLog(const string& message, LogSeverity severity, const string& module) {
        if (logs.size() >= MAX_LOG_ENTRIES) {
            logs.erase(logs.begin());
        }
        logs.push_back({message, severity, module});
    }

    static string severityToString(LogSeverity severity) {
        switch (severity) {
            case LogSeverity::INFO: return "INFO";
            case LogSeverity::WARNING: return "WARNING";
            case LogSeverity::ERROR: return "ERROR";
            default: return "UNKNOWN";
        }
    }

public:
    Logger(const string& password) : auditorPassword(password) {}

    void logInfo(const string& message, const string& module) {
        addLog(message, LogSeverity::INFO, module);
    }

    void logWarning(const string& message, const string& module) {
        addLog(message, LogSeverity::WARNING, module);
    }

    void logError(const string& message, const string& module) {
        addLog(message, LogSeverity::ERROR, module);
    }

    void log(const string& message, LogSeverity severity, const string& module) {
        addLog(message, severity, module);
    }

    const vector<string> getLogs(const string& password) const {
        if (password != auditorPassword) {
            return {"Access denied: Invalid password"};
        }

        vector<string> formattedLogs;
        for (const auto& entry : logs) {
            formattedLogs.push_back(
                "[" + entry.module + "] " +
                "[" + severityToString(entry.severity) + "] " +
                entry.message
            );
        }
        return formattedLogs;
    }

    class LogIterator {
        const vector<LogEntry>& logs;
        size_t index;
    public:
        LogIterator(const vector<LogEntry>& logEntries) : logs(logEntries), index(0) {}

        bool hasNext() const {
            return index < logs.size();
        }

        string next() {
            const auto& entry = logs[index++];
            return "[" + entry.module + "] [" + 
                   Logger::severityToString(entry.severity) + "] " + entry.message;
        }
    };

    LogIterator getIterator(const string& password) const {
        if (password != auditorPassword) {
            throw "Access denied: Invalid password";
        }
        return LogIterator(logs);
    }
};

int main() {
    Logger logger("secure123");

    logger.logInfo("System initialized", "System");
    logger.logWarning("Network latency detected", "Network");
    logger.logError("Database connection failed", "Database");
    logger.log("User login successful", LogSeverity::INFO, "Authentication");

    cout << "Unauthorized access attempt:\n";
    auto unauthorizedLogs = logger.getLogs("wrongpass");
    for (const auto& msg : unauthorizedLogs) {
        cout << msg << "\n";
    }

    cout << "\nAuthorized access:\n";
    auto auditLogs = logger.getLogs("secure123");
    for (const auto& msg : auditLogs) {
        cout << msg << "\n";
    }

    cout << "\nTesting log rotation (adding 1002 entries):\n";
    for (int i = 0; i < 1002; i++) {
        logger.logInfo("Test message " + to_string(i), "Test");
    }

    auto logsAfterRotation = logger.getLogs("secure123");
    cout << "Total logs after rotation: " << logsAfterRotation.size() << "\n";
    cout << "First log after rotation: " << logsAfterRotation.front() << "\n";
    cout << "Last log after rotation: " << logsAfterRotation.back() << "\n";

    return 0;
}