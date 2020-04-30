# SESSION 7 (30/04/2020)
## Author: Kasra Tabrizi

- Introduction to programming
- Introduction to Python
- Programming exercises

### Assignment 

- Write a program in Python using the sense HAT. Use Trinket to do so: [Trinket.io](https://trinket.io/mission-zero#).

#### Project: Change color of display according to the temperature

```
from sense_hat import SenseHat

sense = SenseHat()
temp = sense.get_temperature()

#Create RGB array 5 different colors
R = [255, 0, 0]  # Red
G = [0,255,0] #Green
B = [0, 0, 255]  # Blue
W = [255,255,255] # White
Y = [255,255,0] #Yellow

#Create an array of 64 elements which will represent the led matrix display
display = range(64)


if temp >= -40 and temp <= -10:
  for pixel in range(len(display)):
    display[pixel] = W
if temp > -10 and temp <= 10:
  for pixel in range(len(display)):
    display[pixel] = B
if temp > 10 and temp <= 30:
  for pixel in range(len(display)):
    display[pixel] = G
if temp > 30 and temp <= 60:
  for pixel in range(len(display)):
    display[pixel] = R
if temp > 60:
  for pixel in range(len(display)):
    display[pixel] = Y
sense.set_pixels(display)
print("Temperature: %s C" % temp)

```


[Go Back](../README.md)