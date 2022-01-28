from itertools import combinations

def solution(orders, course):
    answer = []
    for c in course:
        courseDict = {}
        for order in orders:
            multiple = list(combinations(list(order), c))
            for case in multiple:
                caseList = list(case)
                caseList.sort()
                courseStr = ''.join(caseList)
                if courseStr not in courseDict:
                    courseDict[courseStr] = 1
                else:
                    courseDict[courseStr] = courseDict[courseStr] + 1
        maxValue = 0
        maxCourse = []
        keysList = courseDict.keys()
        for courseCase in keysList:
            if courseDict[courseCase] >= 2:
                if maxValue < courseDict[courseCase]:
                    maxCourse = [courseCase]
                    maxValue = courseDict[courseCase]
                elif maxValue == courseDict[courseCase]:
                    maxCourse.append(courseCase)
        answer = answer + maxCourse
        answer.sort()
    return answer