#!/usr/bin/python3
""" UTF-8 Validation """


def validUTF8(data):
    """
    Method that determines if a given data set represents a valid
    UTF-8 encoding
    """
    num_bytes = 0

    maskone = 1 << 7
    masktwo = 1 << 6

    for i in data:

        mask_n_byte = 1 << 7

        if num_bytes == 0:
            # Count number of bytes the UTF-8 Character will have
            while mask_n_byte & i:
                num_bytes += 1
                mask_n_byte = mask_n_byte >> 1

            # If number of bytes did not increase then it has 1 byte
            if num_bytes == 0:
                continue

            # A character in UTF-8 can be 1 to 4 bytes long

            if num_bytes == 1 or num_bytes > 4:
                return False

        else:
            if not (i & maskone and not (i & masktwo)):
                    return False

        num_bytes -= 1

    if num_bytes == 0:
        return True

    return False
