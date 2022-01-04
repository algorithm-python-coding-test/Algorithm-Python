#△
def solution(key, lock):
    for i in range(4):  #90도 회전 4가지 경우의 수
        key = rotate_90(key)
        print(key)
        #이동 구현
        #일치 검사 구현

    answer = True
    return answer


def rotate_90(key):  #회전하는 함수 구현
    M = len(key)
    rot = [[0] * M for _ in range(M)]

    for i in range(M):
        for j in range(M):
            rot[j][M - 1 - i] = key[i][j]
    return rot