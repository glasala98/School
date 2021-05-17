from math import *
import numpy as np
from matrix import matrix
from parametricObject import parametricObject

class parametricCircle(parametricObject):

    def __init__(self,T=matrix(np.identity(4)),radius=10.0,color=(255,255,255),reflectance=(0.2,0.4,0.4,1.0),uRange=(0.0,2.0*pi),vRange=(0.0,2.0*pi),uvDelta=(pi/18.0,pi/9.0)):
        super().__init__(T,color,reflectance,uRange,vRange,uvDelta)
        self.__radius = radius

    # The circle ( 0≤u≤1,0≤v≤2 π ):
    def getPoint(self,u,v):
        P = matrix(np.ones((4,1)))
        # r u cos (v)
        P.set(0, 0, self.__radius * u * cos(v))
        # r u sin (v)
        P.set(1, 0, self.__radius * u * sin(v))
        # 0
        P.set(2, 0, 0)
        # 1
        return P

    # Set parameters
    def setRadius(self,radius):
        self.__radius = radius

    # Get parameters
    def getRadius(self):
        return self.__radius
