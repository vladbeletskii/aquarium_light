# Simple Aquarium Light  

This project is a **smart lighting controller for aquariums**, designed to gradually adjust LED brightness to protect plants from sudden light changes.  

📌 **Features:**  
- Smooth brightness transitions to prevent plant damage  
- **Automatic day/night cycle** with customizable time intervals  
- **Manual brightness control** for different LED strips  
- **OLED display + encoder** for easy adjustments  
- **DS3231 real-time clock** to keep settings even after power loss  
- **PWM control for LED strips** via transistor modules  
- Settings are **stored in non-volatile memory**  

---

## 🛠 Hardware Requirements  
To build this project, you will need:  

- Arduino Nano (ATmega328P)  
- **128x32 OLED I2C Display**  
- **DS3231 Real-Time Clock (RTC)**  
- **Rotary encoder** with push-button function  
- **Transistor modules** for PWM control  
- **LED strips** (customizable color & length)  
- Power supply  
- Wires and connectors  

---

## 🔧 How It Works  

### **1️⃣ Startup & Display**  
- On power-up, a loading screen appears.  
- After loading, the main screen displays the current settings for each LED strip.  
- The display shows the active mode:  
  - 🌅 **Transition mode** (gradual brightness change)  
  - 🌙 **Static mode** (constant brightness)  

### **2️⃣ Automatic Lighting Control**  
- The system operates on two customizable time intervals:  
  - **t1 → t2** (lights on, gradually increasing brightness)  
  - **t2 → t1** (lights off, gradual dimming)  
- Brightness transition happens smoothly over **30 minutes** to avoid plant stress.  

### **3️⃣ Manual Control & Settings**  
- **Menu 1 (Short press encoder)**  
  - Adjust current time  
  - Set start and end times for lighting  

- **Menu 2 (Long press encoder)**  
  - Adjust brightness for each LED strip  
  - Switch between LED strips (single press)  
  - Set brightness for specific time intervals (double press)  

🚀 **Bonus Features:**  
- Adjusting brightness will temporarily light up the selected LED strip for visual confirmation.  
- Timekeeping remains accurate even after power loss, thanks to the **DS3231 RTC module**.  
- Settings are **automatically saved** in non-volatile memory (EEPROM).  

---

## ⚠️ Important Notes  
- **Smooth Brightness Adjustment:** The LED brightness gradually increases from **0% to the set value** after power restoration, preventing plant stress.  
- **EEPROM Write Optimization:** Changes are saved **after 5 seconds of inactivity** to prolong memory lifespan.  

---

## 📚 Libraries Used  
This project utilizes libraries from **AlexGyver** projects.  

---

### 📥 Download & Build  
💾 **Code & Schematics:** Available in this repository.  
📎 **STL Files for 3D-printed parts:** [Thingiverse Link]  

---

Let me know if you'd like any further improvements! 🚀  
