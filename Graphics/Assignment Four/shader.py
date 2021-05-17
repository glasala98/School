# CS-3388 Computer Graphics Winter 2021
# Assignment Four
# Gerrid La Sala
# glasala
# 250900234

class shader:
    # For a given ray (and its corresponding pixel (i , j) in the image), the constructor computes the color for the pixel (i , j)
    # by applying a shading model identical to that employed in Assignment 3. The helper method __shadowed determines if a particular pixel
    # in in the shadow of other objects, or itself. It does so by forming a ray from the intersection point in the direction of the light source.
    # If any object is intersected by the ray, then the pixel is in shadowed, and the pixel is shaded using ambient light only.
    # In order to program this properly, you may use the algorithms that are provided in the class notes titled Initial Ray Tracing Algorithms.

    # Helper: method __shadowed(self,object,I,S,objectList):
    # Input: object is that which there is an intersection with; I is the intersection
    # point; S is the vector to the light source, and objectList is a list of objects
    # composing the scene.
    # Output: Returns true if the ray from the intersection point to the light source
    # intersects with an object from the scene, and returns false otherwise.
    def __shadowed(self,object,I,S,objectList):
        # Algorithm:
        # • M = matrix T associated with object
        M = object.getT()
        # • compute I=M (I+ϵ S ) where ϵ=0.001 . This operation detaches the
        I = M * (I + S.scalarMultiply(0.001))
        # intersection point from its surface, and then transforms it into world
        # coordinates
        # • compute S=MS . This transforms S into world coordinates
        S = M * S
        # • for object in objectList:
        for x in objectList:
            # ◦ M−1 = inverse of matrix T associated with object
            # ◦ compute I=M−1
            MInv = x.getTinv()
            # I . This transforms the intersection point into the generic coordinates of the object
            Ix = MInv * I
            # ◦ compute S=M−1 * S and normalize S .
            # This transforms the vector to the light source into the generic coordinates of the object
            Sx = (MInv * S).normalize()
            # ◦ if object.intersection (I , S) ≠ −1.0 : (this means there is an
            if x.intersection(Ix,Sx) != -1.0:
            # intersection with another object) then return True
                return True
            # • return False
        return False

    # Shader: __init__ (self,intersection,direction,camera,objectList,light):
    # Input: intersection is the first (k ,t0# ) tuple from the intersection list; direction is
    # the vector describing the direction of the ray; objectList is a list of objects
    # composing the scene, and light is a lightSource object.
    # CS-3388 Computer Graphics Winter 2021
    # Output: Computes the shaded color for pixel (i , j) as instance variable
    # self.__color
    def __init__(self,intersection,direction,camera,objectList,light):
        # Algorithm:
        # • consider tuple (k ,t# 0# ) from intersection
        self.__k = intersection[0]
        self.__object = objectList[self.__k]
        # • object = objectList [k ]
        # • t0 is the t-value associated with object from tuple (k ,t0)
        self.__t0 = intersection[1]
        # • M−1 = inverse of matrix T associated with object
        self.__MInv = self.__object.getT().inverse()
        # • T s = light position transformed with M−1
        self.__Ts = self.__MInv * light.getPosition()
        # • transform the ray with M−1 in the following way:
        # Te=M−1e , where e is the position of the camera,
        self.__Te = self.__MInv * camera.getE()
        # and T d=M−1d , where d is the direction of the ray
        self.__Td = self.__MInv * direction
        # • compute the intersection point as I=T e+T dt0
        self.__I = self.__Te + self.__Td.scalarMultiply(self.__t0)
        # • compute vector from intersection point to light source position as S=(T s−I) , and normalize it
        self.__S = (self.__Ts - self.__I).normalize()
        # • compute normal vector at intersection point as
        # N = object.normal Vector (I )
        self.__N = self.__object.normalVector(self.__I)
        # • compute specular reflection vector as R=−S+(2 S⋅N )N
        self.__R = self.__N.scalarMultiply(2 * (self.__S.removeRow(3).transpose() * self.__N.removeRow(3)).get(0, 0)) - self.__S
        # • compute vector to center of projection V =T e−I , and normalize it
        self.__V = (self.__Te - self.__I).normalize()
        # • compute I d=max {N⋅S ,0} and I s=max {R⋅V ,0}
        self.__Id = max(((self.__N.removeRow(3).transpose() * self.__S.removeRow(3)).get(0, 0)), 0)
        self.__Is = max(((self.__R.removeRow(3).transpose() * self.__V.removeRow(3)).get(0, 0)), 0)
        # • r= object.getReflectance()
        self.__r = self.__object.getReflectance()
        # • c= object.getColor()
        self.__c = self.__object.getColor()
        # • Li= light.getIntensity()
        self.__Li = light.getIntensity()
        # • if the intersection point is not shadowed by other objects e.g. this is a call to helper method __shadowed(object, I , S ,objectList):
        self.__f = 0.0
        self.__color = (0, 0, 0)
        if not self.__shadowed(self.__object, self.__I, self.__S, objectList):
            # ◦ compute f =r[0]+r[1] I d+r[2] Is r[3]
            self.__f = self.__r[0] + self.__r[1] * self.__Id + self.__r[2] * (self.__Is ** self.__r[3])
        # • else:
        # ◦ compute f =r[0]
        else:
            self.__f = self.__r[0]
        # • compute tuple self.__color = ( f (c [0] Li[0], c[1] Li[1], c [2] Li [2]))
        self.__color = (int(self.__f * self.__c[0] * self.__Li[0]), int(self.__f * self.__c[1] * self.__Li[1]),
                        int(self.__f * self.__c[2] * self.__Li[2]))

    def getShade(self):
        return self.__color
