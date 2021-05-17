from math import *
import numpy as np
from matrix import matrix
from parametricObject import parametricObject

class parametricPlane(parametricObject):

    def __init__(self, T=matrix(np.identity(4)), width=1.0, height=1.0, color=(0, 0, 0), reflectance=(0.0, 0.0, 0.0), uRange=(0.0, 0.0), vRange=(0.0, 0.0), uvDelta=(0.0, 0.0)):
        super().__init__(T,color,reflectance,uRange,vRange,uvDelta)
        self.__height = height
        self.__width = width

    #The plane ( 0≤u≤1,0≤v≤1 ):

    def getPoint(self,u,v):
        P = matrix(np.ones((4, 1)))
        # uw
        P.set(0, 0, self.__width * u)
        # vh
        P.set(1, 0, self.__height * v)
        # 0
        P.set(2, 0, 0)
        # 1 , already 1
        return P

    # Set parameters
    def setWidth(self,width):
        self.__width = width

    def setHeight(self, height):
        self.__height

    # Get parameters
    def getWidth(self):
        return self.__width

    def getHeight(self):
        return self.__height
