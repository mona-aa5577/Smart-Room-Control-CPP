#include <iostream>
#include <string>

using namespace std;

class SmartLight {
private:
    bool isOn;
    int brightness; // من 0 إلى 100

public:
    SmartLight() : isOn(false), brightness(0) {}

    void sensorTrigger(int lightLevel) {
        // إذا كانت الإضاءة المحيطة ضعيفة (أقل من 30)، يعمل النظام تلقائياً
        if (lightLevel < 30) {
            isOn = true;
            brightness = 100;
            cout << "Sensor Action: Ambient light is low. Turning ON lights." << endl;
        } else {
            isOn = false;
            brightness = 0;
            cout << "Sensor Action: Ambient light is sufficient. Turning OFF lights." << endl;
        }
    }

    void displayStatus() {
        cout << "--- Room Light Status ---" << endl;
        cout << "Power: " << (isOn ? "ON" : "OFF") << endl;
        cout << "Brightness Level: " << brightness << "%" << endl;
        cout << "-------------------------" << endl;
    }
};

int main() {
    SmartLight myRoom;

    cout << "Smart Home System Simulation (C++)" << endl;
    
    // محاكاة دخول الليل (إضاءة منخفضة 15%)
    cout << "\nSimulating Night Time:" << endl;
    myRoom.sensorTrigger(15);
    myRoom.displayStatus();

    // محاكاة وقت النهار (إضاءة عالية 80%)
    cout << "\nSimulating Day Time:" << endl;
    myRoom.sensorTrigger(80);
    myRoom.displayStatus();

    return 0;
}
