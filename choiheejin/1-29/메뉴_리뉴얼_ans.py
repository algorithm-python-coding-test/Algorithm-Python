    def solution_itertools(orders, course):
        import itertools

        answer = []

        for size_of_course in course:
            order_dict = {}
            order_combinations = []
            for order in orders:
                order_combinations.extend(list(itertools.combinations(sorted(order), size_of_course)))

            for order_combination in order_combinations:
                order_str = ''.join(order_combination)
                if order_str in order_dict:
                    order_dict[order_str] += 1
                else:
                    order_dict[order_str] = 1

            for order in order_dict:
                if order_dict[order] == max([order_dict[order] for order in order_dict]):
                    if order_dict[order] > 1:
                        answer.append(order)


        return sorted(answer) # 오름차순으로 반환해야 하기 때문에, sorted로 정렬 해준다.