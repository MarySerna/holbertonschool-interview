#!/usr/bin/python3
""" UTF-8 Validation """


def validUTF8(data):
    """
    Method that determines if a given data set represents a valid
    UTF-8 encoding.
    """
  
	nm_bytes = 0
	maskone = 1 << 7
	masktwo = 1 << 6

	for i in data:

	mask_n_byte = 1 << 7

	if nm_bytes == 0:
		while mask_n_byte & i:
			nm_bytes += 1
			mask_n_byte = mask_n_byte >> 1

		if nm_bytes == 0:
			continue

		if nm_bytes == 1 or nm_bytes > 4:
			return False

	else:
		if not (i & maskone and not (i & masktwo)):
			return False

		nm_bytes -= 1

	if nm_bytes == 0:
        return True

    return False
