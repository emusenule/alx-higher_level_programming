#!/usr/bin/python3

def add_tuple(tuple_a=(), tuple_b=()):
    # Pad the tuples with zeros if they have less than 2 elements
    tuple_a += (0, 0)[:2 - len(tuple_a)]
    tuple_b += (0, 0)[:2 - len(tuple_b)]

    # Add the corresponding elements from each tuple
    result = (tuple_a[0] + tuple_b[0], tuple_a[1] + tuple_b[1])

    return result
