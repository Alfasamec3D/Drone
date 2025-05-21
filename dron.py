import serial

bt_port = 'COM5'  # Replace with your Bluetooth COM port
baud_rate = 115200

try:
    ser = serial.Serial(bt_port, baud_rate, timeout=1)
    print(f"Connected to {bt_port}. Type commands and press Enter to send. Type 'exit' to quit.")

    while True:
        command = input("Enter command: ")
        if command.lower() == 'exit':
            break
        ser.write((command + '\n').encode())
        print(f"Sent: {command}")

except serial.SerialException as e:
    print(f"Serial port error: {e}")

except KeyboardInterrupt:
    print("\nUser interrupted")

finally:
    if 'ser' in locals() and ser.is_open:
        ser.close()
        print("Serial port closed")
