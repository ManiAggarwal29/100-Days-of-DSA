/*
Problem: Implement Binary Search Iterative - Implement the algorithm.
*/
def binary_search_iterative(arr, target):
   low, high = 0, len(arr) - 1
   while low <= high:
       mid = low + (high - low) // 2
       if arr[mid] == target:
           return mid
       elif arr[mid] < target:
           low = mid + 1
       else:
           high = mid - 1
   return -1
# Example usage
nums = [2, 5, 8, 12, 16, 23, 38, 56, 72, 91]
target = 23
result = binary_search_iterative(nums, target)
if result != -1:
   print(f"Element found at index {result}")
else:
   print("Element not found")
