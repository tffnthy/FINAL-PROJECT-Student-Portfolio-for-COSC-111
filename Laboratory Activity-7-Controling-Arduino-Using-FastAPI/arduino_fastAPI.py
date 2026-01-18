from fastapi import FastAPI
import serial
import time

# -------------------------------
# Arduino Serial Setup
# -------------------------------
SERIAL_PORT = "COM3"  # change if needed
BAUD_RATE = 9600

arduino = serial.Serial(SERIAL_PORT, BAUD_RATE, timeout=1)
time.sleep(2)  # allow Arduino reset

# -------------------------------
# FastAPI Setup
# -------------------------------
app = FastAPI(title="Arduino LED Controller API")

# -------------------------------
# Helper Function
# -------------------------------
def send_to_arduino(cmd: str):
    """
    Send a single-character command + newline to Arduino
    """
    arduino.write(f"{cmd}\n".encode())
    arduino.flush()
    return {"command_sent": cmd}

# -------------------------------
# API Endpoints
# -------------------------------

# Turn all LEDs ON
@app.get("/led/on")
def led_all_on():
    responses = []
    for cmd in ["R", "G", "B"]:
        responses.append(send_to_arduino(cmd))
    return {"status": "all LEDs ON", "details": responses}

# Turn all LEDs OFF
@app.get("/led/off")
def led_all_off():
    responses = []
    for cmd in ["r", "g", "b"]:
        responses.append(send_to_arduino(cmd))
    return {"status": "all LEDs OFF", "details": responses}

# Toggle individual LED
@app.get("/led/{color}")
def led_color(color: str):
    color = color.lower()
    if color == "red":
        cmd = "1"
    elif color == "green":
        cmd = "2"
    elif color == "blue":
        cmd = "3"
    else:
        return {"error": "Invalid color. Choose red, green, or blue."}

    response = send_to_arduino(cmd)
    return {"status": f"{color} LED toggled", "details": response}
