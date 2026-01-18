import serial
import time
import threading


arduino_port = 'COM6' 
baud_rate = 9600

# ---------- FUNCTION: READ FROM ARDUINO ----------
def read_arduino():
    while True:
        if ser.in_waiting > 0:
            msg = ser.readline().decode('utf-8').strip()

            if msg == 'R':
                ser.write(b'1')
                print("Button 1 → Red LED toggled")

            elif msg == 'G':
                ser.write(b'2')
                print("Button 2 → Green LED toggled")

            elif msg == 'B':
                ser.write(b'3')
                print("Button 3 → Blue LED toggled")
        time.sleep(0.01)  

# ---------- MAIN PROGRAM ----------
try:
    ser = serial.Serial(arduino_port, baud_rate, timeout=0.1)
    time.sleep(2) 

    print(f"Connected to {arduino_port}")
    print("Press the buttons or type 1, 2, 3 to toggle LEDs\n")

 
    threading.Thread(target=read_arduino, daemon=True).start()

   
    while True:
        user_input = input("Enter command (1/2/3): ").strip()
        if user_input in ('1', '2', '3'):
            ser.write(user_input.encode('ascii'))
            print(f"Sent '{user_input}'")
        else:
            print("Invalid input. Please enter 1, 2, or 3.")

except serial.SerialException:
    print("Could not open serial port. Check COM port.")
finally:
    if 'ser' in locals() and ser.is_open:
        ser.close()
