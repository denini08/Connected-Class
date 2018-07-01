import RPi.GPIO as gpio

#class Sala:
lamp1 = 3
lamp2 = 5
lamp3 = 11
porta_ar = 38

def init():




    gpio.setmode(gpio.BOARD)
    print ("aqui")
    gpio.setup(lamp1, gpio.OUT)
    gpio.setup(lamp2, gpio.OUT)
    gpio.setup(lamp3, gpio.OUT)
    gpio.setup(porta_ar, gpio.OUT)



def alterarLampada(porta_lampada, boll):
    if boll == True:
                gpio.output(porta_lampada, gpio.HIGH)	##ACHO q da para colocar True no lugar de gpio.HIGH 
    else: 
                gpio.output(porta_lampada, gpio.LOW)


def ligarTodasLampadas():
    gpio.output(lamp1, gpio.HIGH)
    gpio.output(lamp2, gpio.HIGH)
    gpio.output(lamp3, gpio.HIGH)
