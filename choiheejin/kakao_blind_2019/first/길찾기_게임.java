// 이진 트리 간선 연결 후
// 순회
// 루트 노드 찾는 법 : 제일 위에 있는 것
// 왼쪽 노드 찾는 법 : 자기보다 왼쪽, 아래에 있는 것들 중에 제일 위에 있는 것
// 오른쪽 노드 찾는 법 : 자기보다 오른쪽, 아래에 있는 것들 중에 제일 위에 있는 것
// 아래 정보 확인 못함
// 같은 y좌표는 같은 레벨
package choiheejin.kakao_blind_2019.first;

import java.util.*;

public class 길찾기_게임 {
    class Node {
        int left;
        int right;
    }

    Node[] graph;
    int root;

    public int[][] solution(int[][] nodeinfo) {

        // y축 내림차순
        PriorityQueue<int[]> pq = new PriorityQueue<>((o1, o2) -> o2[2] - o1[2]);
        for (int i = 0; i < nodeinfo.length; i++) {
            pq.offer(new int[] { i + 1, nodeinfo[i][0], nodeinfo[i][1] });
        }
        graph = new Node[nodeinfo.length + 1];
        root = pq.peek()[0];
        // 현재 노드 생성
        graph[root] = new Node();
        drawGraph(pq);

        int[][] answer = {};
        return answer;
    }

    private void drawGraph(PriorityQueue<int[]> pq) {
        while (!pq.isEmpty()) {
            int[] curr = pq.poll();
            Node currNode = graph[curr[0]];
            Iterator<int[]> iterator = pq.iterator();
            while (iterator.hasNext()) {
                iterator.next();
            }
        }
    }

    public static void main(String args[]) {
        int[][] nodeinfo = { { 5, 3 }, { 11, 5 }, { 13, 3 }, { 3, 5 }, { 6, 1 }, { 1, 3 }, { 8, 6 }, { 7, 2 },
                { 2, 2 } };
        System.out.println(new 길찾기_게임().solution(nodeinfo));

    }

}
