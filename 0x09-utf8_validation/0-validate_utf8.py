#!/usr/bin/python3
"""
 method that determines if a given data set represents a valid UTF-8 encoding
"""


def validUTF8(data):
    """
    Method that determines if a data set represents a valid UTF-8 encoding.
    """

    # Number of bytes in the current UTF-8 character
    n_bytes = 0

    
    for num in data:

        # Get the binary representation.
        b_rep = format(num, '#010b')[-8:]

        if n_bytes == 0:

            # Get the number of 1 in the beginning of the string.
            for bit in b_rep:
                if bit == '0':
                    break
                n_bytes += 1

            if n_bytes == 0:
                continue

            if n_bytes < 1 or n_bytes > 4:
                return False
        else:
            # Must start wit 10xxxxxxxx
            if not (b_rep[0] == '1' and b_rep[1] == '0'):
                return False

        # We reduce the number of bytes to process by 1 after each integer.
        n_bytes -= 1

    # catch for not enough data
    return n_bytes == 0