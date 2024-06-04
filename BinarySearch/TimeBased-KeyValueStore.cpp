#include <bits/stdc++.h>
class TimeMap {
public:
struct Time {
    std::string value;
    int timestamp;
};

    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        Time time;
        time.value = value;
        time.timestamp = timestamp;
        mTimeMap[key].push_back(time);
    }

    static bool isBiggerTimestamp(const Time& _t1, const Time& _t2) {
        return _t1.timestamp <= _t2.timestamp;
    }

    std::string binarySearchForValue(const std::vector<Time>& _times, const int& _timestamp) {
        int left = 0;
        int right = _times.size() - 1;
        std::string value = "";

        while(left <= right) {
            int mid = left + (right - left)/2;
            if (_times[mid].timestamp == _timestamp) {
                return _times[mid].value;
            } else if (_times[mid].timestamp < _timestamp) {
                left = mid + 1;
                value = _times[mid].value;
            } else if (_times[mid].timestamp > _timestamp) {
                right = mid - 1;
            }
        }
        return value;
    }
    
    string get(string key, int timestamp) {       
        return binarySearchForValue(mTimeMap[key], timestamp);
    }

private:
    std::unordered_map<std::string, std::vector<Time>> mTimeMap;
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */