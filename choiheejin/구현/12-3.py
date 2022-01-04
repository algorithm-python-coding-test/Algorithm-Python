def check(chars, step):
    i = 0
    while i < len(chars):
        count = 1
        while True:
            if chars[i : i + step] == chars[i + step * count : i + step * (count + 1)]:
                count += 1
            else:
                break
        if count > 1:
            newString = (
                chars[:i] + str(count) + chars[i : i + step] + chars[i + step * count :]
            )
            i += step * count
        else:
            i += 1
        print(newString)


check("aaaababa", 2)
