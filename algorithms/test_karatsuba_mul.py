import unittest
from karatsuba_mul import kmul
class TestAlgorithm(unittest.TestCase):

    def test_karatsuba_mul_even_length_number(self):
        self.assertEqual(41 * 1234, kmul(41, 1234))
        self.assertEqual(5678 * 1234, kmul(5678, 1234))
    def test_karatsuba_mul_odd_length_number(self):
        self.assertEqual(4 * 234, kmul(4, 234))
        self.assertEqual(567 * 123, kmul(567, 123))
    def test_karatsuba_mul_non_positive(self):
        self.assertEqual(-56 * -1234, kmul(-56, -1234))
        self.assertEqual(-5678 * 1234, kmul(-5678, 1234))
