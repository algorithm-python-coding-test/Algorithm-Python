package choiheejin.kakao_winter_2019.first_try;
// 구현

// [0 0 0 0 0]
// [0 0 1 0 3]
// [0 2 5 0 1]
// [4 2 4 4 2]
// [3 5 1 3 1]
// 1. 하나의 move 항목에 대해서
//  - 해당 열에 있는 0이 아닌 것들 중 제일 위에 있는 값을 가져오고 그 자리는 0으로
//  - stack에 하나를 peek한 것과 같다면 그것을 pop한 후 answer +2, 다르다면 push
import java.util.Stack;

class Solution {
    public int solution(int[][] board, int[] moves) {
        int answer = 0;
        Stack<Integer> stack = new Stack<>();
        for (int col : moves) {
            for (int i = 0; i < board.length; i++) {
                if (board[i][col - 1] > 0) {
                    if (!stack.empty() && board[i][col - 1] == stack.peek()) {
                        stack.pop();
                        answer += 2;
                    } else {
                        stack.push(board[i][col - 1]);
                    }
                    board[i][col - 1] = 0;
                    break;
                }
            }
        }

        return answer;
    }
}