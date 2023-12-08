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
