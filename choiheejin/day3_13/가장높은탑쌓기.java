// 1번째는 그냥 첫번째 블록 높이
// 2번째는 1번째 블록과 함께 끼울 수 있는지 확인
// 안되면 기존 것을 빼고 새로운 것으로 끼운 경우와
// 그대로 놔둔 경우를 비교 하여 더 높은 것을 저장
// 3번째는 기존 탑에 끼울 수 있는지 확인하고
// 안되면 일부를 뺴되, 못들어갔던 블록들이 들어갈 수 있는지 확인
// 기존의 경우와 비교 후 최대인 경우를 저장
package choiheejin.day3_13;

import java.util.*;

public class 가장높은탑쌓기 {

    static class Block {
        int index;
        int area;
        int height;
        int weight;

        public Block(int index, int area, int height, int weight) {
            this.index = index;
            this.area = area;
            this.height = height;
            this.weight = weight;
        }
    }

    // [인덱스, 넓이, 높이, 무게]
    static Block[] blocks;

    // 해당 번째 블록을 쌓은 경우
    static List<List<Block>> haveI = new ArrayList<>();

    // 해당 번째 블록을 쌓지 않은 경우
    static List<List<Block>> dontHaveI = new ArrayList<>();

    // 두 경우에 대한 높이 저장
    static int[][] dp = new int[100][2];

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        blocks = new Block[n];
        sc.nextLine();
        for (int i = 0; i < n; i++) {
            blocks[i] = new Block(i + 1, sc.nextInt(), sc.nextInt(), sc.nextInt());
            haveI.add(new ArrayList<>());
            dontHaveI.add(new ArrayList<>());
            sc.nextLine();
        }

        // 일단 넓이로 정렬
        Arrays.sort(blocks, (o1, o2) -> o1.area - o2.area);

        haveI.get(0).add(blocks[0]);
        dp[0][0] = blocks[0].height;
        for (int i = 1; i < blocks.length; i++) {
            Block curr = blocks[i];
            int last = i - 1;
            while (last >= 0 && blocks[last].weight > curr.weight) {
                last--;
            }
            if (last == i - 1) {
                if (dp[i - 1][0] >= dp[i - 1][1]) {
                    haveI.get(i).addAll(haveI.get(i - 1));
                    dp[i][0] = dp[i - 1][0];
                } else if (dp[i - 1][0] < dp[i - 1][1]) {
                    haveI.get(i).addAll(dontHaveI.get(i - 1));
                    dp[i][0] = dp[i - 1][1];
                }
                haveI.get(i).add(curr);
                dp[i][0] += curr.height;
            } else {
                haveI.get(i).addAll(dontHaveI.get(last + 1));
                haveI.get(i).add(curr);
                dp[i][0] = dp[last + 1][1] + curr.height;
            }

            if (dp[i - 1][0] >= dp[i - 1][1]) {
                dontHaveI.get(i).addAll(haveI.get(i - 1));
                dp[i][1] = dp[i - 1][0];
            } else if (dp[i - 1][0] < dp[i - 1][1]) {
                dontHaveI.get(i).addAll(dontHaveI.get(i - 1));
                dp[i][1] = dp[i - 1][1];
            }
        }

        if (dp[n - 1][0] >= dp[n - 1][1]) {
            System.out.println(haveI.get(n - 1).size());
            for (Block block : haveI.get(n - 1)) {

                System.out.println(block.index);
            }
        } else {
            for (Block block : dontHaveI.get(n - 1)) {
                System.out.println(dontHaveI.get(n - 1).size());
                System.out.println(block.index);
            }
        }
    }

}
