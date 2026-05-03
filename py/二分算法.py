def binary_search(arr, target, left, right):
    # 基线条件：搜索区间无效
    if left > right:
        return -1
    
    mid = (left + right) // 2
    
    # 基线条件：找到目标值
    if arr[mid] == target:
        return mid
    # 递归条件：目标值在左半部分
    elif arr[mid] > target:
        return binary_search(arr, target, left, mid - 1)
    # 递归条件：目标值在右半部分
    else:
        return binary_search(arr, target, mid + 1, right)