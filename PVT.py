# PVT Calculator
# Program that lets user enter 2 of either pressure in pascals, temperature in kelvin or volume in m^3 and uses PV=RT to calculate the other variable
# Author: Chris Vanden

# Defining functions
# Function to check if a value is a float and positive
def checkValue(value):
    try:
        # tries to convert the value sent to the function to a flat
        value = float(value);
        if value >= 0:
            # checks if number is positive, returns value if it is
            return value;
        else:
            # gets here if number is less than 0, displays error and returns False
            print('Input must be positive')
            return False;
    except:
        # gets here if value cannot be converted to a float, displays error and returns False
        print('Input must be a number')
        return False;


# Defining variables
# Variable r used in final calculation
r = 8.315
# Variable YesNo used to decide if program loops
YesNo = 'yes'

# Start of program
# Loop that loops if user says they want to do another calculation at the end of the program
while YesNo.lower() == 'yes':
    # Asks user which variable they want to calculate
    choice = input('Do you want to calculate a [t]emperature, a [p]ressure or a [v]olume? ')
    while choice.lower() != 't' and choice.lower() != 'p' and choice.lower() != 'v':
        # Keeps looping and asking for an answer until input is either t, p or v
        print('Please enter either t, p or v as your choice of calculation')
        choice = input('Do you want to calculate a [t]emperature, a [p]ressure or a [v]olume? ')

    # If input is t program gets here
    if choice.lower() == 't':
        # Asks for a pressure in Pascals
        p = input('Please input a pressure in Pascals ');
        while checkValue(p) == False:
            # Sends the input to the checkValue function to see if sensible input, if it returns false then keeps looping and asking for a pressure
            p = input('Please input a pressure in Pascals ');
        # Converts the pressure to a float
        p = float(p);
        # Asks for a volume in m^3
        v = input('Please input a volume in m^3 ');
        while checkValue(v) == False:
            # Sends the input to the checkValue function to see if sensible input, if it returns false then keeps looping and asking for a volume
            v = input('Please input a volume in m^3 ');
        # Converts the volume to a float
        v = float(v);
        # Calculates the value of temperature using the inputed values of p and v
        answer = p * v / r
        # Prints the answer nicely
        print(
            'The temperature of a mole of gas at a pressure of %8.2e and a volume of %6.3f is %8.3e ' % (p, v, answer))

        # If input is p program gets here
    elif choice.lower() == 'p':
        # Asks for a temperature in Kelvin
        t = input('Please input a temperature in Kelvin ');
        while checkValue(t) == False:
            # Sends the input to the checkValue function to see if sensible input, if it returns false then keeps looping and asking for a temperature
            t = input('Please input a temperature in Kelvin ');
        # Converts the temperature to a float
        t = float(t)
        # Asks for a volume in m^3
        v = input('Please input a volume in m^3 ');
        while checkValue(v) == False:
            # Sends the input to the checkValue function to see if sensible input, if it returns false then keeps looping and asking for a volume
            v = input('Please input a volume in m^3 ');
        # Converts the volume to a float
        v = float(v)
        # Calculates the value of pressure using the inputed values of temperature and volume
        answer = r * t / v
        # Prints the answer nicely
        print(
            'The pressure of a mole of gas at a temperature of %6.3f and a volume of %6.3f is %8.3e ' % (t, v, answer))

    # If input is v program gets here
    elif choice.lower() == 'v':
        # Asks for a pressure in Pascals
        p = input('Please input a pressure in Pascals ');
        while checkValue(p) == False:
            # Sends the input to the checkValue function to see if sensible input, if it returns false then keeps looping and asking for a pressure
            p = input('Please input a pressure in Pascals ');
        # Converts the pressure to a float
        p = float(p)
        # Asks for a temperature in Kelvin
        t = input('Please input a temperature in Kelvin ');
        while checkValue(t) == False:
            # Sends the input to the checkValue function to see if sensible input, if it returns false then keeps looping and asking for a temperature
            t = input('Please input a temperature in Kelvin ');
        # Converts the temperature to a float
        t = float(t)
        # Calculates the value of volume using the inputed calues of temperature and pressure
        answer = r * t / p
        # Prints the answer nicely
        print(
            'The volume of a mole of gas at a temperature of %6.3f and a pressure of %8.2e is %8.2e ' % (t, p, answer))

    # Program gets here once calculation has been done and result has been displayed
    # Asks user if they want to do another calculation
    YesNo = input('Do you want to do another calculation? (Yes/No) ')
    while YesNo.lower() != 'yes' and YesNo.lower() != 'no':
        # Keeps looping and asking for either Yes or No input until one of them is entered, loops back to start if input is yes and ends program if no
        YesNo = input('Please input either Yes or No ')

