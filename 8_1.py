def binary_and(a: str, b: str) -> str:
    result = bin(int(a, 2) & int(b, 2))[2:]  
    return result.zfill(max(len(a), len(b)))
def binary_sum(a: str, b: str) -> str:
    result = bin(int(a, 2) + int(b, 2))[2:] 
    return result  


A = "101101"  
B = "110011"


and_result = binary_and(A, B)
print(f"Результат побитовой операции AND: {and_result}")


sum_result = binary_sum(A, B)
print(f"Сумма: {sum_result}")

