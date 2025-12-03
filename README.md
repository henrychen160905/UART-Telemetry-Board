# UART BoilerMark for SoCET Intro 1 

## Scoring Module
Scoring Eq: .35f + .30d + .20m + .15t  
f = CPU clock freq. (MHz)  
d = disk read/write spd. (Mb/s)  
m = Memory usg. (bytes or multiples of)  
t = temp. (C)  

## Transmitter Module
UART based transmitter
Reads in bytes (FIFO) and times bits from the system clock

## Reciever Module
