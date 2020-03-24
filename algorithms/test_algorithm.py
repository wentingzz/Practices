import unittest
from karatsuba_mul import kmul
from merge_sort_alg import merge_sort
class TestAlgorithm(unittest.TestCase):

    def test_karatsuba_mul_even_length_number(self):
        self.assertEqual(41 * 1234, kmul(41, 1234))
        self.assertEqual(5678 * 1234, kmul(5678, 1234))
        self.assertEqual(5678567856785678 * 1234123412341234, kmul(5678567856785678, 1234123412341234))
    def test_karatsuba_mul_odd_length_number(self):
        self.assertEqual(4 * 234, kmul(4, 234))
        self.assertEqual(567 * 123, kmul(567, 123))
    def test_karatsuba_mul_non_positive(self):
        self.assertEqual(-56 * -1234, kmul(-56, -1234))
        self.assertEqual(-5678 * 1234, kmul(-5678, 1234))
    
    def test_merge_sort(self):
        self.assertEqual([1,2,3,4,5,6,7,8], merge_sort([5,4,1,8,7,2,6,3]))
        self.assertEqual([1,2,4,5,6,7,8], merge_sort([5,4,1,8,7,2,6]))