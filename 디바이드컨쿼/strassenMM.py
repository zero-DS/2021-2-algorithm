from typing import Mapping


def matrix_Sum(a,b,len):
    result=[]
    for i in range(len):
        result.append([])
        for j in range(len):
            result[i].append(a[i][j]+b[i][j])
    return result
def matrix_Substract(a,b,len):
    result=[]
    for i in range(len):
        result.append([])
        for j in range(len):
            result[i].append(a[i][j]-b[i][j])
    return result

def matrix_Multiply(a,b,len):
    result=[]
    if len==1:
        result.append([])
        result[0].append(a[0][0]*b[0][0])
        return result
    len=int(len/2)
    A11,A12,A21,A22,B11,B12,B21,B22=[],[],[],[],[],[],[],[]
    for i in range(len):
        A11.append([])
        A12.append([])
        A21.append([])
        A22.append([])
        B11.append([])
        B12.append([])
        B21.append([])
        B22.append([])
        for j in range(len):
            A11[i].append(a[i][j])
            A12[i].append(a[i][len+j])
            A21[i].append(a[len+i][j])
            A22[i].append(a[len+i][len+j])
            B11[i].append(b[i][j])
            B12[i].append(b[i][len+j])
            B21[i].append(b[len+i][j])
            B22[i].append(b[len+i][len+j])

    
    M1=matrix_Multiply(matrix_Sum(A11,A22,len),matrix_Sum(B11,B22,len),len)
    M2=matrix_Multiply(matrix_Sum(A21,A22,len),B11,len)
    M3=matrix_Multiply(A11,matrix_Substract(B12,B22,len),len)
    M4=matrix_Multiply(A22,matrix_Substract(B21,B11,len),len)
    M5=matrix_Multiply(matrix_Sum(A11,A12,len),B22,len)
    M6=matrix_Multiply(matrix_Substract(A21,A11,len),matrix_Sum(B11,B12,len),len)
    M7=matrix_Multiply(matrix_Substract(A12,A22,len),matrix_Sum(B21,B22,len),len)

    
    C11=matrix_Substract(matrix_Sum(matrix_Sum(M1,M4,len),M7,len),M5,len)
    C12=matrix_Sum(M3,M5,len)
    C21=matrix_Sum(M2,M4,len)
    C22=matrix_Sum(matrix_Substract(M1,M2,len),matrix_Sum(M3,M6,len),len)
    
    for i in range(len*2):
        result.append([])
        for j in range(len*2):
            result[i].append(0)
    for i in range(len):
        for j in range(len):
            result[i][j]=C11[i][j]
            result[i][len+j]=C12[i][j]
            result[len+i][j]=C21[i][j]
            result[len+i][len+j]=C22[i][j]
    
    return result

arr1=[]
arr2=[]
print("strassen's algorithm")
print("N x N 행렬의 크기를 입력하세요 (2의 n제곱꼴만 가능) : ",end='')
MATSIZE=int(input())
print("첫번째 행렬을 입력하세요 : ")
for i in range(MATSIZE):
    arr1.append(input().split())
    arr1[i]=list(map(int,arr1[i]))
print("두번째 행렬을 입력하세요 : ")
for i in range(MATSIZE):
    arr2.append(input().split())
    arr2[i]=list(map(int,arr2[i]))

result=matrix_Multiply(arr1,arr2,MATSIZE)
print("matrix multiplication result")
for i in range(MATSIZE):
    for j in range(MATSIZE):
        print(result[i][j],end=' ')
    print()


