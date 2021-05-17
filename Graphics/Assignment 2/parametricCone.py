from math import *
import numpy as np
from matrix import matrix
from parametricObject import parametricObject

class parametricCone(parametricObject):

    def __init__(self,T=matrix(np.identity(4)),height=10.0,radius=5.0,color=(255,255,255),reflectance=(0.2,0.4,0.4,1.0),uRange=(0.0,2.0*pi),vRange=(0.0,2.0*pi),uvDelta=(pi/18.0,pi/9.0)):
        super().__init__(T,color,reflectance,uRange,vRange,uvDelta)
        self.__height = height
        self.__radius = radius

    # The cone ( 0≤u≤1,0≤v≤2 π ):


    def getPoint(self,u,v):
        P = matrix(np.ones((4, 1)))
        # h(1-u)/h r sin (v)
        P.set(0, 0, ((self.__height * (1 - u)) / self.__height) * self.__radius * sin(v))
        # h(1-u)/h r cos (v)
        P.set(1, 0, ((self.__height * (1 - u)) / self.__height) * self.__radius * cos(v))
        # hu
        P.set(2, 0, self.__height * u)
        # 1 , already 1
        return P

    # Set parameters
    def setRadius(self, width):
        self.__radius = width

    def setHeight(self, height):
        self.__height = height

    # Get parameters
    def getRadius(self):
        return self.__radius

    def getHeight(self):
        return self.__height
