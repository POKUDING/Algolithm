#!/usr/bin/env python3

import random as rd  # random 모듈의 이름을 'rd'로 변경

# N과 M 입력 받기
N, M = map(int, input().split())

# N x N 크기의 2차원 배열 초기화
array = [[-1 for _ in range(N)] for _ in range(N)]

# 각 원소를 -1 이상 M 이하의 랜덤 정수로 채우기
for i in range(N):
    for j in range(N):
        array[i][j] = rd.randint(-1, M)  # 'rd'로 변경

# 배열 출력
for row in array:
    for element in row:
        print(element, end=' ')
    print()
