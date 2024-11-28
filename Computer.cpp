#include "Computer.h"

// Component class implementation
Component::Component(ComponentType type, int cpuUsage, int ramUsage)
    : type(type), cpuUsage(cpuUsage), ramUsage(ramUsage), poweredOn(false) {}

void Component::PowerOn() {
    poweredOn = true;
}

void Component::PowerOff() {
    poweredOn = false;
}

bool Component::IsPoweredOn() const {
    return poweredOn;
}

int Component::GetCpuUsage() const {
    return cpuUsage;
}

int Component::GetRamUsage() const {
    return ramUsage;
}

// Computer class implementation
Computer::Computer(const std::string &ipAddress, const std::string &name, int totalRam)
	: ipAddress(ipAddress), name(name), totalRam(totalRam), poweredOn(false), connected(false),  cpuUsage(0) , ramUsage(0){}

void Computer::Connect() {
    connected = true;
}

void Computer::Disconnect() {
    connected = false;
}

void Computer::PowerOn() {
    poweredOn = true;
}

void Computer::PowerOff() {
    poweredOn = false;
}

bool Computer::IsPoweredOn() const {
    return poweredOn;
}



void Computer::AddComponent(const Component& component) {
    components.push_back(component);
    CalculateUsage();
}

std::string Computer::GetStatusReport() const {
    // Generate status report including IP address, power state, CPU usage, RAM usage, and brightness
    std::string report = "IP Address: " + ipAddress + "\n";
    report += "Power State: " + std::string(IsPoweredOn() ? "ON" : "OFF") + "\n";
    report += "CPU Usage: " + std::to_string(cpuUsage) + "%\n";
    report += "RAM Usage: " + std::to_string(ramUsage) + "%\n";
//    report += "Brightness: " + std::to_string(brightness) + "%\n";
    return report;
}

void Computer::RandomlyFluctuateUsage() {
	double fluctuation = (std::rand() % 7 - 4); // Random value between -1 and 1


	if( cpuUsage < 90 && cpuUsage >= 0)
		cpuUsage += fluctuation;

	if( ramUsage < 90 && ramUsage >= 0)
		ramUsage += fluctuation;

    // Ensure that CPU usage is between 0% and 100%
	if (cpuUsage < 0) {
		cpuUsage = 0;
	} else if (cpuUsage > 100) {
		cpuUsage = 100;
	}

	// Ensure that RAM usage does not exceed total RAM or fall below 0
	if (ramUsage < 0) {
		ramUsage = 0;
	} else if (ramUsage > 100) {
		ramUsage = 100;
	}
}

void Computer::UpdateUsage() {
	CalculateUsage();
	RandomlyFluctuateUsage();

}

void Computer::CalculateUsage() {
	cpuUsage = 15;
	ramUsage = 25;
	for (const auto &comp : components) {
	if (comp.IsPoweredOn()) {
			cpuUsage += comp.GetCpuUsage();
            ramUsage += comp.GetRamUsage();
        }
    }

    // Ensure that the usage values do not exceed the total available resources
    if (cpuUsage > 100) {
		cpuUsage = 100;
    }
	if (ramUsage > 100) {
        ramUsage = 100;
    }
}

// Accessor methods
std::string Computer::GetIpAddress() const {
    return ipAddress;
}

std::string Computer::GetName() const {
    return name;
}

int Computer::GetTotalRam() const {
    return totalRam;
}

int Computer::GetCpuUsage() const {
    return cpuUsage;
}

int Computer::GetRamUsage() const {
    return ramUsage;
}

bool Computer::IsConnected() const {
    return connected;
}

