#ifndef ComputerH
#define ComputerH

#include <string>
#include <vector>

using namespace std;

class Component {
public:
    enum ComponentType { MICROPHONE, CAMERA, CPU, RAM };
    Component(ComponentType type, int cpuUsage, int ramUsage);
    void PowerOn();
    void PowerOff();
    bool IsPoweredOn() const;

	int GetCpuUsage() const;
    int GetRamUsage() const;

private:
    ComponentType type;
	bool poweredOn;
	int cpuUsage; // of single component
	int ramUsage; //
};

class Computer {
public:

	Computer(const string &ipAddress, const string &name, int totalRam);

	// Use Timer to update
	void UpdateUsage();

	// components
	void AddComponent(const Component& component);
	std::string GetStatusReport() const;

	// power
    void PowerOn();
    void PowerOff();
	bool IsPoweredOn() const;
	// network
	void Connect();
	void Disconnect();
	bool IsConnected() const;

	//
//	void AdjustBrightness(int level);
//    int GetBrightness() const;



    // Accessor methods
    string GetIpAddress() const;
    string GetName() const;
	int GetTotalRam() const;


    int GetCpuUsage() const;
	int GetRamUsage() const;



private:
	string ipAddress;  // IP address of the computer
	string name;       // Name of the computer
    int totalRam;           // Total RAM size (in MB)
//	int usedRam;            // Currently used RAM (in MB)

    // usage in %
	int cpuUsage;
	int ramUsage;

    bool poweredOn;         // Power state
    bool connected;         // Network connection state
//    int brightness;         // Screen brightness (percentage)
	std::vector<Component> components; // List of components

	void CalculateUsage();  // Calculate total CPU and RAM usage

    void RandomlyFluctuateUsage();
};

#endif

