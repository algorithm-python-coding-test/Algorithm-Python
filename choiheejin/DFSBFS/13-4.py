def separateUV(s):
    l = 0
    r = 0

    for i in range(len(s)):
        if s[i] == "(":
            l += 1
        else:
            r += 1

        if l == r and l != 0 and r != 0:
            return i
    return len(s) - 1


def checkU(u):
    while True:
        if "()" in u:
            u = u.replace("()", "")
        else:
            break
    if u == "":
        return True
    else:
        return False


def service(p):
    if p == "":
        return ""

    u = p[0 : separateUV(p) + 1]
    v = p[separateUV(p) + 1 :]

    if checkU(u):
        return u + service(v)
    else:
        u = u[1 : len(u) - 1]
        u = u.replace(")", "x")
        u = u.replace("(", ")")
        u = u.replace("x", "(")
        return "(" + service(v) + ")" + u


def solution(p):
    return service(p)
