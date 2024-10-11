#pragma once


#include <iostream>
#include <vector>
#include <string>
#include <map>

//1. SystemMonitor
//cpp
//Copy code
/**
 * Class Name: SystemMonitor
 * Input Variables:
 *   - pcList: vector<string> - List of PC identifiers.
 * Output Variables:
 *   - monitoringData: map<string, MonitoringData> - Stores monitoring metrics for each PC.
 * Purpose: To manage and aggregate the monitoring of multiple PCs on the network.
 */
class SystemMonitor {
public:
    SystemMonitor(const std::vector<std::string>& pcList);
    void updateMonitoringData();  // Updates data for each PC every 5 seconds
    const std::map<std::string, MonitoringData>& getMonitoringData() const; // Retrieves the latest monitoring data

private:
    std::vector<std::string> pcList;
    std::map<std::string, MonitoringData> monitoringData;  // Holds the monitoring data for each PC
};
//2. MonitoringData
//cpp
//Copy code
/**
 * Class Name: MonitoringData
 * Input Variables:
 *   - None
 * Output Variables:
 *   - cpuUsage: float - Percentage of CPU usage.
 *   - memoryUsage: float - Percentage of memory usage.
 *   - diskUsage: float - Percentage of disk usage.
 *   - networkActivity: float - Network activity in Mbps.
 *   - cpuTemperature: float - Temperature of the CPU in Celsius.
 *   - powerConsumption: PowerConsumptionData - Data related to power consumption of the components.
 *   - runningSoftware: vector<string> - List of software currently running on the PC.
 * Purpose: To encapsulate the various monitoring parameters for a single PC.
 */
class MonitoringData {
public:
    float cpuUsage;
    float memoryUsage;
    float diskUsage;
    float networkActivity;
    float cpuTemperature;
    PowerConsumptionData powerConsumption;
    std::vector<std::string> runningSoftware;

    void generateAlerts();  // Check thresholds and generate alerts if necessary
};
//3. PowerConsumptionData
//cpp
//Copy code
/**
 * Class Name: PowerConsumptionData
 * Input Variables:
 *   - None
 * Output Variables:
 *   - gpuPower: float - Power consumption of the GPU.
 *   - cpuPower: float - Power consumption of the CPU.
 *   - ramPower: float - Power consumption of the RAM.
 * Purpose: To store the power consumption details of specific hardware components within a PC.
 */
class PowerConsumptionData {
public:
    float gpuPower;
    float cpuPower;
    float ramPower;
};
//4. ControlManager
//cpp
//Copy code
/**
 * Class Name: ControlManager
 * Input Variables:
 *   - pcList: vector<string> - List of PC identifiers.
 * Output Variables:
 *   - None
 * Purpose: To manage the control operations such as toggling microphone, camera, adjusting brightness, etc.
 */
class ControlManager {
public:
    ControlManager(const std::vector<std::string>& pcList);

    void toggleMicrophone(const std::string& pcId, bool state);  // Turn on/off the microphone
    void toggleCamera(const std::string& pcId, bool state);  // Turn on/off the camera
    void adjustBrightness(const std::string& pcId, int level);  // Adjust the brightness (0-100)
    void muteSpeakers(const std::string& pcId, bool mute);  // Mute/unmute the speakers
    void restartPC(const std::string& pcId);  // Restart the PC
    void shutdownPC(const std::string& pcId);  // Shutdown the PC
    void controlFanSpeed(const std::string& pcId, int speed);  // Control fan speed (0-10)
    void toggleWiFi(const std::string& pcId, bool state);  // Turn on/off the Wi-Fi
};
//5. HMIInterface
//cpp
//Copy code
/**
 * Class Name: HMIInterface
 * Input Variables:
 *   - None
 * Output Variables:
 *   - None
 * Purpose: To provide the Human-Machine Interface (HMI) for interaction with the monitoring and control system.
 */
class HMIInterface {
public:
    void displayMonitoringData(const MonitoringData& data);  // Display monitoring data on the HMI
    void showControlOptions();  // Display control options for the user
    void notifyAlert(const std::string& alertMessage);  // Notify the user of any alerts (CPU temp, etc.)
};
//6. Logger
//cpp
//Copy code
/**
 * Class Name: Logger
 * Input Variables:
 *   - None
 * Output Variables:
 *   - None
 * Purpose: To log monitoring data and control actions for audit and troubleshooting purposes.
 */
class Logger {
public:
    void logMonitoringData(const std::string& pcId, const MonitoringData& data);  // Log monitoring data for a PC
    void logControlAction(const std::string& pcId, const std::string& action);  // Log a control action performed
};