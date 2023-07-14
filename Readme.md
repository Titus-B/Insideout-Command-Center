# Inside-Out Control Panel

<img src="https://github.com/Titus-B/Insideout/assets/58118976/8017f88d-bedc-4316-b44d-b08035c6b7b0" height="360">
<img src="https://github.com/Titus-B/Insideout/assets/58118976/ebb498fc-270b-42fa-8fff-f92c4a95e103" height="360">


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
<img src="https://github.com/Titus-B/Insideout/assets/58118976/82dde02f-b15b-4a70-9cb1-b07258a3f114" height="280">
<img src="https://github.com/Titus-B/Insideout/assets/58118976/f9f0d8d5-9d93-4818-8529-f78eb3617379" height="280">


# Wiring of Button Panels and Connectors:
**Each of the Button Panels have 7 connection points beneath them. Each color connects to itself.**  
  
    For example, the brain has a green, brown, yellow, white, blue, red, and black wire coming out of it. 
    On the table there is are the same color of wires. The wires connect to the wire of the same color. 

  **The Connector panels only have 2 wires, but they follow the same convention as the Button Panels.**

  (The connectors are all red)

<img src="https://github.com/Titus-B/Insideout/assets/58118976/c2775380-47e4-4521-960d-ee4e4a4e8b29" height="300">
<img src="https://github.com/Titus-B/Insideout/assets/58118976/47982619-09fc-491b-814f-5fc67a4bb8ba" height="300">

  
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
    
# Maintenance:
  To access the inside of any of the **panels**:
    
    1) There square headed screw on the bottom of the table that needs to taken out.
    
    2) The whole panel can be lifted straight up slowly.
    
    3) If possible leave the wires connected. (The wires only come apart at the red connectors, not on the buttons)
   
    4) Maintenance is most likely required for a) tightening the buttons, b) checking wire connections, or c) the simon 
    needs its batteries replaced
     
      a) There is a simple plastic nut on the bottom of the button that can be tightened to stop the buttons from moving

      b) Check to see if there is any lose hanging wire. If there is, the red wire goes into the top prong sticking out the side
      , the black wire goes into side with less plastic, and the colored wire goes out the bottom prong.

      c) Batteries should be taped inside otherwise it is 3 double A batteries.

    5) When done, Lower panel back in and make sure the panel doesn't sit on any wires.

    6) Put the square headed screw back in.

  To access the inside of the **Control Panel**:
    
    1) There square headed screw on the bottom of the table that needs to taken out.

    2) The whole panel can be lifted straight up slowly. (There are a lot of wire connections inside and pulling it to far 
    would make them break)

    3) The control panel should realistically be able to be held or placed on an object 2-4 inches above the table.

    4) This is the mostlikely place for something to have gone wrong due to the number of wires. 

      a)The stuff that is extraneous: The small speakers inside of the control panel and their wires, the transistor 
      and resistors, and one of the 12 volt power supply.

      b) Random Blinking LED (the two side panels)
      : These are connnected to the Arduino Uno (the smaller one) in the front of the control panel 
      (see Wiring of Button Panels and Connectors)


      c) Button Controlled LED (Central Panel)
      : These are individually connected to the Arduino Mega (the bigger one) in the back of the control panel. 
      (See Wiring inside of the Control Panel)
      
    5) When done, Lower panel back in and make sure the panel doesn't sit on any wires.

    6) Put the square headed screw back in.

  


    
