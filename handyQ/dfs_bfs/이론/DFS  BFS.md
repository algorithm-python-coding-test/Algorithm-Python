# DFS / BFS



## 1. 꼭 필요한 자료구조 기초

- 탐색

  많은 양의 데이터 중 원하는 데이터를 찾는 과정

- 대표적 탐색 알고리즘

  - DFS
  - BFS



- 자료구조

  데이터를 표현하고 관리하고 처리하기 위한 구조

  

- 기본 자료구조

  - 스택

  - 큐

    - 함수로 구성

      삽입 : 데이터 삽입

      삭제 : 데이터 삭제

    - 재귀 함수





### 스택

선입후출 구조 또는 후입선출 구조



### 큐

선입선출 구조

```python
# 파이썬 collections 모듈의 deque 자료구조 활용

from collections import deque

# 큐(Queue) 구현을 위해 deque 라이브러리 사용
queue = deque()

queue.append(5)
queue.append(2)
queue.append(3)
queue.append(7)
queue.popleft()
queue.append(1)
queue.append(4)
queue.popleft()

print(queue)
queue.reverse()
print(queue)

# deque([3,7,1,4])
# deque([4,1,7,3])

list(queue)
#리스트 자료형으로 변경
```



### 재귀함수

자기 자신을 다시 호출하는 함수



```python
def recursive_function():
    print('재귀 함수를 호출')
    recursive_function()

recursive_function()

# RecursionError: maximum recursion depth exceeded while calling a Python object
```



#### 종료 조건

재귀 함수 문제 풀이는 종료 조건을 꼭 명시해야 함



```python
def recursive_function(i):
    # 100번 째 출력했을 때 종료되도록 종료 조건 명시
    
    if i == 100:
        return 
    
    print(i, '번째 재귀 함수에서', i+1 , '번째 재귀 함수를 호출!!!')
    recursive_function(i+1)
    print(i, '번째 재귀 함수 종료---')
    
recursive_function(1)
```

컴퓨터 내부에서 재귀 함수 수행은 스택 자료구조 이용.

메인 메모리 스택 공간에 적재.

상당수 알고리즘은 재귀 함수를 이용해서 간편하게 구현. DFS



팩토리얼

```python
# 반복적 구현
def factorial_iterative(n):
    result = 1
    
    for i in range(1,n+1):
        result *= i
    return result

# 재귀적 구현
def factorial_recursive(n):
    if n<= 1:
        return 1
    
    return n * factorial_recursive(n-1)
```

if 문을 사용하여 종료 조건을 구현하기

반복문 보다 재귀가 간결한 경우.



## 2. 탐색 알고리즘 DFS / BFS



### DFS

깊이 우선 탐색

그래프에서 깊은 부분을 우선적으로 탐색하는 알고리즘



- 인접 행렬 

  2차원 배열로 그래프의 연결 관계를 표현하는 방식

- 인접 리스트

  리스트로 그래프의 연결 관계를 표현하는 방식



인접행렬 예제

```python
INF = 999999999 # 무한 

graph = [
    [0,7,5],
    [7,0,INF],
    [5,INF,0]
]

print(graph)

#[[0, 7, 5], [7, 0, 999999999], [5, 999999999, 0]]
```



인접리스트

C++, 자바는 별도 연결 리스트 기능 라이브러리 제공

파이썬은 2차원 리스트로 이용

```python
# 행이 3개인 2차원 리스트로 인접 리스트 표현

graph = [[] for _ in range(3)]

# 노드 0에 연결된 노드 정보 저장(노드, 거리)
graph[0].append((1,7))
graph[0].append((2,5))

# 노드 1에 연결된 노드 정보 저장(노드, 거리)
graph[1].append((0,7))

# 노드 2에 연결된 노드 정보 저장(노드, 거리)
graph[2].append((0,5))

print(graph)
#[[(1, 7), (2, 5)], [(0, 7)], [(0, 5)]]
```



| /           | 메모리 측면     | 두 노드 연결 정보 확인 |
| ----------- | --------------- | ---------------------- |
| 인접 행렬   | 불필요하게 낭비 | 빠르다                 |
| 인접 리스트 | 효율적          | 속도 느리다            |





#### DFS 탐색진행

스택 자료구조에 기초

실제로는 스택 쓰지 않아도 되고 데이터 개수가 N개인 경우 O(N)의 시간 소요

스택 이용 알고리즘이기 때문에 실제 구현은 재귀 함수를 이용했을 때 간결하게 구현 가능



```python
# DFS 메서드 정의

def dfs(graph, v, visited):
    # 현재 노드를 방문 처리
    visited[v] = True
    print(v, end=' ')
    
    # 현재 노드와 연결된 다른 노드를 재귀적으로 방문
    for i in graph[v]:
        if not visited[i]:
            dfs(graph, i, visited)
     
    
# 각 노드가 연결된 정보를 리스트 자료형으로 표현(2차원 리스트)
graph = [
    [],
    [2,3,8],
    [1,7],
    [1,4,5],
    [3,5],
    [3,4],
    [7],
    [2,6,8],
    [1,7]
]


# 각 노드가 방문된 정보를 리스트 자료형으로 표현 (1차원 리스트)
visited = [False] * 9


# 정의된 DFS 함수 호출
dfs(graph, 1, visited)
```



### BFS

너비 우선 탐색

가까운 노드부터 탐색하는 알고리즘

큐 자료구조 이용하는 것이 정석. 인접한 노드를 반복적으로 큐에 넣도록 알고리즘 작성 -> 먼저 들어온 것이 먼저 나가고 -> 가까운 노드부터 탐색 진행



deque 라이브러리 사용하는 것이 좋다. 

탐색 시간은 O(N)

일반적 실제 수행 시간은 DFS보다 좋은 편



```python
from collections import deque

# BFS 메서드 정의
def bfs(graph, start, visited):
    # 큐(Queue) 구현을 위해 deque 라이브러리 사용
    queue = deque([start])
	
    # 현재 노드를 방문 처리
    visited[start] = True
    
    # 큐가 빌 때까지 반복
    while queue:
        # 큐에서 하나의 원소를 뽑아 출력
        v = queue.popleft()
        print(v, end=' ')
        # 해당 원소와 연결된, 아직 방문하지 않은 원소들을 큐에 삽입
        for i in graph[v]:
            if not visited[i]:
                queue.append(i)
                visited[i] = True
```





| /         | DFS            | BFS              |
| --------- | -------------- | ---------------- |
| 동작 원리 | 스택           | 큐               |
| 구현 방법 | 재귀 함수 이용 | 큐 자료구조 이용 |



2차원 배열에서의 탐색 문제를 만나면 그래프 형태로 바꿔서 생각

