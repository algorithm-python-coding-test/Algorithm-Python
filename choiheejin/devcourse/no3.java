// 철로는 신장트리임
// 모든 노드를 포함하면서 사이클이 없음
// 종착역을 정해서 종착역으로 가는 길을 왕복으로 돌아야함
// 종착역으로 향하는 길은 하나 밖에 없음
// 모든 곳을 종착역으로 지정해보고 dfs로 이용객수를 모두 구해야함
package choiheejin.devcourse;

import java.util.ArrayList;
import java.util.List;

public class no3 {
    public int[] solution(int n, int[] passenger, int[][] train) {

        int[] people = new int[n];
        List<List<Integer>> graph = new ArrayList<>();
        for (int i = 0; i <= n; i++) {
            graph.add(new ArrayList<>());
        }

        for (int[] entity : train) {
            graph.get(entity[0]).add(entity[1]);
            graph.get(entity[1]).add(entity[0]);
        }

        dfs(people, graph, 1, passenger);

        int[] answer = {};
        return answer;
    }

    public static void dfs(int[] people, List<List<Integer>> graph, int node, int[] passenger) {
        people[node] += passenger[node];

    }

    public static void main(String[] args) {
        int n = 6;
        int[] passenger = { 1, 1, 1, 1, 1, 1 };
        int[][] train = { { 1, 2 }, { 1, 3 }, { 1, 4 }, { 3, 5 }, { 3, 6 } };
        new no3().solution(n, passenger, train);
    }
}