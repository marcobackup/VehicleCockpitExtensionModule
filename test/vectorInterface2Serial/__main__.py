import serial
import can

"""
    VECTOR INTERFACE TO SERIAL PORT
    reading CAN data via vector interface
    and forward them to serial port

    B-CAN - low speed - 50kbit/s
"""

BITRATE = 50000

serial_port = \
    serial.Serial(
        port='COM2', 
        baudrate=115200, 
        bytesize=8
    )

if serial_port.is_open:
    bus = \
        can.Bus(**can.detect_available_configs(['vector'])[0], bitrate=BITRATE)
    with bus as b:
        try:
            while True:
                message = b.recv()
                data = ''
                for _, __ in enumerate(message.data):
                    data += hex(__)
                    if _ < len(message.data) - 1:
                        data += ','
                data_serialized = f'{message.arbitration_id}#0{message.dlc}#{data}\n'.encode()
                serial_port.write(data_serialized)
        except KeyboardInterrupt:
            pass

    # close serial port
    serial_port.close()
    