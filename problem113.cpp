// Problem 113: Ground Zero
#include <algorithm>
#include <iostream>
#include <cmath>
#include <sstream>
#include <tuple>
#include <vector>

struct Sensor {
    int x;
    int y;
    double T;
    double distance{};
    double speed{};
};

// parse case data and load vector with Sensor data
void parseline(const std::string& in, std::vector<Sensor>& vec) {
    std::istringstream data{ in };
    std::string substr{};
    getline(data, substr, ';');
    int sensors { std::stoi(substr) };
    for (int i{ 0 }; i < sensors; ++i) {
        int x, y;
        double time;
        getline(data, substr, ';');
        std::istringstream sensorData{ substr };
        sensorData >> x >> y >> time;
        vec.push_back(Sensor{ x, y, time });
    }
}

int main() {
    const int maxX_Y = 10000;

    // get number of testcases     
    int testcases{};
    std::cin >> testcases;
    // throw away trailing newline
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::vector<std::string> cases;
    std::vector<Sensor> sensors;
    
    // get all case data and store in string vector
    for (int i{ 0 }; i < testcases; ++i) {
        std::string line{};
        getline(std::cin, line);
        cases.push_back(line);
    }

    // process each case data set
    std::ostringstream out{};
    for (auto c: cases) { 
        parseline(c, sensors);

        for (int x = 0; x < maxX_Y; ++x) {
            for (int y = 0; y < maxX_Y; ++y) {
                // calculate distance to candidate position for each sensor
                for (auto& sensor: sensors)
                    sensor.distance = std::sqrt((sensor.x - x)*(sensor.x - x) + (sensor.y - y)*(sensor.y - y));
                
                double T = ((sensors[1].distance*sensors[0].T) - (sensors[0].distance*sensors[1].T)) / (sensors[1].distance - sensors[0].distance);
                // calculate speeds from candidate position for each sensor
                for (auto& sensor: sensors)
                    sensor.speed = sensor.distance / (sensor.T - T);
                // check speeds for all matches
                bool speedMatch{ true };
                //int speedMatches{ 0 };
                for (size_t i{ 1 }; i < sensors.size(); ++i) {
                    speedMatch = std::abs(sensors[i].speed - sensors[0].speed) < 0.001;
                    if (!speedMatch)
                        break;
                }
                if (speedMatch && T > 0.0 && T < sensors[0].T) {
                    out << x << ' ' << y << ' ' << T << ' ';
                    std::cout << '*' << std::endl;
                    // prevent further processing for this case
                    x = maxX_Y;
                    y = maxX_Y;
                }
            }
        }
        
        sensors.clear();
    }
    
    std::cout << '\n' << out.str() << '\n';
    return 0;
}