#!/usr/bin/python3

import sys

def print_arguments(argv):
    num_args = len(argv)
    print("Number of argument(s):", num_args)

    if num_args == 0:
        print(".")
    else:
        print(":")
        for i, arg in enumerate(argv):
            print(i + 1, ":", arg)

if __name__ == "__main__":
    print_arguments(sys.argv[1:])
