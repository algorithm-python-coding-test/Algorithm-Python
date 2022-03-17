// ULURRDLLU
// 노드의 개수는 11 * 11 = 121
// 존재하는 간선의 개수는 10 * 11 * 2 = 220
// 노드를 간선으로 연결하고 이동하면서 해당 간선을 이미 갔는지 확인할 수 있음
// 간선 정보는 가로 : x -> x + 1, y (ex- (0, -5 ~ -4), (0, 1-2), ...(0, 4 ~ 5))
// 세로: x, y -> y + 1 
// 소요시간: 0.15ms
package choiheejin.day3_20;

public class 방문_길이 {

    // x : -5 ~ 5 (11) y: -5 ~ 4 (10)
    static boolean[][] ver = new boolean[11][10];
    // x : -5 ~ 4 (10) y: -5 ~ 5 (11)
    static boolean[][] hori = new boolean[10][11];

    public int solution(String dirs) {
        int[] curr = new int[2];
        int count = 0;

        for (int i = 0; i < dirs.length(); i++) {
            if (dirs.charAt(i) == 'U') {
                if (curr[1] + 1 > 5)
                    continue;
                // 세로 간선 (curr[0], curr[1] ~ curr[1] + 1)을 확인
                if (!ver[curr[0] + 5][curr[1] + 5]) {
                    count++;
                    ver[curr[0] + 5][curr[1] + 5] = true;
                }
                // curr 이동
                curr[1] = curr[1] + 1;
            } else if (dirs.charAt(i) == 'D') {
                if (curr[1] - 1 < -5)
                    continue;
                // 세로 간선 (curr[0], curr[1] - 1 ~ curr[1])을 확인
                if (!ver[curr[0] + 5][curr[1] - 1 + 5]) {
                    count++;
                    ver[curr[0] + 5][curr[1] - 1 + 5] = true;
                }
                // curr 이동
                curr[1] = curr[1] - 1;
            } else if (dirs.charAt(i) == 'R') {
                if (curr[0] + 1 > 5)
                    continue;
                // 가로 간선 (curr[0] ~ curr[0] + 1, curr[1])을 확인
                if (!hori[curr[0] + 5][curr[1] + 5]) {
                    count++;
                    hori[curr[0] + 5][curr[1] + 5] = true;
                }
                // curr 이동
                curr[0] = curr[0] + 1;
            } else {
                if (curr[0] - 1 < -5)
                    continue;
                // 가로 간선 (curr[0] - 1 ~ curr[0], curr[1])을 확인
                if (!hori[curr[0] - 1 + 5][curr[1] + 5]) {
                    count++;
                    hori[curr[0] - 1 + 5][curr[1] + 5] = true;
                }
                // curr 이동
                curr[0] = curr[0] - 1;
            }
        }

        return count;
    }
}
