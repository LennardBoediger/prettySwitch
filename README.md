


---

# **prettySwitch**

<img src="https://github.com/user-attachments/assets/11438c50-b7ff-47f2-a863-70cc9c6f4ea0" height="350" alt="Remote">
<img src="https://github.com/user-attachments/assets/99e02daa-2c17-4be3-a1df-59b1a44898a1" height="350" alt="HomeKit">



### An elegant "smart" light switch system
Welcome to **prettySwitch**! This project is my personal take on creating a usable "smart" light system. The goal is to create a system where you can control all the lights in your home from one or two permanently mounted, stylish remotes.

### **Key Features**

* **Permanently Mounted Remotes:** prettySwitch is designed around the idea of beautiful, permanent wall-mounted remotes that give you complete control over your lighting.
* **Clap-to-Turn-Off Functionality:** The 80's already got it right so prettySwitch also has a "clap-to-off" feature. Just a simple clap of your hands, and your entire flat goes dark.
* **iOS HomeKit Integration:** As a bonus, I've integrated iOS HomeKit support. This allows you to control your lights using your iPhone, iPad, or even Siri, adding a layer of convenience while I wait for all the hardware components to arrive.


### **HomeKit Integration & Power Efficiency**

I've integrated iOS HomeKit support as a bonus, which allows you to control your lights using your iPhone, iPad, or Siri. While this was super easy to implement using the Arduino library HomeSpan, this library isn't designed with power-saving functionality in mind. For a more power-efficient solution, the official Espressif Matter SDK would be the correct approach. However, since my primary goal is to avoid having to use my phone to control my lights, I likely won't do this. For a simple, power-efficient integration without HomeKit functionality, check out my Espressif SDK based implementation here: TODO add Link

---

### **Getting Started**
```console
git clone --recurse-submodules git@github.com:LennardBoediger/prettySwitch.git
```



