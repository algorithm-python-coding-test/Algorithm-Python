// 특정 레벨에 데이터가 들어올떄 같은 키값이 있으면 해당 데이터는 삭제 후 새로 넣음
// k를 처음만난 레벨과 할당된 메모리 크기를 출력하되 못찾으면 none
// 마지막 레벨에는 메모리 제한이 없음
// 아발랑쉬 연산은 insert 연산과 공통적인 부분이 있음 특정 레벨에 데이터를 넣는 과정
// 함수로 빼놓자
// 무조건 큰레벨이 더 큰 메모리를 갖고 있음
package choiheejin.swma;

import java.util.*;

public class no2 {
    static int N;
    static int[] memory = new int[101];
    static int[] currMem = new int[101];
    // 각 레벨 별로 [[키, 데이터], [키, 데이터]...]
    static List<List<int[]>> files = new ArrayList<>();

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        int Q = sc.nextInt();
        sc.nextLine();
        // 0레벨
        files.add(new ArrayList<>());
        for (int i = 1; i < N; i++) {
            memory[i] = sc.nextInt();
            files.add(new ArrayList<>());
        }
        // 마지막 레벨
        files.add(new ArrayList<>());
        sc.nextLine();

        List<String> answer = new ArrayList<>();
        for (int i = 0; i < Q; i++) {
            String query = sc.nextLine();
            // insert라면
            if (query.charAt(0) == 'I') {
                // 1레벨에 [k,S]를 집어넣는다.
                String[] info = query.split(" ");
                putData(1, Integer.parseInt(info[1]), Integer.parseInt(info[2]));
            } else {
                String[] info = query.split(" ");
                // 찾기 연산
                answer.add(find(1, Integer.parseInt(info[1])));
            }
        }

        for (int i = 0; i < answer.size(); i++) {
            System.out.println(answer.get(i));
        }
    }

    // 찾기 연산
    // 특정 레벨에서 찾고 없으면 다음 레벨로
    private static String find(int level, int key) {
        if (level > N)
            return "none";
        for (int i = 0; i < files.get(level).size(); i++) {
            if (files.get(level).get(i)[0] == key) {
                return level + " " + files.get(level).get(i)[1];
            }
        }
        return find(level + 1, key);
    }

    // 특정 레벨에 데이터 집어넣기
    private static void putData(int level, int key, int data) {
        // 키 값이 존재한다면 해당 키 값에 데이터를 갱신
        // 이부분 성능상 문제
        boolean exist = false;
        for (int i = 0; i < files.get(level).size(); i++) {
            if (files.get(level).get(i)[0] == key) {
                exist = true;
                currMem[level] -= files.get(level).get(i)[1];
                files.get(level).get(i)[1] = data;
                break;
            }
        }
        if (!exist) {
            files.get(level).add(new int[] { key, data });
        }
        currMem[level] += data;

        // 메모리 제한을 넘기면 레벨 i에 저장된 데이터를 모두 레벨 i+1로 넘기기
        if (level < N && memory[level] < currMem[level]) {
            for (int i = 0; i < files.get(level).size(); i++) {
                putData(level + 1, files.get(level).get(i)[0], files.get(level).get(i)[1]);
            }
            while (files.get(level).size() > 0) {
                files.get(level).remove(0);
            }
            currMem[level] = 0;
        }
    }
}
