class TransactionLog{
public:
    TransactionLog(const std::string& name, const int time, const int amount, const std::string& city) : mName(name), mCity(city), mAmount(amount), mTime(time) {}

    std::string getName() const { return mName; }
    std::string getCity() const { return mCity; }
    int getAmount() const { return mAmount; }
    int getTime() const { return mTime; }

    std::string getStringLog() const { return mName + "," + std::to_string(mTime) + "," + std::to_string(mAmount) + "," + mCity; }
private:
    std::string mName, mCity;
    int mAmount, mTime;
};

class Solution {
public:
    
    TransactionLog getTransaction(const std::string& log){
        int start = 0;
        int delimiterPos = log.find(',', start);
        std::string name = log.substr(0, delimiterPos - start);
        
        start = delimiterPos + 1;
        delimiterPos = log.find(',', start);
        std::string time = log.substr(start, delimiterPos - start);

        start = delimiterPos + 1;
        delimiterPos = log.find(',', start);
        std::string amount = log.substr(start, delimiterPos - start);
        
        start = delimiterPos + 1;
        std::string city = log.substr(start, log.size() - start);

        return TransactionLog(name, std::stoi(time), std::stoi(amount), city);
    }


    vector<string> invalidTransactions(vector<string>& transactions) {
        std::vector<TransactionLog> allTransactions;

        for(const auto& log: transactions){
            allTransactions.push_back(getTransaction(log));
        }

        std::vector<std::string> invalidLogs;
        for(auto& log: allTransactions){
            // Transactions with amount > 1000 are invalid
            if(log.getAmount() > 1000){
                invalidLogs.push_back(log.getStringLog());
            }
            else{
                auto iter = std::find_if(allTransactions.begin(), allTransactions.end(), [&log](const TransactionLog& otherLog){ return abs(log.getTime() - otherLog.getTime()) <= 60 && log.getCity() != otherLog.getCity() && log.getName() == otherLog.getName();});
                // i.e. we have a transaction in another city within 60 mins.
                if(iter != allTransactions.end()){
                    invalidLogs.push_back(log.getStringLog());
                }
            }
        }

        return invalidLogs;
    }
};