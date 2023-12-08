#!/usr/bin/python3

import sys
from decimal import Decimal

def add_arguments(argv):
    total = Decimal(0)
    for arg in argv:
        total += Decimal(arg)
    return total

if __name__ == "__main__":
    sum_result = add_arguments(sys.argv[1:])
print(sum_result)

if __name__ == "__main__":
    """Print the addition of all arguments."""
    import sys

    total = 0
    for i in range(len(sys.argv) - 1):
        total += int(sys.argv[i + 1])
    print("{}".format(total))

