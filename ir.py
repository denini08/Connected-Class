import serial
ser = serial.Serial("/dev/ttyS0", 9600)

def enviarCode(entrada):
    
    if(entrada == "on"):
        ser.write("on\n")
    elif(entrada == "off"):
        ser.write("off\n")
    elif(entrada == "16"):
        ser.write("16\n")
    elif(entrada == "17"):
        ser.write("17\n")
    elif(entrada == "18"):
        ser.write("18\n")
    elif(entrada == "19"):
        ser.write("19\n")
    elif(entrada == "20"):
        ser.write("20\n")
    elif(entrada == "21"):
        ser.write("21\n")
    elif(entrada == "22"):
        ser.write("22\n")
    elif(entrada == "23"):
        ser.write("23\n")
    else:
    	print("----ERRO------ enviarCode()")
        
        