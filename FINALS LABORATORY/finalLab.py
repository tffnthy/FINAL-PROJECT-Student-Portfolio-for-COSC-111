import serial
import requests
import time

SERIAL_PORT = 'COM6'
BAUD_RATE = 9600
BASE_URL = "http://172.20.10.3:8000"


def start_client():
    try:
        ser = serial.Serial(SERIAL_PORT, BAUD_RATE, timeout=1)
        print(f"--- Listening for Arduino on {SERIAL_PORT} ---")

        while True:
            if ser.in_waiting > 0:
                raw_data = ser.readline().decode('utf-8').strip()

                if raw_data:
                    if raw_data.isdigit():
                        GROUP_NUMBER = raw_data
                        endpoint = f"{BASE_URL}/led/group/{GROUP_NUMBER}/toggle"

                        print(f"\n[EVENT] Received group number: {GROUP_NUMBER}")
                        print(f"[ACTION] Calling: {endpoint}")

                        response = requests.get(endpoint)

                        if response.status_code == 200:
                            print(f"[SUCCESS] API Response: {response.text} OK")
                        else:
                            print(f"[ERROR] API Response: {response.status_code}")
                    else:
                        print(f"[VALIDATION ERROR] Invalid serial format: {raw_data}")

            time.sleep(0.1)

    except serial.SerialException:
        print("Error: Could not open serial port. Is the Arduino connected?")
    except KeyboardInterrupt:
        print("\nProgram terminated by user.")


if __name__ == "__main__":
    start_client()