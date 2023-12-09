#!/usr/bin/python3

def switch_values(a, b):
    # Insert your code here
    a, b = b, a
    return a, b

# Test the function
a = 10
b = 89
a, b = switch_values(a, b)
print(f"a={a} - b={b}")  # Output: a=10 - b=89
