# Inside-Out Control Panel
   **Created for LCBC Westshore At The Movies (ATM) 2023**

  **The Control Panel from the Disney and Pixar Film "Inside Out"**

# Terminology:
**Button Panels:**
  
    Leg:
      The L shaped panel that goes from the bottom to the top with the large buttons on the far left. 
    
    Pentagon:
      The pentagon shaped panel with triangular buttons in the curve of the L.
    
    Brain:
      The panel on the top right shaped like a brain.
    
    Heart:
      The panel between the brain and stomach shaped like a heart.
  
    Stomach:
      The panel on the bottom right shaped like a bowl.
    
**Non Button Panel:**
   
    Connector:
      The slightly curved panels between the Stomach, Brain, and Heart that glow blue.
   
    Simon:
      The panel with a simon inlaid right above the Pentagon.
   
    Levers:
      The panel with 5 black levers made of PVC. This is on the bottom of the table right of of the bottom of the L.
   
    Instructions:
      The panel with a yellow coloring with a "warning". This is right beside the Levers.
  
 **Control Panel:**
  
    This is the big box in the middle with the glass covering. Where all the indicator and blinking lights are.


# Wiring of Button Panels and Connectors:
**Each of the Button Panels have 7 connection points beneath them. Each color connects to itself.**  
  
    For example, the brain has a green, brown, yellow, white, blue, red, and black wire coming out of it. 
    On the table there is are the same color of wires. The wires connect to the wire of the same color. 

  **The Connector panels only have 2 wires, but they follow the same convention as the Button Panels.**

  (The connectors are all red)

  
# Wiring inside of the Control Panel:
**Where the wires from the Button Panels conect to Arduino Mega**

    Leg: 
       White   - 22
       Yellow  - 23
       Red     - 24
       Blue    - 25
       Green   - 26
    
    Pentagon:
       White   - 27
       Yellow  - 28
       Red     - 29
       Blue    - 30
       Green   - 31
    
    Brain:
       White   - 32
       Yellow  - 33
       Red     - 34
       Blue    - 35
       Green   - 36
      
    
    Heart:
       White   - 37
       Yellow  - 38
       Red     - 39
       Blue    - 40
       Green   - 41
      
  
    Stomach:
       White   - 42
       Yellow  - 43
       Red     - 44
       Blue    - 45
       Green   - 46

**Where the wires from the SD Card conect to Arduino Mega**

    CS   - 53
    SCK  - 52
    MOSI - 51
    MISO - 50
    VCC  - 5V supply (from Arduino)
    GND  - Gnd       (from Arduino)

**Where the wires from the Amp conect to Arduino Mega/Speaker**

    Input:
      GND - GND       (from Arduino)
      GND - Nothing
      IN  - 5
      VCC - 5V supply (from Arduino)

    Output:
      GND - GND       (of Speaker/Black Wire)
      OUT - Positive  (of Speaker/Red Wire)

**Where the wires from the Speaker conect to Amp**

    Red/+    : Red wire
    Black/-  : Black wire
  
# Code:
  To upload code to the arduino you can follow these instructions. 
  
https://support.arduino.cc/hc/en-us/articles/4733418441116-Upload-a-sketch-in-Arduino-IDE
  
  **The Arduino Mega has the Screen_and_Sound.Ino uploaded to it.**
 
  **The Arduino Uno has the LED_Random.ino uploaded to it.**
  
  
