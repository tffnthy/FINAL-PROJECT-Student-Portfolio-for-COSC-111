import serial
import os
import time

# arduino port
arduino = serial.Serial(port="COM4", baudrate=9600, timeout=1)
time.sleep(2)  # allow Arduino to reset

def clear():
    os.system("cls" if os.name == "nt" else "clear")


def print_menu():
    print("[R] Red ON/OFF")
    print("[G] Green ON/OFF")
    print("[B] Blue ON/OFF")
    print("[A] All ON")
    print("[O] All OFF")
    print("[X] Exit\n")

while True:
    clear()
    print_menu()
    choice = input("Enter choice: ").strip().lower()

    if choice == "x":
        arduino.write(choice.encode())
        time.sleep(0.1)
        response = arduino.readline().decode().strip()
        print("Exiting...")
        break

    if choice in ["r", "g", "b", "a", "o", "Enter"]:
        arduino.write(choice.encode())
        time.sleep(0.1)
        response = arduino.readline().decode().strip()
        print("Arduino:", response)
        while True:
            user = input("\nPress Enter to continue...")
            if user == "":
                break
            else:
                arduino.write(choice.encode())
                time.sleep(0.1)
                response = arduino.readline().decode().strip()
                print ("invalid input")


    else:
        arduino.write("o".encode())
        time.sleep(0.1)
        response = arduino.readline().decode().strip()
        print("Invalid input!")
        break
