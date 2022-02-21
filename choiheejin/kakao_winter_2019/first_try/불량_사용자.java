// 중요한 점: 응모자 아이디가 중복해서 제제 아이디 목록에 들어가는 경우는 없음
// fr*d*, fr**i -> [frodo, fradi], [fradi] => frodo, fradi : 1가지 경우
// fr*d*, fr**i -> [frodo, fradi], [frodo, fradi] => 2가지 경우
// 1. 일단 각 banned_id 항목에 대해서 조건에 일치하는 user_id 항목을 저장
//   - 길이 먼저 찾기 => 길이 같으면 fr*d* -> 
// 2. 경우의 수 찾기
//   - 하나만 갖고 있는 것부터 일단 확정
//   - 두 개 이상인 경우에는 하나를 확정하였을 때의 나머지 경우의 수를 따짐 -> 확정할 때마다 항목 삭제
package choiheejin.kakao_winter_2019.first_try;

import java.util.ArrayList;
import java.util.List;

public class 불량_사용자 {
    public int solution(String[] user_id, String[] banned_id) {

        // 각 항목에 대하여 조건에 맞는 user_id 인덱스 리스트구하기
        List<List<Integer>> banned_user = new ArrayList<>();

        for (int i = 0; i < banned_id.length; i++) {
            List<Integer> index_list = new ArrayList<>();
            String query = banned_id[i];

            jj: for (int j = 0; j < user_id.length; j++) {
                // 길이가 다르면 pass
                if (user_id[j].length() != query.length()) {
                    continue;
                } else {
                    for (int k = 0; k < user_id[j].length(); k++) {
                        if (query.charAt(k) != '*' && user_id[j].charAt(k) != query.charAt(k)) {
                            continue jj;
                        }
                    }
                    index_list.add(j);
                }
            }
            banned_user.add(index_list);
        }

        // 경우의 수 구하기
        boolean[] checked = new boolean[user_id.length];
        return dfs(checked, banned_user, 0);
    }

    private int dfs(boolean[] checked, List<List<Integer>> banned_user, int i) {
        int caseCount = 0;
        for (int j = 0; j < banned_user.get(i).size(); j++) {
            if (!checked[banned_user.get(i).get(j)]) {
                checked[banned_user.get(i).get(j)] = true;
                if (i == banned_user.size() - 1) {
                    caseCount++;
                } else {
                    caseCount += dfs(checked, banned_user, i + 1);
                }
                checked[banned_user.get(i).get(j)] = false;
            }
        }
        return caseCount;
    }

    public static void main(String[] args) {
        String[] user_id = { "frodo", "fradi", "crodo", "abc123", "frodoc" };
        String[] banned_id = { "*rodo", "*rodo", "******" };
        System.out.println(new 불량_사용자().solution(user_id, banned_id));

    }

}
