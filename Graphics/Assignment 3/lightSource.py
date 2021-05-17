# CS-3388 Computer Graphics
# Assignment Three
# Gerrid La Sala
# 250900234

import numpy as np
from matrix import matrix


# Initializes position, color and intensity of the light source.
# Has helper functions to set and return parameters.
class lightSource:

    def __init__(self, position=matrix(np.zeros((4, 1))), color=(0, 0, 0), intensity=(1.0, 1.0, 1.0)):
        self.__position = position
        self.__color = color
        self.__intensity = intensity

    # Getter Method to return position
    def getPosition(self):
        return self.__position

    # Getter Method to return color
    def getColor(self):
        return self.__color

    # Getter Method to return Intensity
    def getIntensity(self):
        return self.__intensity

    # Setter Method to set position
    def setPosition(self, position):
        self.__position = position

    # Setter Method to set color
    def setColor(self, color):
        self.__color = color

    # Setter Method to set intensity
    def setIntensity(self, intensity):
        self.__intensity = intensity
