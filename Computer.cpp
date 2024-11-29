#include "Computer.h"

// Component class implementation
Component::Component(string type, double cpuUsage, double ramUsage)
	: type(type), cpuUsage(cpuUsage), ramUsage(ramUsage), poweredOn(false) {}



void Component::SaveToFile(ofstream &out) const {
	out << type << " " << poweredOn << " " << cpuUsage << " " << ramUsage << "\n";
}

void Component::LoadFromFile(ifstream &in) {
	in >> type >> poweredOn >> cpuUsage >> ramUsage;
}

void Component::PowerOn() { poweredOn = true; }
void Component::PowerOff() { poweredOn = false; }
bool Component::IsPoweredOn() const { return poweredOn; }
double Component::GetCpuUsage() const { return cpuUsage; }
double Component::GetRamUsage() const { return ramUsage; }
string Component::GetType() const { return type; }



// Computer class implementation
Computer::Computer(const std::string &name, const std::string &ipAddress, int totalRam)
	: ipAddress(ipAddress), name(name), totalRam(totalRam),
	poweredOn(false), connected(false),  cpuUsage(5) , ramUsage(10){

//	this.AddComponent();
}


void Computer::SaveToFile(ofstream &out) const {
	out << ipAddress << "\n"
		<< name << "\n"
		<< totalRam << "\n"
        << cpuUsage << "\n"
		<< ramUsage << "\n"
        << poweredOn << "\n"
		<< connected << "\n"
		<< components.size() << "\n";

	for (const auto &component : components) {
		component.SaveToFile(out);
	}
}

void Computer::LoadFromFile(ifstream &in) {
	size_t componentsCount;
	in >> ws;  // Consume any whitespace
	getline(in, ipAddress);
	getline(in, name);
	in >> totalRam >> cpuUsage >> ramUsage >> poweredOn >> connected >> componentsCount;
	components.clear();
	for (size_t i = 0; i < componentsCount; ++i) {
        Component comp("", 0, 0);  // Placeholder component
		comp.LoadFromFile(in);
		components.push_back(comp);
    }
}



 void Computer::AddComponent(const Component &component) {

	components.push_back(component);

    CalculateUsage();
}

void Computer::PowerOn() { poweredOn = true; }
void Computer::PowerOff() { poweredOn = false; }
bool Computer::IsPoweredOn() const { return poweredOn; }
void Computer::Connect() { connected = true; }
void Computer::Disconnect() { connected = false; }
bool Computer::IsConnected() const { return connected; }
void Computer::SetName(const string &newName) { name = newName; }
string Computer::GetIpAddress() const { return ipAddress; }
string Computer::GetName() const { return name; }
int Computer::GetTotalRam() const { return totalRam; }
double Computer::GetCpuUsage() const { return cpuUsage; }
double Computer::GetRamUsage() const { return ramUsage; }

//
//
//std::string Computer::GetStatusReport() const {
//	// Generate status report including IP address, power state, CPU usage, RAM usage, and brightness
//	std::string report = "IP Address: " + ipAddress + "\n";
//	report += "Power State: " + std::string(IsPoweredOn() ? "ON" : "OFF") + "\n";
//	report += "CPU Usage: " + std::to_string(cpuUsage) + "%\n";
//	report += "RAM Usage: " + std::to_string(ramUsage) + "%\n";
////    report += "Brightness: " + std::to_string(brightness) + "%\n";
//	return report;
//}


void Component::RandomlyFluctuateUsage() {
	double fluctuation = (rand() % 5 - 2); // Random value between -2 and 2
	fluctuation +=  0.1 * (rand() % 21 - 10);


	if( cpuUsage < 20 && cpuUsage >= 0)
		cpuUsage += fluctuation;

	if( ramUsage < 20 && ramUsage >= 0)
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
//	RandomlyFluctuateUsage();

}


void Component::UpdateUsageComponent() {

	RandomlyFluctuateUsage();

}

void Computer::CalculateUsage() {
	cpuUsage = 6;
	ramUsage = 10;
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
