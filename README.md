


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

### **Hardware: 433MHz Wireless Sockets**

This project uses inexpensive 433MHz wireless sockets. These are produced by many different companies and are widely available. My specific ones are from Pollin and Brennenstuhl.

[Funkschalt-Set RCS 1000 N Comfort](https://www.brennenstuhl.com/de-DE/produkte/funksteckdosen/funkschalt-set-rcs-1000-n-comfort-1-handsender-2-schaltempfaenger-1000w).

They are all very similar in their functionality and protocol. To ensure reliable operation, make sure to get the ones that use DIP switches and not the ones that are self-learning, as they lose their settings after a power outage.


### **Getting Started**
```console
git clone --recurse-submodules git@github.com:LennardBoediger/prettySwitch.git
```

---

### **Setting Up the DIP Switches**

To link your remote control to your wireless sockets, you need to configure the DIP switches on both devices. This is a crucial step to ensure they communicate on the same channel.

**1. Locate the DIP Switches:**
* **On the socket:** The switches are typically found in a small compartment, often on the side or back of the socket. You may need a small screwdriver to open the cover.

**2. Configure the System Code:**
The first five switches (usually labeled 1 through 5) define the "system code" or "group." This code determines which remote controls can talk to which sockets.
* Use a small object (like a tiny screwdriver or a ballpoint pen) to set the switches to either the ON (up) or OFF (down) position.
* Set the switches on **all** your remotes and **all** your sockets to the exact same combination. For example, you could choose a pattern like ON-OFF-OFF-ON-ON.
<img width="235" height="296" alt="Screenshot 2025-08-25 at 12 22 10 copy" src="https://github.com/user-attachments/assets/79602480-a044-4834-96bc-47cd321efd94" />

**3. Configure the Channel Code:**
The remaining switches (often labeled A, B, C, D, etc.) are used to assign a specific channel to a remote's button. For a single remote with four buttons (like the Brennenstuhl one), each button will correspond to a different channel setting on the socket.
* The remote's channel switches are often located next to the system code switches. You may have one for each button (e.g., A, B, C, D).
* The socket's channel switches are also located in its compartment. You'll need to set the channel on the socket to match the specific button you want to use on the remote. For example, if you set a socket's channel switch to 'A', it will only respond to the 'A' button on your remote.
<img width="235" height="74" alt="Screenshot 2025-08-25 at 12 22 10" src="https://github.com/user-attachments/assets/80d4258a-5f72-4df7-a3f8-410d26792de7" />

