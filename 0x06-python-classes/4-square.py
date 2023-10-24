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
        self.size = size

    @property
    def size(self):
        """
        This is a Python property that gets the size.
        """
        return self.__size

    @size.setter
    def size(self, value):
        """
        This is a Python property setter that sets the size and validates it.

        Parameters:
           value (int): The new size of the square.
        """
        if not isinstance(value, int):
            raise TypeError("size must be an integer")
        elif value < 0:
            raise ValueError("size must be >= 0")
        else:
            self.__size = value

    def area(self):
        """
        This is a method that calculates and returns the current square area.
        """
        return self.__size * self.__size
