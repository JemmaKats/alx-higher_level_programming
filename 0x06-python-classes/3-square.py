#!/usr/bin/python3
class Square:
    """
    This is a class which defines a square.

    Attributes:
        size (int): The size of the square.
    """

    def __init__(self, size=0):
        """
        The constructor for Square class.

        Parameters:
           size (int): The size of the square. Defaults to 0.
        """
        if not isinstance(size, int):
            raise TypeError("size must be an integer")
        elif size < 0:
            raise ValueError("size must be >= 0")
        else:
            self.__size = size

    def area(self):
        """
        This is a method that calculates and returns the current square area.
        """
        return self.__size * self.__size
