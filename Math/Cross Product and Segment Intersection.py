import cmath
 
# Function to calculate cross product of two vectors AB and AC
def cross_product(A, B, C):
    AB = B - A  # Vector from A to B
    AC = C - A  # Vector from A to C
    return AB.conjugate() * AC  # Cross product of AB and AC
 
# Function to compare two points
def compare_points(a, b):
    return (a.real == b.real and a.imag < b.imag) or a.real < b.real
 
# Function to check if point C lies between point A and B
def is_mid_point(A, B, C):
    v = [A, B, C]
    v.sort(key=lambda x: (x.real, x.imag))
    return v[1] == C
 
# Function to get sign of a number
def sign(x):
    return (x > 0) - (x < 0)
 
# Function to check if line segments AB and CD intersect
def do_intersect(A, B, C, D):
    cross_product1 = cross_product(A, B, C)
    cross_product2 = cross_product(A, B, D)
    cross_product3 = cross_product(C, D, A)
    cross_product4 = cross_product(C, D, B)
    if cross_product1.imag == 0 and is_mid_point(A, B, C):
        return True
    if cross_product2.imag == 0 and is_mid_point(A, B, D):
        return True
    if cross_product3.imag == 0 and is_mid_point(C, D, A):
        return True
    if cross_product4.imag == 0 and is_mid_point(C, D, B):
        return True
    if sign(cross_product1.imag) != sign(cross_product2.imag) and sign(cross_product3.imag) != sign(cross_product4.imag):
        return True
    return False