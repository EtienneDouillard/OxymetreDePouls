# OxymetreDePouls

This app is a school project. All the initial instructions from the school are in french and are located in the "Documentation" folder.

## Goal of the project
This project involves producing a medical equipment called a "pulse oximeter", which measures an individual's heart rate and blood oxygen saturation (SpO2) using a generally non-invasive photoelectric sensor at the end of the patient's finger. The IT part of this project consists in developing a module allowing to calculate and display the heart rate and the Sp02 frequency from the red light and infrared absorption measurements provided by an electronic module.

The absorption measurements provided for the previous module are as follows:

AC R: peak-to-peak variation of the measured red light (pulsed wave)

DC R: average value of the measured red light (fabric)

AC IR: peak-to-peak variation of the infrared light measured (pulsed wave)

DC IR: average value of the infrared light measured (tissue)

These 4 measurements are transmitted every 2 ms by USB link to the computer module. The IT module must do the following:

Reading of signals AC R, DC R, AC IR and DC IR from a USB device
Digital filtering of signals
Sp02 and heart rate measurement
Display of measurements via a JAVA interface


## Information

This is a one week project of a french engineering school (ISEN Nantes) 
