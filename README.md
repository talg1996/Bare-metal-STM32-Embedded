
# Bare-metal-STM32-Embedded 

After use HAL library I started Bare metal code to increase my knowledge.


## Related

* GUI via Ethernet with Preact.js will come soon
* Digital filtering with FMAC will upload soon



## Lessons Learned
### GPIO 
1. How to set a pin as digital output and turn on/off LED2 using memory map
 (**No Header files**)

2. Same as 1 but use struct for offset memory. Use dummy array for more cleare code. struct contain only register i used.

3. Same as 1&2 but now i added the headers file "CMSIS".

4. Change the digital pin with BSRR for atomic operation unlike ODR.

5. Added a push BTN as input to control the LED state.

### USART
1. Send the ABC.. to my PC via the micro USB.
2. Add printf to send more than one char.
3. Make usart reusable by split files.
4. Add Rx to my usart.
* If user press '1' the LED will turn on. 
* If user press any but '1' LED will turn off
* On PC will be print the char that the user pressed.
### ADC
 Start with ADC single conversion driver development
 1.